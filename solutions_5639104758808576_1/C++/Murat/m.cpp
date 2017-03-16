#include<bits/stdc++.h>
  
using namespace std;

template<class T> inline T sqr(const T& a) { return a * a; }
  
typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
  
constexpr ld EPS = 1e-9;
constexpr ld PI = 2 * acos(0.0);
constexpr int N = 100;

int main() {
  int tests;
  scanf("%d\n", &tests);
  for (int it = 1; it <= tests; ++it) {
    int n;
    scanf("%d ", &n);
    string s;
    getline(cin, s);
    assert(n + 1 == int(s.size()));
    int ans = 0;
    int acc = 0;
    for (int i = 0; i <= n; ++i) {
      int d = s[i] - '0';
      if (!d)
        continue;
      if (acc < i) {
        ans += i - acc;
        acc = i;
      }
      acc += d;
    }
    printf("Case #%d: %d\n", it, ans);
  }

  return 0;
}
