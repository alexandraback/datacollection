#include <cstdio>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
  int T;
  double c, f, x;
  scanf("%d", &T);
  for (int t=1; t<=T; t++) {
    scanf("%lf %lf %lf", &c, &f, &x);
    printf("Case #%d: ", t);
    double res = numeric_limits<double>::max();
    double val = 0;
    for (int n=0; ; n++) {
      if (n > 0)
        val += c/(2.0+(n-1)*f);
      if (res > (val + x/(2+n*f)))
        res = val + x/(2+n*f);
      else
        break;
      //printf("%d: %.7f\n", n, val);
    }
    printf("%.7f\n", res);
  }
  return 0;
}
