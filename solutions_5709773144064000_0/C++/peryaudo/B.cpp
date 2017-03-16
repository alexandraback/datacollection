#include <cstdio>
#include <algorithm>

using namespace std;
 
double F(double c, double f, double x) {
  double res = x / 2.0;
  double cur = 0.0;
  double cur_cps = 2.0;
  // verified for maximum case F(1, 100, 100000)
  for (int i = 0; i < (1 << 24); ++i) {
    cur += c / cur_cps;
    cur_cps += f;
    res = min(res, cur + x / cur_cps);
  }
  return res;
}

int main() {
  int t;
  scanf("%d\n", &t);
  for (int i = 0; i < t; ++i) {
    double c, f, x;
    scanf("%lf %lf %lf\n", &c, &f, &x);
    double res = F(c, f, x);

    printf("Case #%d: %.7lf\n", i + 1, res);
  }
  return 0;
}
