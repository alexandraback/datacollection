#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#include <map>
#include <set>

#define double long double

using namespace std;

struct Set {
  int j, p, s;

  Set() {}
  Set(int j, int p, int s) : j(j), p(p), s(s) {}

  bool operator< (const Set& other) const {
    if (j == other.j) {
      if (p == other.p) {
        return s < other.s;
      }
      return p < other.p;
    }
    return j < other.j;
  }

};

bool check(vector<Set> sets, int t) {
  map<Set, int> tmp;
  for (int i = 0; i < sets.size(); ++i) {
    Set a = sets[i], b = sets[i], c = sets[i];
    a.j = 0;
    b.p = 0;
    c.s = 0;
    ++tmp[a];
    ++tmp[b];
    ++tmp[c];
    if (tmp[a] > t || tmp[b] > t || tmp[c] > t) {
      return false;
    }
  }
  return true;
}

vector<Set> ans1;

void calc(int mask, vector<Set>& sets, int t) {
  vector<Set> cur;
  for (int i = 0; i < sets.size(); ++i) {
    if (mask & 1) {
      cur.push_back(sets[i]);
    }
    mask >>= 1;
  }

  if (check(cur, t) && ans1.size() < cur.size()) {
    ans1 = cur;
  }
}

int solve(int j, int p, int s, int t) {
  ans1.clear();
  vector<Set> sets;
  for (int i = j; i >= 1; --i) {
    for (int k = p; k >= 1; --k) {
      for (int q = s; q >= 1; --q) {
        sets.push_back(Set(i, k, q));
      }
    }
  }

  int mask = (1 << (int)sets.size()) - 1;
  for (int s = mask; s; s = (s - 1) & mask) {
    calc(s, sets, t);
  }

  return ans1.size();
}

int main() {
  ios::sync_with_stdio(false);
  freopen("test.in", "r", stdin);
  freopen("output.txt", "w", stdout);

  int cnt_tests;
  cin >> cnt_tests;

  for (int test = 1; test <= cnt_tests; ++test) {
    
    map<Set, int> sets;

    int j, p, s, t;
    cin >> j >> p >> s >> t;

    vector<Set> ans;
    for (int i = j; i >= 1; --i) {
      for (int k = p; k >= 1; --k) {
        for (int q = s; q >= 1; --q) {
          Set a(0, k, q);
          Set b(i, 0, q);
          Set c(i, k, 0);
          if (sets[a] == t || sets[b] == t || sets[c] == t) {
            continue;
          }
          ++sets[a];
          ++sets[b];
          ++sets[c];
          ans.push_back(Set(i, k, q));
        }
      }
    }

    printf("Case #%d: ", test);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
      cout << ans[i].j << " " << ans[i].p << " " << ans[i].s << endl;
    }

  }

  return 0;
}