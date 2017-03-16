// by tmt514
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
using namespace std;
typedef long long LL;

void solve() {
  static int cs=0;
  ++cs;
  printf("Case #%d:", cs);
  fprintf(stderr, "Case #%d:", cs);

  int K, C, S;
  scanf("%d%d%d", &K, &C, &S);
  if (K > C * S) {
    printf(" IMPOSSIBLE\n");
    fprintf(stderr, " IMPOSSIBLE\n");
    return;
  }

  for(int i=0;i<K;i+=C) {
    long long v = 0;
    for(int j=0;j<C && i+j<K;j++) {
      v = v * K + (i+j);
    }
    printf(" %lld", v+1);
    fprintf(stderr, " %lld", v+1);
  }
  printf("\n");
  fprintf(stderr, "\n");
}

int main(void) {
  int T;
  scanf("%d", &T);
  while(T--) solve();
  return 0;
}
