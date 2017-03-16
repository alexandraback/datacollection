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
map<LL,LL> ako;
vector<LL> viem;
LL a[500];

void vypis(LL x){
  if(ako[x] == 0) return;
  printf("%lld ",ako[x]);
  vypis(x - ako[x]);
}

void solve(){
  int n; scanf("%d",&n);
  viem.clear(); ako.clear();
  viem.PB(0); ako[0]=0;
  FOR(i,n) scanf("%lld",&a[i]);
  FOR(i,n) {
    set<LL> nove;
    FOR(j,10000) nove.insert(viem[rand()%(int) viem.SZ] + a[i]);
    FORIT(it, nove){
      if(ako.count(*it)){
        printf("%lld ",a[i]); vypis((*it) - a[i]); PN;
        vypis(*it); PN;
        goto endy;
      } else {
        ako[*it] = a[i];
        viem.PB(*it);
      }
    }
  }
endy: 
  ;
}

int main(){
  int pvs; scanf("%d",&pvs);
  FR(ppp,1,pvs+1) if(ppp>=9){
     printf("Case #%d: ",ppp);

     solve();
  }
}


// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
