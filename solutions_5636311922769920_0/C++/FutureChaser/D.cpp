#include <stdio.h>

int main()
{
  int cases;
  scanf("%d", &cases);
  for (int cc = 1; cc <= cases; ++cc)
  {
    printf("Case #%d: ", cc);
    int k, c, s;
    scanf("%d%d%d", &k, &c, &s);
    if (((c == 1) && (s < k)) || (s < k - 1))
      printf("IMPOSSIBLE\n");
    else
    {
      if (c == 1)
      {
        for (int i = 1; i <= s; ++i)
          printf("%d ", i);
        printf("\n");
      }
      else
      {
        if (k > 1)
        {
          for (int i = 2; i <= s; ++i)
            printf("%d ", i);
          printf("\n");
        }
        else
        {
          printf("1\n");
        }
      }
    }
  }
  return 0;
}
