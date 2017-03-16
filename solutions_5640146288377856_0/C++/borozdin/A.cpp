#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

const int N = 20;
const int INF = (int) 1e9;

bool bit(int a, int b)
{
    return (a & (1 << b)) != 0;
}

int n, m, w;
int dp[1 << N][N + 2][N + 2];

bool is_correct(int mask, int l, int r)
{
    l--; r--;
    if (l > r && !(l == m && r == -1))
        return false;
    if (l < m && !bit(mask, l))
        return false;
    if (r >= 0 && !bit(mask, r))
        return false;

    for (int i = 0; i + w <= m; i++)
    {
        if (l <= r && !(i <= l && r < i + w))
            continue;
        bool bad = false;
        bool any = false;
        for (int j = i; j < i + w && !bad; j++)
        {
            if (!(l <= j && j <= r) && bit(mask, j))
                bad = true;
            if (!bit(mask, j))
                any = true;
        }
        if (bad)
            continue;
        if (any)
            return true;
    }

    return false;
}

int solve_row()
{
    for (int mask = (1 << m) - 1; mask >= 0; mask--)
        for (int i = 0; i <= m + 1; i++)
            for (int j = 0; j <= m + 1; j++)
            {
                if (!is_correct(mask, i, j))
                {
                    dp[mask][i][j] = 0;
                    continue;
                }

                int minima = INF;

                for (int p = 0; p < m; p++)
                {
                    if (bit(mask, p))
                        continue;

                    int new_mask = (mask | (1 << p));
                    int cur = max(dp[new_mask][i][j], dp[new_mask][min(i, p + 1)][max(j, p + 1)]) + 1;
                    minima = min(minima, cur);
                }

                dp[mask][i][j] = minima;
            }

    return dp[0][m + 1][0];
}

void solve()
{
    scanf("%d%d%d", &n, &m, &w);

    int ans = solve_row();
    printf("%d\n", ans * n);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        printf("Case #%d: ", i + 1);
        solve();
    }

    eprintf("time = %.3lf\n", (double) clock() / CLOCKS_PER_SEC);

    return 0;
}
