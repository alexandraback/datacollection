#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int n[1050], d[1050], w[1050], e[1050], s[1050], dd[1050], dp[1050], ds[1050]; 
int D;
int wall[1050*2];

int main() {
  int cas = 0;
  int T; scanf("%d", &T);
  while (T--) {
    memset(wall, 0, sizeof(wall));
    int *p = wall + 1000;
    D = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
      scanf("%d%d%d%d%d%d%d%d", &d[i], &n[i], &w[i], &e[i], &s[i], &dd[i], &dp[i], &ds[i]);
      dp[i] *= 2;
      D = max(D, d[i] + (n[i] - 1) * dd[i]);
    }
    int suc = 0;
    for (int day = 0; day <= D; ++day) {
      for (int i = 0; i < N; ++i) {
        int tmp = day - d[i];
        if (tmp >= 0 && tmp % dd[i] == 0 && tmp / dd[i] <= n[i] - 1) {
          int k = tmp / dd[i];
          //printf("day: %d, tribe: %d, [%d, %d], string: %d\n", day, i + 1, w[i]*2 + k*dp[i], e[i]*2 + k*dp[i], s[i] + k*ds[i]);
          bool lose = 0;
          for (int j = w[i]*2; j <= e[i]*2; ++j) {
            int nj = j + k * dp[i];
            int ns = s[i] + k * ds[i];
            if (p[nj] < ns) {
              //printf("%d %d %d\n", nj, p[nj], ns);
              lose = 1;
            }
          }
          if (lose == 1) ++suc;
        }
      }
      for (int i = 0; i < N; ++i) {
        int tmp = day - d[i];
        if (tmp >= 0 && tmp % dd[i] == 0 && tmp / dd[i] <= n[i] - 1) {
          int k = tmp / dd[i];
          for (int j = w[i]*2; j <= e[i]*2; ++j) {
            int nj = j + k * dp[i];
            int ns = s[i] + k * ds[i];
            p[nj] = max(p[nj], ns);
          }
        }
      }
    }
    printf("Case #%d: ", ++cas);
    printf("%d\n", suc);
  }
  return 0;
}
