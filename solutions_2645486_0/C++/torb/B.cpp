#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <set>
#include <cstdio>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;

int main() {
  int TC; cin >> TC;
  for (int tc = 1; tc <= TC; tc++) {
    int E, R, N; cin >> E >> R >> N;
    vi vals(N);
    for(int i = 0; i < N; ++i) {
      cin >> vals[i];
    }
    vvi dp(N, vi(E+1, 0));
    for(int i = N-1; i >= 0; --i) {
      for(int j = min(E, R); j <= E; ++j) {
        if(i == N-1) dp[i][j] = j*vals[i];
        else {
          for(int k = 0; k <= j; ++k) {
            dp[i][j] = max(dp[i][j], k*vals[i] + dp[i+1][min(j-k+R, E)]);
          }
        }
      }
    }

    printf("Case #%d: %d\n", tc, dp[0][E]);
  }


  return 0;
}
