#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
#define sz(a)      (int)((a).size())
#define rep(i,n)   for(int i=0; i<n; ++i)
#define REP(i,j,k) for(int i=j; i<k; ++i)

typedef vector<int> Array;
typedef vector<Array> Mat;

int N, M;
Mat a;
bool result;

bool memo[200][101];

bool desired(Mat &g) {
  rep (i, N) rep (j, M) {
    if (g[i][j] != a[i][j]) return false;
  }
  return true;
}

void dfs(Mat &g) {
  if (desired(g)) {
    result = true;
    return;
  }
  
  // h
  rep (i, N) {
    int m = 0;
    rep (j, M) m = max(m, a[i][j]);
    Array cache = Array(M);
    rep (j, M) {
      cache[j] = g[i][j];
      g[i][j] = min(g[i][j], m);
    }
    if (memo[i][m]) {
      memo[i][m] = false;
      dfs(g);
    }
    rep (j, M) g[i][j] = cache[j];
  }
  
  // v
  rep (j, M) {
    int m = 0;
    rep (i, N) m = max(m, a[i][j]);
    Array cache = Array(N);
    rep (i, N) {
      cache[i] = g[i][j];
      g[i][j] = min(g[i][j], m);
    }
    if (memo[100+j][m]) {
      memo[100+j][m] = false;
      dfs(g);
    }
    rep (i, N) g[i][j] = cache[i];
  }
}

void solve(Mat &g) {
  result = false;
  dfs(g);
  cout << (result ? "YES" : "NO") << endl;
}

void init() {
  a.clear();
  rep (i, 200) rep (j, 101) memo[i][j] = true;
}

int main () {
  int TC = 0;  scanf("%d", &TC);
  rep (tc, TC) {
    printf("Case #%d: ", tc+1);
    init();

    scanf("%d %d", &N, &M);
    a.resize(N, Array(M));
    
    rep (i, N) rep (j, M) scanf("%d", &a[i][j]);

    Mat g(N, Array(M, 100));
    solve(g);
  }
  return 0;
}
