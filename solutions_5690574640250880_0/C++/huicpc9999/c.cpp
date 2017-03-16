#include <iostream>
#include <cstdio>
using namespace std;


char mp[100][100];

bool recurse(int r, int c, int m)
{
    if (m == 0) return true;
    if (r == 2 && c == 2) return false;

    if (r >= c)
    {
        if (m >= c || m <= c-2)
        {
            for (int j = c - 1; j >= 0 && m > 0; --j, --m)
                mp[r-1][j] = '*';
        }
        else
        {
            for (int j = c - 1; j >= 2 && m > 0; --j, --m)
                mp[r-1][j] = '*';
        }
        return recurse(r-1, c, m);
    }
    else
    {
        if (m >= r || m <= r-2)
        {
            for (int i = r - 1; i >= 0 && m > 0; --i, --m)
                mp[i][c-1] = '*';
        }
        else
        {
            for (int i = r - 1; i >= 2 && m > 0; --i, --m)
                mp[i][c-1] = '*';
        }
        return recurse(r, c-1, m);
    }
}

bool solve(int r, int c, int m)
{
    // only one blank
    if (m + 1 == r * c)
    {
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                mp[i][j] = '*';
        mp[0][0] = 'c';
        return true;
    }
    // one row
    if (r == 1)
    {
        mp[0][0] = 'c';
        for (int j = 1; j < c; ++j)
        {
            if (j < c - m) mp[0][j] = '.';
            else mp[0][j] = '*';
        }
        return true;
    }
    // one col
    if (c == 1)
    {
        mp[0][0] = 'c';
        for (int i = 1; i < r; ++i)
        {
            if (i < r - m) mp[i][0] = '.';
            else mp[i][0] = '*';
        }
        return true;
    }
    // general
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            mp[i][j] = '.';
    mp[0][0] = 'c';
    return recurse(r, c, m);
}

int main()
{
    //freopen("C-small-attempt0.in", "r", stdin);
    //freopen("C.out", "w", stdout);
    int T; scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        int r, c, m;
        scanf("%d %d %d", &r, &c, &m);
        printf("Case #%d:\n", cas);
        if (solve(r, c, m))
        {
            for (int i = 0; i < r; ++i)
            {
                for (int j = 0; j < c; ++j)
                    printf("%c", mp[i][j]);
                printf("\n");
            }
        }
        else
        {
            puts("Impossible");
        }
    }

    return 0;
}
