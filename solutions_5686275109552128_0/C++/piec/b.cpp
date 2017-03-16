#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <queue>
#include <bitset>
#include <utility>
#include <stack>

using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
#define MP make_pair
#define FOR(v,p,k) for(int v=(p);v<=(k);++v)
#define FORD(v,p,k) for(int v=(p);v>=(k);--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()

#define ODD(x) ((x)%2)
#define EVEN(x) (!(ODD(x)))

#define N 1000
#define INF 10000009

int main() {
  vector<VI> dyn(N+1, VI(N+1));

  FOR(j,1,N) dyn[0][j]=INF;

  FOR(i,1,N) FOR(j,2,N) {
    int best = dyn[i-1][j-1];
    FOR(k,1,j/2) best = min(best, dyn[i][k] + dyn[i][j-k] + 1);
    dyn[i][j] = best; 
  }

  int T;
  scanf("%d", &T);

  VI pan;
  pan.reserve(N);
  FOR(Ti,1,T) {
    int D;
    scanf("%d", &D);
    pan.clear();
    REP(i,D) {
      int i;
      scanf("%d", &i);
      pan.PB(i);
    }
    sort(ALL(pan));

    int res = INF;
    FOR(i,1,N) {
      int new_res = i;
      FOREACH(p, pan) new_res+=dyn[i][*p];
      res = min(res, new_res);
    }
    printf("Case #%d: %d\n", Ti, res);
  }
  return 0;
}

