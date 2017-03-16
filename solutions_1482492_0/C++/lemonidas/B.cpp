#include <cstdio>
#include <cmath>

long double accs[250];

int main () {
  int t;
  scanf("%d", &t);
  for (int c = 1; c <= t; c++) {
    long double d;
    int n,a;
    scanf("%Lf %d %d", &d, &n, &a);
    long double x0,t0,t1,x1;
    scanf("%Lf %Lf", &t0, &x0);
    if (n > 1) scanf("%Lf %Lf", &t1, &x1);
    for (int i = 0; i<a; i++){
      scanf("%Lf", &accs[i]);
    }
    printf("Case #%d:\n", c);
    for (int i = 0; i<a; i++){
      if (n==1) {
        printf("%Lf\n", (long double) sqrt(2 * d / accs[i]));
      }
      else {
        long double v,t,dt,dr,tr;
        v = (x1 - x0) / (t1 - t0);
        t = (v + sqrt (v * v + 2 * accs[i] * x0)) / accs[i];
        dt = 0.5 * accs[i] * t * t;
        if (dt >= d) {
          printf("%Lf\n", (long double) sqrt(2 * d / accs[i]));
        }
        else {
          dr = d - dt;
          tr = dr / v;
          printf("%Lf\n", (long double) t + tr);
        }
      }
    }
  }
  return 0;
}

     
