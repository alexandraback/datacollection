/*
 * File:     main.cpp
 * Author:   Hrayr [HarHro94]
 * Problem:  
 * IDE:      Visual C++ 2008
 */
//#pragma comment(linker, "/STACK:66777216")
#include <functional>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <string>
#include <Vector>
#include <ctime>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define LL long long
#define LD long double

char st[7][7];

string solve()
{
    int i, j;
    bool free=false;
    for(i=0;i<4;++i)
    {
        for(j=0;j<4;++j)
        {
            if (st[i][j]=='.')
            {
                free=true;
            }
        }
    }
    // rows
    for(i=0;i<4;++i)
    {
        int T=0, X=0, O=0;
        for(j=0;j<4;++j)
        {
            if (st[i][j]=='X')
            {
                X++;
            }
            if (st[i][j]=='O')
            {
                O++;
            }
            if (st[i][j]=='T')
            {
                T++;
            }
        }
        if (T+O==4)
        {
            return "O won";
        }
        if (T+X==4)
        {
            return "X won";
        }
    }
    // coloumns
    for(j=0;j<4;++j)
    {
        int T=0, X=0, O=0;
        for(i=0;i<4;++i)
        {
            if (st[i][j]=='X')
            {
                X++;
            }
            if (st[i][j]=='O')
            {
                O++;
            }
            if (st[i][j]=='T')
            {
                T++;
            }
        }
        if (T+O==4)
        {
            return "O won";
        }
        if (T+X==4)
        {
            return "X won";
        }
    }
    // main diagonal
    int X=0, T=0, O=0;
    for(i=0;i<4;++i)
    {
        if (st[i][i]=='X')
        {
            X++;
        }
        if (st[i][i]=='O')
        {
            O++;
        }
        if (st[i][i]=='T')
        {
            T++;
        }
    }
    if (T+O==4)
    {
        return "O won";
    }
    if (T+X==4)
    {
        return "X won";
    }
    // second diagonal
    X=O=T=0;
    for(i=0;i<4;++i)
    {
        if (st[i][3-i]=='X')
        {
            X++;
        }
        if (st[i][3-i]=='O')
        {
            O++;
        }
        if (st[i][3-i]=='T')
        {
            T++;
        }
    }
    if (T+O==4)
    {
        return "O won";
    }
    if (T+X==4)
    {
        return "X won";
    }
    return free? "Game has not completed":"Draw";
}

int main()
{
#ifdef harhro94
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int i, j, test, testCnt;
    cin >> testCnt;
    for(test=1;test<=testCnt;++test)
    {
        for(i=0;i<4;++i)
        {
            for(j=0;j<4;++j)
            {
                cin >> st[i][j];
            }
        }
        cout << "Case #" << test << ": " << solve() << endl;
    }

#ifdef harhro94
	cerr << fixed << setprecision(3) << "\nExecution time = " << clock()/1000.0 << "s\n";
#endif
	return 0;
}
