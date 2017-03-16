#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")

#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define all(v) v.begin(), v.end()

using namespace std;
using ll = int64_t;

const vector<string> kDigits = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
const string kFail = "FAIL";

string rec(map<char, int> remains, char digit) {
  bool all_zero = true;
  for (auto c : remains)
    if (c.se != 0)
      all_zero = false;
  if (all_zero) return "";

  for (char c = digit; c <= '9'; c++) {
    int i = c - '0';
    string token = kDigits[i];
    auto new_remains = remains;
    bool fail = false;
    for (char x : token) {
      --new_remains[x];
      fail |= (new_remains[x] < 0);
    }
    if (!fail) {
      string check = rec(new_remains, c);
      if (check != kFail)
        return c + check;
    }
  }

  return kFail;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests;
  cin >> tests;
  for (int test = 0; test < tests; test++) {
    string res;

    string s;
    cin >> s;

    map<char, int> remains;
    for (char c : s)
      remains[c]++;

    cout << "Case #" << (test + 1) << ": ";
    cout << rec(remains, '0') << endl;
  }

  return 0;
}
