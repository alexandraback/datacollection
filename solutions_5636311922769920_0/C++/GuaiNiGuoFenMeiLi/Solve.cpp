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
   freopen("D-small-attempt1.in", "r", stdin);
   freopen("D-small-attempt1.out", "w", stdout);

  int T;
  scanf("%d", &T);
  for (int test = 1; test <= T; ++test) {
    int k, c, s;
    scanf("%d %d %d", &k, &c, &s);
    printf("Case #%d:", test);
    uint64_t dis = power(k, c - 1);
    for (int i = 0; i < k; ++i) {
      cout << " " << dis * i + 1;
    }
    puts("");
  }
  return 0;
}
