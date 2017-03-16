#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

bool test(double c, double f, double x, double T) {
  double t = 0, rate = 2;
  while (t < T) {
    double next = t + c/rate;
    double no_buying = rate*(T-t);
    double buying = (T-next)*(rate + f);
    if (next >= T || no_buying > buying || no_buying >= x) return no_buying >= x; 
    t = next, rate += f;
  }
  return false;
}

int main(void) {
  int T;
  scanf("%d", &T);
  for (int tp = 1; tp <= T; ++tp) {
    double c, f, x;
    scanf("%lf %lf %lf", &c, &f, &x);
    
    double lo = 0, hi = 1e6;
    REP(it, 100) {
      double mid = (lo + hi)/2;
      if (test(c, f, x, mid)) hi = mid; else
        lo = mid;
    }

    printf("Case #%d: ", tp);
    printf("%.7lf\n", lo);
  }
  return 0;
}
