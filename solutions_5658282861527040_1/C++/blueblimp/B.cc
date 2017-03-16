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

//#define dlog printf
#define dlog(...)

const int TOP = 40;

ll A,B,K;
ll dp[TOP][2][2][2]; // [remaining][eqa][eqb][eqk]

void doit(int cas)
{
  assert( sizeof(ll) == 8 );
  scanf(" %lld %lld %lld", &A, &B, &K);
  assert(1 <= A && A <= 1000000000);
  assert(1 <= B && B <= 1000000000);
  assert(1 <= K && K <= 1000000000);

  memset(dp, 0, sizeof(dp));
  dp[0][0][0][0] = 1LL;
  FR(r,1,TOP) FOR(eqa,2) FOR(eqb,2) FOR(eqk,2) {
    FOR(a,2) FOR(b,2) {
      int k = a & b;
      int p = r-1;
      int da = !!( (1LL<<p) & A );
      int db = !!( (1LL<<p) & B );
      int dk = !!( (1LL<<p) & K );
      if (eqa && a && !da) continue;
      if (eqb && b && !db) continue;
      if (eqk && k && !dk) continue;
      int next_eqa = eqa && a == da;
      int next_eqb = eqb && b == db;
      int next_eqk = eqk && k == dk;
      dlog("%d %d %d %d %d %d %d %d\n",
        k, p, da, db, dk, next_eqa, next_eqb, next_eqk);

      dp[r][eqa][eqb][eqk] += dp[r-1][next_eqa][next_eqb][next_eqk];
    }
    dlog("dp[%d][%d][%d][%d] = %lld\n", r, eqa, eqb, eqk,
      dp[r][eqa][eqb][eqk]);
  }

  printf("Case #%d: %lld\n", cas, dp[TOP-1][1][1][1]);
}

int T;
int main() {
  scanf(" %d", &T);
  assert(1 <= T && T <= 100);
  FOR(cas,T) doit(cas+1);
  return 0;
}
