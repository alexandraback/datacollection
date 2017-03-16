#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

#define f(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n)  f(i, 0, n)

const int N = 1005;
int size[N], adj[N][N];
int dp[N][N];

int solve(int a, int b) {
  if(a == b) return 1;
  int &d = dp[a][b];
  if(d != -1) return d;
  int res = 0;
  rep(i, size[a]) {
    res += solve(adj[a][i], b);
    if(res > 1) break;
  }
  return d = res;
}

int main(){
  int T; scanf("%d", &T); for(int test = 1; test <= T; test++) {
    printf("Case #%d: ", test);
    int n; scanf("%d", &n);
    rep(i, n) {
      scanf("%d", &size[i]);
      rep(j, size[i]) {
        scanf("%d", &adj[i][j]);
        adj[i][j]--;
      }
    }

    memset(dp, -1, sizeof(dp));
    int res = 0;
    rep(i, n) rep(j, n) if(i != j) {
      if(solve(i, j) > 1) {
        res = 1;
        break;
      }
    }

    printf("%s\n", res ? "Yes" : "No");
  }
}
