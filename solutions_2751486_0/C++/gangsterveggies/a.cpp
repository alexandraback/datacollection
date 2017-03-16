#include <stdio.h>
#include <string.h>

char pal[1001000];

int vol(char ch)
{
  return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main()
{
  int t, T, n;
  scanf("%d", &T);
  for (t = 1; t <= T; t++)
  {
    scanf(" %s %d", pal, &n);
    long long int ans = 0;
    int i, ct = 0, L = strlen(pal), last = 0;
    for (i = 0; i < L; i++)
    {
      if (vol(pal[i]))
        ct = 0;
      else
      {
        ct++;
        if (ct >= n)
        {
          ans += (i - n - last + 2) * (L - i);
          last = i - n + 2;
        }
      }
    }
    printf("Case #%d: %lld\n", t, ans);
  }
  return 0;
}
