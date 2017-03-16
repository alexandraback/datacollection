#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <string>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <ctime>

#define FOR(i, m, n) for (int i=m; i<n; i++)
typedef long long ll;

using namespace std;

int N, M, W, H;
int deg[1200];
vector<int> graf[1200];
int cesta[1200];

bool dfs(int i) {
  FOR (j, 0, graf[i].size()) {
    if (cesta[graf[i][j]]==1) return true;
    cesta[graf[i][j]] = 1;
    if (dfs(graf[i][j])) return true;
  }
  return false;
}

void solve() {
  scanf("%d", &N);
  FOR (i, 1, N+1) {
    graf[i].clear(); deg[i] = 0;
  }
  FOR (i, 1, N+1) {
    scanf("%d", &M);
    FOR (j, 0, M) {
      int x; scanf("%d", &x);
      deg[x]++;
      graf[i].push_back(x);
    }
  }
  bool ret = false;
  FOR (i, 1, N+1) {
    if (deg[i]==0) {
      FOR (j, 0, N+1) cesta[j] = 0;
      cesta[i] = 1;
      if (dfs(i)) {
        ret = true; break;
      }
    }
  }
  if (ret) printf("Yes\n");
  else printf("No\n");
}

int main()
{
  int t; scanf("%d", &t);
  FOR (i, 0, t) {
    printf("Case #%d: ", i+1);
    solve();
  }
  return 0;
}
