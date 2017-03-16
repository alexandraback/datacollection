#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ALL(c) (c).begin(), (c).end()

vector<int> G[1010];
bool visited[1010];

bool dfs(int p) {
  if(visited[p]) return true;
  visited[p] = true;
  bool res = false;
  FOR(n, G[p]) {
    res |= dfs(*n);
    if(res) break;
  }
  return res;
}

int main() {

  int T;
  scanf("%d", &T);

  REP(tc, T) {

    int N;
    scanf("%d", &N);

    REP(i, N) G[i].clear();

    REP(i, N) {
      int M;
      scanf("%d", &M);

      REP(j, M) {
        int kls;
        scanf("%d", &kls);
        kls--;
        G[kls].push_back(i);
      }
    }    

    bool res = false;
    REP(i, N) {
      memset(visited, 0, sizeof(visited));
      res |= dfs(i);
    }

    printf("Case #%d: %s\n", tc + 1, res ? "Yes" : "No");
  }

  return 0;
}
