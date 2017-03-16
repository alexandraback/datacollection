#include <cstdio>
#include <algorithm>
using namespace std;
bool solve() {
  int X, R, C;
  scanf("%d%d%d", &X, &R, &C);
  if (R > C) swap(R, C);
  if (X > max(R, C) || (X - 1) / 2 + 1 > min(R,C)|| R * C % X > 0) return true;
  if (X - R < 0)
    return false;
  for (int i = 0; i < X - R; i++) {
    int len1 = i, len2 = X - R - i;
    bool fail = false;
    for (int j = 0; j < C; j++)
      if (j-len1 >= 0 && j + len2 < C) {
        if ((j * R - i) % X == 0) fail = true;
      }
    if (!fail) return true;
  }
  return false;
}
int main() {
  freopen("t.in", "r", stdin);
  freopen("t.out", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    printf("Case #%d: %s\n", tc, solve() ? "RICHARD" : "GABRIEL");
  }
}
