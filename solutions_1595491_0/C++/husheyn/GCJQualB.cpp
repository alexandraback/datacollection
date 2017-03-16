#include <iostream>
using namespace std;

int t, n, s, p;
int a[105];
int dp[105][105];

int max(int a, int b) {return a > b ? a : b;}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cin >> n >> s >> p;
        for(int j = 1; j <= n; j++) cin >> a[j];
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        for(int j = 1; j <= n; j++)
            for(int k = 0; k <= s; k++)
            {
                if (dp[j - 1][k] != -1)
                {
                    dp[j][k] = dp[j - 1][k];
                    if (a[j] % 3 == 0 && a[j] / 3 >= 0 && a[j] / 3 <= 10 && a[j] / 3 >= p) dp[j][k] = max(dp[j][k], dp[j - 1][k] + 1);
                    if ((a[j] - 1) % 3 == 0 && (a[j] - 1) / 3 >= 0 && (a[j] - 1) / 3 + 1 <= 10 && (a[j] - 1) / 3 + 1 >= p) dp[j][k] = max(dp[j][k], dp[j - 1][k] + 1);
                    if ((a[j] - 2) % 3 == 0 && (a[j] - 2) / 3 >= 0 && (a[j] - 2) / 3 + 1 <= 10 && (a[j] - 2) / 3 + 1 >= p) dp[j][k] = max(dp[j][k], dp[j - 1][k] + 1);
                }
                if (k > 0 && dp[j - 1][k - 1] != -1)
                {
                    dp[j][k] = max(dp[j][k], dp[j - 1][k - 1]);
                    if ((a[j] - 2) % 3 == 0 && (a[j] - 2) / 3 >= 0 && (a[j] - 2) / 3 + 2 <= 10 && (a[j] - 2) / 3 + 2 >= p) dp[j][k] = max(dp[j][k], dp[j - 1][k - 1] + 1);
                    if ((a[j] - 3) % 3 == 0 && (a[j] - 3) / 3 >= 0 && (a[j] - 3) / 3 + 2 <= 10 && (a[j] - 3) / 3 + 2 >= p) dp[j][k] = max(dp[j][k], dp[j - 1][k - 1] + 1);
                    if ((a[j] - 4) % 3 == 0 && (a[j] - 4) / 3 >= 0 && (a[j] - 4) / 3 + 2 <= 10 && (a[j] - 4) / 3 + 2 >= p) dp[j][k] = max(dp[j][k], dp[j - 1][k - 1] + 1);
                }
            }
        if (dp[n][s] == -1) dp[n][s] = 0;
        cout << "Case #" << i << ": " << dp[n][s] << endl;
    }
    return 0;
}
