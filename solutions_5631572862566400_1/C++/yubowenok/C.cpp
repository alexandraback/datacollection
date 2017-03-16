#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <ctime>
#include <cassert>
#include <functional>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 1005

int N, g[MAXN], TRAV, MAXD, deg[MAXN];
VI rg[MAXN];
bool v[MAXN];
void dfs(int x, int d) {
  v[x] = 1;
  MAXD = max(MAXD, d);
  TRAV++;

  int sz = rg[x].size();
  REP(i,0,sz) {
    int y = rg[x][i];
    if (v[y]) continue;
    dfs(y, d + 1);
  }
}
int run(int x, int ban) {
  FILL(v,0); MAXD = 0;
  v[ban] = 1;
  dfs(x, 0);
  return MAXD;
}
int main() {
  freopen("input", "r", stdin);
  //freopen("output", "w", stdout);
  int cs;
  cin >> cs;
  REP(csn, 1, cs + 1) {
    printf("Case #%d: ", csn);
    //cerr << csn << endl;
    cin >> N;
    REP(i,1,N+1) rg[i].clear();
    FILL(deg, 0);
    REP(i,1,N+1) {
      cin >> g[i];
      deg[g[i]]++;
      rg[g[i]].push_back(i);
    }
    queue<int> q;
    REP(i,1,N+1) {
      if (!deg[i]) q.push(i);
    }
    FILL(v, 0);
    while(!q.empty()) {
      int x = q.front(); q.pop();
      v[x] = 1;
      deg[g[x]]--;
      if(deg[g[x]] == 0) q.push(g[x]);
    }
    int comp = 0;
    REP(i,1,N+1) {
      if (!v[i]) {
        TRAV = 0;
        dfs(i, 0);
        comp = max(comp, TRAV);
      }
    }
    int solcomp = 0;
    REP(i,1,N+1){
      REP(j,i+1,N+1) {
        if (g[i]==j && g[j]==i) {
          int d1 = run(i, j);
          int d2 = run(j, i);
          solcomp += d1 + d2 + 2;
        }
      }
    }
    cout << max(comp, solcomp) << endl;
  }
  return 0;
}
