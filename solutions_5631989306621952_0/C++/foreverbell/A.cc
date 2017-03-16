#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxint = 0x7f7f7f7f, mod = 1000000007;
const double eps = 1e-8, pi = acos(-1.0);

void rd() { }
template<typename... T> void rd(int &h, T &... t) { scanf("%d", &h); rd(t...); }
template<typename... T> void rd(long long &h, T &... t) { scanf("%lld", &h); rd(t...); }
template<typename... T> void rd(double &h, T &... t) { scanf("%lf", &h); rd(t...); }

string s, t;

void solve() {
  string s1, s2;

  cin >> s;
  t.clear();
  t.push_back(s[0]);
  for (int i = 1; i < (int) s.length(); ++i) {
    s1 = t; s1.push_back(s[i]);
    s2.clear();
    s2.push_back(s[i]);
    s2 += t;
    if (s1 > s2) t = s1;
    else t = s2;
  }
  cout << t << endl;
}

int main() {
  freopen("A-small-attempt0.in", "r", stdin);
  int tests;
  
  rd(tests);
  for (int tt = 1; tt <= tests; ++tt) {
    printf("Case #%d: ", tt);
    solve();
  }
  return 0;
}
