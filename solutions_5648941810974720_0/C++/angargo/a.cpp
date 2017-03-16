#include <bits/stdc++.h>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using ll = long long;
using VL = vector<ll>;
using VVL = vector<VL>;
using P = pair<int, int>;
using VP = vector<P>;
using VVP = vector<VP>;

vector<string> nums{"ZERO", "ONE", "TWO",
  "THREE", "FOUR", "FIVE", "SIX",
  "SEVEN", "EIGHT", "NINE"};

bool bt(VI &v, VI &w, int i) {
  for (int j = 0; j < 26; ++j) if (v[j] < 0) return false;

  if (i == 10) {
    for (int j = 0; j < 26; ++j) if (v[j]) return false;
    for (int j = 0; j < 10; ++j) {
      for(int k = 0; k < w[j]; ++k) cout << j;
    }
    cout << endl;
    return true;
  }

  if (bt(v, w, i + 1)) return true;

  for (char c : nums[i]) --v[c - 'A'];
  ++w[i];
  if (bt(v, w, i)) return true;
  --w[i];
  for (char c : nums[i]) ++v[c - 'A'];
  return false;
}

void solve() {
  string s;
  cin >> s;
  VI v(26);
  for (char c : s) ++v[c - 'A'];
  VI w(10, 0);
  bt(v, w, 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
}
