#include <bits/stdc++.h>

using namespace std;

int t, r, c, w;
int dp[21], dp1[21];

int main()
{
    freopen("aaa.in","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> t;
    for (int j = 0; j < t; ++j)
    {
        cin >> r >> c >> w;
        memset(dp, 0, sizeof(dp));
        memset(dp1, 0, sizeof(dp1));
        dp[w] = w;
        dp1[w] = 1;
        for (int i = w + 1; i <= c; ++i)
        {
            dp[i] = dp[i - 1] + 1;
            dp1[i] = dp1[i - 1] + 1;
            for (int i1 = 1; i1 < i; ++i1)
            {
                dp1[i] = min(dp1[i], dp1[i1 - 1] + dp1[i - i1] + 1);
                if (i1 - 1 < w && i - i1 < w)
                    dp[i] = min(dp[i], w + 1);
                else
                {
                    int rez = w + 1;
                    rez = max(rez, dp1[i1 - 1] + dp[i - i1] + 1);
                    rez = max(rez, dp[i1 - 1] + dp1[i - i1] + 1);
                    dp[i] = min(dp[i], rez);
                }
            }
        }
        int rez = dp[c] + dp1[c] * (r - 1);
        cout << "Case #" << j + 1 << ": " << rez << '\n';
    }
    return 0;
}
