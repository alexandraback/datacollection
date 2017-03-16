#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <cassert>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define FN "c"

#define MAXP 10000000
bool iscomp[MAXP];
int pr[MAXP],prc;
void getPrimes() {
	CLEAR(iscomp); prc=0;
	for (int i = 2; i < MAXP; i++) if (!iscomp[i])	{
		pr[prc++]=i;
		if (i <= MAXP/i) for (int j = i*i; j < MAXP; j+=i)
			iscomp[j]=true;
	} }

int n;

bool stupid(LL mask) {
  int divs[10];
  FOR(base,2,10) {
    int div = -1;
    REP(j,prc) {
      int x = 0;
      REPD(i,n){
        x = x*base + ((mask & (1LL<<i))? 1 : 0);
        x %= pr[j];
      }
      if (x == 0) {
        div = pr[j];
        break;
      }
    }
    if (div == -1) return false;
    divs[base] = div;
  }
  REPD(i,n){
    printf("%d",(mask & (1LL<<i))? 1 : 0);
  }
  FOR(base,2,10) printf(" %d",divs[base]);
  printf("\n");
  fflush(stdout);
  return true;
}

int main()
{
  //freopen(FN ".in","r",stdin);
  //freopen(FN ".out","w",stdout);
  getPrimes();

  int tests,J;
  scanf("%d %d %d",&tests,&n,&J);
  assert(tests==1);
  srand(123);
  int cnt = 0;
  printf("Case #1:\n");
  for (LL mask = (1LL<<(n-1))+1; mask < (1LL<<n); mask += 2) {
    if (stupid(mask)) {
      ++cnt;
    }
    if (cnt == J) return 0;
  }
  fprintf(stderr,"BAD!\n");
  return 0;
}
