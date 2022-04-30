#include <iostream>
#include <fstream>
using namespace std;

#define el '\n'
#define ll long long





ll last_F = 0, last_P = 0;
struct sys_data_flight
{
    int Flight_Number, NO_ava_seats;
    string Flight_Date;
    string DEP_city, DEP_time, ARIV_city, ARIV_time;
};

sys_data_flight flights[10] = {};


struct sys_data_passenger
{
    ll pass_ID;
    string F_name, Mid_name, last_name, phone_NO, Address, Res_date;
};


sys_data_passenger passengers[10] = {};

struct Ticket
{
    ll TIC_NO;
    int ps_id, flight_no;
    string Res_date;
};

void ADD_FLIGHT(int f_no, int ava_no, string f_date, string de_city, string de_time, string arrival_city, string arrival_time);
void DELET_FLIGHT(int f_no);
void DISPLAY_FLIGHT_Search_For_AVF();

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Add_NEW_RES(int P_ID, string f_neme, string mid_name, string last_name, string address, string Phone_no,string Res_date );
void DELET_RES(int P_ID);
void DISPLAY_RES(int P_ID);
int main()
{
    flights[1].Flight_Number = 1;
    flights[1].NO_ava_seats = 80;
    flights[1].Flight_Date = "12/03/2021";
    flights[1].DEP_city = "Cairo";
    flights[1].DEP_time = "08:15";
    flights[1].ARIV_city = "Maldives";
    flights[1].ARIV_time = "11:11";
  
    flights[2].Flight_Number = 2;
    flights[2].NO_ava_seats = 65;
    flights[2].Flight_Date = "10/06/2021";
    flights[2].DEP_city = "Dubai";
    flights[2].DEP_time = "06:20";
    flights[2].ARIV_city = "Kuala Lumpur";
    flights[2].ARIV_time = "12:45";

    flights[3].Flight_Number = 3;
    flights[3].NO_ava_seats = 47;
    flights[3].Flight_Date = "12/07/2021";
    flights[3].DEP_city = "Los Angeles";
    flights[3].DEP_time = "10:00";
    flights[3].ARIV_city = "Moscow";
    flights[3].ARIV_time = "13:50";

    flights[4].Flight_Number = 4;
    flights[4].NO_ava_seats = 99;
    flights[4].Flight_Date = "20/08/2021";
    flights[4].DEP_city = "Berlin";
    flights[4].DEP_time = "05:00";
    flights[4].ARIV_city = "stockholm";
    flights[4].ARIV_time = "06:15";
    last_F = 4;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    passengers[1].pass_ID = 1;
    passengers[1].F_name = "Maged";
    passengers[1].Mid_name = "Mohamed";
    passengers[1].last_name = "Ibrahem";
    passengers[1].Address = "12.Nasercity/Cairo/Egypt";
    passengers[1].phone_NO = "01225267868";
    passengers[1].Res_date = "24/6/2023";
    
    passengers[2].pass_ID = 2;
    passengers[2].F_name = "Ali";
    passengers[2].Mid_name = "Mohamed";
    passengers[2].last_name = "Ali";
    passengers[2].Address = "16.G7/MadintyNewCairo/Egypt";
    passengers[2].phone_NO = "01159358304";
    passengers[2].Res_date = "19/12/2021";


    passengers[3].pass_ID = 3;
    passengers[3].F_name = "Ahmed";
    passengers[3].Mid_name = "Deiaa";
    passengers[3].last_name = "Mosalam";
    passengers[3].Address = "17.Zagazig.st/Egypt";
    passengers[3].phone_NO = "01225267868";
    passengers[3].Res_date = "12/03/2021";
    last_P = 3;


    while (true)
    {
         string PASSWORD = "password",USERNAME;
        system("cls");
        cout << " Select Your Option   \n\n   1.Register As Admin. \n\n   2.Register As Client. \n\n ";
        int key=0 ; cin >> key;
        
         if (key==1 || key==2)
        {

            system("cls");
            if (key == 1) {
                 USERNAME = "Admin";
            }
            else if (key == 2) {
                 USERNAME = "Clint";
            }
            
            
            string username, password;
            bool user_validated = false;


            do
            {

                cout << "\n\n Insert USER NAME : ";
                cin >> username;
                
                if (username.length() < 4)
                {
                    system("cls");
                    cout << "\n Username length must be atleast 4 characters long.";
                }
                else
                {
                    cout << "\n Insert  password : ";
                    cin >> password;

                    if (password.length() < 6)
                    {
                        system("cls");
                        cout << "\n Password length must be atleast 6 characters long." << endl;
                    }
                    else
                    {

                        if (username == USERNAME && password == PASSWORD)

                        {
                            system("cls");
                            cout << "\n User credentials are correct, Granting access.....\n" << endl;
                            user_validated = 1;
                        }
                        else
                        {
                            system("cls");
                            cout << "\n Invalid Password OR User Name, Please Make Sure of Your Data....\n " << endl;
                        }
                    }
                }
            } while (user_validated == 0);
        }

         


        if (key == 1)
        {


            bool  KE = 1;
            while (KE)
            {
                system("cls");
                cout << " Select Your Option   \n\n   1.Add NEW Flight Schedule. \n\n   2.Update Existing flight schedule. \n\n   3.Delete Existing flight schedule. \n\n   4.press '0' to Sign Out. \n\n";
                int z; cin >> z;
                if (z == 1)
                {
                    int x, y;
                    string a, b, c, d, e;
                    system("cls");
                    cout << " Inter Flight Number : "; cin >> x;
                    cout << " \n Inter The Number of Available seats: "; cin >> y;
                    cout << " \n Inter Flight date : dd/mm/yyy : "; cin >> a;
                    cout << " \n Inter Departure City : ";         cin >> b;
                    cout << " \n Inter Departure Time : hh:mm... "; cin >> c;
                    cout << " \n Inter Arrival City : ";          cin >> d;
                    cout << " \n Inter Arrival Time : hh:mm... ";  cin >> e;
                    ADD_FLIGHT(x, y, a, b, c, d, e);
                    last_F = x;
                    cout << "\n\n\n Successful Operation Thank you....";
                    cout << "\n\n Press 1 to Menu : ";
                    char s; cin >> s;
                }

                else if (z == 2)
                {
                    int x, y;
                    string a, b, c, d, e;
                    system("cls");
                    cout << " Inter Flight Number : "; cin >> x;
                    system("cls");
                    cout << " Inter The New info.....\n ";
                    cout << " \n Inter The Number of Available seats: "; cin >> y;
                    cout << " \n Inter Flight date : dd/mm/yyy : "; cin >> a;
                    cout << " \n Inter Departure City : ";         cin >> b;
                    cout << " \n Inter Departure Time : hh:mm... "; cin >> c;
                    cout << " \n Inter Arrival City : ";          cin >> d;
                    cout << " \n Inter Arrival Time : hh:mm... ";  cin >> e;
                    ADD_FLIGHT(x, y, a, b, c, d, e);
                    
                    cout << "\n\n\n Your Flight Updated, Thank you....";
                    cout << "\n\n Press 1 to  Menu : ";
                    char s; cin >> s;
                   

                }

                else if (z == 3)
                {
                    system("cls");
                   
                    cout << "Inter Flight Number";
                    int r; cin >> r;
                    DELET_FLIGHT(r);
                    cout << "\n\n\n Your Flight Deleted, Thank you....";
                    cout << "\n\n Press 1 to  Menu : ";
                    char s; cin >> s;
                }
                else
                {
                    KE = 0;
                }

            }
        }
        else if(key==2)
        {
            bool  k = 1;
            do
            {

                system("cls");
                cout << " \n\n\  1.Search Available Flights.\n\n  2.Add new reservation.\n\n  3.Cancel reservation.\n\n  4.Modify reservation log.\n\n  5.Show reservation log.\n\n  6. Sign Out.\n\n";
                int y; cin >> y;

                if (y == 1)
                {
                    system("cls");
                    DISPLAY_FLIGHT_Search_For_AVF();
                    cout << "\n\n Press 1 to Menu : ";
                    char s; cin >> s;
                }
                if (y == 2)
                {
                    int x; string a, b, c, d, e, f;
                    system("cls");
                    cout << " Your ID is :: " << last_P + 1 << el;
                    cout << " Inter Passenger ID : ";
                    cin >> x;
                    system("cls");
                    cout << " \n Passenger's First name : ";  cin >> a;
                    cout << " \n Second name : ";  cin >> b;
                    cout << " \n Last name  : ";  cin >> c;
                    cout << " \n Address : "; cin >> d;
                    cout << " \n Phone Number : "; cin >> e;
                    cout << " \n Reservation Date : dd/mm/yyy :"; cin >> f;
                    Add_NEW_RES(x, a, b, c, d, e, f);
                    cout << "\n\n\n Successful Operation Thank you....";
                    cout << "\n\n Press 1 to Menu: ";
                    char s; cin >> s;
                }
                if (y == 3)
                {
                    system("cls");
                    cout << " Inter Passenger ID : ";
                    int x; cin >> x;
                    DELET_RES(x);
                    cout << "\n\n\n Your Reservation Canceled, Thank you....";
                    cout << "\n\n Press 1 to  Menu : ";
                    char s; cin >> s;

                }

                if (y == 4)
                {
                    int x; string a, b, c, d, e, f;
                    system("cls");
                    cout << " Inter Passenger ID : "; cin >> x;

                    system("cls");
                    cout << " Inter The New info.....\n ";
                    cout << " \n Passenger's First name : ";  cin >> a;
                    cout << " \n Second name : ";  cin >> b;
                    cout << " \n Last name  : ";  cin >> c;
                    cout << " \n Address : "; cin >> d;
                    cout << " \n Phone Number : "; cin >> e;
                    cout << " \n Reservation Date : dd/mm/yyy :"; cin >> f;
                    Add_NEW_RES(x, a, b, c, d, e, f);
                    cout << "\n\n\n Your Reservation  Updated, Thank you....";
                    cout << "\n\n Press 1 to  Menu : ";
                    char s; cin >> s;
                }

                if (y == 5)
                {
                    system("cls");
                    cout << " Inter Passenger ID : ";
                    int x; cin >> x;
                    DISPLAY_RES(x);
                    cout << "\n\  ___________________________________________" << el;
                    cout << "\n\n\n Press 1 to  Menu : ";
                    char s; cin >> s;

                }
                if(y==6)
                {
                    k = 0;
                }
                

            } while (k!=0);
        }
        else
        {
            return main();
        }
    }
  

    return 0;
}
void ADD_FLIGHT(int f_no, int ava_no, string f_date, string de_city, string de_time, string arrival_city, string arrival_time)
{



    flights[f_no].NO_ava_seats = ava_no;
    flights[f_no].Flight_Date = f_date;

    flights[f_no].DEP_city = de_city;
    flights[f_no].DEP_time = de_time;

    flights[f_no].ARIV_city = arrival_city;
    flights[f_no].ARIV_time = arrival_time;



}

