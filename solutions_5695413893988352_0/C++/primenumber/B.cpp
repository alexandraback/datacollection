#include <bits/stdc++.h>

#define REP(i,n)    for(int i=0;i<(n);++i)

using namespace std;

int64_t val(const pair<string, string>& p) {
  return abs(stoll(p.first) - stoll(p.second));
}

bool cmp(const string& lhs, const string& rhs) {
  REP(i, lhs.size()) {
    if (lhs[i] == '?' || rhs[i] == '?') continue;
    if (lhs[i] < rhs[i]) return false;
    if (lhs[i] > rhs[i]) return true;
  }
  return false;
}

pair<string, string> solve(string coder, string jammer, int pos, int spaceship) {
  if (pos >= coder.size()) return make_pair(coder, jammer);
  if (spaceship) {
    if (spaceship > 0) { // coder > jammer
      if (coder[pos] == '?') coder[pos] = '0';
      if (jammer[pos] == '?') jammer[pos] = '9';
    } else if (spaceship < 0) {
      if (coder[pos] == '?') coder[pos] = '9';
      if (jammer[pos] == '?') jammer[pos] = '0';
    }
    return solve(coder, jammer, pos+1, spaceship);
  } else {
    if (cmp(coder, jammer)) {
      if (coder[pos] == '?') {
        if (jammer[pos] == '?') {
          coder[pos] = jammer[pos] = '0';
          auto res1 = solve(coder, jammer, pos+1, 0);
          jammer[pos] = '1';
          auto res2 = solve(coder, jammer, pos+1, -1);
          return val(res1) <= val(res2) ? res1 : res2;
        } else {
          if (jammer[pos] == '0') {
            coder[pos] = '0';
            return solve(coder, jammer, pos+1, 0);
          } else {
            coder[pos] = jammer[pos] - 1;
            auto res1 = solve(coder, jammer, pos+1, -1);
            coder[pos] = jammer[pos];
            auto res2 = solve(coder, jammer, pos+1, 0);
            return val(res1) <= val(res2) ? res1 : res2;
          }
        }
      } else if (jammer[pos] == '?') {
        if (coder[pos] == '9') {
          jammer[pos] = '9';
          return solve(coder, jammer, pos+1, 0);
        } else {
          jammer[pos] = coder[pos] + 1;
          auto res1 = solve(coder, jammer, pos+1, -1);
          jammer[pos] = coder[pos];
          auto res2 = solve(coder, jammer, pos+1, 0);
          return val(res1) < val(res2) ? res1 : res2;
        }
      } else {
        if (coder[pos] > jammer[pos]) {
          return solve(coder, jammer, pos+1, 1);
        } else if (coder[pos] < jammer[pos]) {
          return solve(coder, jammer, pos+1, -1);
        } else {
          return solve(coder, jammer, pos+1, 0);
        }
      }
    } else if (cmp(jammer, coder)) {
      auto res = solve(jammer, coder, pos, 0);
      return make_pair(res.second, res.first);
    } else {
      if (coder[pos] == '?') {
        if (jammer[pos] == '?') {
          coder[pos] = jammer[pos] = '0';
        } else {
          coder[pos] = jammer[pos];
        }
      } else if (jammer[pos] == '?') {
        jammer[pos] = coder[pos];
      }
      return solve(coder, jammer, pos+1, 0);
    }
  }
}

int main() {
  int t;
  cin>>t;
  REP(cnt, t) {
    string coder, jammer;
    cin>>coder>>jammer;
    cout << "Case #" << (cnt+1) << ": ";
    auto result = solve(coder, jammer, 0, 0);
    cout << result.first << ' ' << result.second << endl;
  }
  return 0;
}
