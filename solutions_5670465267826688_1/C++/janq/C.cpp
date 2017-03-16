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

struct Element{
  public:
  char v;
  short sign;
  Element(char v): v(v) { sign=1;};
  Element(char v, short sign): v(v), sign(sign) {};
};

Element operator *(const Element &a, const Element &b) {
  char v='x';
  short sign = 1;
  if(a.v == '1') {
    v= b.v;
  } else
  if(a.v == 'i') {
    if(b.v == '1') v = 'i';
    if(b.v == 'i') { v = '1'; sign = -1; }
    if(b.v == 'j') { v = 'k'; }
    if(b.v == 'k') { v = 'j'; sign = -1; }  
  } else
  if(a.v == 'j') {
    if(b.v == '1') v = 'j'; else
    if(b.v == 'i') { v = 'k'; sign = -1; } else
    if(b.v == 'j') { v = '1'; sign = -1; } else
    if(b.v == 'k') { v = 'i'; }      
  } else
  if(a.v == 'k') {
    if(b.v== '1') v = 'k'; else
    if(b.v == 'i') { v = 'j'; } else
    if(b.v == 'j') { v = 'i'; sign = -1; } else
    if(b.v == 'k') { v = '1'; sign = -1; }      
  }  
  assert( v!= 'x');
  Element ret = Element(v, a.sign * b.sign * sign);
  return ret;
}

bool operator == (const Element &a, const Element &b) {
  return (a.v == b.v) && (a.sign == b.sign);
}

bool operator != (const Element &a, const Element &b) {
  return (a.v != b.v) || (a.sign != b.sign);
}


int n,x;


void solve(){
  scanf("%d %d\n",&n,&x);
  if(x>64) {
    x = 64 + x%64;
  }
  char r[10005];
  scanf("%s\n",r);
  vector<Element> h;
  FOR(xx,x) FOR(i,n) h.PB(Element(r[i]));
  Element t = Element('1');
  int firstI = -1;
  FORSZ(i,h) {
    t = t * h[i];
    if(firstI == -1 && t == Element('i')) {
      firstI = i;
    }
  }
  if(t != Element('1',-1)) {
    printf("NO\n"); return;
  }
  t = Element('1');
  int lastK = -1;
  for(int i = h.SZ-1;i>=0;i--) {
    t =  h[i] * t;
    if(lastK== -1 && t == Element('k')) {
      lastK = i;
    }
  }
  if(firstI == -1 || lastK == -1) {
    printf("NO\n"); return;
  }
  if(firstI < lastK + 1) {
    printf("YES\n"); 
  } else {
    printf("NO\n");
  }

}

int main(){
  stackSizeUnlimited();
  int pvs; scanf("%d\n",&pvs);
  FR(ppp,1,pvs+1){
     printf("Case #%d: ",ppp);

     solve();
  }
}


// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
