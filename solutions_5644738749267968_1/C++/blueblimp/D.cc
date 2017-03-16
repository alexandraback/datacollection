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

typedef pair<double, int> pdi;

int N;


void doit(int cas)
{
  scanf(" %d", &N);
  assert(1 <= N && N <= 1000);

  vector<pdi> events;
  double x;
  FOR(i, N) {
    scanf(" %lf", &x);
    events.push_back( make_pair(x, 1) );
  }
  FOR(i, N) {
    scanf(" %lf", &x);
    events.push_back( make_pair(x, -1) );
  }
  sort( BEND(events) );
  reverse( BEND(events) );

  int dwar = N;
  int war = 0;
  int cur = 0;
  for (auto it = events.begin(); it != events.end(); ++it) {
    cur += it->second;
    war = max(war, cur);
    dwar = min(dwar, N + cur);
  }

  printf("Case #%d: %d %d\n", cas, dwar, war);
}

int T;
int main() {
  scanf(" %d", &T);
  assert(1 <= T && T <= 50);
  FOR(cas,T) doit(cas+1);
  return 0;
}
