#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
using namespace std;

void solve() {
  
  int n, ans = 0;
  pair<string, string> T[18];
  set<string> first, second;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> T[i].first >> T[i].second;
  }

  for (int mask = 1; mask < (1<<n); mask++) {
    vector<pair<string, string> > R, F;
    for (int i = 0; i < n; i++) {
      if (mask&(1<<i)) {
        R.push_back(T[i]);
      } else {
        F.push_back(T[i]);
      }
    }
    first.clear();
    second.clear();
    for (auto p : R) {
      first.insert(p.first);
      second.insert(p.second);
    }
    int g = F.size();
    while (F.size()) {
      int j = -1;
      for (int i = 0; i < F.size(); i++) {
        auto p = F[i];
        if (first.count(p.first) && second.count(p.second)) {
          j = i;
          break;
        }
      }
      if (j != -1) {
        F.erase(F.begin()+j);
      } else {
        break;
      }
    }
    if (F.empty()) {
      ans = max(ans, g);
    }
  }
  cout << ans;
}
int main() { _
  int tt;
  cin >> tt;
  for (int t = 1; t <= tt; t++) {
    cout << "Case #" << t << ": ";
    solve();
    cout << endl;
  }
  return 0;
}
