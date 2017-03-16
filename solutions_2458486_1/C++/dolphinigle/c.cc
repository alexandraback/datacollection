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

int need[405];
vint keys[405];
int nk, nc;

vint chest_of_key[405];
int dp[405];

int dgrab[405];
int dgcnt = 0;
int targ;

int Dfs(int keynum, const vint& op) {
  if (keynum == targ) return 1;
  if (dgrab[keynum] == dgcnt) return 0;
  dgrab[keynum] = dgcnt;
  FORIT(it, chest_of_key[keynum]) if (!op[*it]) FORIT(jt, keys[*it]) if (Dfs(*jt, op)) return 1;
  return 0;
}

int HasSelfRoute(int chest, const vint& op) {
  if (dp[chest] == 0) return 0;
  // check
  ++dgcnt;
  targ = need[chest];
  FORIT(it, keys[chest]) if (Dfs(*it, op)) return 1;
  return dp[chest] = 0;
}

int IsPossible(vint op, vint my) {
  // count required keys
  int done = 1;
  FORIT(it, op) if (!(*it)) done = 0;
  if (done) return 1;
  //cout << "TEST" << endl;
  vint req(202, 0);
  FORN(i, nc) if (!op[i]) req[need[i]] += 1;
  // use duplicate / must keys
  //cout << "DUPLICATE" << endl;
  FORN(i, nc) if (!op[i] && (my[need[i]] > 1 || my[need[i]] >= req[need[i]])) {
    // open!
    //cout << "SO OPEN " << i << endl;
    op[i] = 1;
    my[need[i]] -= 1;
    FORIT(it, keys[i]) my[*it] += 1;
    return IsPossible(op, my);
  }
  // open one with self-route
  //cout << "SELF ROUTE" << endl;
  FORN(i, nc) if (!op[i] && my[need[i]] > 0) {
   // cout << i << endl;
    assert(my[need[i]] == 1);
    if (HasSelfRoute(i, op)) {
      // open this
      op[i] = 1;
      my[need[i]] -= 1;
      FORIT(it, keys[i]) my[*it] += 1;
      return IsPossible(op, my);
    }
  }
  //cout << "FAILED" << endl;
  return 0;
}

int main() {
  int ntc;
  cin >> ntc;
  FORN(itc, ntc) {
    cout << "Case #" << (itc+1) << ": ";
    cin >> nk >> nc;
    vint initk(202);
    FORN(i, nk) {
      int x;
      cin >> x;
      initk[x] += 1;
    }
    FORN(i, 405) chest_of_key[i].clear();
    FORN(i, nc) {
      cin >> need[i];
      chest_of_key[need[i]].PB(i);
      int nk;
      cin >> nk;
      keys[i].clear();
      FORN(j, nk) {
        int z;
        cin >> z;
        keys[i].PB(z);
      }
    }
    vint opened(nc, 0);
    vint steps;
    int failed = 0;
    while (true) {
     // cout << "OH HAI" << endl;
      int cont = 0;
      FORN(i, nc) if (!opened[i]) cont = 1;
      if (!cont) break;
      int yes = 0;
      FORN(i, nc) if (!opened[i] && initk[need[i]] > 0) {
        // try this one
        vint cop = opened;
        vint cinit = initk;
        cop[i] = 1;
        cinit[need[i]] -= 1;
        FORIT(it, keys[i]) cinit[*it] += 1;
        FORN(j, nc) dp[j] = -1;
       // cout << "opened chest " << i << endl;
        if (IsPossible(cop, cinit)) {
          opened = cop;
          initk = cinit;
          steps.PB(i);
          yes = 1;
          break;
        }
      }
      if (yes) continue;
      failed = 1;
      break;
    }
    if (!failed) {
      FORN(i, SZ(steps)) {
        if (i) cout << " ";
        cout << steps[i] + 1;
      }
      cout << endl;
    } else {
      cout << "IMPOSSIBLE" << endl;
    }
  }
}
