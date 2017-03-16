#include <stdio.h>

#include <algorithm>


int main() {
  int zzz;
  scanf("%d", &zzz);
  for (int t = 1; t <= zzz; ++t) {
    int s_max;
    static char arr[1005];
    static int count[1005];
    scanf("%d %s", &s_max, arr);
    int ans = 0;
    for (int i = 1; i <= s_max; ++i) {
      count[i - 1] = arr[i - 1] - '0' + (i > 1 ? count[i - 2] : 0);
      if (arr[i] - '0' > 0) {
        ans = std::max(ans, i - count[i - 1]);
      }
    }
    printf("Case #%d: %d\n", t, ans);
  }
  return 0;
}
