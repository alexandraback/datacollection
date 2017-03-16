#include <stdio.h>

int covered(int cover[31], int V)
{
  int i;
  for (i = 1; i <= V; ++i)
    if (!cover[i])
      return 0;
  return 1;
}

int solve()
{
  int C, D, V, n, existing[5], coins1[30], coins2[30], cover[61], taken[31], i;
  for (i = 0; i < 31; ++i)
    taken[i] = 0;
  scanf("%d%d%d", &C, &D, &V);
  for (i = 0; i < D; ++i) {
    scanf("%d", existing + i);
    taken[existing[i]] = 1;
  }
  for (n = 0; ; ++n) {
    for (i = 0; i < n; ++i) {
      coins1[i] = i + 1;
    }
    for (;;) {
      int j = 0, k = 0;
      for (i = 0; i < n; ++i) {
        while (k < coins1[i]) {
          ++k;
          while (taken[++j]) {}
        }
        coins2[i] = j;
      }
      cover[i] = 1;
      for (i = 1; i <= V; ++i) {
        cover[i] = 0;
      }
      for (i = 0; i < D; ++i)
        for (j = V; j >= 0; --j)
          if (cover[j])
            cover[j+existing[i]] = 1;
      for (i = 0; i < D; ++i)
        cover[existing[i]] = 1;
      for (i = 0; i < n; ++i)
        for (j = V; j >= 0; --j)
          if (cover[j])
            cover[j+coins2[i]] = 1;
      if (covered(cover, V))
        return n;
      if (!n) break;
      for (i = 0; i < n - 1; ++i) {
        if (coins1[i] < coins1[i+1]-1)
          ++coins1[i];
      }
      if (i == n - 1)
        ++coins1[n-1];
      if (coins1[n-1] > V)
        break;
    }
  }
}

int main()
{
  int T, cases;
  scanf("%d", &T);
  for (cases = 1; cases <= T; ++cases) {
    printf("Case #%d: %d\n", cases, solve());
  }
  return 0;
}
