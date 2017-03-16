#include <bits/stdc++.h>

using namespace std;
const int INF = 10001000;

typedef long long L;

int main()
{
  freopen("IN.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  
  int t;
  scanf("%d", &t);
  
  for(int tt = 1; tt <= t; ++tt) {
    int n; L m;
    scanf("%d %lld", &n, &m);
    
    vector < vector <int> > mat(n, vector <int>(n, 0));
    if(m > (1LL << (n - 1))) {
      printf("Case #%d: IMPOSSIBLE\n", tt);
      continue;
    }
    m--;
    for(int i = 1; i < n - 1; ++i) {
      for(int j = i + 1; j < n; ++j) {
        mat[i][j] = 1;
      }
    }
    
    for(int j = 1; j < n - 1; ++j) {
      int k = n - j - 2;
      if(m >= (1LL << k)) {
        m -= (1LL << k);
        mat[0][j] = 1;
      }
    }
    if(m != 0) {
      printf("Case #%d: IMPOSSIBLE\n", tt);
      continue;
    }
    mat[0][n - 1] = 1;
    printf("Case #%d: POSSIBLE\n", tt);
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        printf("%d", mat[i][j]);
      }
      printf("\n");
    }
  }
  return(0);
}
