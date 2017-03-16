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


char k[100];
char t[100];
char v[100];
int K,L,S;
int maxvysk=0;
long double ret = 0.0;

void doit(int q) {
  if(q==S) {    
    //hotovo
    int vysk=0;
    FOR(z,S-L+1) {
      bool ok = true;
      FOR(i,L) {        
        if(t[i]!=v[z+i]) {
          ok=false;
        }
      }
      if(ok) vysk++;
    }
    maxvysk = max(maxvysk, vysk);    
    ret += vysk;
  } else {
    FOR(i,K) {
      v[q] = k[i];
      doit(q+1);
    }
  }  
}


void solve(){
  scanf("%d %d %d\n",&K,&L,&S);
//  printf("%d %d %d\n",K,L,S);
  scanf("%s\n",k);
  scanf("%s\n",t);
  ret = 0.0;    
  maxvysk = 0;
  doit(0);
  long double w = maxvysk;
  FOR(i,S) ret/=K;
//  printf("maxvysk: %lf\n",(double) w);
  printf("%.8lf\n",(double)(w-ret));
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
