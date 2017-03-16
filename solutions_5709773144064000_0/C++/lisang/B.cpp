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

double solve() {
  double cost, inc, goal, rate = 2.0, curr = 0.0, time = 0.0;
  cin >> cost >> inc >> goal;
  if (cost >= goal) return goal / rate;
  while(true) {
    curr = cost;
    time += cost / rate;
    if ((goal - curr) / rate < goal / (rate + inc)) return time + (goal - curr) / rate;
    curr = 0.0;
    rate += inc;
  }
}

int main() {
  freopen("B-small-attempt0.in", "r", stdin);
  freopen("outputB", "w", stdout);
  int tests;
  cin >> tests;
  REP(test, tests) {
    printf("Case #%d: %.8lf\n", int(test + 1), solve());
  }
  return 0;
}