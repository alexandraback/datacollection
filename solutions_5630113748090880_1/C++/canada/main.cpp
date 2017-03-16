#include <iostream>
#include <algorithm>
#include <bitset>
#include <cstdint>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>

using namespace std;

typedef int64_t ii;
typedef uint64_t ui;

bool f(const vector<int>& a, const vector<int>& b) {
  return a.back() < b.back();
}

int main() {
  freopen("in", "r", stdin);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cout << "Case #" << i << ":";
    int v; cin >> v;
    map<int, int> idk;
    for (int j = 0; j < v * (2 * v - 1); ++j) {
      int k; cin >> k; idk[k] = idk[k] + 1;
    }
    set<int> s;
    for (auto p : idk) {
      if (p.second % 2)
        s.insert(p.first);
    }
    for (int t : s) cout << " " << t;
    cout << "\n";
  }
}
