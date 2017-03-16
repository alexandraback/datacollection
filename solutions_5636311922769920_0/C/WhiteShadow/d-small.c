#include <stdio.h>

int main() {
  long long n, i, j, k, c, s, step, aux;

  scanf("%lld", &n);
  for (i=1; i<=n; i++) {
    scanf("%lld %lld %lld", &k, &c, &s);        
    printf("Case #%lld:", i);
    for (j=step=1; j<c; j++) step = step * k + 1;
    for (j=aux=1; j<=k; j++, aux += step)
      printf(" %lld", aux);
    putchar('\n');
  }
   
  return 0;
}
  
