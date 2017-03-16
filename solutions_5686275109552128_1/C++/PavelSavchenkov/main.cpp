
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>

using namespace std;

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

const ld EPS = 1e-9;
const int MAXN = 1e3 + 10;

int make[MAXN][MAXN]; // make[x][y] -- steps, to make x_i <= y

void precalc() {
  forn(x, MAXN) forn(y, MAXN) {
    if  (x <= y) {
      make[x][y] = 0;
    } else {
      make[x][y] = 1 + make[x - y][y];
    }
  }
}

vi read() {
  int n;
  scanf("%d", &n);
  vi p(n);
  forn(i, n) scanf("%d", &p[i]);
  return p;
}

int solve(const vi& p) {
  int ans = (int) 1e9;
  int n = sz(p);

  for (int mx = 1; mx < MAXN; ++mx) {
    int cur = mx;
    forn(i, n) {
      cur += make[p[i]][mx];
    }
    ans = min(ans, cur);
  }

  return ans;
}
/*
int old(const vi& p) {
  int n = sz(p);
  multiset<int> S;
  int steps = 0;
  forn(i, n) {
    S.insert(p[i]);
  }
  int ans = *S.rbegin();
  while (steps < ans) {
    int mx = *S.rbegin();
    S.erase(S.find(mx));

    S.insert(mx / 2);
    S.insert((mx + 1) / 2);

    ++steps;
    ans = min(ans, steps + *S.rbegin());
  }

  return ans;
}
*/

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
#endif

  precalc();

  int T;
  scanf("%d", &T);
  forn(tt, T) {
    auto p = read();
  //  assert(old(p) == solve(p));
    printf("Case #%d: %d\n", tt + 1, solve(p));
  }

  return 0;
}
