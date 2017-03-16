// @author kelvin
// #includes {{{
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
// }}}
// #defines {{{
#define RI(x) scanf("%d",&(x))
#define RII(x,y) scanf("%d %d",&(x),&(y))
#define RF(x) scanf("%lf",&(x))
#define RS(x) scanf("%s",x)
#define PRI(x) printf("%d\n",x);
#define PR printf
#define MP(x,y) make_pair(x,y)
#define PB(x) push_back(x)
#define POP() pop_back()
#define F first
#define S second
typedef pair<int,int> pii;
// }}}
// #functions {{{
pii operator+(const pii &a,const pii &b) { return MP(a.F+b.F,a.S+b.S); }
pii operator-(const pii &a,const pii &b) { return MP(a.F-b.F,a.S-b.S); }
pii& operator+=(pii &a,const pii &b) { a.F+=b.F; a.S+=b.S; return a; }
pii& operator-=(pii &a,const pii &b) { a.F-=b.F; a.S-=b.S; return a; }
template <class T,class U>
bool cmp_second(const pair<T,U> &a,const pair<T,U> &b) { return a.second<b.second; }
template <class T>
T gcd(T a,T b) { a=abs(a); b=abs(b); while(b) { T t=b; b=a%b; a=t; } return a; }
template <class T>
pair<T,T> ext_gcd(T a,T b) {
   T a0=1,a1=0,b0=0,b1=1;
   if(a<0) { a=-a; a0=-1; }
   if(b<0) { b=-b; b1=-1; }
   while(b) {
      T t,q=a/b;
      t=b; b=a-b*q; a=t;
      t=b0; b0=a0-b0*q; a0=t;
      t=b1; b1=a1-b1*q; a1=t;
   }
   return MP(a0,a1);
}
inline int sg(int x) { return x?(x>0?1:-1):0; }
// }}}

#define OWIN 1
#define XWIN 2
#define DRAW 0
#define INCOMPLETE 3

char gr[4][6];

bool win(char c) {
   for(int i=0;i<4;i++) {
      bool bad=0;
      for(int j=0;j<4;j++)
         if(gr[i][j]!=c&&gr[i][j]!='T') bad=1;
      if(!bad) return 1;
   }
   for(int j=0;j<4;j++) {
      bool bad=0;
      for(int i=0;i<4;i++)
         if(gr[i][j]!=c&&gr[i][j]!='T') bad=1;
      if(!bad) return 1;
   }
   bool bad=0;
   for(int i=0;i<4;i++)
      if(gr[i][i]!=c&&gr[i][i]!='T') bad=1;
   if(!bad) return 1;
   bad=0;
   for(int i=0;i<4;i++)
      if(gr[i][3-i]!=c&&gr[i][3-i]!='T') bad=1;
   if(!bad) return 1;
   return 0;
}

int solve() {
   int cc=0;
   for(int i=0;i<4;i++)
      for(int j=0;j<4;j++)
         if(gr[i][j]!='.') cc++;
   bool owin=win('O');
   bool xwin=win('X');
   assert(!(owin&&xwin));
   if(owin) return OWIN;
   if(xwin) return XWIN;
   if(cc==16) return DRAW;
   else return INCOMPLETE;
}

int main(void) {
   int tn,cas=1;
   RI(tn);
   while(tn--) {
      for(int i=0;i<4;i++)
         RS(gr[i]);
      printf("Case #%d: ",cas++);
      int res=solve();
      if(res==DRAW) puts("Draw");
      else if(res==OWIN) puts("O won");
      else if(res==XWIN) puts("X won");
      else if(res==INCOMPLETE) puts("Game has not completed");
      else assert(false);
   }
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread

