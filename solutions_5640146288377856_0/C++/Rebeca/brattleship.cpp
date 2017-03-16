#include <cstdio>

int main()
{
  int t, r, c, w, y;

  scanf("%d", &t);

  for(int i = 1; i <= t; i++)
  {
    y = 0;
    scanf("%d%d%d", &r, &c, &w);
    y = r * (c / w);
    if (c % w == 0)
    {
      y += w - 1;
    }
    else
    {
      y += w;
    }
    printf("Case #%d: %d\n", i, y);
  }
}