void DELET_FLIGHT(int f_no)
{
    flights[f_no].NO_ava_seats = 0;
    flights[f_no].Flight_Date = '\0';

    flights[f_no].DEP_city = '\0';
    flights[f_no].DEP_time = '\0';

    flights[f_no].ARIV_city = '\0';
    flights[f_no].ARIV_time = '\0';
}

void DISPLAY_FLIGHT_Search_For_AVF()
{
    for (int i = 1; i <= last_F; i++)
    {

        if (flights[i].NO_ava_seats)
        {
            cout << " \n Flight Number : "; cout << i << el;
            cout << " Available seats : "; cout << flights[i].NO_ava_seats <<el;
            cout << " Flight Date : ";     cout << flights[i].Flight_Date << el<<el;

            cout << " Departure City  : ";  cout << flights[i].DEP_city << el;
            cout << " Departure time  : ";  cout << flights[i].DEP_time << el << el;

            cout << " Arrival City  : "; cout << flights[i].ARIV_city << el;
            cout << " Arrival time : "; cout << flights[i].ARIV_time << el;
            cout << "\n\  ___________________________________________" << el;
        }



    }
}


void Add_NEW_RES(int P_ID, string f_neme, string mid_name,string last_name, string address, string Phone_no,string res_date)
{
    passengers[P_ID].F_name = f_neme;
    passengers[P_ID].Mid_name = mid_name;
    passengers[P_ID].last_name = last_name;
    passengers[P_ID].Address = address;
    passengers[P_ID].phone_NO = Phone_no;
    passengers[P_ID].Res_date = res_date;
  
        
}
void DELET_RES(int P_ID)
{
    passengers[P_ID] .F_name="INVALED";
    passengers[P_ID].Mid_name = '\0';
    passengers[P_ID].last_name = '\0';
    passengers[P_ID].Address = '\0';
    passengers[P_ID].phone_NO = '\0';
    passengers[P_ID].Res_date = '\0';
}

void DISPLAY_RES(int P_ID)
{
    

    if (passengers[P_ID].F_name  != "INVALED" && passengers[P_ID].F_name !="")
    {
        system("cls");
        cout << " Passenger's INFO.......";
        cout<<"\n\n\n Name : " << passengers[P_ID].F_name <<" "<< passengers[P_ID].Mid_name<<" "<< passengers[P_ID].last_name << el;
       
      
        cout <<" \n Address : "<< passengers[P_ID].Address << el;

        cout <<" \n Phone Number : "<< passengers[P_ID].phone_NO << el;
        cout <<" \n Reservation date : "<< passengers[P_ID].Res_date << el;
        cout << "\n\  ___________________________________________" << el;
    }
    else
    {
        cout << " \n INVALED ID....";
    }
}
/*
1
80
27/5/2021
Cairo
12:05
MALIZIA
08:59

2
69
27/5/2021
Cairo
12:05
USE
13:07

1
Zeyad
Yasser
Farg
12.Nasercity\Cairo\Egypt
01225267868
24/6/2023
*/