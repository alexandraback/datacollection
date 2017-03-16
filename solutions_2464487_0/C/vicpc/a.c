#include <stdio.h>
#include <math.h>

int main()
{
  int T,ind;
  long long unsigned t,r;
  long long unsigned delta;
  long long int b;
  long long unsigned N;
  long double aux;

  scanf("%d", &T);
  for(ind = 0; ind < T; ind++)
  {
    scanf("%llu %llu", &r, &t);
    b = (2*r-1);
    delta = b*b + 8*t;
    aux = -b + (sqrt((long double)delta));
    N = (long long unsigned)floor(aux/4);

    printf("Case #%d: %llu\n",ind+1, N);
  }

  return 0;
}
