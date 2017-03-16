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
#include <deque>
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


void solve() {
  int n, m, u, v;
  cin >> n >> m;
  vector<int> id(n);
  vector<string> st(n); REP(i, n) cin >> st[i], id[i] = i;
  string best(5 * n, '9');
  vector<vector<bool> > g(n, vector<bool>(n));
  REP(i, m) {
    cin >> u >> v; 
    --u, --v;
    g[u][v] = g[v][u] = true;
  }

  do {
    bool ok = true;
    vector<int> pred(n);
    int curr = id[0];
    pred[id[0]] = id[0];
    FOR(i, 1, n - 1) {
      int to = id[i];
      while(!g[curr][to] && curr != pred[curr]) curr = pred[curr];
      if (g[curr][to]) pred[to] = curr, curr = to;
      else {
        ok = false;
        break;
      }
    }
    if (ok) {
      string curr; REP(i, n) curr += st[id[i]];
      best = min(best, curr);
    }
  } while(next_permutation(ALL(id)));
  cout << best << endl;
}

int main() {
  freopen("C-small-attempt0.in", "r", stdin);
  freopen("c.out", "w", stdout);
  int tests;
  scanf("%d", &tests);
  REP(i, tests) {
    cerr << i << endl;
    printf("Case #%d: ", int(i + 1));
    solve();
  }
  return 0;
}