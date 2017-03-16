#include<iostream>
using namespace std;

int dp[1000005] = { 0 };

long long reverse(long long x)
{
    long long ans = 0;
    while (x > 0)
    {
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return ans;
}

long long len(long long x)
{
    int ret = 0;
    while (x > 0)
    {
        ret ++;
        x /= 10;
    }
    return ret;
}
long long exp(long long base,long long e)
{
    long long ret = 1;
    e--;
    for (int i = 0; i < e; i++)
        ret *= base;
    return ret;
}

long long calc(long long x, long long y)
{
    if (x == y)
        return 0;
    if (len(x) == 1)
        return y - x;
    if (y % 10 == 0)
        return calc(x,y - 1) + 1;
    int half = len(y)/ 2;
    long long mod = exp(10,half + 1);
    long long ans = 0;
    ans += reverse(y / mod);
    ans += y % mod;
    if (ans > y - x)
        ans = y - x;
    return ans;
}


long long solve(long long x,long long y)
{
    long long p1 = len(x);
    long long p2 = len(y);
    if (p1 == p2)
        return calc(x,y);
    else
        return solve(x,exp(10,p1 + 1) - 1) + 1 + solve(exp(10,p1 + 1),y);
}

int main()
{
    int tt;
    cin >> tt;
    dp[1] = 1;
    /*
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
    */
    for (int ii = 0; ii < tt; ii++)
    {
        long long n;
        cin >> n;
        cout << "Case #" << ii + 1 << ": " << solve(1,n) + 1<< endl;
    }
    return 0;
}
