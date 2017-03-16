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

// 1 -1 i -i j -j k -k
// 0  1 2  3 4  5 6  7

string s;
string ss;

int convert(char c) {
  if (c == 'i') return 2;
  if (c == 'j') return 4;
  return 6;
}

int neg(int c) {
  return (c / 2 * 2 + 1) * 2 - 1 - c;
}

int mult(int a, int b) {
  int sign = (a % 2) ^ (b % 2);
  a -= a % 2;
  b -= b % 2;
  int ans;
  if (a == 0) {
    ans = b;
  } else if (a == 2) {
    if (b == 0) ans = 2;
    if (b == 2) ans = 1;
    if (b == 4) ans = 6;
    if (b == 6) ans = 5;
  } else if (a == 4) {
    if (b == 0) ans = 4;
    if (b == 2) ans = 7;
    if (b == 4) ans = 1;
    if (b == 6) ans = 2;
  } else if (a == 6) {
    if (b == 0) ans = 6;
    if (b == 2) ans = 4;
    if (b == 4) ans = 3;
    if (b == 6) ans = 1;
  }
  if (sign) ans = neg(ans);
  return ans;
}

int main()
{
  int t;
  cin >> t;
  FOR(tt, 1, t + 1) {
    int len;
    LL x;
    cin >> len >> x >> ss;
    s = ss;
    REP(i, x - 1) s += ss;
    len = len * x;
    int cur = 0;
    bool hasi = false;
    bool hasj = false;
    REP(i, len) {
      cur = mult(cur, convert(s[i]));
      if (cur == 2) {
        hasi = true;
      }
      if (hasi && cur == 6) {
        hasj = true;
      }
    }
    cout << "Case #" << tt << ": ";
    if (hasi && hasj && cur == 1) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << endl;
  }
  return 0;
}
