//AC small

#define DEBUG 0

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

long long E, R, N, best, v[10000], mxn[10000];

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
  int tc, cn, i, j;
  long long e;
  scanf("%d", &tc);
  for(cn = 1; cn <= tc; cn++) {
    scanf("%lld%lld%lld", &E, &R, &N);
    for(i = 0; i < N; i++)
      scanf("%lld", &v[i]);
    for(i = N - 1; i >= 0; i--)
      for(mxn[i] = 0, j = i + 1; j < N; j++)
        mxn[i] = max(mxn[i], v[j]);
    best = 0;
    e = E;
    for(i = 0; i < N; i++, e += R)
      if(v[i] >= mxn[i]) {
        best += e * v[i];
        e = 0;
      } else if(e + R > E) {
        int tmp = e + R - E;
        best += tmp * v[i];
        e = E - R;
      }

    printf("Case #%d: %lld\n", cn, best);
  }
  return 0;
}
