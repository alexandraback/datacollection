#include <bits/stdc++.h>

using namespace std;
const int INF = 10001000;

int dp[10];

int solve(int s, int d, vector < vector <int> > & mat) {
  if(dp[s] != -1) return dp[s];
  int n = mat.size();
  
  int& res = dp[s];
  res = 0;
  if(s == d) return res = 1;
  for(int j = 0; j < n; ++j) {
    if(mat[s][j]) {
      res += solve(j, d, mat);
    }
  }
  
  return res;
}

int getPaths(vector <vector <int>>& mat) {
  int n = mat.size();
  
  memset(dp, -1, sizeof(dp));
  return solve(0, n - 1, mat);
}

int main()
{
  freopen("IN.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  
  int t;
  scanf("%d", &t);
  
  for(int tt = 1; tt <= t; ++tt) {
    int n, m;
    scanf("%d %d", &n, &m);
    int f = (n * (n - 1)) / 2;
    int tot = (1 << f);
    
    printf("Case #%d:", tt);
    bool got = false;
    
    for(int mask = 0; mask < tot; ++mask) {
      vector < vector <int> > mat(n, vector <int> (n, 0));
      bool good = true;
      
      for(int k = 0, i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; j++, k++) {
          if(mask & (1 << k)) {
            if(i == n - 1) {
              good = false;
              break;
            }
            mat[i][j] = 1;
          }
        }
      }
      if(!good) continue;
      int res = getPaths(mat);
      if(res == m) {
        got = true;
        printf(" POSSIBLE\n");
        for(int i = 0; i < n; ++i) {
          for(int j = 0; j < n; ++j) {
            printf("%d", mat[i][j]);
          }
          printf("\n");
        }
        break;
      }
    }
    
    if(!got) {
      printf(" IMPOSSIBLE\n");
    }
  }
  return(0);
}
