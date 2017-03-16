#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define SZ(a) (int)(a).size()
#define FOR(i,a,b) for (int i=(a); i<=(b); ++i)
#define REP(i,n) for (int i=0; i<(n); ++i)
#define ALL(c) c.begin(), c.end()
typedef vector<int> VI;
typedef pair<int, int> PII;
#define CLR(c,n) memset(c,n,sizeof(c))
template <class T> void checkmin(T &a, T b) { if (b<a) a=b; }
template <class T> void checkmax(T &a, T b) { if (b>a) a=b; }
#define TR(it, container) for(typeof(container.begin()) it = container.begin();\
it != container.end(); it++)
#define CONTAIN(it, container) (container.find(it)!=container.end())

long a, b, k;
long dp[32][2][2][2];
long go(int bit, int ea, int eb, int ek) {
  if (bit < 0) return 1;
  long &ans = dp[bit][ea][eb][ek];
  if (ans != -1) return ans;
  ans = 0;
  int bita = (a >> bit) & 1, bitb = (b >> bit) & 1, bitk = (k >> bit) & 1;
  REP(ia, 2) REP(ib, 2) {
    int ik = ia & ib;
    if (ea && ia > bita) continue;
    if (eb && ib > bitb) continue;
    if (ek && ik > bitk) continue;
    ans += go(bit-1, ea && ia == bita, eb && ib == bitb, ek && ik == bitk);
  }
  return ans;
}
int main(int argc, char *argv[]) {
  int tc; cin >> tc;
  FOR(ic, 1, tc) {
    cin >> a >> b >> k;
    --a; --b; --k;
    memset(dp, -1, sizeof(dp));
    printf("Case #%d: %ld\n", ic, go(31, 1, 1, 1));
  }
}
