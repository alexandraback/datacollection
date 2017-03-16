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

int gcd (int a, int b) { return b==0?a:gcd(b,a%b); }

void solve () {

  int Y,X,D;
  scanf ("%d %d %d\n",&Y,&X,&D);

  char m[Y][X+1];
  REP(y,Y)
    scanf ("%s\n",m[y]);

  int sy=-1,sx=-1;
  REP(y,Y) REP(x,X) if (m[y][x]=='X') { sy=y; sx=x; }

  Y-=2;
  X-=2;

  Y*=2;
  X*=2;
  D*=2;
  
  sy*=2;
  sx*=2;
  sy--;
  sx--;
  
  set<pair<int,int> > res;
  
  FOR(dy,-D,D+1) FOR(dx,-D,D+1) {
    if (dy==0 && dx==0) continue;
    int ny=sy; if (dy%2) ny=Y-sy; ny+=dy*Y;
    int nx=sx; if (dx%2) nx=X-sx; nx+=dx*X;
    if ((ny-sy)*(ny-sy) + (nx-sx)*(nx-sx) <= D*D) {
      int g = abs(gcd(ny-sy,nx-sx));
      res.insert(make_pair((nx-sx)/g,(ny-sy)/g));
    }
  }

  printf ("%d",res.size());
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
