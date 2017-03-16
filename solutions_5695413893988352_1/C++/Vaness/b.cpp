#include <bits/stdc++.h>
using namespace std;

long long to_long(const string& s) {
  long long res = 0;
  for (int i = 0; i < s.size(); ++i) {
    res *= 10;
    res += s[i] - '0';
  }
  return res;
}

string to_string(long long val, int len) {
  string res;
  while (val) {
    res += val % 10 + '0';
    val /= 10;
  }
  while (res.size() < len) {
    res += '0';
  }
  reverse(res.begin(), res.end());
  return res;
}

pair<string, string> calc_less(string f, string s) {
  if (f.empty()) {
    return {"", ""};
  }

  string best_f, best_s;
  for (int i = 0; i < f.size(); ++i) {
    int flag = 0;
    for (int j = 0; j < i; ++j) {
      if (f[j] != '?' && s[j] != '?' && s[j] != f[j]) {
        if (s[j] < f[j]) {
          flag = -1;
        } else {
          flag = 1;
        }
        break;
      }
    }
    if (flag == -1) {
      break;
    }
    if (flag == 1) {
      string ftmp = f, stmp = s;
      for (int j = i; j < f.size(); ++j) {
        if (ftmp[j] == '?') {
          ftmp[j] = '9';
        }
        if (stmp[j] == '?') {
          stmp[j] = '0';
        }
      }
      if (best_f.empty() || ftmp < best_f || (ftmp == best_f && stmp < best_s))
        {
          best_f = ftmp;
          best_s = stmp;
        }
    }
    if (flag == 0) {
      bool cflag = true;
      string ftmp = f, stmp = s;
      if (ftmp[i] == '?') {
        if (stmp[i] == '?') {
          ftmp[i] = '0';
          stmp[i] = '1';
        } else if (stmp[i] > '0') {
          ftmp[i] = stmp[i] - 1;
        } else {
          cflag = false;
        }
      } else if (stmp[i] == '?') {
        if (ftmp[i] < '9') {
          stmp[i] = ftmp[i] + 1;
        } else {
          cflag = false;
        }
      } else if (ftmp[i] >= stmp[i]) {
        cflag = false;
      }

      if (cflag) {
        for (int j = i + 1; j < f.size(); ++j) {
          if (ftmp[j] == '?') {
            ftmp[j] = '9';
          }
          if (stmp[j] == '?') {
            stmp[j] = '0';
          }
        }
        if (best_f.empty() || ftmp < best_f || (ftmp == best_f && stmp < best_s))
          {
            best_f = ftmp;
            best_s = stmp;
          }
      }
    }

    if (f[i] == '?') {
      if (s[i] == '?') {
        f[i] = s[i] = '0';
      } else {
        f[i] = s[i];
      }
    } else if (s[i] == '?') {
      s[i] = f[i];
    } else if (s[i] != f[i]) {
      break;
    }
  }
  if (f == s) {
    best_f = f;
    best_s = s;
  }
  return {best_f, best_s};
}

bool is_better(const string& a1, const string& b1, const string& a2, const
               string& b2) {
  if (a1 < a2) {
    return true;
  } else if (a1 == a2) {
    return b1 < b2;
  } else {
    return false;
  }
}

pair<string, string> solve() {
  string s, t;
  cin >> s >> t;
  int sign = 0;
  int N = s.size();
  long long best_diff = -1;
  string best_s, best_t;

  for (int i = 0; i < N; ++i) {
    pair<string, string> l1 = calc_less(s.substr(i), t.substr(i));
    string fs = s.substr(0, i);
    string ss = t.substr(0, i);
    long long fval = to_long(fs + l1.first);
    long long sval = to_long(ss + l1.second);
    long long diff = abs(fval - sval);
    bool better = is_better(fs + l1.first, ss + l1.second, best_s, best_t);
    if (!l1.first.empty() && (best_diff == -1 || diff < best_diff ||
                              (diff == best_diff && better))) {
      best_diff = diff;
      best_s = fs + l1.first;
      best_t = ss + l1.second;
    }
    l1 = calc_less(t.substr(i), s.substr(i));
    fs = s.substr(0, i);
    ss = t.substr(0, i);
    fval = to_long(fs + l1.second);
    sval = to_long(ss + l1.first);
    diff = abs(fval - sval);
    better = is_better(fs + l1.second, ss + l1.first, best_s, best_t);
    if (!l1.first.empty() && (best_diff == -1 || diff < best_diff ||
                              (diff == best_diff && better))) {
      best_diff = diff;
      best_s = fs + l1.second;
      best_t = ss + l1.first;
    }

    if (s[i] == '?') {
      if (t[i] == '?') {
        s[i] = t[i] = '0';
      } else {
        s[i] = t[i];
      }
    } else if (t[i] == '?') {
      t[i] = s[i];
    } else if (s[i] != t[i]) {
      break;
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
