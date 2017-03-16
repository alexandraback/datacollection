#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100000

int main(void) {
  int t=0, a=0, b=0, i=0, j=0, k=0;
  double p[N] = {0};
  double ex=0;
  double s=0;
  double pr=0;

  scanf("%d", &t);
  while (getchar()!='\n');
  for (k=0;k<t;k++) {
    scanf("%d %d", &a, &b);
    s=b+2;
    pr=1;
    p[0]=1.0;
    for (j=0;j<a;j++) scanf("%lf", p+j+1);
    for (j=0;j<a+1;j++) {
      pr*=p[j];
      ex=a+b+1-2*j+(b+1)*(1-pr);
      if (s>ex) s=ex;
      //printf("%lf ", ex);
    }
    printf("Case #%d: %lf\n", k+1, s);
  }
  return 0;
}
