#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)

int T;
int N;

int dp[1000005];

int reverse(int x)
{
    int res = 0;
    while (x)
    {
        res = res * 10 + x%10;
        x /= 10;
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    REP(tc, T)
    {
        scanf("%d", &N);

        dp[N] = 0;

        for (int i = N-1; i >= 0; i--)
        {
            dp[i] = 1 + dp[i+1];

            int rev = reverse(i);
            if (rev > i && rev <= N)
                dp[i] = min(dp[i], 1 + dp[rev]);
        }

        printf("Case #%d: %d\n", tc+1, dp[0]);
    }
}
