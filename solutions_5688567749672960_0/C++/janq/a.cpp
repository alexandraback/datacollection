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

const int MAXI=10000000;
int v[MAXI];

void solve(){
  int x;
  scanf("%d",&x); 
  printf("%d\n",v[x]);
}

int reversed(int x) {
  int ret = 0;
  while(x>0) {
    ret *= 10;
    ret += x%10;
    x/=10;
  }
  return ret;
}

int main(){
  CL(v);
  VI Q;
  Q.PB(1);
  v[1]=1;
  int have=1;  
  int i=0;
  while(have<MAXI) {
    int x=Q[i++];
    if(x<MAXI) have++;
    int xx = x+1;
    if(xx<MAXI && v[xx]==0) {
      v[xx] = v[x] + 1;
      Q.PB(xx);
    }
    xx=reversed(x);
    if(xx<MAXI && v[xx]==0) {
      v[xx] = v[x] + 1;
      Q.PB(xx);
    } 
  }
  FR(i,1,MAXI) {
    if(v[i]==0) printf("0\n");
  }

  stackSizeUnlimited();
  int pvs; scanf("%d",&pvs);
  FR(ppp,1,pvs+1){
     printf("Case #%d: ",ppp);

     solve();
  }
}


// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
