// Authored by dolphinigle
// GCJ 2013 Qual
// 13 Apr 2013

#include <vector>
#include <list>
#include <map>
#include <set>

#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <assert.h>

#define FORN(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define REP(X,Y,Z) for (int (X) = (Y);(X) < (Z);++(X))

#define SZ(Z) ((int)(Z).size())
#define ALL(W) (W).begin(), (W).end()
#define PB push_back

#define MP make_pair
#define A first
#define B second

#define INF 1023123123
#define EPS 1e-11

#define MX(Z,Y) Z = max((Z),(Y))
#define MN(X,Y) X = min((X),(Y))

#define FORIT(X,Y) for(typeof((Y).begin()) X = (Y).begin();X!=(Y).end();X++)

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> vint;

template<class C>
vector< vector< C > > Transpose(const vector< vector< C > >& matrix) {
  int row = SZ(matrix);
  int col = 0;
  if (row != 0) col = SZ(matrix[0]);
  vector< vector< C > > res(col, vector<C>(row));
  FORN(i, row) FORN(j, col) res[j][i] = matrix[i][j];
  return res;
}

int mow[250][250];

int Solv(vector<vint> pct, int trans = 0) {
  if (SZ(pct) == 0 || SZ(pct[0]) == 0) {
    // all mowed
    return 1;
  }
  int shorty = INF;
  int row = SZ(pct);
  int col = SZ(pct[0]);
  FORN(i, row) FORN(j, col) MN(shorty, pct[i][j]);
  // find a row of shorties
  FORN(i, row) {
    int yes = 1;
    FORN(j, col) if (pct[i][j] != shorty) yes = 0;
    if (yes) {
      pct.erase(pct.begin() + i);
      return Solv(pct, 0);
    }
  }
  if (trans) return 0;
  return Solv(Transpose(pct), 1);
}

int main() {
  int ntc;
  cin >> ntc;
  FORN(itc, ntc) {
    cout << "Case #" << (itc+1) << ": ";
    int row, col;
    cin >> row >> col;
    FORN(i, row) FORN(j, col) cin >> mow[i][j];
    vector< vint > haha(row, vint(col));
    FORN(i, row )FORN(j, col) haha[i][j] = mow[i][j];
    if (Solv(haha, 0)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
