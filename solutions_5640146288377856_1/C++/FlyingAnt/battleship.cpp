#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int t, w, r, c;
  scanf("%d", &t);
  for (int k = 1; k <= t; k++) {
    scanf("%d %d %d", &r, &c, &w);
    int ans = 0;
    if (c == w) ans = r - 1 + c;
    else {
      ans = (c / w) * (r - 1);
      ans += (c / w) - 1 + w + (c % w != 0 ? 1 : 0);
    }
    printf("Case #%d: %d\n", k, ans);
  }
  return 0;
}
