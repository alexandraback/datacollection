#include<iostream>
using namespace std;

int dp[1000005] = { 0 };

int reverse(int x)
{
    int ans = 0;
    while (x > 0)
    {
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return ans;
}

int main()
{
    int tt;
    cin >> tt;
    dp[1] = 1;
    for (int i = 2; i <= 1000000; i++)
    {
        int r = reverse(i);
        if (dp[i] == 0)
            dp[i] = dp[i - 1] + 1;
        else
            dp[i] = min(dp[i],dp[i - 1] + 1);
        if (r > i)
        {
            if (dp[r] == 0)
                dp[r] = dp[i] + 1;
            else
                dp[r] = min(dp[r],dp[i] + 1);
        }
    }
    for (int ii = 0; ii < tt; ii++)
    {
        int n;
        cin >> n;
        cout << "Case #" << ii + 1 << ": " << dp[n] << endl;
    }
    return 0;
}
