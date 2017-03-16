#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int tc; scanf("%d", &tc);
  for(int tci = 0; tci < tc; tci++) {
    int a,b; scanf("%d%d", &a, &b);
    double minval = b+2;
    double val = a+b+1;
    double prob = 1.0;
    for(int i = 0; ; i++) {
      minval = min(minval, val);
      if(i >= a) break;
      double p; scanf("%lf", &p);
      val = val - 2 + prob*(1-p)*(b+1);
      prob *= p;
    }
    printf("Case #%d: %.6f\n", tci+1, minval);
  }
  return 0;
}
