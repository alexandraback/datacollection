#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <queue>
#include <cassert>
#include <bitset>
#include <climits>
#include <cfloat>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<int, int> pii;

#define FF first
#define SS second

#define FOR(v, s, e) for (int v = s; v < e; v++)
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define FI(c) for (ll i = 0; i < c; ++i)
#define FJ(s,c) for (ll j = s; j < c; ++j)
#define FK(s,c) for (ll k = s; k < c; ++k)
#define MP(X,Y) make_pair(X,Y)
// end boilerplate code...

map<pii, ll> dp;
vector<int> vals;

ll maxval;
ll E, R, N;

void start(int act, int e, ll val) {
  //pair<map<pii, ll>::iterator, bool> ret = dp.insert(MP(MP(act, e), val));
  maxval = max(maxval, val);
  if (act == N) return;
  FJ(0, e+1) {
    start(act+1, min(E, e-j+R), val + j*vals[act]);
  }
}

void runcase() {
  maxval = 0;
  dp.clear();
  vals.clear();
  cin >> E >> R >> N;
  vals.resize(N);
  FI(N) {
    cin >> vals[i];
  }
  start(0, E, 0);
  cout << maxval << endl;
}

int main() {
  cout << setprecision(9);
/* *** codejam style *** */
  int case_count;
  cin >> case_count;
  for (int i = 0; i < case_count; i++) {
    cout << "Case #" << (i+1) << ": ";
    runcase();
  }
/* *** because I'm awesome *** */
  return 0;
}

