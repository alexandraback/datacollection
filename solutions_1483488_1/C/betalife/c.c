#include <stdio.h>

#define maxB 2200000

int o[maxB];

int main ()
{
  freopen ("c.in" , "r", stdin);
  freopen ("c.out", "w", stdout);

  int T, tc, i, A, B, L, j, t, k, tms = 0;

  scanf ("%d", &T);

  for (tc = 1; tc <= T; ++tc)
    {
      scanf ("%d%d", &A, &B);
      for (L = 0, k = 1; k * 10 <= B; ++L, k *= 10);
      int ans = 0;
      for (i = 1; i <= B; ++i)
        {
          t = i, ++tms;
          for (j = 1; j <= L; ++j)
            {
              t = t / 10 + t % 10 * k;
              if (A <= t && t < i && o[t] != tms)
                ++ans, o[t] = tms;
            }
        }
      printf ("Case #%d: %d\n", tc, ans);
      fprintf (stderr, "Case #%d: %d\n", tc, ans);
    }
  return 0;
}
