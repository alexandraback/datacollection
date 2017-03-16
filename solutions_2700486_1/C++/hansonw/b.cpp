#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

const int MAX = 4000;
double dp[MAX+1][MAX+1];

int main()
{
  int T; cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    int N, X, Y; cin >> N >> X >> Y;
    int cp = 1, cc = 1, cn = 0, lp = 1;
    while (cp < N) {
      cp += (cc+1) + (cc+2);
      if (cp <= N) lp = cp;
      cc += 2;
      cn++;
    }
    
    double p = 0;
    if ((abs(X)+Y)/2 < cn) {
      p = 1;
    } else if ((abs(X)+Y)/2 == cn) {
      if (cp == N) {
        p = 1;
      } else {
        N -= lp;
        // N elements will be assigned either left or right.
        // No more than cn*2 elements can go on either side.
        // We need to get y+1 elements on one side.
        if (N > MAX) {
          cout << N << endl;
          throw;
        }
        memset(dp, 0, sizeof dp);
        for (int i = Y+1; i <= N; i++) {
          if (i <= cn*2 && N-i <= cn*2) {
            dp[N][i] = 1;
          }
        }
        for (int i = N-1; i >= 0; i--) {
          for (int j = 0; j <= i && j <= cn*2; j++) {
            if (j == cn*2) {
              dp[i][j] = dp[i+1][j];
            } else if (i-j == cn*2) {
              dp[i][j] = dp[i+1][j+1];
            } else {
              dp[i][j] = (dp[i+1][j] + dp[i+1][j+1])/2;
            }
          }
        }
        p = dp[0][0];
      }
    }
    
    printf("Case #%d: %.7lf\n", tt, p);
  }
}