#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    int r, c, w;
    scanf("%d %d %d", &r, &c, &w);
    int ans = 0;
    for (int i = 0; i < r; i++) {
      ans += (c / w);
    }
    if (c % w == 0) {
      ans += w-1;
    } else {
      ans += w;
    }
    printf("Case #%d: %d\n", tc, ans);
  }
  return 0;
}
