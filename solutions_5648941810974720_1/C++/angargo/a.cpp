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
  while (v['Z' - 'A'] > 0) {
    ++w[0];
    for (char c : nums[0]) --v[c - 'A'];
  }
  while (v['W' - 'A'] > 0) {
    ++w[2];
    for (char c : nums[2]) --v[c - 'A'];
  }
  while (v['X' - 'A'] > 0) {
    ++w[6];
    for (char c : nums[6]) --v[c - 'A'];
  }
  while (v['G' - 'A'] > 0) {
    ++w[8];
    for (char c : nums[8]) --v[c - 'A'];
  }
  while (v['H' - 'A'] > 0) {
    ++w[3];
    for (char c : nums[3]) --v[c - 'A'];
  }
  while (v['R' - 'A'] > 0) {
    ++w[4];
    for (char c : nums[4]) --v[c - 'A'];
  }
  while (v['F' - 'A'] > 0) {
    ++w[5];
    for (char c : nums[5]) --v[c - 'A'];
  }
  while (v['I' - 'A'] > 0) {
    ++w[9];
    for (char c : nums[9]) --v[c - 'A'];
  }
  while (v['O' - 'A'] > 0) {
    ++w[1];
    for (char c : nums[1]) --v[c - 'A'];
  }
  while (v['V' - 'A'] > 0) {
    ++w[7];
    for (char c : nums[7]) --v[c - 'A'];
  }
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
    cerr << i << endl;
  }
}
