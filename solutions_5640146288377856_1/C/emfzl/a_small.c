#include <stdio.h>

int main(void)
{
  int i, t, r, c, w;
  scanf("%d", &t);
  for (i = 0; i < t; i++)
    {
      scanf("%d %d %d", &r, &c, &w);
      if (r < 1 || w < 1 || w > c)
	continue;

      printf("Case #%d: %d\n", i + 1, 
	     c / w * r + w + ((c % w == 0) ? -1 : 0));
    }

  return 0;
}
