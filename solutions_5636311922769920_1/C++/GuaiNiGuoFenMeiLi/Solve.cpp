#include <bits/stdc++.h>

using namespace std;

uint64_t power(int a, int b) {
  uint64_t res = 1, base = a;
  for (; b; b /= 2, base = base * base) {
    if (b & 1) {
      res *= base;
    }
  }
  return res;
}

int main() {
  freopen("D-large.in", "r", stdin);
  freopen("D-large.out", "w", stdout);

  int T;
  scanf("%d", &T);
  for (int test = 1; test <= T; ++test) {
    int k, c, s;
    scanf("%d %d %d", &k, &c, &s);
    printf("Case #%d:", test);
    int n = (k + (c - 1)) / c;
    if (n > s) {
      printf(" IMPOSSIBLE");
    } else {
      for (int i = 0; i < n; ++i) {
        uint64_t v = 0;
        for (int j = 0; j < c; ++j) {
          v += power(k, j) * min(c * i + j, k - 1);
        }
        ++v;
        cout << " " << v;
      }
    }
    puts("");
  }
  return 0;
}
