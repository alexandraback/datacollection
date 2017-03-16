#include <stdio.h>

char s[1000001];

int chk(int l, int r, int need) {
  int i, j, now = 0, max = 0;
  for (i = l; i <= r; i++) {
    now = 0;
    for (j = i; j <= r; j++)
      if (s[j] != 'a' && s[j] != 'e' && s[j] != 'i' && s[j] != 'o' && s[j] != 'u') {
        now++;
        if (now > max) max = now;
      } else now = 0;
  }
  return (max >= need);
}

int main() {
  int T, C = 1;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%s%d", s, &n);
    int i, j, ans = 0;
    for (i = 0; s[i]; i++)
      for (j = i; s[j]; j++)
        ans += chk(i, j, n);
    printf("Case #%d: %d\n", C++, ans);
  }
  return 0;
}
