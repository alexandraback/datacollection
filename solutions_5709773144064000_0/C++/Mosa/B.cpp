#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("B-small-attempt0.in", "rt", stdin);
  freopen("out.txt", "wt", stdout);
  int t; scanf("%d", &t);
  for(int tst = 1; tst <= t; ++tst) {
    double c, f, x;
    scanf("%lf %lf %lf", &c, &f, &x);
    double ans = x / 2.0;
    double rate = 2;
    double tt = 0;
    while(rate <= 10 * x) { // zeyadet ta2keed
      tt += c / rate;
      rate += f;
      ans = min(ans, tt + x / rate);
    }
    printf("Case #%d: %.7lf\n", tst, ans);
  }
  return 0;
}
