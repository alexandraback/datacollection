#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <valarray>
#include <vector>
#include <ext/algorithm>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/numeric>
using namespace std;
using namespace __gnu_cxx;

#define F(i,a,b)for(int i=a;i<b;++i)
#define rep(i,n)F(i,0,n)
#define all(a)a.begin(),a.end()
template<class T>vector<T>&operator<<(vector<T>& v,T t){v.push_back(t);return v;} 

// don't forget about the case where you have to drag your kayak
// through the entire maze after the water has fallen

int T;
int H;
int N;
int M;
int C[101][101];
int F[101][101];
//               v----------------------------x
//                    v-----------------------y
//                         v------------------t (tenths of seconds)
unsigned char dp[101][101][100001];

bool ok(int waterlevel, int oldx, int oldy, int newx, int newy) {
  if (newx < 0 || newx >= M) return false;
  if (newy < 0 || newy >= N) return false;
  int oldf = max(waterlevel, F[oldx][oldy]);
  int oldc = C[oldx][oldy];
  int newf = max(waterlevel, F[newx][newy]);
  int newc = C[newx][newy];
  if (newc - oldf < 50) return false;
  if (newc - newf < 50) return false;
  if (oldc - newf < 50) return false;
  /*
  printf("Going from %d,%d to %d,%d\n", oldx, oldy, newx, newy);
  printf("OK\n");
  */
  return true;
}

void dfs(int startx, int starty, int newt);

inline void okDfs(int newt, int waterlevel, int oldx, int oldy, int newx, int newy) {
  if (newt > H * 10 + 10000) return;
  if (ok(waterlevel, oldx, oldy, newx, newy)) dfs(newx, newy, newt);
}

// mark all starting from startx, starty
void dfs(int startx, int starty, int newt) {
  if (dp[startx][starty][newt]) return;
  int waterlevel = H - newt;
  int cost = ((waterlevel - F[startx][starty]) >= 20) ? 10 : 100;
  if (newt == 0) cost = 0;

  dp[startx][starty][newt] = 1;
  if (newt <= H * 10 + 10000) {
    dfs(startx, starty, newt + 1);
  }
  okDfs(newt + cost, waterlevel, startx, starty, startx - 1, starty);
  okDfs(newt + cost, waterlevel, startx, starty, startx + 1, starty);
  okDfs(newt + cost, waterlevel, startx, starty, startx, starty - 1);
  okDfs(newt + cost, waterlevel, startx, starty, startx, starty + 1);
}

int main() {
  cin >> T;
  rep(t, T) {
    printf("Case #%d: ", t+1);
    memset(dp, 0, sizeof(dp));
    cin >> H >> N >> M;
    rep(i, N) rep(j, M) cin >> C[j][i];
    rep(i, N) rep(j, M) cin >> F[j][i];
    dfs(0, 0, 0);
    rep(i,10 * H + 10000) {
      if (dp[M-1][N-1][i]) {
        printf("%d.%d\n", i / 10, i % 10);
        break;
      }
    }
  }
}
