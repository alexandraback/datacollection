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
#include <sys/resource.h>
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
void stackSizeUnlimited() { struct rlimit rl; getrlimit(RLIMIT_STACK, &rl); rl.rlim_cur = RLIM_INFINITY; setrlimit(RLIMIT_STACK, &rl); }
///////////////////////////////////////////////////////////////////////////////////
// }}}


void solve(){
  int x,n,m;
  scanf("%d %d %d",&x,&n,&m);
  if(n>m) swap(n,m);
  if(x==1) {
    printf("GABRIEL\n");
  }
  if(x==2) {
    if(n*m%2==0) {
      printf("GABRIEL\n");
    } else {
      printf("RICHARD\n");
    }
  }
  if(x==3) {
    if( (n==2 && m==3) ||
        (n==3 && m==3) ||
        (n==3 && m==4) ) {
      printf("GABRIEL\n");
    } else {
      printf("RICHARD\n");
    }
  }
  if(x==4) {
    if( (n==3 && m==4) ||
        (n==4 && m==4) ) {
      printf("GABRIEL\n");
    } else {
      printf("RICHARD\n");
    }
  }

}

int main(){
  stackSizeUnlimited();
  int pvs; scanf("%d",&pvs);
  FR(ppp,1,pvs+1){
     printf("Case #%d: ",ppp);

     solve();
  }
}


// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
