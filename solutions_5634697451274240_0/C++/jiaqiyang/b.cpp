#include <cstdio>
#include <cstring>

const char N = 100 + 10;

int main() {
  int tcase;
  scanf("%d", &tcase);
  for (int tid = 1; tid <= tcase; ++tid) {
    static char s[N];
    scanf(" %s", s);
    int n = strlen(s);
    s[n] = '+';
    int ans = 0;
    for (int i = 0; i < n; ++i) ans += (s[i] != s[i + 1]);
    printf("Case #%d: %d\n", tid, ans);
  }
  return 0;
}
