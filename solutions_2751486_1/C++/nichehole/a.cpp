#include <cstdio>
#include <cstring>
typedef long long LL;

char s[5000000];
int n;

int main() {
  int cas = 0;
  int T; scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    scanf("%d", &n);
    LL cnt = 0;
    int len = strlen(s);
    int tmp = 0;
    int j = 0;
    int start = 10000000;
    for (int i = 0; i < len && j <= len; ++i) {
      if (i > start) --tmp;
      for (; tmp < n && j < len; ++j) {
        //printf("%c\n", s[j]);
        if (s[j] != 'a' && s[j] != 'e' && s[j] != 'i' && s[j] != 'o' && s[j] != 'u') {
          ++tmp;
          if (tmp == 1) start = j;
        } else {
          tmp = 0;
        }
        //printf("i: %d, j: %d, tmp: %d begin %d\n", i, j, tmp, start);
      }
      if (tmp >= n) {
        cnt += (len + 1 - j);
      }
    }
    printf("Case #%d: ", ++cas);
    printf("%lld\n", cnt);
  }
  return 0;
}
