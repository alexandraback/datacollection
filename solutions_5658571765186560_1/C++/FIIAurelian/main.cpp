#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;

int X, L, C,SOL[30][30][30],T;

int main()
{
    freopen("file.in","r",stdin);
    freopen("file.out","w",stdout);
    cin>>T;
    SOL[6][4][6] = SOL[6][5][6] = SOL[6][6][4] = SOL[6][6][5] = SOL[6][6][6] = SOL[5][3][5] = SOL[5][4][5] = SOL[5][5][3] = SOL[5][5][4] = SOL[5][5][5] = SOL[3][2][3] = SOL[3][3][2] = SOL[3][3][3] = SOL[3][3][4] = SOL[3][4][3] = SOL[4][3][4] = SOL[4][4][3] = SOL[4][4][4] = 1;
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
        if(X < 7 && L > 4 && C > 4 && (L * C) % X == 0)
        {
            cout<<"GABRIEL\n";
            continue;
        }
        if(SOL[X][L][C])
            cout<<"GABRIEL\n";
        else
            cout<<"RICHARD\n";
    }
    return 0;
}
