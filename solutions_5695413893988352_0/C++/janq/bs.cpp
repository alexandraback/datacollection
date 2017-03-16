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
#include <sstream>
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

LL s2ll(string s) { stringstream ss(s); LL x; ss>>x; return x; }

LL besta, bestb;
string bestas, bestbs;
void zlepsi(string a, string b) { 
  if(besta==-1) {
    besta = s2ll(a);
    bestb = s2ll(b);
    bestas = a;
    bestbs = b;
  } else
  if(abs(s2ll(a)-s2ll(b)) < abs(besta-bestb)) {
    besta = s2ll(a);
    bestb = s2ll(b);
    bestas = a;
    bestbs = b;    
  } else
  if(abs(s2ll(a)-s2ll(b)) == abs(besta-bestb)) {    
    if( s2ll(a) < besta) {
     besta = s2ll(a);
     bestb = s2ll(b);
     bestas = a;
     bestbs = b;    
    } else 
    if( s2ll(a) == besta) {
      if(s2ll(b) < bestb) {
       besta = s2ll(a);
       bestb = s2ll(b);
       bestas = a;
       bestbs = b;    
      }
    }
  }
}

bool valid(string a, string ref) {
  if(a.SZ!=ref.SZ) return false;
  FORSZ(i,a) {
    if(a[i]!=ref[i] && ref[i]!='?') return false;
  }
  return true;
}

string getStringValue(int x, int d) {
  char r[50];
  if(d==1) sprintf(r,"%01d",x); else
  if(d==2) sprintf(r,"%02d",x); else
  if(d==3) sprintf(r,"%03d", x);
  return r;
}

void solve(){
  besta=-1; bestb=-1;
  char sa[100],sb[100];
  string a,b;
  scanf("%s %s\n",sa,sb);
  a = sa;
  b = sb;
  FOR(i,1000) FOR(j,1000) {
    if(valid(getStringValue(i, a.SZ), a))
    if(valid(getStringValue(j, b.SZ), b)) 
    zlepsi(getStringValue(i, a.SZ), getStringValue(j, b.SZ));
  }
  printf("%s %s\n",bestas.c_str(), bestbs.c_str());
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
