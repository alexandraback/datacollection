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

int x,y;
int de[10];

void solve(){
  de[0] = 1;
  FR(i,1,8) de[i] = de[i-1]*10;
  scanf("%d %d",&x,&y);
  int d;
  for(d=1;d<10;d++) if(y<de[d]) break;
  int ret=0;
  FR(h,x,y+1){
    set<int> hhh;
    FR(i,1,d) {
      int hh = h;
      hh /= de[i];
      hh += (h%de[i]) * de[d-i];
      if(hh < h)
        if(x<= hh && hh<=y) {          
          hhh.insert(hh);
        }      
    }    
    ret+=hhh.size();
  }
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
