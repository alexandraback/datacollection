#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <string>
#include <cmath>

using namespace std;

int p = 1000000007;

int solve(int E, int R, int N, vector<int>& a) {
  vector<vector<int> > dp(N + 1, vector<int>(E + 1, -p));
  dp[0][E] = 0;
  for (int pos = 0; pos < N; ++pos) {
    for (int energy = 0; energy <= E; ++energy) {
      for (int use = 0; use <= energy; ++use) {
        int val = a[pos] * use;
        // printf("%d * %d = %d ", a[pos], use, val);
        int new_energy = min(E, energy-use + R);
        int old_val = dp[pos+1][new_energy];
        dp[pos+1][new_energy] = max(old_val, val + dp[pos][energy]);
        // cerr << ref << ' ';

        ;
      }
    }
  }
  return *max_element(dp[N].begin(), dp[N].end());
}

int main() {
    int T;
    cin >> T;

    for(unsigned int _ = 0; _ < T; _++) {
        cout <<"Case #" << (_+1) << ": ";
        int E, R, N;
        cin >> E >> R >> N;
        vector<int> a(N);
        for (int i = 0; i < N; ++i) {
          cin >> a[i];
        }
        cout << solve(E, R, N, a) << endl;
    }
    return 0;
}