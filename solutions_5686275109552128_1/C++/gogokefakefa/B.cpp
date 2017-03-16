#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>

int go(int a[], int N, int mx)
{
    int dp[1024];
    memset(dp, 100, sizeof(dp));

    for(int i = 0; i <= mx; ++i)
        dp[i] = 0;
    for (int i = mx + 1; i <= 1000; ++i)
    {
        for(int j = 1; j <= i - j; ++j)
        {
            dp[i] = std::min(dp[i], dp[j] + dp[i - j] + 1);
        }
    }

    int res = 0;

    for(int i = 0; i < N; ++i)
    {
        res += dp[a[i]];
    }

    return res + mx;
}

int solve()
{
    int N;

    scanf("%d", &N);
    int a[1024];

    for (int i = 0; i < N; ++i)
    {
        scanf("%d", a + i);
    }

    int mn = 1e9;

    for(int i = 1; i <= 1000; ++i)
    {
        mn = std::min(mn, go(a, N, i));
    }

    return mn;
}

int main()
{
    int tests;
    scanf ("%d", &tests);

    for(int i = 0; i < tests; ++i)
    {
        printf("Case #%d: %d\n", i + 1, solve());
    }
}
