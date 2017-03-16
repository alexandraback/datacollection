#include <cstdio>
#include <cstring>
int main() {
  int t;
  scanf("%d", &t);
  for (int ti = 1; ti <= t; ++ti) {
    printf("Case #%d:\n", ti);
    int n, m;
    scanf("%d%d", &n, &m);

    char s[99], *o = s;
    memset(s, 0, sizeof(s));
    *o++ = '1';
    for (int i = 2; i < n; ++i)
      *o++ = '0';
    *o++ = '1';
    for (int i = 3; i <= 11; ++i)
      o += sprintf(o, " %d", i);
    *o++ = '\n';
    *o++ = '\0';

    int c = 0;
    for (int i0 = 1; i0 < n - 1; i0 += 2) {
      for (int i1 = i0 + 2; i1 < n - 1; i1 += 2) {
        for (int i2 = 2; i2 < n; i2 += 2) {
          for (int i3 = i2 + 2; i3 < n; i3 += 2) {
            s[i0] = s[i1] = s[i2] = s[i3] = '1';
            printf("%s", s);
            s[i0] = s[i1] = s[i2] = s[i3] = '0';
            if (++c == m)
              goto l0;
          }
        }
      }
    }
l0:;
  }
  return 0;
}
