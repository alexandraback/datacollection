#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;


int check(char c[5][5])
{
    int i,j;
    int cntx = 0,cnto = 0,cntt = 0;

    for(i = 0;i < 4;i++)
    {
        cntx = 0;cnto = 0;cntt = 0;
        for(j = 0;j < 4;j++)
        {
            if(c[i][j] == 'X') cntx++;
            else if(c[i][j] == 'T') cntt++;
            else if(c[i][j] == 'O') cnto++;
        }
        if((cntt == 1 && cntx == 3) || (cntx == 4)) return 1;
        if((cntt == 1 && cnto == 3) || (cnto == 4)) return 2;
    }

    for(j = 0;j <4;j++)
    {
        cntx = 0;cnto = 0;cntt = 0;
        for(i = 0;i < 4;i++)
        {
            if(c[i][j] == 'X') cntx++;
            else if(c[i][j] == 'T') cntt++;
            else if(c[i][j] == 'O') cnto++;
        }
        if((cntt == 1 && cntx == 3) || (cntx == 4)) return 1;
        if((cntt == 1 && cnto == 3) || (cnto == 4)) return 2;
    }

    cntx = 0;cnto = 0;cntt = 0;
    for(j = 0;j <4;j++)
    {
        if(c[j][j] == 'X') cntx++;
        else if(c[j][j] == 'T') cntt++;
        else if(c[j][j] == 'O') cnto++;
    }
    if((cntt == 1 && cntx == 3) || (cntx == 4)) return 1;
    if((cntt == 1 && cnto == 3) || (cnto == 4)) return 2;

    cntx = 0;cnto = 0;cntt = 0;
    for(j = 0;j <4;j++)
    {
        if(c[j][3 - j] == 'X') cntx++;
        else if(c[j][3 - j] == 'T') cntt++;
        else if(c[j][3 - j] == 'O') cnto++;
    }

    if((cntt == 1 && cntx == 3) || (cntx == 4)) return 1;
    if((cntt == 1 && cnto == 3) || (cnto == 4)) return 2;

    for(i = 0;i < 4;i++)
    {
        for(j = 0;j < 4;j++)
        {
            if(c[i][j] == '.')
                return 3;
        }
    }

    return 0;
}

int main()
{
    int ca,cn,i;
    char t[5][5];

    freopen("AS.in","r",stdin);
    freopen("AS.out","w",stdout);

    cin >> cn;

    for(ca = 1;ca <= cn;ca++)
    {
        cout <<"Case #"<< ca <<": ";
        for(i = 0;i < 4;i++)
        {
            cin >> t[i];
        }

        int res = check(t);
        if(res == 1)
            cout << "X won" << endl;
        else if(res == 2)
            cout << "O won" << endl;
        else if(res == 3)
            cout << "Game has not completed" << endl;
        else
            cout << "Draw" << endl;
    }
    return 0;
}
