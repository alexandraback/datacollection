#include <stdio.h>

#define MAX 2333
#define INF 0x3f3f3f3f
#define max(a, b) (a) >= (b) ? (a) : (b)
#define min(a, b) (a) <= (b) ? (a) : (b)
int n, a[MAX];

int solve() {
  int ret = INF, md = 0;
  for (int i = 0; i < n; i++) md = max(md, a[i]);
  for (int i = 1; i < md; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (a[j] <= i) continue;
      if (a[j] % i) cnt += a[j] / i;
      else cnt += (a[j] / i) - 1;
    }
    ret = min(cnt + i, ret);
  }
  ret = min(ret, md);
  return ret;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    scanf("%d", &n);
    for (int j = 0; j < n; j++) scanf("%d", &a[j]);

    printf("Case #%d: %d\n", i, solve());
  }
  return 0;
}
