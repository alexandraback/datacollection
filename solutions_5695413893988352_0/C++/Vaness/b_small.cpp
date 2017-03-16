#include <bits/stdc++.h>
using namespace std;

int to_int(const string& s) {
  int val = 0;
  for (int i = 0; i < s.size(); ++i) {
    val *= 10;
    val += s[i] - '0';
  }
  return val;
}

string to_string(int val, int len) {
  string res;
  while (val) {
    res += val % 10 + '0';
    val /= 10;
  }
  while (res.size() < len) {
    res += '0';
  }
  reverse(res.begin(), res.end());
  if (res.size() > len) {
    return "";
  }
  return res;
}

pair<string, string> solve() {
  string s, t;
  cin >> s >> t;

  string best_s, best_t;
  int best_diff = 100000000;
  for (int i = 0; i < 1000; ++i) {
    string curs = to_string(i, s.size());
    if (curs.empty()) {
      continue;
    }
    bool flag = true;
    for (int j = 0; j < curs.size(); ++j) {
      if (s[j] != '?' && s[j] != curs[j]) {
        flag = false;
        break;
      }
    }
    if (!flag) {
      continue;
    }
    for (int j = 0; j < 1000; ++j) {
      string curt = to_string(j, t.size());
      if (curt.empty()) {
        continue;
      }
      bool flagt = true;
      for (int k = 0; k < curt.size(); ++k) {
        if (t[k] != '?' && t[k] != curt[k]) {
          flagt = false;
          break;
        }
      }
      if (!flagt) {
        continue;
      }
      int diff = abs(i - j);
      if (diff < best_diff) {
        best_diff = diff;
        best_s = curs;
        best_t = curt;
      } else if (diff == best_diff) {
        if (curs < best_s || (curs == best_s && curt < best_t)) {
          best_s = curs;
          best_t = curt;
        }
      }
    }
  }

  return {best_s, best_t};
}

int main() {
  int T;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    pair<string, string> res = solve();
    printf("Case #%d: %s %s\n", test, res.first.c_str(), res.second.c_str());
  }
}
