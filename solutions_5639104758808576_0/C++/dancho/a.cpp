#include <cstdio>
#include <cstring>

int n;
char s[1024];

int main() {
  int t, T;
  scanf("%d", &T);
  for (t = 1; t <= T; ++t) {
    scanf("%d", &n);
    scanf("%s", s);
    int cur = 0;
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
      if (i > cur) {
        ans += i - cur;
        cur = i;
      }
      cur += (s[i] - '0');
    }
    printf("Case #%d: %d\n", t, ans);
  }
  return 0;
}
