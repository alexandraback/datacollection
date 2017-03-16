#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

long long an[100], at[100], bn[100], bt[100];
long long dp[100][100];

long long solve(int n, int m)
{
    long long res = dp[n][m];
    if (n == 0 || m == 0) return 0;
    if (res > 0) return res;
    if (at[n - 1] == bt[m - 1])
    {
        long long sum1 = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            if (at[i] != at[n - 1]) continue;
            sum1 += an[i];
            long long sum2 = 0;
            for (int j = m - 1; j >= 0; --j) {
                if (bt[j] != bt[m - 1]) continue;
                sum2 += bn[j];
                res = max(res, min(sum1, sum2) + solve(i, j));
            }
        }
    }
    else
    {
        res = max(res, solve(n - 1, m));
        res = max(res, solve(n, m - 1));
    }
    return res;
}

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int no = 1; no <= t; no++)
    {
        int n, m;
        cin>>n>>m;
        for (int i = 0; i < n; i++)
        {
            cin>>an[i]>>at[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin>>bn[i]>>bt[i];
        }
        memset(dp, -1, sizeof(dp));
        long long res = solve(n, m);
        printf("Case #%d: %lld\n", no, res);
    }
}
