#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <cmath>
#include <algorithm>
#define msg(var) cout << #var << " = " << var << endl
using namespace std;

int n = 4, t;
char a[4][4];

bool check(char c)
{
    int tempX = -1, tempY = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == 'T')
            {
                tempX = i, tempY = j;
                a[i][j] = c;
            }

    for (int i = 0; i < n; i++)
    {
        bool row = true, col = true;
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != c)
                row = false;
            if (a[j][i] != c)
                col = false;
        }
        if (row || col) return true;
    }

    if (a[0][0] == c && a[1][1] == c && a[2][2] == c && a[3][3] == c)
        return true;
    if (a[0][3] == c && a[1][2] == c && a[2][1] == c && a[3][0] == c)
        return true;

    if (tempX != -1) a[tempX][tempY] = 'T';
    return false;
}

int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    freopen("ss.in", "r", stdin);
    freopen("ss.out", "w", stdout);

    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        bool unfinished = false;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == '.')
                    unfinished = true;
            }

        if (check('X'))
            printf("Case #%d: X won\n", T);
        else if (check('O'))
            printf("Case #%d: O won\n", T);
        else if (!unfinished)
            printf("Case #%d: Draw\n", T);
        else
            printf("Case #%d: Game has not completed\n", T);
    }

    return 0;
}
