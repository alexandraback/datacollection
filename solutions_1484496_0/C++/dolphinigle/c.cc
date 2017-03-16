// Authored by dolphinigle
// GCJ 2012 1B
// 5 May 2012

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

ll vals[25];

void Print(int mask) {
  int init = 1;
  FORN(i, 20) if (mask & (1 << i)) {
    if (!init) cout << " ";
    init = 0;
    
    cout << vals[i];
  }
  cout << endl;
}

int main() {
  
  int ntc;
  cin >> ntc;
  
  FORN(itc, ntc) {
    cout << "Case #" << (itc+1) << ":\n";
    map<ll, int> jew;
    int n;
    cin >> n;
    FORN(i, n) cin >> vals[i];
    int ok = 0;
    FORN(i, (1 << 20)) {
      if (i == 0) continue;
      ll sum = 0LL;
      FORN(j, 20) if (i & (1 << j)) sum += vals[j];
      if (jew.count(sum)) {
        // found
        int partner = jew[sum];
        Print(i);
        Print(partner);
        ok = 1;
        break;
      }
      jew[sum] = i;
    }
    if (!ok) {
      cout << "Impossible" << endl;
    }
  }
  
}
