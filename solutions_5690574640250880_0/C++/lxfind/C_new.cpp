#include <set>
#include <bitset>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <climits>
#include <cstring>
#include <ctime>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <sstream>
#define MID(x,y) ( ( x + y ) >> 1 )
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define REP(i,t) for(int i=0; i<(t); i++)
#define FOR(i,s,t) for(int i=(s); i<(t); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define FORL(i,s,t) for(L i=(s); i<(t); i++)
#define BUG puts("here!!!")
#define STOP system("pause")
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)
#define EPS 1e-11
#define EQ(a, b) (fabs((a) - (b)) <= EPS)
#define POS(a) ((a) >= EPS)
#define NEG(a) ((a) <= -EPS)
#define BG(a, b) ((a) - (b) >= EPS)
#define LS(a, b) ((b) - (a) >= EPS)
#define CLR(a, x) memset( a, x, sizeof( a ) )
#define PI (atan(1.0) * 4)
#define SQ(x) ((x) * (x))
#define DIST(x1, y1, x2, y2) (sqrt(SQ((x1) - (x2)) + SQ((y1) - (y2))))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define setmin(a, b) (a = min(a, b))
#define setmax(a, b) (a = max(a, b))
#define LOG2(x) (log(x) / log(2))
#define XX first.first
#define XY first.second
#define YX second.first
#define YY second.second

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
typedef pair<double, double> Pd;
typedef pair<int, int> Pi;
typedef pair<LL, LL> Pl;

int r, c, n;
char a[100][100];
bool v[100][100];

void solve() {
  int m = n;
  REP(i, r) REP(j, c) a[i][j] = '.';
  int leftr = 0, leftc = 0, rightr = r - 1, rightc = c - 1;
  while (m) {
    int height = rightr - leftr + 1;
    int width = rightc - leftc + 1;
    if (height >= width) {
      if (m >= width) {
        REP(i, width) a[leftr][leftc + i] = '*';
        m -= width;
        leftr++;
      } else if (m < width - 1) {
        REP(i, m) a[leftr][leftc + i] = '*';
        m = 0;
      } else {
        int first = width - 2;
        REP(i, first) a[leftr][leftc + i] = '*';
        REP(i, m - first + 1) a[leftr + i][leftc] = '*';
        m = 0;
      }
    } else {
      if (m >= height) {
        REP(i, height) a[leftr + i][leftc] = '*';
        m -= height;
        leftc++;
      } else if (m < height - 1) {
        REP(i, m) a[leftr + i][leftc] = '*';
        m = 0;
      } else {
        int first = height - 2;
        REP(i, first) a[leftr + i][leftc] = '*';
        REP(i, m - first + 1) a[leftr][leftc + i] = '*';
        m = 0;
      }
    }
  }
  a[r - 1][c - 1] = 'c';
}

bool outofrange(int row, int column) {
  return row >= r || row < 0 || column >= c || column < 0;
}

bool has(int row, int column) {
  return !outofrange(row, column) && a[row][column] == '*';
}

void click(int row, int column) {
  if (outofrange(row, column)) return;
  if (v[row][column]) return;
  v[row][column] = 1;
  bool hasmine = 0;
  FOR(i, row - 1, row + 2)
    FOR(j, column - 1, column + 2)
      hasmine |= has(i, j);
  if (!hasmine) {
    FOR(i, row - 1, row + 2)
      FOR(j, column - 1, column + 2)
        click(i, j);
  }
}

bool verify() {
  int cnt = 0;
  REP(i, r) REP(j, c) {
    cnt += a[i][j] == '*';
  }
  if (cnt != n) return false;
  CLR(v, 0);
  click(r - 1, c - 1);
  bool ans = 1;
  REP(i, r)
    REP(j, c)
      if (a[i][j] != '*' && !v[i][j])
        ans = 0;
  return ans;
}

int main()
{
  int t;
  cin >> t;
  REP(p, t) {
    cin >> r >> c >> n;
    cout << "Case #" << (p + 1) << ":" << endl;
    solve();
    if (verify()) {
      REP(i, r) {
        REP(j, c) cout << a[i][j];
        cout << endl;
      }
    } else {
      cout << "Impossible" << endl;
    }
  }
  return 0;
}

