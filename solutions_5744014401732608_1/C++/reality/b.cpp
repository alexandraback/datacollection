# include <bits/stdc++.h>
using namespace std;
# define x first
# define y second
# define ll long long
# define db long double
# define scn(x) scanf("%I64d",&x)
# define scan(x) scanf("%d",&x)
# define print(x) printf("%d ",x)
# define prnt(x) printf("%I64d ",x);
# define eol printf("\n")
# define IOS ios_base :: sync_with_stdio(0)
#define int ll
int s[505][505];
ll dp[505];
signed main(void)
{
    ifstream fi("input");
    ofstream fo("output");
    int t;
    fi>>t;
    for (int cs = 1;cs <= t;++cs)
    {
        fo << "Case #" << cs << ": ";
        int n;
        ll m;
        fi>>n>>m;
        for (int i = 1;i <= n;++i) dp[i] = 0;
        memset(dp,0,sizeof(dp));
        memset(s,0,sizeof(s));
        dp[1] = 1;
        for (int i = 2;i < n;++i)
            for (int j = 1;j < i;++j)
                s[j][i] = 1,dp[i] += dp[j];
        ll cnt = 0;
        for (int i = 1;i < n;++i) cnt += dp[i];
        if (cnt < m) fo << "IMPOSSIBLE\n";
        else
        {
            fo << "POSSIBLE\n";
            for (int i = n - 1;i;--i)
                if (m >= dp[i]) m -= dp[i],s[i][n] = 1;
            for (int i = 1;i <= n;++i,fo << '\n')
                for (int j = 1;j <= n;++j) fo << s[i][j];
        }
    }
    return 0;
}
