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
  int N,J;
  cin >> N >> J;
  long long from = (1LL << (N-1)) + 1;
  for (long long x = from;; x += 2) {
    vector<int> bits(N);
    long long y = x;
    for (int i=0; i<N; i++) {
      bits[i] = y & 1;
      y >>= 1;
    }
    bool isgood = true;
    VLL divs;
    for (int base = 2; base <= 10; base++) {
      long long z = 0;
      REPD(i,N) z = base*z + bits[i];
      bool isprime = true;
      for (long long div = 2; div < 100; div++) {
	if (z % div == 0) {
	  divs.PB(div);
	  isprime = false;
	  break;
	}
      }
      if (isprime) {
	isgood = false;
	break;
      }
    }
    if (isgood) {
      REPD(i,N) cout << bits[i];
      for(int div : divs) cout << " " << div;
      cout<<endl;
      J--;
      if (J == 0) break;
    }
  }
}

int main () {

  int runs;
  cin >> runs;

  for (int run=1; run<=runs; run++) {
    cout << "Case #" << run << ":" << endl;
    solve();
  }

  return 0;
}
