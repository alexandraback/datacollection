#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("B-small-attempt0.in", "rt", stdin);
  freopen("B-small-attempt0.out", "wt", stdout);
  int t; scanf("%d", &t);
  for(int tst = 1; tst <= t; ++tst) {
    int a, b, k;
    scanf("%d %d %d", &a, &b, &k);
    int ans = 0;
    for(int i = 0; i < a; ++i)
      for(int j = 0; j < b; ++j)
        ans += ((i & j) < k);
    printf("Case #%d: %d\n", tst, ans);
  }
  return 0;
}
