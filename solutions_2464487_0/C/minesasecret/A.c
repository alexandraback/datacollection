#include <stdio.h>

int main()
{
  unsigned int n;
  unsigned int t;
  unsigned int T;
  unsigned int r;

  scanf("%d", &T);
  for(int i = 1; i <= T; i++)
  {
    scanf("%d %d", &r, &t);
    n = 0;
    //will stop when n is too large
    while(t >= n * (2*n + 2*r - 1))
      n++;

    printf("Case #%d: %d\n", i, n-1);
  }

  return 0;
}


