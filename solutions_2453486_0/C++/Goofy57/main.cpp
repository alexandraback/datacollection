#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

char a[10][10];
int t;

bool win(char c)
{
    for (int i = 0; i < 4; i++)
    {
        bool ok = 1;
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j] != c && a[i][j] != 'T') ok = 0;
        }
        if (ok) return 1;
    }

    for (int j = 0; j < 4; j++)
    {
        bool ok = 1;
        for (int i = 0; i < 4; i++)
        {
            if (a[i][j] != c && a[i][j] != 'T') ok = 0;
        }
        if (ok) return 1;
    }

    bool ok = 1;
    for (int i = 0; i < 4; i++)
    {
        if (a[i][i] != c && a[i][i] != 'T') ok = 0;
    }
    if (ok) return 1;

    ok = 1;
    for (int i = 0; i < 4; i++)
    {
        if (a[i][3 - i] != c && a[i][3 - i] != 'T') ok = 0;
    }
    if (ok) return 1;

    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++)
    {
        int num = 0;
        for (int i = 0; i < 4; i++)
        {
            scanf("%s", a[i]);
            for (int j = 0; j < 4; j++)
            {
                if (a[i][j] != '.') num++;
            }
        }

        bool winx = win('X');
        bool winy = win('O');

        char * s;
        if (winx && !winy)
        {
            s = "X won";
        }
        else
        if (winy && !winx)
        {
            s = "O won";
        }
        else
        if (num == 16)
        {
            s = "Draw";
        }
        else
        {
            s = "Game has not completed";
        }

        printf("Case #%d: %s\n", tc, s);
    }

    return 0;
}
