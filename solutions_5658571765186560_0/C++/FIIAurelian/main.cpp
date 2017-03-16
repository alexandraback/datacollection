#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;

int X, L, C,SOL[10][10][10],T;

int main()
{
    freopen("file.in","r",stdin);
    freopen("file.out","w",stdout);
    cin>>T;
    SOL[3][2][3] = SOL[3][3][2] = SOL[3][3][3] = SOL[3][3][4] = SOL[3][4][3] = SOL[4][3][4] = SOL[4][4][3] = SOL[4][4][4] = 1;
    for(int t = 1; t <= T; t++)
    {
        cout<<"Case #"<<t<<": ";
        cin>>X>>L>>C;
        if(X == 1)
        {
            cout<<"GABRIEL\n";
            continue;
        }
        if(X == 2)
        {
            if((L * C) % 2 == 0)
            {
                cout<<"GABRIEL\n";
            }
            else
            {
                cout<<"RICHARD\n";
            }
            continue;
        }
        if(SOL[X][L][C])
            cout<<"GABRIEL\n";
        else
            cout<<"RICHARD\n";
    }
    return 0;
}
