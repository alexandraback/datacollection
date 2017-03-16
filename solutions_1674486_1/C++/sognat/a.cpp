#define DEBUG 0
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
const int INF = 2000000001;
#define FOR(x,b,e) for(int x=(b);x<=(e);++x)
#define FORD(x,b,e) for(int x=(b);x>=(e);--x)
#define REP(x,n) for(int x=0;x<(n);++x)
#define ALL(c) c.begin(),c.end()
#define VAR(x,c) __typeof(c) x=(c)
#define FOREACH(x,c) for(VAR(x,(c).begin());x!=(c).end();++x)
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
#define dbg(...) \
  do { if (DEBUG) fprintf(stderr, __VA_ARGS__); } while (0)

const int MAXN = 1000;

int N;
bool flag;
VI G[MAXN+1];
bool vis[MAXN+1];

void clear() { 
  REP(i,N) {
    vis[i] = 0;
  }
}

void DFS(int v) {
  vis[v] = 1;
  FOREACH (x,G[v]) {
    if (vis[*x]) { flag = true; }
    else { DFS(*x); }
  }
}

int main() {
  int Z;
  scanf("%d", &Z);
  for (int T = 1; T <= Z; T++) {

    scanf("%d", &N);
    int E,b;

    REP (i,N) {
      G[i].clear();
      scanf("%d", &E);
      REP (j,E) {
        scanf("%d", &b);
        G[i].PB(b-1);
      }
    }

    REP (i,N) {
      dbg("G[%d]: ", i);
      FOREACH (x,G[i]) {
        dbg("%d, ", *x);
      }
      dbg("\n");
    }

    flag = false;

    REP (i,N) {
      clear();
      DFS(i);
      if (flag) break;
    }

    if (flag) {
      printf("Case #%d: Yes\n", T);
    } else {
      printf("Case #%d: No\n", T);
    }
  }
  return 0;
}
