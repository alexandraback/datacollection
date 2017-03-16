#include <cstdio>
using namespace std;

int t;
double time, d, c, f, x, min, ans;

bool Opt() {
  time += c/d;
  d += f;
  ans = time+x/d;
  return 1;
}

int main()
{
  freopen("in", "r" ,stdin);
  freopen("out", "w", stdout);
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    scanf("%lf%lf%lf", &c, &f, &x);
    time = 0.0;
    d = 2.0;
    min = x/d;
    while (Opt() && ans<min) min = ans;
    printf("Case #%d: %.7lf\n", i, min);
  }
}
