// C++ 11
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int main() {
  int T; scanf("%d", &T);
  for(int ti = 0; ti < T; ++ti) {
    int N; scanf("%d", &N);
    vector<int> F(N);
    vector<vector<int>> p(N);
    for(int i = 0; i < N; ++i) {
      scanf("%d", &F[i]); --F[i];
      p[F[i]].push_back(i);
    }
    function<int(int)> dfs2 = [&](int v) {
      int mv = 0;
      for(int w : p[v]) {
        if(w != F[v]) mv = max(mv, dfs2(w) + 1);
      }
      return mv;
    };
    int propeller_sum = 0;
    int maxcycle = 0;
    static int vis[1000]; fill(vis, vis+N, -2);
    function<void(int, int)> dfs = [&](int v, int depth) {
      if(vis[v] >= 0) {
        maxcycle = max(maxcycle, depth - vis[v]);
        if(depth - vis[v] == 2) {
          propeller_sum += dfs2(v) + dfs2(F[v]) + 2;
        }
      } else if(vis[v] == -2) {
        vis[v] = depth;
        dfs(F[v], depth + 1);
        vis[v] = -1;
      }
    };
    for(int i = 0; i < N; ++i) dfs(i, 0);
    printf("Case #%d: %d\n", ti+1, max(maxcycle, propeller_sum));
  }
  return 0;
}

