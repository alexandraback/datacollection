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

#define MAXN 10500

const long long infll=1000000000000000100LL;

class Node {
   public:
      int vl,vr;
      long long add,minh;
      Node *_l,*_r;
      Node(int _vl,int _vr,long long _add):vl(_vl),vr(_vr),add(_add) {
         minh=add;
         _l=_r=NULL;
      }
      ~Node() {
         delete _l;
         delete _r;
      }
      Node *left() {
         if(!_l) _l=new Node(vl,(vl+vr)>>1,0);
         return _l;
      }
      Node *right() {
         if(!_r) _r=new Node(((vl+vr)>>1)+1,vr,0);
         return _r;
      }
      void up() {
         minh=min(left()->minh,right()->minh)+add;
      }
      void insert(int l,int r,long long a) {
         //fprintf(stderr,"insert %d %d %lld\n",l,r,a);
         if(vl==l&&vr==r) {
            add+=a;
            minh+=a;
         } else {
            int m=(vl+vr)>>1;
            if(r<=m) left()->insert(l,r,a);
            else if(l>m) right()->insert(l,r,a);
            else {
               left()->insert(l,m,a);
               right()->insert(m+1,r,a);
            }
            up();
         }
      }
      long long query(int l,int r) {
         if(vl==l&&vr==r) {
            return minh;
         } else {
            int m=(vl+vr)>>1;
            if(r<=m) return left()->query(l,r)+add;
            else if(l>m) return right()->query(l,r)+add;
            else return min(left()->query(l,m),right()->query(m+1,r))+add;
         }
      }
};

int maxe,rec,n;
int co[MAXN];

inline long long use(priority_queue<pii> &pq,Node &seg,int amt) {
   long long ret=0;
   // try to use <amount>
   while(amt) {
      //fprintf(stderr,"<amt=%d>\n",amt);
      //assert(pq.size());
      if(!pq.size()) break;
      int v=pq.top().S;
      int a=min((long long)amt,seg.query(v,n));
      seg.insert(v,n,-a);
      ret+=(long long)a*co[v];
      amt-=a;
      //fprintf(stderr,"v=%d rem=%d a=%d\n",v,(int)seg.query(v,n),a);
      if(seg.query(v,n)==0) pq.pop();
   }
   return ret;
}

long long solve() {
   long long sol=0;
   Node seg(0,n,maxe);
   priority_queue<pii> pq;
   co[n]=0;
   for(int i=0;i<n;i++) {
      //fprintf(stderr,"i=%d\n",i);
      pq.push(MP(co[i],i));
      sol+=use(pq,seg,rec);
      seg.insert(i+1,n,rec);
   }
   pq.push(MP(co[n],n));
   sol+=use(pq,seg,maxe);
   return sol;
}

int main(void) {
   int t,cas=1;
   RI(t);
   while(t--) {
      RII(maxe,rec); RI(n);
      for(int i=0;i<n;i++)
         RI(co[i]);
      printf("Case #%d: %lld\n",cas++,solve());
   }

   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread

