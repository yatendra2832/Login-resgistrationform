#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;

void login();
void Registration();
void forgot();

int main()
{

    int c; // c is for choice

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    cout << "                        Welcome To Login Page               \n\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "                               MENU                                           \n";
    cout << "___________________________________________________________________________" << endl;
    cout << "| Press 1 to Login                                                        |" << endl;
    cout << "| Press 2 to Register                                                     |" << endl;
    cout << "| Press 3 to Forgot Password?                                             |" << endl;
    cout << "| Press 4 to Exit                                                         |" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "Please Enter Your Choice: ";
    cin >> c;
    cout << endl;
    // for selecting option we will use the switch case statement

    switch (c)
    {
    case 1:
        login();
        break;
    case 2:
        Registration();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout << "\t\t\t Thank You!\n\n";
        break;
    default:
        system("cls");
        cout << "\t\t\t Please select from the option given above \n"
             << endl;
        main();
    }

    return 0;
}
void login()
{
    int count;
    string userId, password, id, pass;
    system("CLS");
    cout << "\t\t\tPlease Enter the Username and Password: " << endl;
    cout << "\t\t\t USERNAME ";
    cin >> userId;
    cout << "\t\t\t PASSWORD";
    cin >> password;

    ifstream input("records.txt");
    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();
    if (count == 1)
    {
        cout << userId << "\n Your LOGIN is successfull \n Thanks for logging in !\n";
        main();
    }
    else
    {
        cout << "\n LOGIN ERROR\n Please check your username and password";
    }
}

void Registration()
{
    string ruserId, rpassword, rid, rpass;
    system("cls");
    cout << "\t\t\t Enter the Username : ";
    cin >> ruserId;
    cout << "\t\t\t Enter the password : ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    f1 << ruserId << ' ' << rpassword << endl;
    system("cls");
    cout << "\n\t\t Registration is successful!\n";
    main();
}

void forgot()
{
    int option;
    system("cls");
    cout << "\t\t\t You forgot the password? No Worry \n";
    cout << "Press 1 to search your id by username" << endl;
    cout << "Press 2 to go back to the main menu" << endl;
    cout << "\t\t\t Enter your choice : ";
    cin >> option;
    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suserId, sId, spass;
        cout << "\n\t\t Enter th username which you remembered : ";
        cin >> suserId;

        ifstream f2("records.txt");
        while (f2>>sId>>spass)
        {
            if (sId == suserId)
            {
                count = 1;
            }
        }
        f2.close();
        if (count == 1)
        {
            cout << "\n\n Your Account is Found! \n";
            cout << "\n\n Your Password is : " << spass<<endl;
            main();
        }
        else
        {
            cout << "\nsorry your account is not found\n";
            main();
        }
        break;
    }

    case 2:{
        main();
    }
    default:
    cout<<"\t\t\t Wrong choice ! Please Try Again"<<endl;
    forgot();
    }
}
