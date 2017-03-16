#include <bits/stdc++.h>

using namespace std;

#define IS(i, j) (((i) >> (j)) & 1)

int T, R, C, W, bits[1 << 10], f[1 << 10][1 << 10];

int dfs(int a, int b) {
  if (f[a][b] != -1) return f[a][b];
  bool flag = false;
  for (int i = 0; i + W - 1 < C && !flag; ++i) {
    bool ok = true;
    for (int j = i + 0; j < i + W && ok; ++j) {
      if (IS(a, j)) {
        if (!IS(b, j)) ok = false;
      }
    }
    if (ok) flag = true;
  }
  if (!flag) return f[a][b] = -2;
  if (bits[b] == W) return 0;
  f[a][b] = R * C;
  for (int i = 0; i < C; ++i)
    if (!IS(a, i)) {
      int value = max(dfs(a | (1 << i), b), dfs(a | (1 << i), b | (1 << i)));
      if (value >= 0) {
        f[a][b] = min(f[a][b], 1 + value);
      }
    }
  return f[a][b];
}

int main() {

  freopen("A-small-attempt0.in", "r", stdin);
  freopen("A-small-attempt0.out", "w", stdout);

  for (int i = 0; i < (1 << 10); ++i)
    for (int j = 0; j < 10; ++j)
      if (IS(i, j)) bits[i]++;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    cin >> R >> C >> W;
    memset(f, 0xff, sizeof(f));
    printf("Case #%d: %d\n", test, dfs(0, 0));
  }
  return 0;
}
