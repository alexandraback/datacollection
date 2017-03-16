using namespace std;
 
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
 
#define PB push_back
#define SZ size()
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define UNIQUE(x) x.erase(unique(ALL(x)),x.end())
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define REPD(x, hi) for (int x=((hi)-1); x>=0; x--)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define FORD(x, lo, hi) for (int x=((hi)-1); x>=(lo); x--)
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)

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

/////////////////////////////////////////////////////////////////////////////////////////////////

void solve () {

  double D;
  int N,A;
  scanf ("%lf %d %d",&D,&N,&A);
  N++;
  
  VD t(N), x(N);
  FOR(i,1,N) scanf ("%lf %lf",&t[i],&x[i]);

  t[0] = 0;
  x[0] = 0;
  
  t[N-1] = t[N-2] + (D-x[N-2])/(x[N-1]-x[N-2]) * (t[N-1]-t[N-2]);
  x[N-1] = D;
  
  REP(ai,A) {
    double a;
    scanf ("%lf",&a);

    double T=0, V=0;
    
    FOR(i,1,N) {
      T += (sqrt(V*V+2*a*(x[i]-x[i-1])) - V) / a;
      T = max(T, t[i]);
      V = sqrt(2*a*x[i]);
    }
    
    printf ("%.9lf\n", T);
  }
}

int main () {

  int runs;
  scanf ("%i\n",&runs);

  for (int run=1; run<=runs; run++) {
    printf ("Case #%i:\n",run);
    solve();
  }

  return 0;
}
