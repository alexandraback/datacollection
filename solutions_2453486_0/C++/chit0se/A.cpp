#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
#define sz(a)      (int)((a).size())
#define rep(i,n)   for(int i=0; i<n; ++i)
#define REP(i,j,k) for(int i=j; i<k; ++i)

bool only(string &s, char c) {
  rep (i, sz(s)) if (s[i] != c && s[i] != 'T') return false;
  cout << c << " won" << endl;
  return true;
}

void solve(vector<string> &g) {
  rep (i, 4) {
    if (only(g[i], 'O')) return;
    if (only(g[i], 'X')) return;
  }

  rep (j, 4) {
    string t = "";
    rep (i, 4) t += g[i][j];
    if (only(t, 'O')) return;
    if (only(t, 'X')) return;
  }

  string da = "", dd = "";
  rep (i, 4) {
    da += g[3-i][i];
    dd += g[i][i];
  }
  if (only(da, 'O')) return;
  if (only(da, 'X')) return;
  if (only(dd, 'O')) return;
  if (only(dd, 'X')) return;

  rep (i, 4) rep (j, 4) {
    if (g[i][j] == '.') {
      cout << "Game has not completed" << endl;
      return;
    }
  }

  cout << "Draw" << endl;
  return;
}

int main () {
  int TC = 0;
  scanf("%d", &TC);
  rep (tc, TC) {
    vector<string> g(4);
    rep (i, 4) cin >> g[i];
    printf("Case #%d: ", tc+1);
    solve(g);
  }
  return 0;
}
