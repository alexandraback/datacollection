#include <cstdio>
#include <cstring>
char a[111];
int main() {
  int t;
  scanf("%d", &t);
  for (int ti = 1; ti <= t; ++ti) {
    scanf("%s", a);
    int i = strlen(a);
    for (--i; i >= 0 && a[i] == '+'; --i);
    int ans = 0;
    char c = '+';
    for (; i >= 0; --i) {
      if (c != a[i]) {
        c = a[i];
        ++ans;
      }
    }
    printf("Case #%d: %d\n", ti, ans);
  }
  return 0;
}
