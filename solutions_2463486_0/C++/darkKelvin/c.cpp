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

#define MAXL 110
#define HALFL (MAXL/2)

const int maxlen=50;
const int modlen=4;
const int bigmod=10000;
const char prtstr[]="%04d";

class Bignum {
   public:
      int len;
      int s[maxlen];
      Bignum() { len=0; }
      Bignum(int x) {
         len=0;
         while(x) {
            s[len++]=x%bigmod;
            x/=bigmod;
         }
      }
      Bignum(const char *str) {
         int sl=strlen(str);
         if(!strcmp(str,"0")) {
            len=0;
            return;
         }
         len=(sl+modlen-1)/modlen;
         for(int i=0;i<len;i++) {
            s[i]=0;
            for(int j=modlen-1;j>=0;j--)
               s[i]=s[i]*10+(i*modlen+j<sl?str[sl-(i*modlen+j)-1]-'0':0);
         }
         zerojust();
      }
      void print() const {
         if(len) {
            printf("%d",s[len-1]);
            for(int i=len-2;i>=0;i--)
               printf(prtstr,s[i]);
         } else printf("0");
         puts("");
      }
      Bignum& operator+=(const Bignum &b) {
         int i,carry=0;
         for(i=0;i<len||i<b.len||carry;i++) {
            s[i]=(i<len?s[i]:0)+(i<b.len?b.s[i]:0)+carry;
            if(s[i]>=bigmod) {
               s[i]-=bigmod;
               carry=1;
            } else carry=0;
         }
         len=i;
         return *this;
      }
      Bignum operator+(const Bignum &b) const {
         return Bignum(*this)+=b;
      }
      Bignum& operator-=(const Bignum &b) {
         int i,borrow=0;
         for(i=0;i<len||i<b.len;i++) {
            s[i]=(i<len?s[i]:0)-(i<b.len?b.s[i]:0)-borrow;
            if(s[i]<0) {
               s[i]+=bigmod;
               borrow=1;
            } else borrow=0;
         }
         assert(!borrow);
         zerojust();
         return *this;
      }
      Bignum operator-(const Bignum &b) const {
         return Bignum(*this)-=b;
      }
      void leftshift() {
         if(!len) return;
         for(int i=len-1;i>=0;i--)
            s[i+1]=s[i];
         s[0]=0;
         len++;
      }
      Bignum& operator*=(int b) {
         int i,carry=0;
         for(i=0;i<len||carry;i++) {
            s[i]=(i<len?s[i]:0)*b+carry;
            carry=s[i]/bigmod;
            s[i]%=bigmod;
         }
         len=i;
         return *this;
      }
      Bignum operator*(int b) const {
         return Bignum(*this)*=b;
      }
      Bignum operator*(const Bignum &b) const {
         Bignum c;
         for(int i=len-1;i>=0;i--) {
            c.leftshift();
            c+=b*s[i];
         }
         return c;
      }
      void zerojust() {
         while(len&&!s[len-1]) --len;
      }
      bool operator<(const Bignum &b) const {
         if(len!=b.len) return len<b.len;
         for(int i=len-1;i>=0;i--)
            if(s[i]!=b.s[i]) return s[i]<b.s[i];
         return 0;
      }
      bool operator<=(const Bignum &b) const {
         return !(b<*this);
      }
      Bignum& operator/=(int b) {
         int carry=0;
         for(int i=len-1;i>=0;i--) {
            s[i]+=carry*bigmod;
            carry=s[i]%b;
            s[i]/=b;
         }
         zerojust();
         return *this;
      }
      Bignum operator/(int b) const {
         return Bignum(*this)/=b;
      }
};

vector<Bignum> pal;

void dfs(int l,char *s,int x,int rem) {
   if(x*2>=l) {
      pal.PB(s);
      //printf("(%d)",x);
      //pal.back().print();
      return;
   }
   for(int z=(x?0:1);z<=2;z++) {
      int drem=0;
      bool ismid=(x*2+1==l);
      if(ismid) {
         if(z==1) drem=1;
         else if(z==2) drem=4;
      } else {
         if(z==1) drem=2;
         else if(z==2) drem=8;
      }
      s[x]=s[l-x-1]='0'+z;
      if(drem<=rem) dfs(l,s,x+1,rem-drem);
   }
}

void pre() {
   pal.PB(1);
   pal.PB(2);
   pal.PB(3);
   for(int l=2;l<HALFL;l++) {
      char str[l+1];
      str[l]='\0';
      memset(str,'0',sizeof(char)*l);
      dfs(l,str,0,9);
   }
}

Bignum big_sqrt(Bignum s) {
   Bignum l=0,r=s+1;
   while(l+1<r) {
      Bignum m=(l+r)/2;
      //printf("l "); l.print();
      //printf("r "); r.print();
      //printf("m "); m.print();
      if(m*m<=s) l=m;
      else r=m;
   }
   return l;
}

int count_leq(Bignum rb) {
   return upper_bound(pal.begin(),pal.end(),rb)-pal.begin();
}


int solve(Bignum lsqr,Bignum rsqr) {
   Bignum lb=big_sqrt(lsqr-1);
   Bignum rb=big_sqrt(rsqr);
   //lb.print();
   //rb.print();
   return count_leq(rb)-count_leq(lb);
}

int main(void) {
   int t,cas=1;
   /*Bignum x("29835998362");
   Bignum r=big_sqrt(x);
   r.print();*/
   pre();
   RI(t);
   while(t--) {
      char lstr[MAXL],rstr[MAXL];
      RS(lstr);
      RS(rstr);
      printf("Case #%d: %d\n",cas++,solve(lstr,rstr));
   }
   
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread

