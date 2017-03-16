#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
 
using namespace std;
 
#define PB push_back
#define SZ size()
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define UNIQUE(x) x.erase(unique(ALL(x)),x.end())
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define REPD(x, hi) for (int x=((hi)-1); x>=0; x--)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define FORD(x, lo, hi) for (int x=((hi)-1); x>=(lo); x--)

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef long long LL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;

const int inf = 999999999;

////////////////////////////////////////////////////////////

void solve () {
  int K,C,S;
  cin>>K>>C>>S;
  if (S * C < K) {
    cout << " IMPOSSIBLE";
    return;
  }
  for (int s=0; s*C < K; s++) {
    LL pos = 0;
    for (int d=s*C; d<(s+1)*C && d<K; d++) {
      pos = K*pos + d;
    }
    cout << " " << pos+1;
  }
}

int main () {

  int runs;
  cin >> runs;

  for (int run=1; run<=runs; run++) {
    cout << "Case #" << run << ":";
    solve();
    cout << endl;
  }

  return 0;
}
