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

bool getRovnost(string &a, string &b) {
  FORSZ(i,a) {
    if(a[i]=='?' && b[i]!='?') {
      a[i]=b[i];
    } else
    if(a[i]!='?' && b[i]=='?') {
      b[i] = a[i];
    } else
    if(a[i]=='?' && b[i]=='?') {
      a[i]=b[i]='0';
    } else
    if(a[i]!=b[i])
      return false;
  }
  return true;
}

bool getRozdiel(int ro, int smer, string &a, string &b) {
  FORSZ(i,a) {
   if(i<ro) {
    if(a[i]=='?' && b[i]!='?') {
      a[i]=b[i];
    } else
    if(a[i]!='?' && b[i]=='?') {
      b[i] = a[i];
    } else
    if(a[i]=='?' && b[i]=='?') {
      a[i]=b[i]='0';
    } else
    if(a[i]!=b[i])
      return false;    
   } else
   if(i==ro){
     if(smer==0) {
       if(a[i]=='?' && b[i] == '?') {
         a[i]='0';
         b[i]='1';
       } else 
       if(a[i]=='?') {
         if(b[i]>='1') {
           a[i] = b[i] -1;
         } else {
           return false;
         }
       } else
       if(b[i]=='?') {
         if(a[i]<='8') {
           b[i] = a[i] + 1;
         } else {
           return false;
         }
       } else {
         if(a[i] >= b[i]) return false;
       }
     }   
     if(smer==1) {
       if(a[i]=='?' && b[i] == '?') {
         a[i]='1';
         b[i]='0';
       } else 
       if(b[i]=='?') {
         if(a[i]>='1') {
           b[i] = a[i] -1;
         } else {
           return false;
         }
       } else
       if(a[i]=='?') {
         if(b[i]<='8') {
           a[i] = b[i] + 1;
         } else {
           return false;
         }
       } else {
         if(b[i] >= a[i]) return false;
       }       
     }
   } else
   if( i> ro) {
     if(smer==0) {
       if(a[i]=='?') a[i] = '9';
       if(b[i]=='?') b[i] = '0';
     } else 
     if(smer==1) {
       if(a[i]=='?') a[i] = '0';
       if(b[i]=='?') b[i] = '9'; 
     }
   }
  }
  return true;
}


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

void solve(){
  char sa[100],sb[100];
  string a,b;
  scanf("%s %s\n",sa,sb);
  a = sa;
  b = sb;
  // skusit rovnost..
  string wa=a,wb=b;
  if( getRovnost(wa,wb) ) {
    printf("%s %s\n",wa.c_str(),wb.c_str());
    return;
  }
  besta=-1; bestb=-1;
  FORSZ(ro,a) { 
    string wa=a, wb=b;
    if(getRozdiel(ro, 0, wa, wb) ) {
      zlepsi(wa,wb);
    } 
    wa=a; wb=b;
    if(getRozdiel(ro, 1, wa, wb) ) {
      zlepsi(wa,wb);
    } 
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
