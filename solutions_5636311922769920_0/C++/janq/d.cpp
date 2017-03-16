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

LL K,C,S;

void solve(){
  scanf("%lld %lld %lld\n",&K,&C,&S);
  if(K == 1) {
    printf("1\n");
    return;
  }  
  vector<LL> v;
  LL w = 0;
  int i = 0;
  while(i < K){
    FOR(j,C) {
      w *= K;
      if(i<K) w += i;
      i++;
    }
    v.PB(w+1);
    w = 0;
  }

  if(v.size() > S) { assert((S <= K - C)); printf("IMPOSSIBLE\n"); return; }
  FORSZ(i,v){ if(i) printf(" "); printf("%lld",v[i]); }  
  PN;
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
