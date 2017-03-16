#include <cassert>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solver {
 public:
  void Solve() {
    dp[0] = 0;
    for (int i = 1; i < (1 << first.size()); ++i) {
      DP(i);
    }
    cout << dp[(1 << first.size() ) - 1] << endl;
  }

  int DP(int mask) {
    if (dp.find(mask) != dp.end()) return dp[mask];
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      if (mask & (1 << i)) {
        int nask = mask & (~(1 << i));
        if (CanBeFaked(nask, i)) {
          ans = std::max(ans, DP(nask) + 1);
        } else {
          ans = std::max(ans, DP(nask));
        }
      }
    }
    dp[mask] = ans;
    return ans;
  }

  bool CanBeFaked(int mask, int idx) {
    auto f = first[idx];
    auto s = second[idx];
    bool found_first = false;
    bool found_second = false;
    for (int i = 0; i < N; ++i) {
      if (mask & (1 << i)) {
        if (first[idx] == first[i]) found_first = true;
        if (second[idx] == second[i]) found_second = true;
      }
    }
    return found_second && found_first;
  }

  unordered_map<int, int> dp;
  int N;
  vector<string> first;
  vector<string> second;
};

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    Solver solver;
    cout << "Case #" << t + 1 << ": ";
    cin >> solver.N;
    for (int i = 0; i < solver.N; ++i) {
      string a, b;
      cin >> a >> b;
      solver.first.push_back(a);
      solver.second.push_back(b);
    }
    solver.Solve();
  }
}
