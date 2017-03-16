#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <cassert>

#define pb push_back
#define mp make_pair
#define PI 3.14159265358979
#define sqr(x) (x)*(x)
#define forn(i, n) for(int i = 0; i < n; ++i)
#define ALL(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define X first
#define Y second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
typedef pair<int,int> pii;
const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;

void solve() {
  string s[4];
  forn(i, 4) cin >> s[i];
  bool hasdot = false;
  forn(i, 4) forn(j, 4) if (s[i][j] == '.') {
    hasdot = true;
  }
  bool xwon = false;
  bool owon = false;
  char need = 'O';
  char rev = 'X';
  forn(iter, 2) {
    bool ok = false;
    forn(r, 4) {
      bool ook = true;
      forn(c, 4) if (s[r][c] == rev || s[r][c] == '.') ook = false;
      ok |= ook;
    }
    forn(c, 4) {
      bool ook = true;
      forn(r, 4) {
        if (s[r][c] == rev || s[r][c] == '.') ook = false;
      }
      ok |= ook;
    }
    bool ook = true;
    forn(i, 4) {
      if (s[i][i] == rev || s[i][i] == '.') ook = false;
    }
    ok |= ook;
    ook = true;
    forn(i, 4) {
      if (s[i][3-i] == rev || s[i][3-i] == '.') ook = false;
    }
    ok |= ook;
    if (need == 'O') owon = ok;
    else xwon = ok;
    swap(need, rev);
  }
  assert(!(owon&&xwon));
  if (owon) printf("O won\n");
  if (xwon) printf("X won\n");
  if (!owon&&!xwon) {
    if (hasdot) printf("Game has not completed\n");
    else printf("Draw\n");
  }
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
  int T; scanf("%d", &T);
  forn(tn, T) {
    printf("Case #%d: ", tn+1);
    solve();
  }
	return 0;
}