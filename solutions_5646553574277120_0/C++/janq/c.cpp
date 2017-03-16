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

int h[50];
bool d[50];
bool mam[50];
bool viem[32];
VI pr;

int C,D,V;
bool uzviem=false;

void doit(int q, int poc) {
  if(uzviem) return;
  if(q>V && poc>0) {
    return;
  }
  if(q>V && poc==0) {
    CL(viem);    
    //testovat, ci vieme..
    viem[0]=true;
    FORSZ(i,pr) {
      int x = pr[i];
      for(int z=V-x;z>=0;z--) if(viem[z]) {
        viem[z+x]=true;
      }
    }
    bool ok=true;
    for(int i=1;i<=V;i++){
      if(!viem[i]) {
        ok=false;
        break;
      }
    }
    if(ok) uzviem=true;
    return;
  }
  
  doit(q+1, poc);
  if(!mam[q] && poc>0) {
    pr.push_back(q);
    doit(q+1,poc-1);
    pr.pop_back();
  }
}

void solve(){
  scanf("%d %d %d",&C,&D,&V);
  CL(mam);  
  FOR(i,D) { scanf("%d",&h[i]); mam[h[i]]=true; }
  uzviem=false;
  FOR(poc,V) {    
    pr.clear();
    FOR(i,D) pr.PB(h[i]);
    doit(1,poc);      
    if(uzviem) { 
      printf("%d\n",poc);
      return;
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
