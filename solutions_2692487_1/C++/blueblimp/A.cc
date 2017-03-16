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

const int inf = 1000000;
int A, N;
void doit(int cas) {
  scanf(" %d %d", &A, &N);
  
  vector<int> motes;
  FOR(i,N) {
    int mote;
    scanf(" %d", &mote);
    motes.push_back(mote);
  }
  sort( BEND(motes) );

  int ans = N;
  int cur = 0;
  for (int next = 0; next < N; ++next) {
    while ( A <= motes[next] ) {
      if (A == 1) goto done;
      A += A-1;
      ++cur;
    }

    ans = min(ans, cur + N - next - 1);
    A += motes[next];
  }

done:
  printf("Case #%d: %d\n", cas+1, ans);
}

int T;
int main() {
  scanf(" %d", &T);
  FOR(cas,T) doit(cas);
  return 0;
}
