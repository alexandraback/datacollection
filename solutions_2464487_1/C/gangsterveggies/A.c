#include <stdio.h>

int main()
{
  int t, T;
  scanf("%d", &T);
  for (t = 1; t <= T; t++)
  {
    long long int r, ans = 0, a;
    double av;
    scanf("%lld %lld", &r, &a);
    av = a;
    while (1)
    {
      long long int seg = 1;
      if (av - (seg + 2 * seg * (r + seg - 1)) < 0)
        break;
      while (1)
      {
        if (av - (seg + 2 * seg * (r + seg - 1)) < 0)
        {
          seg /= 2;
          break;
        }
        else
          seg *= 2;
      }
      ans += seg;
      av -= (seg + 2 * seg * (r + seg - 1));
      r += 2 * seg;
    }
    printf("Case #%d: %lld\n", t, ans);
  }
  return 0;
}
