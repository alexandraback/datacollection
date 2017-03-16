#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <algorithm>

#define N 110000
#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX(x,y) ((x)>(y)?(x):(y))

int a, b;
double p[N];

double pass(int a, int b, double p[])
{
  double r = b+2;
  double ps = 1.0;
  for(int i = 0; i < a; i++) {
    ps *= p[i];
    double rx = ps*(a+b+1-2*(i+1)) + (1.0-ps)*(a+b+1-2*(i+1)+b+1);
    if(rx < r) r = rx;
  }
  return r;
}

int main()
{
  int t;
  scanf("%d", &t);
  for(int idx = 1; idx <= t; idx++) {
    scanf("%d%d", &a, &b);
    for(int i = 0; i < a; i++)
      scanf("%lf", &p[i]);
    printf("Case #%d: %.6lf\n", idx, pass(a,b,p));
  }
  return 0;
}


