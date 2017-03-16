#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int k = 1; k <= T; k++)
    {
        int X,Y;
        cin >> X >> Y;
        cout << "Case #" << k << ": ";
        if(X>0)
            for(int i = 0; i < X; i++) cout << "WE";
        else if(X<0)
            for(int i = 0; i < -X; i++) cout << "EW";
        if(Y>0)
            for(int i = 0; i < Y; i++) cout << "SN";
        else if(Y<0)
            for(int i = 0; i < -Y; i++) cout << "NS";
        cout << endl;
    }
}
