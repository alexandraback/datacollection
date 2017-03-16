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

int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

bool valid(const vector<string>& t) {
  int n = SZ(t);
  int m = SZ(t[0]);
  vector<vector<bool> > good(n, vector<bool>(m));
  REP(i, n) {
    REP(j, m) {
      bool ok = true;
      REP(d, 8) {
        int x = i + dx[d];
        int y = j + dy[d];
        if (x < 0 || x >= n || y < 0 || y >= m) continue;
        if (t[x][y] == '*') ok = false;
      }
      good[i][j] = ok;
    }
  }

  int counter = 0;
  REP(i, n) REP(j, m) {
    if (t[i][j] == '*' || good[i][j]) continue;
    bool ok = false;
    REP(d, 8) {
      int x = i + dx[d];
      int y = j + dy[d];
      if (x < 0 || x >= n || y < 0 || y >= m) continue;
      ok |= good[x][y];
    }
    counter += !ok;
  }
  return counter <= 1;
}

void print(const vector<string>& v) {
  if (!valid(v)) cerr << "FAIL\n";
  for (auto& x : v) cout << x << endl;
}

void solve() {
  ll r, c, m;
  cin >> r >> c >> m;
  ll need = r * c - m;
  
  vector<string> table(r, string(c, '*'));
  if (r == 1 || c == 1 || need == 1 || need == r * c) {
    REP(i, r) REP(j, c) if (need) table[i][j] = '.', --need;
    table[0][0] = 'c';
    print(table);
    return;
  }
  
  FOR(x, 2, r) FOR(y, 2, c) {
      if (x * y == need) {
      REP(i, x) REP(j, y) table[i][j] = '.';
      table[0][0] = 'c';
      print(table);
      return;
    }
  }

  FOR(x, 2, r - 1) FOR(y, 2, c - 1) {
    FOR(xa, 2, x) FOR(ya, 2, y) {
      if (x * y + xa + ya != need) continue;
      REP(i, r) REP(j, c) {
        if ((i < x && j < y) || (i == x && j < ya) || (i < xa && j == y)) table[i][j] = '.';
      }
      table[0][0] = 'c';
      print(table);
      return;
    }
  }
  cout << "Impossible\n";
  // cerr << r << " " << c << " " << m << " " << need << endl;
  return;
}
 

int main() {
  freopen("C-small-attempt7.in", "r", stdin);
  freopen("outputC_final", "w", stdout);
  int tests;
  cin >> tests;
  REP(test, tests) {
    printf("Case #%d:\n", int(test + 1)); solve();
  }
  return 0;
}