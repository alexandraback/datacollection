# include <bits/stdc++.h>
using namespace std;
int dp[1000006];
int inv(int x)
{
    int cnt = 0;
    while (x)
    {
        cnt = cnt * 10 + (x%10);
        x /= 10;
    }
    return cnt;
}
int main(void)
{
    ifstream fi("a.in");
    ofstream fo("a.out");
    int t,n;
    fi>>t;
    for (int i = 1;i <= 1000000;++i) dp[i] = 1e9;
    dp[1] = 1;
    for (int i = 1;i <= 1000000;++i)
    {
        if (dp[i-1] + 1 < dp[i]) dp[i] = dp[i-1] + 1;
        if (inv(i) > i && inv(i) <= 1000000) dp[inv(i)] = min(dp[inv(i)],dp[i] + 1);
    }
    for (int i = 1;i <= t;++i)
    {
        fi>>n;
        fo << "Case #" << i << ": " << dp[n] << '\n';
    }
    return 0;
}
