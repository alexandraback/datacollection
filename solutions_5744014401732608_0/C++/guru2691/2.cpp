#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int path[6][6];
bool f = false;
int b,m;
int findways() {
    int dp[8];
    memset(dp,0,sizeof(dp));
    dp[b-1] = 1;
    for (int i = b - 2; i >= 0; i--) {
        for (int j = 0; j < b; j++) {
            if (path[i][j])
                dp[i] += dp[j];
        }
    }
    return dp[0];
}
int dfs(int i, int j) {
  //cout << i << " " << j << endl;
  if (i+1 == b) {
      if (findways() == m) {
          f = 1;
          return 1;
      }
      return 0;
  }
  if (j+1 == b) {
      if (dfs(i+1,i+2)) {
          return 1;
      } else {
          path[i][j] = 1;
          if(dfs(i+1,i+2)) {
              return 1;
          }
          path[i][j] = 0;
          return 0;
      }
  } else {
      if (dfs(i,j+1)) {
          return 1;
      } else {
          path[i][j] = 1;
          if(dfs(i,j+1)) {
              return 1;
          }
          path[i][j] = 0;
          return 0;
      }
  }
  return 0;
}
int main() {
        
  ios::sync_with_stdio(false);

  int t; cin >> t;
  int ca = 0;
  while (t--) {
      ca++;
      cout << "Case #" << ca << ": ";
      cin >> b >> m;
      memset(path,0,sizeof(path));
      f = false;
      dfs(0,1);
      if (f) {
          cout << "POSSIBLE" << '\n';
          for (int i = 0; i < b; i++) {
              for (int j = 0; j < b; j++) {
                  cout << path[i][j];
              }
              cout << '\n';
          }
      } else {
          cout << "IMPOSSIBLE" << '\n';
      }

  }
    
    return 0;
        
}