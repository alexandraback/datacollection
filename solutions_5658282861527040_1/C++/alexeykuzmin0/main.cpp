#include <iostream>
#include <map>
#include <cmath>

using namespace std;

map<long long, map<long long, map<long long, map<long long, long long> > > > dp;

int solve2(int a, int b, int c)
{
    int ans = 0;
    for (int i = 0; i <= a; ++i)
    {
        for (int j = 0; j <= b; ++j)
        {
            if ((i & j) <= c)
            {
                ++ans;
            }
        }
    }
    return ans;
}

long long solve(long long cur, long long a, long long b, long long c)
{
    if (cur == 1)
    {
        int ans = 0;
        for (int i = 0; i <= a; ++i)
        {
            for (int j = 0; j <= b; ++j)
            {
                if ((i & j) <= c)
                {
                    ++ans;
                }
            }
        }
        return ans;
    }
    if (dp[cur][a][b][c] != 0)
    {
        return dp[cur][a][b][c] - 1;
    }
    long long ans = 0;
    if ((c & cur) != 0)
    {
        ans += min(cur, a + 1) * min(cur, b + 1); // 0-0
        if ((a & cur) != 0) // 1-0
        {
            ans += solve(cur / 2, a & (cur - 1), min(b, cur - 1), cur - 1);
        }
        if ((b & cur) != 0) // 0-1
        {
            ans += solve(cur / 2, min(a, cur - 1), b & (cur - 1), cur - 1);
        }
        if (((a & cur) != 0) && ((b & cur) != 0)) // 1-1
        {
            ans += solve(cur / 2, a & (cur - 1), b & (cur - 1), c & (cur - 1));
        }
    }
    else
    {
        ans += solve(cur / 2, min(a, cur - 1), min(b, cur - 1), c); // 0-0
        if ((a & cur) != 0) // 1-0
        {
            ans += solve(cur / 2, a & (cur - 1), min(b, cur - 1), c);
        }
        if ((b & cur) != 0) // 0-1
        {
            ans += solve(cur / 2, min(a, cur - 1), b & (cur - 1), c);
        }
    }
    dp[cur][a][b][c] = ans + 1;
    return ans;
}

int main(void)
{/*
    for (int sum = 3;; ++sum)
    {
        cout << sum << endl;
        for (int a = 1; a < sum - 1; ++a)
        {
            for (int b = 1; a + b < sum; ++b)
            {
                if (solve2(a - 1, b - 1, sum - a - b - 1) != solve(1 << 30, a - 1, b - 1, sum - a - b - 1))
                {
                    cout << a << ' ' << b << ' ' << sum - a - b << endl;
                    return 0;
                }
            }
        }
    }*/

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cout << "Case #" << (i + 1) << ": " << solve(1 << 30, a - 1, b - 1, c - 1) << "\n";
    }
    return 0;
}
