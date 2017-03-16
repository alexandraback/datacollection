#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("A.in", "rt", stdin);
  freopen("A.out", "wt", stdout);
  int t; scanf("%d", &t);
  for(int test = 1; test <= t; ++test) {
    int r, c, w;
    scanf("%d %d %d", &r, &c, &w);
    int ans = c / w * r + w + (c % w > 0) - 1;
    printf("Case #%d: %d\n", test, ans);
  }
  return 0;
}
