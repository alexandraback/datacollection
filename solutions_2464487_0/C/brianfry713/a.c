#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

int main() {
  int tc, cn, i;
  long long r, t;
  scanf("%d", &tc);
  for(cn = 1; cn <= tc; cn++) {
    scanf("%lld%lld", &r, &t);
    for(i = 0; (r + 1) * (r + 1) - r * r <= t; i++, r += 2)
      t -= (r + 1) * (r + 1) - r * r;
    printf("Case #%d: %d\n", cn, i);
  }
  return 0;
}
