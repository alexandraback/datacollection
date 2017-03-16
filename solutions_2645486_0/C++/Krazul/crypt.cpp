#include <iostream>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

using namespace std;

// activity, energy
int dp[20][20];
int v[20];

int main() {
  int t; cin >> t;
  for (int test = 1; test <= t; ++test) {
    cout << "Case #" << test << ": ";
    int e, r, n; cin >> e >> r >> n;
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }

    // zero points to start
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= e; ++j) {
        dp[i][j] = 0;
      }
    }
    for (int i = 0; i < n; ++i) { // activity #
      for (int j = 0; j <= e; ++j) { // starting energy
        for (int k = 0; k <= j; ++k) { // used energy
          dp[i+1][ MIN(e, j-k+r) ] = MAX( dp[i+1][ MIN(e, j-k+r) ],
                                          dp[i][j] + k*v[i] );
        }
      }
    }

    int best = 0;
    for (int i = 0; i <= e; ++i) {
      best = MAX(dp[n][i], best);
    }
    cout << best << endl;
  }
  return 0;
}