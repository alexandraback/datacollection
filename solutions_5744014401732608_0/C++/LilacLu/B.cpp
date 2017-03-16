#include <cstdio>
#include <cstring>

#define SMALL
//#define LARGE

int T, b;
long long m, c[55];
int ans[55];

int main()
{
#ifdef SMALL
  freopen("B-small.in", "r", stdin);
  freopen("B-small.out", "w", stdout);
#endif
#ifdef LARGE
  freopen("B-large.in", "r", stdin);
  freopen("B-large.out", "w", stdout);
#endif

  memset(c, -1, sizeof(c));
  c[1] = c[2] = 1;
  for (int i = 3; 1; ++i) {
    if (c[i - 1] > (long long)1e18 / 2)
      break;
    c[i] = c[i - 1] * 2;
  }
  scanf("%d", &T);
  for (int Case = 1; Case <= T; ++Case) {
    scanf("%d %lld", &b, &m);
    memset(ans, 0, sizeof(ans));
    for (int i = b - 1; i >= 1; --i) {
      if (c[i] < 0)
        continue;
      if (c[i] <= m)
        m -= c[i], ans[i] = 1;
      if (m == 0)
        break;
    }
    printf("Case #%d: ", Case);
    if (m == 0) {
      printf("POSSIBLE\n");
      for (int i = 1; i < b; ++i) {
        for (int j = 1; j <= i; ++j) {
          printf("0");
        }
        for (int j = i + 1; j < b; ++j)
          printf("1");
        printf("%d\n", ans[i]);
      }
      for (int i = 1; i <= b; ++i)
        printf("0");
      printf("\n");
    } else {
      printf("IMPOSSIBLE\n");
    }
  }
  return 0;
}
