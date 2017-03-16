// {{{
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define EB emplace_back
#define SZ(c) int((c).size())
#define ALL(c) (c).begin(),(c).end()
#define REP(i,n) for(int i=0;i<int(n);++i)
template<class T>inline void check_min(T&a,T b){if(b<a)a=b;}
template<class T>inline void check_max(T&a,T b){if(a<b)a=b;}
typedef long long lint;
typedef vector<int> VI;
typedef pair<int, int> PII;
// }}}

string a, b;

inline lint toll(const string &s) {
  stringstream ss(s);
  lint v;
  ss >> v;
  return v;
}

inline int cmp(int i) {
  if (i == 0) return 0;
  lint x = toll(a.substr(0, i));
  lint y = toll(b.substr(0, i));
  return x < y ? -1 : x > y;
}

const lint INF = ~0ULL >> 2;

/*
set<pair<lint, lint>> dfs(int i, int sign) {
  set<pair<lint, lint>> st;
  if (i == 0) {
    if (sign == 0) st.insert(MP(0LL, 0LL));
    return st;
  }
  if (sign < 0) {
    set<pair<lint, lint>> pre = dfs(i - 1, -1);
    int x = a[i] - '0', y = b[i] - '0';
    if (a[i] == '?') x = 9;
    if (b[i] == '?') y = 0;
  } else if (sign > 0) {
  } else {
  }
}

void solve() {
  cin >> a >> b;
  pair<lint, lint> dp[32][3];
  fill(dp[0], dp[32], INF);
  dp[0][0] = 0;
  for (int i = 1; i < SZ(a); ++i) {
    for (int sign = -1; sign <= 1; ++sign) {
      lint dist = dp[i - 1][sign + 1];
      lint d2;
      if (dist == INF) continue;
      int x = a[i] - '0', y = b[i] - '0';
      if (sign == -1) {
        if (b[i] == '?') y = 0;
        if (a[i] == '?') x = 9;
        d2 = dist * 10 - (y - x);
      } else if (sign == 0) {
      } else {
        if (a[i] == '?') a[i] = '0';
        if (b[i] == '?') b[i] = '9';
      }
    }
  }
  printf("%s %s\n", a.c_str(), b.c_str());
}
*/

string to_s(int n, int ds) {
  stringstream ss;
  ss << n;
  string s = ss.str();
  reverse(ALL(s));
  while (SZ(s) < ds) s += "0";
  reverse(ALL(s));
  return s;
}

bool check_it(const string &a, const string &b) {
  if (SZ(a) != SZ(b)) return false;
  REP (i, SZ(a)) {
    if (a[i] != '?' && a[i] != b[i]) return false;
  }
  return true;
}

void gao() {
  string a, b;
  cin >> a >> b;
  lint dist = INF;
  string aa, bb;
  REP (i, 1000) {
    string x = to_s(i, SZ(a));
    if (!check_it(a, x)) continue;
    REP (j, 1000) {
      string y = to_s(j, SZ(b));
      if (!check_it(b, y)) continue;
      lint d = abs(i - j);
      if (d < dist) {
        dist = d;
        aa = x, bb = y;
      }
    }
  }
  printf("%s %s\n", aa.c_str(), bb.c_str());
}

int main() {
  int n_case;
  cin >> n_case;
  for (int index = 1; index <= n_case; ++index) {
    printf("Case #%d: ", index);
    gao();
  }
  return 0;
}
