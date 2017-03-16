// License {{{
// <=================================================================>
//
//             DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
//                     Version 2, December 2004
//
//  Copyright (C) 2004 Sam Hocevar <sam@hocevar.net>
//
//  Everyone is permitted to copy and distribute verbatim or modified
//  copies of this license document, and changing it is allowed as long
//  as the name is changed.
//
//             DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
//    TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
//
//   0. You just DO WHAT THE FUCK YOU WANT TO.
//
// <=================================================================>
// }}}

#include <bits/stdc++.h>
using namespace std;

#ifdef moskupols
    #define debug(...) fprintf(stderr, __VA_ARGS__) // thank Skird it's friday!
#else
    #define debug(...) 42
#endif

#define timestamp(x) debug("["#x"]: %.3f\n", (double)clock() / CLOCKS_PER_SEC) // thank PavelKunyavskiy i am not pregnant!

#define hot(x) (x)
#define sweet(value) (value)
#define lovelyCute(nine) 9

#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).begin(),(v).end()
#define UNIQ(v) (v).erase(unique(ALL(v)),(v).end())

typedef long long int64;
typedef unsigned long long uint64;
typedef long double kingsized;

const int maxr = 22;

const int da[4] = {-1, 0, 1, 0};
const int db[4] = {0, 1, 0, -1};

int x, r, c;

bool grid[maxr][maxr];

bool isok(int a, int b)
{
    return a>=0 && b>=0 && a<r && b<c;
}

int fill(int a, int b, int mask)
{
    for (int i = 0; i < x; ++i)
    {
        if (!isok(a, b))
            return 0;
        if (grid[a][b])
            return -1;
        grid[a][b] = true;

        int m = mask % 4;
        mask /= 4;

        a += da[m];
        b += db[m];
    }
    return 1;
}

int dfs(int a, int b)
{
    int ret = 1;
    grid[a][b] = true;
    for (int k = 0; k < 4; ++k)
    {
        int na = a + da[k], nb = b + db[k];
        if (isok(na, nb) && !grid[na][nb])
            ret += dfs(na, nb);
    }
    return ret;
}

int tryfit(int mask, bool rot)
{
    if (rot)
        swap(r, c);
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
        {
            memset(grid, 0, sizeof grid);

            int f = fill(i, j, mask);
            if (!f)
                continue;
            if (f == -1)
                return -1;

            bool ok = true;
            for (int a = 0; ok && a < r; ++a)
                for (int b = 0; ok && b < c; ++b)
                    if (!grid[a][b] && dfs(a, b) % x)
                        ok = false;
            if (ok)
            {
                if (rot)
                    swap(r, c);
                return 1;
            }
        }
    if (rot)
        swap(r, c);
    return 0;
}

void solve()
{
    cin >> x >> r >> c;

    if (x >= 7)
    {
        cout << "RICHARD\n";
        return;
    }

    int p = 1;
    for (int i = 0; i + 1 < x; ++i)
        p *= 4;

    for (int i = 0; i < p; ++i)
    {
        int a = tryfit(i, false), b = tryfit(i, true);
        if (a == -1 || b == -1)
            continue;
        if (a  == 0 && b == 0)
        {
            cout << "RICHARD\n";
            return;
        }
    }
    cout << "GABRIEL\n";
}

int main()
{
    cin.sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solve();
        debug("%d ", i);
        timestamp(multi);
    }

    timestamp(end);
    return 0;
}

