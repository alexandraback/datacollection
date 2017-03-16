#include <cstdio>
#include <cassert>
#include <algorithm>

void Work() {
  double c, f, x;
  assert(scanf("%lf%lf%lf", &c, &f, &x) == 3);
  double rate = 2.0;
  double ans = x / rate;
  double time_cost = 0.0;
  for (int farm = 1; time_cost < ans; ++farm) {
    time_cost += c / rate;
    rate += f;
    ans = std::min(ans, time_cost + x / rate);
  }
  printf("%.7lf\n", ans);
}

int main() {
  int cases;
  assert(scanf("%d", &cases) == 1);
  for (int i = 1; i <= cases; ++i) {
    printf("Case #%d: ", i);
    Work();
  }
  return 0;
}
