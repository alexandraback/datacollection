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

#define MAXN 13
#define MAXK 15

int n,m,k; // n=3, m=5, k=7
int p[MAXK];

int s[MAXN];
//vector<int> mm;
map<int,int> mm;
map<vector<int>,double> xmap;

void dfs2(int x,int z) {
   if(x==n) {
      //mm.PB(z);
      mm[z]++;
      return;
   }
   dfs2(x+1,z);
   dfs2(x+1,z*s[x]);
}

inline double prob() {
   mm.clear();
   dfs2(0,1);
   double ret=1.0;
   for(int i=0;i<k;i++) {
      //printf("<%d: %d>\n",p[i],mm[p[i]]);
      ret*=(double)mm[p[i]]/(1<<n);
   }
   return ret;
}

void dfs(int x) {
   if(x==n) {
      double pr=prob();
      //if(pr>1e-9) {
      vector<int> a(s,s+n);
      sort(a.begin(),a.end());
      xmap[a]+=pr;
      //}
      return;
   }
   for(s[x]=2;s[x]<=m;s[x]++)
      dfs(x+1);
}

void solve() {
   xmap.clear();
   dfs(0);
   vector<int> arr;
   double opt=-1.0;
   for(map<vector<int>,double>::iterator it=xmap.begin();it!=xmap.end();it++) {
      if(it->S>opt) {
         opt=it->S;
         arr=it->F;
      }
   }
   for(int i=0;i<arr.size();i++)
      printf("%d",arr[i]); puts("");
}

int main(void) {
   int t,cas=1;
   RI(t);
   while(t--) {
      int qn;
      RI(qn);
      RII(n,m); RI(k);
      printf("Case #%d:\n",cas++);
      for(int qi=0;qi<qn;qi++) {
         for(int i=0;i<k;i++)
            scanf("%d",p+i);
         solve();
      }
   }
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread

