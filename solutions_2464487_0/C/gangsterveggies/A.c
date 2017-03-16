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
      av -= (r + 1) * (r + 1) - r * r;
      if (av >= 0)
      {
        ans++;
        r += 2;
      }
      else
        break;
    }
    printf("Case #%d: %lld\n", t, ans);
  }
  return 0;
}
