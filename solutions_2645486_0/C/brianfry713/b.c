#define DEBUG 0

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

long long E, R, N, best, v[10000];

void f(int pos, long long cur, long long e) {
  if(DEBUG) printf("pos = %d, cur = %lld, e = %lld\n", pos, cur, e);
  if(pos == N) {
    best = max(best, cur);
    return;
  }
  for(int i = 0; i <= e; i++)
    f(pos + 1, cur + v[pos] * i, min(E, e - i + R));
}

int main() {
  int tc, cn, i;
  scanf("%d", &tc);
  for(cn = 1; cn <= tc; cn++) {
    scanf("%lld%lld%lld", &E, &R, &N);
    for(i = 0; i < N; i++)
      scanf("%lld", &v[i]);
    best = 0;
    f(0, 0, E);
    printf("Case #%d: %lld\n", cn, best);
  }
  return 0;
}
