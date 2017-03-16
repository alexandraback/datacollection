#include <stdio.h>

#define MAX 100000
char s[MAX];
int n;

int solve() {
  int ret = 0, tot = 0;
  for (int i = 0; i < n + 1; i++) {
    if (i) {
      if (tot < i) {
        ret += i - tot;
        tot = i;
      }
    }
    tot += *(s + i) - '0';
    //printf("%d %d\n", ret, tot);
  }
  return ret;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    scanf("%d", &n);
    scanf("%s", s);
    printf("Case #%d: %d\n", i, solve());
  }
  return 0;
}
