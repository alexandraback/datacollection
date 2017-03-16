#include <stdio.h>

int main()
{
  int T,t;
  long long unsigned E, R, N;
  long long unsigned n;
  long long unsigned acumulado, v, v_max;

  scanf("%d", &T);
  for(t = 0; t<T; t++)
  {
    scanf("%llu %llu %llu", &E, &R, &N);
    if (R > E)
      R = E;

    v_max = 0;
    acumulado = 0;
    for(n = 0; n<N; n++)
    {
      scanf("%llu", &v);
      if (v > v_max)
      {
        acumulado -= v_max*E;
        acumulado += v_max*R;
        acumulado += v*E;
        v_max = v;        
      }
      else
      {
        acumulado += v*R;
      }

    }
    printf("Case #%d: %llu\n", t+1, acumulado);
  
  }

  return 0;
}
