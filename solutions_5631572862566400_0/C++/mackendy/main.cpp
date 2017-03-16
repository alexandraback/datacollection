#include <algorithm>
#include <ios>
#include <iostream>
#include <istream>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <map>
#include <vector>

#define debug(x) do { cout << #x << " = " << x << endl; } while(0)

using namespace std;

void solve(int tid) {
  int n; cin >> n;
  vector<int> bffs;
  set<int> small_cycles;
  for (int i = 0; i < n; ++i) {
    int bff; cin >> bff;
    --bff;
    bffs.push_back(bff);

    // Small cycle
    if (bff < i && bffs[bff] == i) {
      small_cycles.insert(i);
      small_cycles.insert(bff);
    }
  }

  map<size_t, int> max_cycles;
  int max_unpaired = 1;
  for (size_t i = 0; i < bffs.size(); ++i) {
    if (small_cycles.count(i)) {
      continue;
    }

    size_t bff = i;
    int cnt = 0;
    vector<bool> visited(bffs.size(), false);

    while (true) {
      bff = bffs[bff];
      ++cnt;

      if (bff == i) {
        if (cnt > max_unpaired) {
          max_unpaired = cnt;
        }
        break;
      }

      if (visited[bff]) {
        break;
      } else {
        visited[bff] = true;
      }

      auto it = small_cycles.find(bff);
      if (it != small_cycles.end()) {
        if (max_cycles[*it] < cnt) {
          max_cycles[*it] = cnt;
        }

        break;
      }
    }
  }

  auto small_total = accumulate(max_cycles.begin(), max_cycles.end(), 0, [](int acc, auto p) {
    return p.second + acc;
  }) + int(small_cycles.size());


  cout << "Case #" << tid << ": " << max(small_total, max_unpaired) << endl;
  return;
}

int main() {
  cout.precision(8); cout.setf(ios_base::showpoint);
  int t; cin >> t;

  for (int i = 1; i <= t; ++i) {
    solve(i);
  }

  return 0;
}
