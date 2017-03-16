#include <cstdio>
#include <cstring>

#define SMALL
//#define LARGE

int T, n, m, ans, ans1, ans2;
char C[40];

void dfs(const int& id, const int& now) {
  if (id == 2 * n) {
    int temp = (now / m) - (now % m);
    if (temp < 0)
      temp *= -1;
    if (temp < ans)
      ans = temp, ans1 = now / m, ans2 = now % m;
    return;
  }
  if (C[id] != '?') {
    dfs(id + 1, 10 * now + C[id] - '0');
    return;
  }
  for (int i = 0; i < 10; ++i)
    dfs(id + 1, 10 * now + i);
}

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

  scanf("%d", &T);
  for (int Case = 1; Case <= T; ++Case) {
    scanf("%s", C);
    n = strlen(C);
    m = 1;
    for (int i = 0; i < n; ++i)
      m *= 10;
    scanf("%s", C + n);
    ans = 10000;
    dfs(0, 0);
    printf("Case #%d: ", Case);
    if (n == 1)
      printf("%01d %01d\n", ans1, ans2);
    if (n == 2)
      printf("%02d %02d\n", ans1, ans2);
    if (n == 3)
      printf("%03d %03d\n", ans1, ans2);
  }
  return 0;
}
