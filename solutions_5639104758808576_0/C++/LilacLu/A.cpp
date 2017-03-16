#include <cstdio>

#define small
//#define large

int t, n;
char inp[1005];

int main()
{
#ifdef small
  freopen("small.in", "r", stdin);
  freopen("small.out", "w", stdout);
#endif
#ifdef large
  freopen("large.in", "r", stdin);
  freopen("large.out", "w", stdout);
#endif
  scanf("%d", &t);
  for (int Case = 1; Case <= t; ++Case) {
    scanf("%d %s", &n, inp);
    int ans = 0, now = 0;
    for (int i = 0; i <= n; ++i) {
      if (now < i) {
        ans += i - now;
        now += i - now;
      }
      now += inp[i] - '0';
    }
    printf("Case #%d: %d\n", Case, ans);
  }
  return 0;
}
