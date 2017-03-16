#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#define msg(var) cerr << #var << " = " << var << endl
using namespace std;

const int MAXE = (int)(100);
const int MAXN = 10224;

long long dp[20][MAXE];
int t, n;
long long e, r, v[MAXN];

int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    freopen("ss.in", "r", stdin);
    freopen("ss.out", "w", stdout);

    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        memset(dp, 0, sizeof(dp));
        cin >> e >> r >> n;
        for (int i = 1; i <= n; i++)
            cin >> v[i];

        for (int i = 1; i <= n; i++)
        {
            //if (T == 2) msg(v[i]);
            for (int j = 0; j <= e; j++)
            {
                int currE = min(j + r, e);
                for (int k = currE; k >= 0; k--)
                {
                    dp[i][k] = max(dp[i][k], v[i] * (currE - k) + dp[i - 1][j]);
                    //if (T == 2 && i == 1)
                     //   msg(v[i] * (currE - k));
                }
            }
        }
        long long ans = 0ll;
        for (int i = 0; i <= e; i++)
        {
           // if (T == 2) cout << dp[1][i] << endl;
            ans = max(ans, dp[n][i]);
        }
        printf("Case #%d: %lld\n", T, ans);
    }

    return 0;
}
