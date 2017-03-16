#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;

string solve(int n, ll m) {
  vector<ll> count(n);
  vector<vector<int>> mtr(n, vector<int>(n));
  count[n-1] = 1;
  for (int i = n - 2; i >= 0; --i) {
    for (int j = i+1; j < n; ++j) {
      assert(count[i] + count[j] >= 0);
      if (count[i] + count[j] <= m) {
        count[i] += count[j];
        mtr[i][j] = 1;
      }
    }
  }
  string ans = "";
  if (count[0] == m) {
    ans = string("POSSIBLE") + "\n";
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
        ans += to_string(mtr[i][j]);
      ans += "\n";
    }
  } else {
    ans = "IMPOSSIBLE";
  }
  return ans;
}

int main() {
  cin >> t;
  int nmb = 0;
  while (t-->0) {
    int b;
    ll m;
    cin >> b >> m;
    cout << "Case #" << ++nmb << ": " << solve(b, m) << endl;
  }
  return 0;
}
