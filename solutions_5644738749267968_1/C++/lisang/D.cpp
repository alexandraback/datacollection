#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <utility>
#include <functional>
#include <bitset>
#include <tuple>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef pair<int, int> pii;

#define FOR(i, x, y) for(ll i=x; i<=y; i++)
#define FORD(i, x, y) for (ll i = x; i >= y; --i)
#define REP(i, n) for(ll i=0; i<n; i++)
#define REPD(i, n) for(ll i = n - 1; i >= 0; --i) 

#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define UNIQ(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define SZ(c) (int)(c).size()
#define CONTAINS(s,obj) (s.find(obj)!=s.end())

#define CLEAR(x) memset(x,0,sizeof x)
#define COPY(from,to) memcpy(to, from, sizeof to)

#define sq(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define X first
#define Y second

const double eps = 1.0e-11;
const double pi = acos(-1.0);

int get(set<double> f, set<double> s) {
  for(auto x : f) {
    auto y = s.upper_bound(x);
    if (y == s.end()) break;
    s.erase(y);
  }
  return SZ(s);
}

void solve() {
  int n;
  double x;
  cin >> n;
  set<double> f, s;
  REP(i, n) {
    cin >> x;
    f.insert(x);
  }
  REP(i, n) {
    cin >> x;
    s.insert(x);
  }
  cout << SZ(s) - get(s, f) << " " << get(f, s) << endl;
}

int main() {
  freopen("D-large.in", "r", stdin);
  freopen("outputD", "w", stdout);
  int tests;
  cin >> tests;
  REP(test, tests) {
    printf("Case #%d: ", int(test + 1));
    solve();
  }
  return 0;
}