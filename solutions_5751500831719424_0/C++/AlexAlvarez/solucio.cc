#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<string>& v, vector<int>& pos) {
  char c = v[0][pos[0]];
  for (int i = 1; i < v.size(); ++i) if (v[i][pos[i]] != c) return false;
  return true;
}

void solve() {
  int n;
  cin >> n;
  vector<string> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  vector<int> pos(n, 0);

  bool fin = false;
  int res = 0;
  while (not fin) {
    if (not check(v, pos)) {
      cout << "Fegla Won" << endl;
      return;
    }
    vector<int> qtt(n, 0);
    for (int i = 0; i < n; ++i) {
      while (pos[i] + 1 < v[i].size() and v[i][pos[i]] == v[i][pos[i] + 1]) {
        ++qtt[i];
        ++pos[i];
      }
      ++qtt[i];
      ++pos[i];
    }
    sort(qtt.begin(), qtt.end());
    int best = 1e9;
    for (int i = 0; i < n; ++i) {
      int goal = qtt[i];
      int aux = 0;
      for (int j = 0; j < n; ++j) {
        aux += abs(qtt[i] - qtt[j]);
      }
      best = min(best, aux);
    }
    res += best;
    bool some_end = false;
    bool all_end = true;
    for (int i = 0; i < n; ++i) {
      if (pos[i] == v[i].size()) some_end = true;
      else all_end = false;
    }

    if (some_end and not all_end) {
      cout << "Fegla Won" << endl;
      return;
    }
    if (all_end) fin = true;
  }
  cout << res << endl;
}

int main() {
  int casos;
  cin >> casos;
  for (int cas = 1; cas <= casos; ++cas) {
    cout << "Case #" << cas << ": ";
    solve();
  }
}
