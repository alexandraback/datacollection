#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

int n;
double dp[1010][1010];

int main() {
  int T;
  scanf("%d",&T);
  for (int ca = 1 ; ca <= T ; ++ca) {
    int x, y;
    scanf("%d%d%d",&n,&x,&y);
    if (x < 0) x = -x;
    printf("Case #%d: ", ca);
    if ((x+y) % 2) {
      printf("0.0\n");
      continue;
    }
    int lay;
    for (lay = 1 ; ; ++lay) {
      if (lay * (lay * 2 - 1) > n) break;
    }
    int rl = (x+y)/2+1;
    if (rl < lay) {
      printf("1.0\n");
      continue;
    }
    if (rl > lay) {
      printf("0.0\n");
      continue;
    }
    int left = n - (lay-1) * (lay*2-3);
    // printf("lay:%d left:%d\n", lay, left);
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1.0;
    for (int i = 0 ; i < left ; ++i) {
      for (int j = 0 ; j <= left ; ++j) {
        if (dp[i][j] == 0) continue;
        int L = j, R = i - j;
        assert(L < (lay-1)*2 || R < (lay-1)*2);
        if (L == (lay-1)*2) {
          dp[i+1][j] += dp[i][j];
        } else if (R == (lay-1)*2) {
          dp[i+1][j+1] += dp[i][j];
        } else {
          dp[i+1][j] += dp[i][j] / 2.0;
          dp[i+1][j+1] += dp[i][j] / 2.0;
        }
      }
    }
    // for (int i = 0 ; i <= lay ; ++i)
    //   printf("dp[%d][%d]:%lf\n", left, i, dp[left][i]);
    double ans = .0;
    for (int i = y+1 ; i <= (lay-1)*2 ; ++i)
      ans += dp[left][i];
    printf("%.10lf\n", ans);
  }
  return 0;
}

