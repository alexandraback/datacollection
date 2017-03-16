#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
#define VAR(a,b) __typeof(b) a=(b)
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define ALL(c) (c).begin(),(c).end()
#define STRING(x) #x
#define PING cerr << "(" << __LINE__ << "): " << __FUNCTION__ << endl
#define PRINT(x) cerr << STRING(x) << " = " << (x) << endl

typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000; const LL INFLL = LL(INF) * LL(INF);
template<class T> inline int size(const T&c) { return c.size(); }

int paths[1001][1001];

int main() {
  int T;
  scanf("%d\n", &T);
  FOR(c, 1, T) {
    bool res = false;
    memset(paths, 0, sizeof(paths));
    int N;
    scanf("%d\n", &N);
    REP(i, N) {
      int M;
      scanf("%d", &M);
      REP(j, M) {
        int cl;
        scanf("%d", &cl);
        paths[i][cl - 1] = 1;
      }
    }
    REP(k, N) REP(i, N) REP(j, N) {
      paths[i][j] += paths[i][k] * paths[k][j];
      if (paths[i][j] > 1) {
        res = true;
      }
    }
    /*REP(i, N) {
      REP(j, N) cout << paths[i][j] << " ";
      cout << endl;
    }*/
    printf("Case #%d: %s\n", c, res? "Yes" : "No");
  }
  return 0;
}


