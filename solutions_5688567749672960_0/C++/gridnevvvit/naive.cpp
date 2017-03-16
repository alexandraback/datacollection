#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <algorithm>
#include <bitset>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

#define forn(i, n) for(int i = 0; i< int(n); i++)
#define ford(i, n) for(int i = int(n) - 1; i >= 0; i--)
#define foreach(it, a) for(__typeof((a).begin()) it = a.begin(); it != a.end(); it++)

template<typename X> X abs(X a) { if (a < 0) return -a; return a; }
template<typename X> X sqr(X a) { return a * a; }
template<typename X> bool hasbit(X mask, int pos) { return (mask >> pos) & 1; }

#define sz(a) int((a).size())
#define all(a) (a).begin(),(a).end()
#define mp make_pair
#define pb push_back
#define ft first
#define sc second

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = 1000000000;
const ld EPS = 1e-9;
const ld PI = ld(3.1415926535897932384626433832795);

using namespace std;

int n;
const int N = 1000 * 1000 * 10;
int d[N];

inline bool read(){
  if (scanf("%d", &n) != 1)
    return false;
  return true;
}

int rev(int a) {
  if (a % 10 == 0) return INF;
  int res = 0;
  while (a > 0) {
    int cur = a % 10;
    res = res * 10 + cur;
    a /= 10;
  }
  return res;
}

inline void prepare() {
  d[1] = 1;
  for(int i = 2; i <= N; i++) {
    d[i] = d[i - 1] + 1;
    if (rev(i) < i) {
      d[i] = min(d[i], d[rev(i)] + 1);
    }
  }
}

inline void solve() {
  cout << d[n] << endl;
}

int main() {
#ifdef gridnevvvit
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  int testcount;
  scanf("%d\n", &testcount);
  prepare();
  forn(test, testcount) {
    assert(read());
    cout << "Case #" << test + 1 << ": ";
    solve();
  }
}
