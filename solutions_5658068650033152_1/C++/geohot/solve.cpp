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
#define typeof __typeof__
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

#define BACKUP oldX = currX; oldY = currY; oldADD = currADD;
#define RESTORE currX = oldX; currY = oldY; currADD = oldADD;
#define COMPUTE \
  tot = (currX * currY) - 4 + currADD; \
  ts = (currX-2)*2 + (currY-2)*2 + currADD;
  //cout << currX << "x" << currY << " + " << currADD << " surrounded " << tot << " with " << ts << endl;


int runcase() {
  int K, N, M;
  cin >> N >> M >> K;
  
  // an upper bound is the rectangle on the grid border
  // the outer 4 can be removed at will
  // then we have to munch in on the rectangle, always munch on the longer side
  // lose 2 stones for each munch
  int currX = N;
  int currY = M;
  int currADD = 4;

  int oldX, oldY, oldADD;

  // special case, can't surround here
  if (currX < 3 || currY < 3 || K < 5) return K;

  int tot, ts;

  
  COMPUTE;
  while (tot >= K && currADD > 0) {
    BACKUP;
    currADD--;
    COMPUTE;
  }

  while (tot >= K) {
    BACKUP;
    if (currX >= currY) currX--;
    else currY--;
    COMPUTE;
  }

  // special case
  if (tot+1 == K) { currADD++; }
  else { RESTORE; }

  COMPUTE;
  
  // special case
  int cornerHACKS = 0;
  while ((tot-2) >= K && cornerHACKS < 4) { 
    //cout << K << " " << tot << " " << cornerHACKS << endl;
    tot -= 2; cornerHACKS++; }

  return ts - cornerHACKS;
}

int main() {
  cout << setprecision(9);
/* *** codejam style *** */
  int case_count;
  cin >> case_count;
  for (int i = 0; i < case_count; i++) {
    cout << "Case #" << i+1 << ": " << runcase() << endl;
  }
/* *** because I'm awesome *** */
  return 0;
}

