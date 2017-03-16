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


char s[10][10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

void solve(){ 
  bool cons[10]; CL(cons);
  map<char, set<int> > visk;
  FOR(w,10) {
    for(int i = 0; s[w][i] != '\0'; i++ ) {
      visk[s[w][i]].insert(w);
    }
  }
  char r[2500];
  VI ret;
  scanf("%s\n",r);
  int p[256]; CL(p);
  FOR(i,strlen(r)) {
    p[r[i]]++;
  }  
  while(1) {
    bool mam = false;
    for(char c = 'A'; c<='Z'; c++) {
      if(visk[c].size() == 1 ) {
        mam = true;
        int kde = *(visk[c].begin());
        while(p[c]>0) {
          for(int i=0; s[kde][i]!='\0'; i++) {
            p[s[kde][i]]--;
          }
          ret.PB(kde);
        }
        for(int i=0; s[kde][i]!='\0'; i++) {
          visk[s[kde][i]].erase(kde);
        }
      }
    }
    if(!mam) break;
  }
  sort(ALL(ret));
  FORSZ(i,ret) printf("%d",ret[i]); PN;
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
