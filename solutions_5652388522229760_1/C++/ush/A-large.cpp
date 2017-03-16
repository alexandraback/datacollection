
#include <cassert>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
using namespace std;
typedef long long ll;

char buf[10000];
int main(void) {
  int nCase;
  scanf("%d", &nCase);
  REP(iCase, nCase) {
    int n;
    scanf("%d", &n);
    ll v = 0;
    int b = 0;
    ll res = -1;
    REP(i, 1000000) {
      v += n;
      ll k = v;
      while(k > 0){
        int d = k % 10;
        k /= 10;
        b |= 1 << d;
        if(b == (1 << 10)-1) {
          res = v;
          goto OUT;
        }
      }
    }
  OUT:
    if(res < 0) {
      printf("Case #%d: INSOMNIA\n", iCase+1);
    } else {
      printf("Case #%d: %lld\n", iCase+1, res);
    }
  }
  return 0;
}
