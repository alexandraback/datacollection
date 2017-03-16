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

int n;
vector<int> f;
vector<vector<int>> g;
vector<int> len;
vector<bool> seen;

int getlen(int i) {
  if (len[i] > 0) return len[i];
  seen[i] = true;
  int tmp = 1;
  for (unsigned j = 0; j < g[i].size(); ++j) {
    if (!seen[g[i][j]]) {
      tmp = max(tmp, getlen(g[i][j]) + 1);
    }
  }
  return tmp;
};

int main() {
  freopen("in", "r", stdin);
  int aa; cin >> aa;
  for (int bb = 1; bb <= aa; bb++) {
    cout << "Case #" << bb << ": ";
    cin >> n; f = vector<int>(n);
    g = vector<vector<int> >(n, vector<int>());
    for (int &i : f) { cin >> i; --i; }
    for (int i = 0; i < n; ++i) g[f[i]].push_back(i);
    len = vector<int>(n, -1);
    seen = vector<bool>(n, false);
    int total = 0;
    bool cont = false;
    for (int i = 0; i < n; ++i) {
      if (!seen[i] && !seen[f[i]] && f[f[i]] == i) {
        seen[i] = seen[f[i]] = true;
        total += getlen(i);
        total += getlen(f[i]);
      }
    }

    int total2 = 0;
    for (int i = 0; i < n; ++i) {
      vector<int> seen2(n, -1);
      seen2[i] = 0;
      int cur_len = 1, cur = f[i];
      while (true) {
        if (seen2[cur] == -1) {
          seen2[cur] = cur_len++;
          cur = f[cur];
        } else {
          total2 = max(total2, cur_len - seen2[cur]);
          break;
        }
      }
    }

    cout << max(total, total2) << "\n";
  }
}
