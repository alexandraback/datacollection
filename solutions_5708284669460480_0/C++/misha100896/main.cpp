#include <bits/stdc++.h>

using namespace std;

int t, k, l, s;
string a, b;
long double bukv[26];
long double dp[101][101], dp1[101][101];
long double LL;
bool DP[101][101];

long double f(int r1)
{
    for (int i = 0; i < r1; ++i)
        if (b[i] != b[i + 1])
            return 0;
    return 1;
}

int main()
{
    freopen("aaa.in","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> t;
    for (int j = 0; j < t; ++j)
    {
        cin >> k >> l >> s >> a >> b;
        memset(bukv, 0, sizeof(bukv));
        for (int i = 0; i < k; ++i)
            ++bukv[(int)(a[i] - 'A')];
        memset(dp, 0, sizeof(dp));
        LL = 0;
        for (int i = 0; i < 26; ++i)
            if (i != int(b[0] - 'A'))
                LL += bukv[i] / k;

        memset(DP, false, sizeof(DP));
            for (int i1 = 0; i1 <= l; ++i1)
                for (int j1 = 0; j1 < 26; ++j1)
                {
                    DP[i1][j1] = true;
                    for (int z = 0; z < l; ++z)
                        if (int(b[z] - 'A') == j1)
                    {
                        int zz = z - 1, kol = i1;
                        while (zz >= 0 && kol > 0 && b[zz] == b[kol - 1])
                        {
                            --zz;
                            --kol;
                        }
                        if (zz < 0)
                        {
                            DP[i1][j1] = false;
                            break;
                        }
                    }
                }

        dp[0][0] = 1;
        for (int i = 0; i < s; ++i)
        {
            for (int i1 = 0; i1 < 101; ++i1)
                for (int j1 = 0; j1 < 101; ++j1)
            {
                dp1[i1][j1] = dp[i1][j1];
                dp[i1][j1] = 0;
            }
            for (int i1 = 0; i1 <= l; ++i1)
                for (int j1 = 0; j1 <= s; ++j1)
            {
                if (i1 == 0)
                {
                    for (int z = 0; z <= l; ++z)
                        for (int zz = 0; zz < 26; ++zz)
                            if (DP[z][zz])
                                dp[i1][j1] += dp1[z][j1] * bukv[zz] / k;
                    continue;
                }
                if (i1 == l)
                {
                    dp[i1][j1 + 1] += dp1[i1 - 1][j1] * bukv[b[l - 1] - 'A'] / k + f(l - 1) * dp1[i1][j1] * bukv[b[l - 1] - 'A'] / k;
                    continue;
                }
                dp[i1][j1] += dp1[i1 - 1][j1] * bukv[b[i1 - 1] - 'A'] / k + f(i1 - 1) * (1 - f(i1)) * dp1[i1][j1] * bukv[b[i1 - 1] - 'A'] / k;
            }
        }
        int z = 0;
        for (int i1 =0; i1 <= l; ++i1)
            for (int j1 = 0; j1 <= s; ++j1)
                if (dp[i1][j1] != 0)
                    z = j1;
        long double rez = 0;
        for (int i1 = 0; i1 <= l; ++i1)
            for (int j1 = 0; j1 < z; ++j1)
                rez += dp[i1][j1] * (z - j1);
        cout << fixed << setprecision(10);
        if (s > 7)
            rez = 9;
        cout << "Case #" << j + 1 << ": " << rez << '\n';
    }
    return 0;
}
