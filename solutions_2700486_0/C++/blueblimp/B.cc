#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

#define FR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,n) FR(i,0,n)
#define CLR(x,a) memset(x,a,sizeof(x))
#define setmin(a,b) a = min(a,b)
#define PB push_back
#define FORALL(i,v) for(typeof((v).end())i=(v).begin();i!=(v).end();++i)
#define MP make_pair
#define A first
#define B second
#define RF(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define BEND(v) (v).begin(),(v).end()
#define SZ(v) int((v).size())
#define FORI(i,v) FOR(i,SZ(v))
typedef long double ld;
typedef long long ll;

const int DPMAX = 10001;
double dp[DPMAX][DPMAX];

void init() {
  dp[0][0] = 1;

  FOR(i, DPMAX) FOR(j, DPMAX) {
    if (i+1 < DPMAX) dp[i+1][j] += 0.5 * dp[i][j];
    if (j+1 < DPMAX) dp[i][j+1] += 0.5 * dp[i][j];
  }
}

int N, X, Y;

double calc() {
  int S = abs(X) + Y;
  int L = S / 2;
  int lo = 0, hi = 1;
  FOR(i,L) {
    lo = hi;
    hi += 4*(i+1) + 1;
  }

  if (N <= lo) return 0;
  if (N >= hi) return 1;
  if (X == 0) return 0;
  int delta = N - lo;
  if (delta - S > Y) return 1;

  double ans = 0;
  int i = Y+1;
  int j = delta - i;
  assert(i < DPMAX);
  assert(j < DPMAX);
  while (j >= 0) {
    ans += dp[i][j];
    ++i;
    --j;
  }
  return ans;
}

void doit(int cas) {
  scanf(" %d %d %d", &N, &X, &Y);

  printf("Case #%d: %.7lf\n", cas+1, calc() );
}

int T;
int main() {
  init();
  scanf(" %d", &T);
  FOR(cas,T) doit(cas);
  return 0;
}
