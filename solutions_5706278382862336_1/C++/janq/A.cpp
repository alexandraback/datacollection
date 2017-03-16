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

long long P,Q;

void solve(){
  scanf("%lld/%lld\n",&P,&Q);
  int p=0,q=0;
  LL gcd = __gcd(P,Q);
  P/= gcd;
  Q/= gcd;
  while(P%2==0) { p++; P/=2; }
  while(Q%2==0) { q++; Q/=2; }
  if(Q!=1) { printf("impossible\n"); return; }  
  LL x=1;
  FOR(i,q+2) {
    if (x>P) {
      printf("%d\n",q-i+1);
      return;
    }
    x*=2;
  }
  printf("0\n");
  return;

}

int main(){
  int pvs; scanf("%d",&pvs);
  FR(ppp,1,pvs+1){
     printf("Case #%d: ",ppp);

     solve();
  }
}


// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
