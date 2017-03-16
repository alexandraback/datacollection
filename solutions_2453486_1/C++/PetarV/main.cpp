/*
 Petar 'PetarV' Velickovic
 Task: Tic-Tac-Toe-Tomek
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
using namespace std;
typedef long long lld;

int t, f;
int win;
char mat[10][10];

inline void printWin()
{
    printf("Case #%d: ",f);
    if (win == 0) printf("Draw\n");
    else if (win == 1) printf("X won\n");
    else if (win == 2) printf("O won\n");
    else if (win == -1) printf("Game has not completed\n");
}

int main()
{
    freopen("/Users/PetarV/A-large.in.txt","r",stdin);
    freopen("/Users/PetarV/A-large-out.txt","w",stdout);
    cin >> t;
    for (f=1;f<=t;f++)
    {
        for (int i=0;i<4;i++)
        {
            scanf("%s",&mat[i]);
        }
        for (int i=0;i<4;i++)
        {
            win = 1;
            for (int j=0;j<4;j++)
            {
                if (mat[i][j] != 'X' && mat[i][j] != 'T')
                {
                    win = 0;
                    break;
                }
            }
            if (win != 0) break;
        }
        if (win != 0)
        {
            printWin();
            continue;
        }
        for (int j=0;j<4;j++)
        {
            win = 1;
            for (int i=0;i<4;i++)
            {
                if (mat[i][j] != 'X' && mat[i][j] != 'T')
                {
                    win = 0;
                    break;
                }
            }
            if (win != 0) break;
        }
        if (win != 0)
        {
            printWin();
            continue;
        }
        win = 1;
        for (int i=0;i<4;i++)
        {
            if (mat[i][i] != 'X' && mat[i][i] != 'T')
            {
                win = 0;
                break;
            }
        }
        if (win != 0)
        {
            printWin();
            continue;
        }
        win = 1;
        for (int i=0;i<4;i++)
        {
            if (mat[i][4-i-1] != 'X' && mat[i][4-i-1] != 'T')
            {
                win = 0;
                break;
            }
        }
        if (win != 0)
        {
            printWin();
            continue;
        }
        for (int i=0;i<4;i++)
        {
            win = 2;
            for (int j=0;j<4;j++)
            {
                if (mat[i][j] != 'O' && mat[i][j] != 'T')
                {
                    win = 0;
                    break;
                }
            }
            if (win != 0) break;
        }
        if (win != 0)
        {
            printWin();
            continue;
        }
        for (int j=0;j<4;j++)
        {
            win = 2;
            for (int i=0;i<4;i++)
            {
                if (mat[i][j] != 'O' && mat[i][j] != 'T')
                {
                    win = 0;
                    break;
                }
            }
            if (win != 0) break;
        }
        if (win != 0)
        {
            printWin();
            continue;
        }
        win = 2;
        for (int i=0;i<4;i++)
        {
            if (mat[i][i] != 'O' && mat[i][i] != 'T')
            {
                win = 0;
                break;
            }
        }
        if (win != 0)
        {
            printWin();
            continue;
        }
        win = 2;
        for (int i=0;i<4;i++)
        {
            if (mat[i][4-i-1] != 'O' && mat[i][4-i-1] != 'T')
            {
                win = 0;
                break;
            }
        }
        if (win != 0)
        {
            printWin();
            continue;
        }
        for (int i=0;i<4;i++)
        {
            for (int j=0;j<4;j++)
            {
                if (mat[i][j] == '.') win = -1;
            }
        }
        printWin();
    }
    return 0;
}