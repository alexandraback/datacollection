#include <assert.h>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <string>
#include <list>
#include <stack>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <list>
#define INF 0x3fffffff
#define LINF 0x3fffffffffffffffll
#define DINF 1e100
#define EPS 0.000000000001

typedef long long ll;
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define PDD pair<double, double>
#define PIL pair<int, ll>
#define PLI pair<ll, int>
#define PID pair<int, double>
#define PDI pair<double, int>
#define PLD pair<ll, double>
#define PDL pair<double, ll>

#define NUL(x) memset(x, 0, sizeof(x))
#define MINUS(x) memset(x, 0xff, sizeof(x))
#define PQ(x) priority_queue< x >  //highest first
#define PQR(x) priority_queue< x , vector< x > , greater < x > > //lowest first
#define MP make_pair
#define PB push_back
#define IT(x) for (typeof((x).begin()) it = (x).begin() ; it != (x).end() ; it++)
#define IT2(x) for (typeof((x).begin()) it2 = (x).begin() ; it2 != (x).end() ; it2++)
#define FOR(i, a, b) for (int i = (a) ; i< (b) ; i++)
#define DEB(x...) fprintf(stderr,x)
//#define DEB

using namespace std;

struct entry{
  int Y;
  int i;
  bool operator<(const entry other) const {
    return Y>other.Y;
  }
};

bool testc(int tc=0)
{
  int n;
  int X = 0;

  scanf("%i ", &n);
  vector<entry> Y(n);
  FOR(i,0,n) {
    int v;
    scanf("%i ", &v);
    Y[i]=(entry){v,i};
    X+=v;
  }
  sort(Y.begin(), Y.end());
  vector<double> sol(n, 2.0);
  FOR(i,0,n) {
    int G = X-Y[i].Y;
    
    FOR(j,0,i+1) {
      int A = n-1-j;
      double m = 1.*(X+G-A*Y[i].Y)/(A*X+X);
      //DEB("i %i j %i G %i A %i m %lf\n", i, j, G, A, m);
      //      DEB("%i possible: %lf\n", Y[i].i, m);
      sol[Y[i].i] = max(0., min(m, sol[Y[i].i]));
      G -= Y[j].Y;
    }
  }
  printf("Case #%i:", tc);
  IT(sol) printf(" %lf", *it*100);
  printf("\n");
}


int main()
{
  int t;
  scanf("%i ",&t);
  FOR(i,0,t)
    testc(i+1);

  /*
    while(testc());
  */
  
  return 0;
}
