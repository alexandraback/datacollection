#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 120, MT = 110;
int n, m, ta[MAXN], tb[MAXN], tc, tci;
long long dp[MAXN][MAXN], a[MAXN], b[MAXN], sa[MAXN][MAXN], sb[MAXN][MAXN];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc;
    for (tci = 1; tci <= tc; tci++)
    {
        memset(dp, 0, sizeof(dp));
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i] >> ta[i];
        for (int i = 1; i <= m; i++) cin >> b[i] >> tb[i];
        for (int k = 1; k <= MT; k++)
        {
            sa[k][0] = sb[k][0] = 0;
            for (int i = 1; i <= n; i++) sa[k][i] = sa[k][i - 1] + (k == ta[i] ? a[i] : 0);
            for (int j = 1; j <= m; j++) sb[k][j] = sb[k][j - 1] + (k == tb[j] ? b[j] : 0);
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (ta[i] != tb[j]) dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                else
                for (int ii = 0; ii < i; ii++)
                    for (int jj = 0; jj < j; jj++)
                        dp[i][j] = max(dp[i][j], dp[ii][jj] + min( \
                            sa[ta[i]][i] - sa[ta[i]][ii], sb[tb[j]][j] - sb[tb[j]][jj]));
            }        
        cout << "Case #" << tci << ": " << dp[n][m] << endl;
        //for (int i = 1; i <= n; i++) { for (int j = 1; j <= m; j++) cout << dp[i][j] << ' '; cout << endl; }
    }
    return 0;
}
