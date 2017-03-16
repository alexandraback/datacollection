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
int a[20];
const int MAXI = 100000*20+5;
int ako[MAXI];

void vypis(int x){
  if(ako[x]==-1) return;
  printf("%d ",ako[x]);
  x-=ako[x];
  vypis(x);
}

void solve(){
  CL(ako);
  scanf("%d",&n);
  FOR(i,n) scanf("%d",&a[i]);
  ako[0]=-1;
  FOR(i,n){
    for(int x=MAXI-1;x>=a[i];x--){
      if(ako[x]==0){
        if(ako[x-a[i]]!=0) ako[x] = a[i];
      } else {
        if(ako[x-a[i]]!=0) {
          //mame riesenie..
          vypis(x); PN;
          printf("%d ",a[i]); vypis(x-a[i]); PN;
          goto endy;
        }
      }      
    }
  }
  printf("Impossible\n");
endy:
  ;
}

int main(){
  int pvs; scanf("%d",&pvs);
  FR(ppp,1,pvs+1){
     printf("Case #%d:\n",ppp);
     solve();
  }
}


// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
