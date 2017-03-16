
#include <bits/stdc++.h>

using namespace std;

const int maxN = 111111;
int n, times, seq[maxN];
char str[maxN];

const int mul[5][5] = {
  {},
  {0, 1, 2, 3, 4},
  {0, 2, -1, 4, -3},
  {0, 3, -4, -1, 2},
  {0, 4, 3, -2, -1}
};

int cal(int x, int y) {
  int sgn = 1;
  if (x < 0) {
    sgn = -sgn;
    x = -x;
  }
  if (y < 0) {
    sgn = -sgn;
    y = -y;
  }
  return sgn * mul[x][y];
}

bool dp[maxN][5+5][6]; // pos, curProduct, wanted

bool dynamic(int n) {
  memset(dp, 0, sizeof(dp));
  dp[0][1 + 4][2] = true;
  for (int i = 0; i < n; ++i) {
    for (int p = 0; p <= 8; ++p) {
      for (int w = 2; w <= 4; ++w) {
        if (!dp[i][p][w]) continue;
        int q = seq[i + 1];
        int got = cal(p - 4, q) + 4;
        dp[i + 1][got][w] = true;
        if (w == got - 4) {
          dp[i + 1][1 + 4][w + 1] = true;
        }
      }
    }
  }
  return dp[n][1 + 4][5];
}

int main() {
  freopen("C-small-attempt0.in", "r", stdin);
  freopen("C-small-attempt0.out", "w", stdout);
  int tests;
  scanf("%d", &tests);
  for (int tt = 1; tt <= tests; ++tt) {
    scanf("%d%d", &n, &times);
    memset(seq, 0, sizeof(seq));
    scanf("%s", str + 1);
    for (int i = 1; i <= n; ++i) {
      if (str[i] == 'i') seq[i] = 2;
      if (str[i] == 'j') seq[i] = 3;
      if (str[i] == 'k') seq[i] = 4;
    }
    for (int t = 2; t <= times; ++t) {
      for (int i = 1; i <= n; ++i) {
        int offset = (t - 1) * n + i;
        seq[offset] = seq[i];
      }
    }
    printf("Case #%d: ", tt);
    if (dynamic(n * times)) {
      puts("YES");
    } else puts("NO");
  }
  return 0;
}
