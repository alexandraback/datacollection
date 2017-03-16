#include <bits/stdc++.h>
using namespace std;
void solve() {
  int k, c, s;
  scanf("%d %d %d", &k, &c, &s);
  if (c * s < k) {
    printf(" IMPOSSIBLE");
    return ;
  }
  long long x = 1;
  for (int i = 0; i < c - 1; i++) {
    x *= k;
  }
  for (int i = 0; i < s && i * c < k; i++) {
    long long s = 0;
    long long t = x;
    for (int j = 0; j < c && i * c + j < k; j++, t /= k) {
      s += (i * c + j) * t;
    }
    printf(" %lld", s + 1);
  }
}
int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    printf("Case #%d:", t);
    solve();
    printf("\n");
  }
  return 0;
}

