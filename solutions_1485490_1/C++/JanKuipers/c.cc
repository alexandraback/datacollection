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

  int Na,Nb;
  scanf ("%d %d",&Na,&Nb);

  VLL na(Na), nb(Nb);
  VI ta(Na), tb(Nb);
  REP(i,Na) scanf ("%lld %d", &na[i], &ta[i]);
  REP(i,Nb) scanf ("%lld %d", &nb[i], &tb[i]);

  LL res = 0;
  VVLL best(Na+1, VLL(Nb+1, 0));
  
  REP(ia,Na) REP(ib,Nb) {
    
    best[ia+1][ib] >?= best[ia][ib];
    best[ia][ib+1] >?= best[ia][ib];
    
    if (ta[ia] == tb[ib]) {
      int ja=ia, jb=ib;
      LL suma=na[ja], sumb=nb[jb];

      while (ja<Na && jb<Nb) {
	res >?= best[ja+1][jb+1] >?= best[ia][ib] + min(suma,sumb);
	
	if (suma < sumb) {
	  ja++;
	  if (ta[ja] == ta[ia]) suma += na[ja];
	}
	else {
	  jb++;
	  if (tb[jb] == tb[ib]) sumb += nb[jb];
	}
      }      
    }
  }

  printf ("%lld", res);
}

int main () {

  int runs;
  scanf ("%i\n",&runs);

  for (int run=1; run<=runs; run++) {
    printf ("Case #%i: ",run);
    solve();
    printf ("\n");
  }

  return 0;
}
