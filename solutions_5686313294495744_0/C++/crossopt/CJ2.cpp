#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int INF = 1e9 + 7;

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("ans.out", "w", stdout);
    int t;
    cin >> t;
    string c, j;
    for (int q = 1; q <= t; ++q)
    {
        cout << "Case #" << q << ": ";
        int n;
        cin >> n;
        vector <string> a(n), b(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i] >> b[i];
        int dp[(1 << n)];
        for (int i = 0; i < (1 << n); ++i)
            dp[i] = 0;

        for (int i = 1; i < (1 << n); ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i & (1 << j))
                    continue;
                bool f1 = false, f2 = false;
                for (int k = 0; k < n; ++k)
                {
                    if ((i & (1 << k)))
                    {
                        if (a[k] == a[j])
                            f1 = true;
                        if (b[k] == b[j])
                            f2 = true;
                    }
                }
                if (f1 && f2)
                    dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i] + 1);
            }
        }
        cout << dp[(1 << n) - 1] << endl;
    }
}
