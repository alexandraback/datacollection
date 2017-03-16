#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

int go(vector<int>& has, vector<bool>& can) {
  int m = -1;
  for (int v = 1; v < can.size(); v++) {
    if (!can[v]) {
      m = v;
      break;
    }
  }
  if (m == -1) return 0;
  int ret = 3333;
  for (int v = m - 1; v >= 0; --v) {
    int add = m - v;
    bool ok = can[v];
    for (int i = 0; ok && i < has.size(); i++) {
      if (has[i] == add) {
        ok = false;
      }
    }
    if (ok) {
      has.push_back(add);
      auto old = can;
      for (int v = can.size() - 1; v - add >= 0; --v) {
        if (can[v - add]) {
          can[v] = true;
        }
      }
      ret = min(ret, go(has, can) + 1);
      can = std::move(old);
      has.pop_back();
    }
  }
  return ret;
}

int run() {
  int C, D, V;
  cin >> C >> D >> V;
  vector<int> has(D);
  for (int i = 0; i < D; i++) {
    cin >> has[i];
  }
  vector<bool> can(V + 1, false);
  for (int i = 0; i < (1 << D); ++i) {
    int s = 0;
    for (int j = 0; j < D; ++j) {
      if (i & (1 << j)) {
        s += has[j];
      }
    }
    if (s <= V) {
      can[s] = true;
    }
  }
  return go(has, can);
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": " << run() << endl;
  }
}
