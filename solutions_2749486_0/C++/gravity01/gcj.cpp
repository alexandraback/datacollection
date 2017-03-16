#include <iostream>
#include <string>
using namespace std;
string s;
int lov= 1;

void go_w(int x) {
    int coun = 0;
   while ( true ){
        if(coun - lov>= x){
            s+= 'W';
            coun-= lov;
            lov++;
        }
        else
            break;
    }
   while ( true ){
        if(coun - 1 >= x)
        {
            s += "EW";
            coun--;
            lov+=2;
        }
        else
            break;
    }
}

void go_e(int x)
{
    int coun = 0;
   while ( true )
    {
        if(coun + lov<= x)
        {
            s += 'E';
            coun+= lov;
            lov++;
        }
        else
            break;
    }
   while ( true )
    {
        if(coun + 1 <= x)
        {
            s += "WE";
            coun++;
            lov+=2;
        }
        else
            break;
    }
}

void go_n(int x)
{
    int coun = 0;
   while ( true )
    {
        if(coun + lov<= x)
        {
            s += 'N';
            coun+= lov;
            lov++;
        }
        else
            break;
    }
   while ( true )
    {
        if(coun + 1 <= x)
        {
            s += "SN";
            coun++;
            lov+=2;
        }
        else
            break;
    }
}

void go_s(int x)
{
    int coun = 0;
   while ( true )
    {
        if(coun - lov>= x)
        {
            s += 'S';
            coun-= lov;
            lov++;
        }
        else
            break;
    }
   while ( true )
    {
        if(coun - 1 >= x)
        {
            s += "NS";
            coun--;
            lov+=2;
        }
        else
            break;
    }
}


int main()
{
    int tc, x;
    int y;
    cin >> tc;
    int co = 0;
    while(tc--) {
        lov= 1;
        s.clear();
        cin >> x >> y;
        if(x < 0)go_w(x);
        else go_e(x);
        if(y < 0)
            go_s(y);
        else
            go_n(y);
        cout << "Case #" << ++co << ": " << s << endl;
    }
}






















