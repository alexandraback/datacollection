#include <bits/stdc++.h>

using namespace std;

long long f[55];
int ans[55][55];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  freopen("log", "w", stderr);
  int tt;
  scanf("%d", &tt);
  for (int cc = 1; cc <= tt; ++cc) {
    printf("Case #%d: ", cc);
    int n;
    long long m;
    scanf("%d %lld", &n, &m);
    memset(ans, 0, sizeof ans);
    f[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
      f[i] = 0;
      for (int j = i + 1; j < n; ++j) {
        if (f[i] + f[j] <= m) {
          f[i] += f[j];
          ans[i][j] = 1;
        }
      }
    }
    if (f[0] == m) {
      puts("POSSIBLE");
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          printf("%d", ans[i][j]);
        }
        printf("\n");
      }
    } else {
      puts("IMPOSSIBLE");
    }
  }
  return 0;
}