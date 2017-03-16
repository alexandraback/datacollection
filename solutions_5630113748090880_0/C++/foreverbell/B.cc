#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxint = 0x7f7f7f7f, mod = 1000000007;
const double eps = 1e-8, pi = acos(-1.0);

void rd() { }
template<typename... T> void rd(int &h, T &... t) { scanf("%d", &h); rd(t...); }
template<typename... T> void rd(long long &h, T &... t) { scanf("%lld", &h); rd(t...); }
template<typename... T> void rd(double &h, T &... t) { scanf("%lf", &h); rd(t...); }

const int maxN = 51, wild = -10000;

int n;

int main() {
  int tests;
  
  freopen("B-small-attempt0.in", "r", stdin);
  rd(tests);
  for (int tt = 1; tt <= tests; ++tt) {
    printf("Case #%d: ", tt);
    rd(n);
    map<int, int> m;
    for (int i = 1; i <= 2*n-1; ++i) {
      for (int j = 1; j <= n; ++j) {
        int x;
        rd(x);
        m[x] += 1;
      }
    }
    vector<int> v;
    for (auto it = m.begin(); it != m.end(); ++it) {
      if (it->second & 1) {
        v.push_back(it->first);
      }
    }
    for (int i = 0; i < n; ++i) {
      printf("%d%c", v[i], i + 1 == n ? '\n' : ' ');
    }
  }
  return 0;
}
