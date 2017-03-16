#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <iostream>
#include <cstring>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define eprintf(...) fprintf(stderr,__VA_ARGS__)

using namespace std;

template<class T> inline void umax(T &a,T b){if(a < b) a = b;}
template<class T> inline void umin(T &a,T b){if(a > b) a = b;}
template<class T> inline T abs(T a){return a > 0 ? a : -a;}

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int inf = 1e9 + 143;
const ll longinf = 1e18 + 143;

inline int read(){int x;scanf(" %d",&x);return x;}

ll binpow(ll x, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) {
      res *= x;
    }
    x *= x;
    n >>= 1;
  }
  return res;
}

void solve() {
  int k = read();
  int c = read();
  int s = read();
  assert(s == k);
  ll delta = binpow(k, c - 1);
  for (int i = 1; i <= k; i++) {
    printf("%lld ", delta * (i - 1) + 1);
  }
  puts("");
}

int main() {
  int t = read();
  for (int i = 1; i <= t; i++) {
    printf("Case #%d: ", i);
    solve();
  }
  return 0;
}