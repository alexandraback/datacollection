#include <cstdio>
#include <cmath>

#define sq(a) (a)*(a)

int main(void)
{
  int T;

  scanf("%d\n", &T);

  for(int cas = 0; cas < T; cas++)
  {
    int r, t;

    scanf("%d %d\n", &r, &t);

    int res = 0;

    for(int i = 0; t >= 0; i++, res++)
    {
      t -= sq(r+2*i+1) - sq(r+2*i);
    }

    printf("Case #%d: %d\n", cas+1, res-1);
  }

  return 0;
}
