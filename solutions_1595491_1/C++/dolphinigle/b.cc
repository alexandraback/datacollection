// Authored by dolphinigle
// Codeforces #115
// 14 April 2012
// Author: Gerald, undef, ashmelev

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
#define ALL(W) W.begin(), W.end()
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

int scores[120];
int dp[120][120];

int ok(int a, int b, int c) {
  if (abs(a-b) > 2 || abs(b-c) > 2 || abs(c-a) > 2) return 0;
  return 1;
}

int Surp(int a, int b, int c) {
  return abs(a-b) == 2 || abs(b-c) == 2 || abs(c-a) == 2;
}

int Solve(int surp, int pos, int p, int n) {
  if (surp < 0) return -INF;
  if (pos == n) {
    if (surp == 0) return 0;
    return -INF;
  }

  
  int& alias = dp[surp][pos];
  if (alias != -1) return alias;
  
  alias = -INF;
  FORN(i, 11) FORN(j, 11) FORN(k, 11) if (i+j+k == scores[pos] && ok(i, j, k)) {
    int plus = Solve(surp - Surp(i, j, k), pos+1, p, n);
    if (i >= p || j >= p || k >= p) ++plus;
    MX(alias, plus);
  }
  return alias;
}

int main() {
  
  int ntc;
  scanf("%d\n", &ntc);
  
  FORN(itc, ntc) {
    cout << "Case #" << (itc+1) << ": ";
    
    int n, s, p;
    cin >> n >> s >> p;
    
    FORN(i, n) {
      cin >> scores[i];
    }
    
    FORN(i, 120) FORN(j, 120) dp[i][j] = -1;
    cout << Solve(s, 0, p, n) << endl;
  }
  
}
