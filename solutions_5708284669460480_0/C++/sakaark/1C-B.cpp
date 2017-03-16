#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <utility>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <list>
#include <iomanip>
#include <ctime>
#include <cassert>
#include <stack>
#include <unordered_map>
#include <unordered_set>

#define what_is(x) cout << #x << " is " << x << endl;

using namespace std;

typedef long long ll;

unordered_map<char,int> keys;

void init_keys() {
  keys.clear();
  for (char c = 'A'; c <= 'Z'; c++) {
    keys[c] = 0;
  }
}

bool is_ok(string& p, int suff) {
  int sz = p.size();
  int back = sz - suff;
  for (int i = 0; i < suff; i++) {
    if (p[i] != p[back + i]) {
      return false;
    }
  }
  return true;
}

int get_kmp_match(string& p) {
  int sz = (int)p.size();
  int ans = sz - 1;
  while (ans > 0) {
    if (is_ok(p, ans)) {
      return ans;
    }
    ans--;
  }
  return 0;
}

int get_max_matches(int psz, int kmp, int sz) {
  if (psz > sz) {
    return 0;
  }
  int ans = 0, jmp = psz - kmp;
  for (int i = 0; i + psz - 1 < sz; i += jmp) {
    ans++;
  }
  return ans;
}

double get_point_exp(string& p, int k) {
  double ans = 1;
  int sz = (int)p.size();
  for (int i = 0; i < sz; i++) {
    ans *= ((double)keys[p[i]]) / k;
  }
  return ans;
}

bool possible(string& p) {
  int sz = (int)p.size();
  for (int i = 0; i < sz; i++) {
    if (keys[p[i]] == 0) {
      return false;
    }
  }
  return true;
}

int main () {
  std::ios::sync_with_stdio(false);
  int t;
  cout << fixed << setprecision(10); 
  cin >> t;
  for (int i = 0; i < t; i++) {
    int k, l, s;
    string p;
    cin >> k >> l >> s;
    init_keys();
    for (int i = 0; i < k; i++) {
      char c;
      cin >> c;
      keys[c]++;
    }
    cin >> p;
    int kmp = get_kmp_match(p);
    int max_match = 0;
    if (possible(p)) {
      max_match = get_max_matches((int)p.size(), kmp, s);
    }
    double point_exp = get_point_exp(p, k);
    double exp = 0;
    if (s >= p.size()) {
      exp = point_exp * (s - (int)p.size() + 1);
    }
    cout << "Case #" << (i + 1) << ": " << (double)max_match - exp << endl;
  }
  return 0;
}
