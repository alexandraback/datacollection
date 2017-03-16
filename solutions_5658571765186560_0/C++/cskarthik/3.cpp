#include <iostream>
using namespace std;
int main()
{
    int T, n;
    cin >> T;
    for(int i = 1; i<=T; i++)
    {
        int X, R, C, min, max;
        cin >> X >> R >> C;
        if(R < C) min = R;
        else min = C;
        if(R > C) max = R;
        else max = C;
        int flag = 1;
        if(X >= 7) flag = 0;
        else if(X>R && X>C) flag = 0;
        else if(R*C % X != 0 ) flag = 0;
        else if((X+1)/2 > min) flag = 0;
        else if(X == 1 || X==2 || X==3) flag = 1;
        else if(X == 4)
        {
            if(min > 2) flag = 1;
            else flag = 0;
        }
        else if(X == 5)
        {
            if(!(min == 3 && max == 5)) flag = 1;
            else flag = 0;
        }
        else if(X == 6)
        {
            if(min > 3) flag = 1;
            else flag = 0;
        }
        if(flag == 0)
            cout << "Case #" << i << ": " << "RICHARD" << endl; 
        else
            cout << "Case #" << i << ": " << "GABRIEL" << endl; 
    }
    return 0;
}