#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
  int tt; scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    int a, b;
    scanf("%d %d", &a, &b);
    vector<double> p(a);
    for (int i = 0; i < a; ++i)
      scanf("%lf", &p[i]);
      
    double ans = b + 2;
    double s = 1.0;
    for (int i = 0; i <= a; ++i) {
      double e = 2 * (a - i) + b - a + 1 + (1 - s) * (b + 1);
      if (e < ans)
        ans = e;
      if (i < a)
        s *= p[i];
    }
    printf("Case #%d: %0.7lf\n", tc, ans);
  }
  return 0;
}
