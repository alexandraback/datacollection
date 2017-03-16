#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <queue>
using namespace std;
typedef long long ll;

const int N = 10000 + 10;
int e, r, n;
int act[N];
ll dp[128][128];
int main()
{
#ifdef _ZZZ_
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  cin >> T;
  for(int tt = 1; tt <= T; ++ tt) {
    cin >> e >> r >> n;
    for(int i = 0; i < n; ++ i) {
      scanf("%d", &act[i]);
    }
    ll ans = 0;
    if (e < 128 && n < 128) {
      memset(dp, -1, sizeof(dp));
      dp[0][e] = 0;
      for(int i = 0; i < n; ++ i) {
        for(int j = 0; j <= e; ++ j) if (dp[i][j] != -1) {
          for(int k = 0; k <= j; k ++) {
            if (dp[i + 1][min(j - k + r, e)] < dp[i][j] + k * 1LL * act[i]) {
              dp[i + 1][min(j - k + r, e)] = dp[i][j] + k * 1LL * act[i];
            }
          }
        }
      }
      for(int i = 0; i <= n; ++ i) {
        for(int j = 0; j <= e; ++ j) {
          ans = max(ans, dp[i][j]);
          //cout << dp[i][j] << " ";
        }//cout << "\n";
      }
     //cout << "ha " << ans << endl;
    }
    cout << "Case #" << tt << ": " << ans << endl;
  }


}















