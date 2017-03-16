#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAXN = 110;
LL a, b[MAXN];

int main() {
  int T, n;
  scanf("%d", &T);
  for (int ca = 1 ; ca <= T ; ++ca) {
    scanf("%lld%d",&a,&n);
    for (int i = 0 ; i< n ; ++i)
      scanf("%lld",&b[i]);
    if (a == 1) {
      printf("Case #%d: %d\n", ca, n);
      continue;
    }
    sort(b, b+n);
    LL best = n, cur = 0;
    for (int i = 0 ; i < n ; ++i) {
      if (cur + n - i < best) best = cur + n - i;
      if (a > b[i]) {a += b[i]; continue;}
      else {
        while (a <= b[i]) {
          a += a - 1;
          ++cur;
        }
        a += b[i];
      }
    }
    if (cur < best) best = cur;
    printf("Case #%d: %lld\n", ca, best);
  }
  return 0;
}

