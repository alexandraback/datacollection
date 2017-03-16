#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

long long dp[101];
int a[101][101];

void solve()
{
    long long n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = 0;

    dp[0] = 1;
    for (int i = 1; i < n - 1; i++)
    {
        dp[i] = 1;
        if (i > 1)
            dp[i] = dp[i - 1] * 2;
        for (int j = 0; j < i; j++)
            a[j][i] = 1;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (dp[i] <= k)
        {
            k -= dp[i];
            a[i][n - 1] = 1;
        }
    }

    if (k != 0) printf("IMPOSSIBLE\n");
    else
    {
        printf("POSSIBLE\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%d", a[i][j]);
            printf("\n");
        }
    }
}

int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.txt", "w", stdout);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        printf("Case #%d: ", i + 1);
        solve();
    }
}
