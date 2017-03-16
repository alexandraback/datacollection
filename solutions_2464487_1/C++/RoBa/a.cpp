#include <cstdio>
#include <cmath>
using namespace std;

typedef long long LL;
LL r, t;

int check(LL n) {
  return 2 * n * n + (2 * r - 1) * n - t <= 0;
}

int main() {
  int T, ca;
  scanf("%d",&T);
  for (ca = 1 ; ca <= T ; ++ca) {
    scanf("%lld%lld",&r,&t);
    LL ans = (LL)(((1 - 2.0 * r) + sqrt((2.0*r-1.0) * (2.0*r-1) + 8.0*t)) / 4.0);
    LL final;
    for (LL tmp = ans - 5 ; tmp <= ans + 5 ; ++tmp) {
      if (check(tmp)) final = tmp;
    }
    printf("Case #%d: %lld\n",ca, final);
  }
  return 0;
}

