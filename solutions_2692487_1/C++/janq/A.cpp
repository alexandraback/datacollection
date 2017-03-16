// pre-written code {{{
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <numeric>
#include <iostream>
#include <cassert>
#include <set>
#define FOR(i,n) for(int _n=n,i=0;i<_n;++i)
#define FR(i,a,b) for(int _b=b,i=a;i<_b;++i)
#define CL(x) memset(x,0,sizeof(x))
#define PN printf("\n");
#define MP make_pair
#define PB push_back
#define SZ size()
#define ALL(x) x.begin(),x.end()
#define FORSZ(i,v) FOR(i,v.size())
#define FORIT(it,x) for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
using namespace std;
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long LL;
///////////////////////////////////////////////////////////////////////////////////
// }}}


int n;
long long A; 
long long e[105];
int r[105];

void solve(){
  scanf("%lld %d",&A,&n);
  FOR(i,n) scanf("%lld",&e[i]);
  sort(e,e+n);
  r[0] = 0;
  int w = 0;
  FOR(i,n) {
    while(A <= e[i]) {
      w++;
      A += A - 1;
      if(w > 2*n) break;
    }
    A += e[i];
    r[i+1] = w;
  }
//  FOR(i,n+1) printf(" %d",r[i]); PN;
  int ret = n;
  FOR(i,n+1) ret = min(ret, n-i + r[i]); 
  printf("%d\n",ret);

}

int main(){
  int pvs; scanf("%d",&pvs);
  FR(ppp,1,pvs+1){
     printf("Case #%d: ",ppp);

     solve();
  }
}


// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
