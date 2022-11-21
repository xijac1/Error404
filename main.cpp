// we will create our project here

#include <iostream>
#include <string>
#include <ctype.h> //isdigit
#include <sstream> //stringstream
#include <iomanip>
#include <fstream>
using namespace std;

void main_program();

int choice;
int inputvalidation();

// functions
void asia();
//variables
ifstream infile1;

//asia
string asian_dish1;


string user_string_num0 = "";
int main()
{
    cout << right << setw(14) << setfill(' ') << endl << endl << "FoodX\n";
 
    cout << right << setw(24) << setfill('-') << " " << endl;

    cout << "| SELECT A REGION     |\n";
    cout << "| [1] - Africa        |\n"
         << "| [2] - North America |\n"
         << "| [3] - Asia          |\n"
         << "| [4] - Europe        |\n"
         << "| [5] - Latin America |\n";
    cout << right << setw(24) << setfill('-') << " " << endl;
    cout << ">>> ";

    choice = inputvalidation();

    switch (choice)
    {
        case 1:
        {
            asia();
        }
        break;

        default:
        {
            cout << "nothing\n";
        }
    }

return 0;

}





void asia()
{
    cout << "African Dishes\n"
        << setw(15) << setfill('-') << " " << endl
        << "Select For Recipe:\n";
    cout << "1 - West African Ribs\n"
         << ">>> ";
    cin >> choice;

    switch(choice)
    {
    case 1:
    {
        int count = 0;
        infile1.open("West_African_Ribs.txt"); // or fstream file to read

        //check for error
        if(infile1.fail())
        {
            cerr << "Error openning file" << endl;
            exit(1);
        }

        while(!infile1.eof())
        {
            getline(infile1, asian_dish1);
            cout << asian_dish1 << endl;
            count ++;
        }

        cout << endl << count << " items found" << endl << endl;
    }
        break;

    default:
    {
        cout << "working\n";
    }

    }
}






// this function checks for input validation.
int inputvalidation()
{
    string user_string_num = "";

    int is_num = 0,
        decimal_count = 0,
        user_converted_num;

    bool is_num_bool = 0,
         contains_spaces = false;

    do
    {
        cout << "Enter a choice: ";
        getline(cin, user_string_num);


        for (int i = 0; i < user_string_num.size(); i++)
        {
            if (isspace(user_string_num[i]))
                contains_spaces = true;
        }

        if (user_string_num[0] == '-') // jesus -8
        {
            is_num++;

            if (user_string_num[1] == '0') // -0999 invalid
                is_num = 0;
        }

        if ((user_string_num[0] == '0' && isdigit(user_string_num[1]))) // 0934939
            is_num = 0;
        else
        {
            for (int i = 0; i < user_string_num.size(); i++)
            {
                if (isdigit(user_string_num[i]))
                    is_num++;
                if (user_string_num[i] == '.')
                    decimal_count++;
            }
        }

        if (decimal_count == 1) // 66.7 // 8..9.9.9..9.9
            is_num = 0;

        if (is_num == user_string_num.size() && contains_spaces == false)
        {
            stringstream str_stream_object(user_string_num);
            str_stream_object >> user_converted_num;

            is_num_bool = 1;

            main_program();
        }
        else
        {
            cout << endl
                 << "Number must NOT contain spaces.\n"
                 << "Number must NOT contain letters.\n"
                 << "Number must NOT contain symbols.\n"
                 << "Number must NOT be a decimal number.\n"
                 << endl;

            is_num_bool = 0;
            is_num = 0;
            decimal_count = 0;
            contains_spaces = false;

        }

    } while (is_num_bool == 0);

    return user_converted_num;


}

void main_program()
{
     // cout << "great job!\n";
}