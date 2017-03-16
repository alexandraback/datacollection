#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <numeric>
#include <limits.h>
#include <assert.h>

using namespace std;

typedef stringstream ss;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef long long ll;

#define FOR(i,n) for(int i = 0; i < n; i++)
#define SZ(v) int(v.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define ITE(v) typeof(v.begin())
#define FORIT(it,v) for(ITE(v) it = v.begin(); it != v.end(); it++)

string tab[4];

int solve2() {
  FOR(i,4) {
    cin >> tab[i];
  }
  int cnt = 0;
  int x,y;
  FOR(i,4) {
    x = 0;
    y = 0;
    FOR(j, 4) {
      if (tab[i][j] == 'X') x++;
      else if (tab[i][j] == 'O') y++;
      else if (tab[i][j] == 'T') x++, y++;
      else cnt++;
      if (x == 4) return 0;
      else if (y == 4) return 1;
    }    
    x = 0;
    y = 0;
    FOR(j, 4) {
      if (tab[j][i] == 'X') x++;
      else if (tab[j][i] == 'O') y++;
      else if (tab[j][i] == 'T') x++, y++;
      if (x == 4) return 0;
      else if (y == 4) return 1;
    }
  }
  x = 0; y = 0;
  FOR(i, 4) {
    if (tab[i][i] == 'X') x++;
    else if (tab[i][i] == 'O') y++;
    else if (tab[i][i] == 'T') x++, y++;
    if (x == 4) return 0;
    else if (y == 4) return 1;
  }
  x = 0; y = 0;
  FOR(i, 4) {
    if (tab[4-i-1][i] == 'X') x++;
    else if (tab[4-i-1][i] == 'O') y++;
    else if (tab[4-i-1][i] == 'T') x++, y++;
    if (x == 4) return 0;
    else if (y == 4) return 1;
  }
  if (cnt) return 2;
  return 3;
}

void solve() {
  switch (solve2()) {
  case 0:
    cout << "X won" << endl;
    break;
  case 1:
    cout << "O won" << endl;
    break;
  case 2:
    cout << "Game has not completed" << endl;
    break;
  case 3:
    cout << "Draw" << endl;
  }
}

int main(int argc, char *argv[]) {
  int ntest;
  cin >> ntest;
  FOR(kk, ntest) {
    cout << "Case #" << kk+1 << ": ";
    solve();
  }
  return 0;
}
