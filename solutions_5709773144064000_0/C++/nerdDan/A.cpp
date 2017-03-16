#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>

using namespace std;

inline double square(double x) { return x*x; }

double C, F, X;

double f(int x) {
  if(x<0)
    return INFINITY;
  double res = 0;
  for(int i = 0; i < x; i++)
    res += 1/(2+i*F);
  res *= C;
  res += X/(2+F*x);
  return res;
}

int main() {
  int nCase;
  scanf("%d", &nCase);
  for(int iCase = 1; iCase <= nCase; iCase++) {
    printf("Case #%d: ", iCase);
    scanf("%lf%lf%lf", &C, &F, &X);
    int a = 0, b = 100;
    while(1) {
      double x = f(a-b), y = f(a), z = f(a+b);
      if(x>y && y>z)
        a += b;
      else if(x<y && y<z)
        a -= b;
      else if(b != 1)
        b >>= 1;
      else
        break;
    }
    printf("%.7lf\n", f(a));
  }
  return 0;
}
