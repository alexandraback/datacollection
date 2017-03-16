#include<stdio.h>
#include <stdio.h>
#include <math.h>
#include<cstring>
#include <vector>
#include <string>
#define base 1000000000
#define base2 ((ull) base * base)
#define KARATSUBA 111
#define fix(x) {x.resize(x[0]+3); x[x[0]+1]=x[x[0]+2]=0;}
#define ull unsigned long long

using namespace std;

int nrdiv=0;

class BigInt{
public:
      vector <unsigned> a;
      int semn;
      inline BigInt();
      inline BigInt(long long nr);
      inline BigInt(vector<unsigned> b);
      inline BigInt& operator+=(const BigInt &b);
      inline BigInt& operator+=(long long k);
      inline friend BigInt operator+(const BigInt &x, const BigInt &y);
      inline friend BigInt operator-(const BigInt &x, const BigInt &y);
      inline BigInt& operator*=(int k);
      inline friend BigInt operator*(const BigInt &x, const BigInt &y);
      inline friend BigInt operator/(const BigInt &x, const BigInt &y);
      inline friend BigInt operator%(const BigInt &x, const BigInt &y);
      inline BigInt& operator/=(int k);
      int operator%(int k);
      inline friend int operator==(const BigInt &x, const BigInt &y);
      inline friend int operator!=(const BigInt &x, const BigInt &y);
      inline friend int operator<(const BigInt &x, const BigInt &y);
      inline friend int operator<=(const BigInt &x, const BigInt &y);
      inline friend int operator>(const BigInt &x, const BigInt &y);
      inline friend int operator>=(const BigInt &x, const BigInt &y);
      inline void shr(unsigned k);
      inline void shl(unsigned k);
      inline void write(FILE *f) const;
      inline void read(FILE *f);
};

inline BigInt::BigInt()
{
       semn=0;
       a.resize(4);
       a[0]=1;
}

inline BigInt::BigInt(long long nr)
{
       if (nr<0) semn=-1, nr=-nr; else semn=1;
       if (!nr) semn=0;
       unsigned long long k=nr;
       a.resize(1);
       while (k>=base) a.push_back(k%base), k/=base;
       a.push_back(k);
       a[0]=a.size()-1;
       fix(a);
}

inline BigInt::BigInt(vector <unsigned> b)
{
      *this=0;
      b.push_back(0);
      int nr=b.size()*32-1;
      while (nr%29) nr--;
      while (nr){
            *this*=(1<<29);
            //mai baga ceva aici :)
            nr-=29;
      }
}

inline void BigInt::shr(unsigned k)
{
        if (k>a[0]) k=a[0];
        unsigned i;
        for (i=1; i<=a[0]-k; i++)
            a[i]=a[i+k];
        a[0]-=k;
        if (!a[0]) a[0]=1, a[1]=1;
        fix(a);
}

inline void BigInt::shl(unsigned k)
{
        unsigned i;
        a[0]+=k;
        a.resize(a[0]+2);
        for (i=a[0]; i>k; i--)
            a[i]=a[i-k];
        memset(&a[1], 0, 4*k);
}

inline BigInt& BigInt::operator+=(const BigInt &b)
{
     if (this == &b){       //in cazul ca in care fac a+=a;
        unsigned i, n=a[0]+1;
        for (i=1; i<n; i++)
            a[i]+=a[i];
        for (i=1; i<n; i++)
            if (a[i]>=base) a[i]-=base, a[i+1]++;
        if (a[n]) a[0]++;
        return *this;
     }
     unsigned i, n=b.a[0]+1;
     for (i=1; i<n; ++i)
         if (a[i]+b.a[i]>=base) a[i]+=(b.a[i]-base), a[i+1]++; else a[i]+=b.a[i];
     if (a[n]) n++;
     if (n-1>a[0]) a[0]=n-1;
     fix(a);
     return *this;
}

inline BigInt operator+(const BigInt &x, const BigInt &y)
{
       if (x.semn==0) return y;
       if (y.semn==0) return x;
       BigInt rez;
       const unsigned *a, *b, *c;
       if (x.semn==y.semn){
          rez.semn=x.semn;
          if (x.a[0]>y.a[0]) a=&x.a[0], b=&y.a[0]; else a=&y.a[0], b=&x.a[0];
          unsigned n=a[0]+1, m=b[0]+1;
          rez.a.resize(a[0]+2);
          memcpy(&rez.a[0], a, sizeof(unsigned) * (n+1));
          for (unsigned i=1; i<m; i++){
              rez.a[i]+=b[i];
              if (rez.a[i]>=base) rez.a[i]-=base, ++rez.a[i+1];
          }
          unsigned k=m;
          while (rez.a[k]>=base) rez.a[k]-=base, ++k, ++rez.a[k];
          if (rez.a[a[0]+1]) rez.a[0]++;
          fix(rez.a);
          if (rez.a[0]==1 && rez.a[1]==0) rez.semn=0;
          return rez;
       }
       rez.semn=x.semn;
       if (x.semn>=0) a=&x.a[0], b=&y.a[0]; else a=&y.a[0], b=&x.a[0];
       unsigned i, n, m, ok=1;
       if (b[0]>a[0]) ok=0;
       if (a[0]==b[0])
          for (i=a[0]; i>0; i--){
              if (a[i]!=b[i]){
                 ok=(a[i]>b[i]);
                 break;
              }
          }
       if (!ok) c=a, a=b, b=c, rez.semn=-x.semn;
       m=b[0]+1;
       rez.a.resize(a[0]+3);
       memcpy(&rez.a[0], a, 4*(a[0]+1));
       for (i=1; i<m; i++){
           if (rez.a[i]>base) rez.a[i]+=base, --rez.a[i+1];
           rez.a[i]-=b[i];
           if (rez.a[i]>base) rez.a[i]+=base, --rez.a[i+1];
       }
       while (rez.a[i]>base) rez.a[i]+=base, ++i, --rez.a[i];
       n=rez.a[0];
       while (n>1 && rez.a[n]==0) --n;
       rez.a[0]=n;
       fix(rez.a);
       if (rez.a[0]==1 && rez.a[1]==0) rez.semn=0;
       return rez;
}

inline BigInt operator-(const BigInt &x, const BigInt &y)
{
       BigInt a=y;
       a.semn*=-1;
       return x+a;
}

inline BigInt& BigInt::operator+=(long long nr)
{
        fix(a);
        if (a.size()<5) a.resize(5);
        ull k = nr, poz=1;
        while (k>=base){
              a[poz]+=k%base;
              k/=base;
              if (a[poz]>=base) a[poz]-=base, ++a[poz+1];
              poz++;
        }
        a[poz]+=k;
        if (a[poz]>=base) a[poz]-=base, ++a[poz+1];
        if (a[a[0]+1]) a[0]++;
        fix(a);
        return *this;
}

inline BigInt& BigInt::operator*=(int nr)
{
        if (nr<0) semn=-semn, nr=-nr;
        ull num, k=nr;
        unsigned i;
        for (i=a[0]; i>0; i--){
            num=a[i] * k;
            unsigned cat = num/base;
            a[i]=num - (ull)cat*base;
            a[i+1]+=cat;
            if (a[i]>=base) a[i]-=base, a[i+1]++;
        }
        if (a[a[0]+1]) a[0]++;
        while (a[0]>1 && !a[a[0]]) --a[0];
        fix(a);
        return *this;
}

inline BigInt operator*(const BigInt &x, const BigInt &y)
{
       const unsigned *a, *b;
       if (x.a[0]>y.a[0]) a=&x.a[0], b=&y.a[0]; else a=&y.a[0], b=&x.a[0];
       unsigned n=a[0]+1, m=b[0]+1, i, j, k;
       unsigned limit=75*n/100;
       if (m>KARATSUBA && m<limit){
          m--; n--;
          BigInt rez, A, B;
          A.a.resize(m+3);
          rez.a.resize(n+m+3);
          const BigInt *C;
          if (x.a[0]>y.a[0]) C=&y; else C=&x;
          A.a[0]=m;
          k=1;
          while (k<=n){
                if (k+m-1>n){
                   A.a[0]=n-k+1; fix(A.a);
                }
                memcpy(&A.a[1], a+k, 4*A.a[0]);
                B=A*(*C);
                for (i=1; i<=B.a[0]; i++){
                    rez.a[i+k-1]+=B.a[i];
                    if (rez.a[i+k-1]>=base) rez.a[i+k-1]-=base, ++rez.a[i+k];
                }
                k+=m;
          }
          n+=m;
          while (n>1 && !rez.a[n]) --n;
          rez.a[0]=n;
          rez.semn=x.semn*y.semn;
          fix(rez.a);
          return rez;
       }
       if (n>KARATSUBA && m>=limit){  //Karatsuba
          BigInt x1, x2, y1, y2, A, B, C;
          unsigned p=(n+m)/4;
          x2.a.resize(p+4);
          x2.a[0]=p;
          memcpy(&x2.a[1], a+1, 4*p);
          x1.a.resize(n-p+4);
          x1.a[0]=n-p-1;
          memcpy(&x1.a[1], a+p+1, 4*(n-p-1));
          y2.a.resize(p+4);
          y2.a[0]=p;
          memcpy(&y2.a[1], b+1, 4*p);
          y1.a.resize(m-p+4);
          y1.a[0]=m-p-1;
          memcpy(&y1.a[1], b+p+1, 4*(m-p-1));
          A=x1*y1;
          B=x2*y2;
          C=(x1+x2)*(y1+y2)-A-B;
          A.shl(2*p);
          memcpy(&A.a[1], &B.a[1], sizeof(unsigned)*2*p);
          C.shl(p);
          A+=C;
          A.semn=x.semn*y.semn;
          fix(A.a);
          return A;
       }
       vector <ull> sol(n+m+1);
       sol[0]=n+m-3;
       for (i=1; i<m; i++)
           for (j=1, k=i; j<n; ){
               #define W sol[k] += (ull) b[i] * a[j++]; if (sol[k]>=base2) sol[k]-=base2, ++sol[k+2]; k++;
               W W W
           }
       BigInt rez;
       rez.a.resize(sol[0]+3);
       for (i=0; i<n+m; i++)
           if (sol[i]>=base2) sol[i]-=base2, ++sol[i+2];
       for (i=0; i<n+m; i++){
           unsigned cat=sol[i]/base;
           sol[i+1]+=cat;
           rez.a[i]=sol[i]-cat*(ull)base;
       }
       if (rez.a[rez.a[0]+1]) rez.a[0]++;
       fix(rez.a);
       rez.semn=x.semn * y.semn;
       return rez;
}

inline BigInt& BigInt::operator/=(int nr)
{
        if (nr<0) semn=-semn, nr=-nr;
        ull num=0;
        const unsigned k=nr;
        for (unsigned i=a[0]; i; i--){
            num=a[i] + num*base;
            a[i]=num/k;
            num%=k;
        }
        while (!a[a[0]] && a[0]>1) a[0]--;
        fix(a);
        if (a[0]==1 && !a[1]) semn=0;
        return *this;
}

inline int BigInt::operator%(int nr)
{
    ull num=0;
    const unsigned k=nr;
    for (unsigned i=a[0]; i; i--)
        num=(a[i] + num*base)%k;
    return num;
}

inline BigInt operator/(const BigInt &x, const BigInt &y)
{
       if (x<y) return 0;
       nrdiv+=x.a[0]*y.a[0];
       unsigned n=x.a[0], m=y.a[0];
       BigInt nr=0, cat, rez;
       nr.semn=1; nr.a[0]=0;
       nr.a.resize(m+4);
       rez.a.resize(n+3);
       unsigned i,j;
       for (i=n; i>0; i--){
           nr.a[0]++;
           for (j=nr.a[0]; j>1; j--)
               nr.a[j]=nr.a[j-1];
           nr.a[1]=x.a[i];
           while (nr.a[0]>1 && !nr.a[nr.a[0]]) --nr.a[0];
           nr.semn=1;
           if (nr<y){ rez.a[i]=0; continue; }
           unsigned p,u;
           long double num1=(long double) base * nr.a[m+1] + (long double)nr.a[m];
           long double num2=(long double) y.a[m];
           if (m>1){
                    num1=num1*base + (long double) nr.a[m-1];
                    num2=num2*base + (long double)  y.a[m-1];
           }
           if (m==1) p=(unsigned) (num1/num2); else p=(unsigned) (num1/(num2+1));
           cat=y;
           cat*=p;
           u = (unsigned) round((num1+1)/(num2-0.5));
           if (m==1) u=(unsigned) round((num1+1)/num2);
           if (u>p && cat+y<=nr) cat=cat+y, ++p;
           nr=nr-cat;
           rez.a[i]=p;
       }
       while (n>1 && !rez.a[n]) --n;
       rez.a[0]=n;
       fix(rez.a);
       rez.semn=x.semn*y.semn;
       return rez;
}

inline BigInt operator%(const BigInt &x, const BigInt &y)
{
       BigInt cat=x/y;
       cat=x-(y*cat);
       return cat;
}

inline int operator==(const BigInt &x, const BigInt &y)
{
    if (x.semn!=y.semn) return 0;
    for (unsigned i=0; i<=y.a[0]; i++)
        if (x.a[i]!=y.a[i]) return 0;
    return 1;
}

inline int operator!=(const BigInt &x, const BigInt &y)
{
    return !(x == y);
}

inline int operator<(const BigInt &y, const BigInt &x)
{
    if (y.semn < x.semn) return 1;
    if (y.semn > x.semn) return 0;
    if (y.a[0]<x.a[0]) return 1;
    if (y.a[0]>x.a[0]) return 0;
    unsigned k=y.a[0];
    while (x.a[k]==y.a[k] && k) k--;
    int ok=(y.a[k]<x.a[k]);
    if (x.semn) return ok; else return !ok;
}

inline int operator<=(const BigInt &y, const BigInt &x)
{
    return ((y<x) || (y==x));
}

inline int operator>(const BigInt &y, const BigInt &x)
{
    return !(y <= x);
}

inline int operator>=(const BigInt &y, const BigInt &x)
{
    return !(y < x);
}

inline void BigInt::write(FILE *f) const
{
     int i,n=a[0];
     if (semn==-1) fprintf(f, "-");
     fprintf(f, "%u", a[n]);
     for (i=n-1; i>0; i--)
         fprintf(f, "%.9u", a[i]);
     fprintf(f,"\n");
}

inline void BigInt::read(FILE *f)
{
     char c=0;
     semn=1;
     while (c<'0' || c>'9'){
           c=fgetc(f);
           if (c=='-') semn=-1;
     }
     string s="000000000";
     while (c>='0' && c<='9') s+=c, c=fgetc(f);
     int i, j, n=s.length()/9, lung=s.length()%9;
     a.resize(n+2);
     if (!lung) lung=9, n--;
     for (i=1; i<=n; i++)
         for (j=lung; j<lung+9; j++)
             a[i]=a[i]*10 + (s[(n-i)*9+j]-'0');
     a[0]=n;
     while (!a[a[0]] && a[0]>0) a[0]--;
     fix(a);
     if (a[0]==1 && a[1]==0) semn=0;
}

inline BigInt pow(const BigInt &a, const BigInt &n, unsigned nr)
{
       BigInt rez=1;
       for (unsigned p=(1<<23); p>0; p/=2){
           rez=rez*rez;
           if (n<rez) return rez;
           if (nr&p) rez=rez*a;
           if (n<rez) return rez;

       }
       return rez;
}

inline BigInt sqrtBig(const BigInt &nr, unsigned ord)
{
 BigInt st=2, dr;

if (nr > 1000000000)
    dr = nr/31622 + 1;
else
if (nr > 100000000)
    dr = nr/10000 + 1;
else
if (nr > 1000000)
    dr = nr/1000 + 1;
else
if (nr > 10000)
    dr = nr/100 + 1;
else
if (nr > 100)
    dr = nr/10 + 1;
else
    dr = nr/2 + 1;

 while (st<dr)
  {
   BigInt mij=(st+dr)/2;
   if( pow(mij, nr, ord) < nr) st=mij+1; else dr=mij;
  }
 return st;
}
int NR;
long long R,T;
int caz;
void bser()
{
    BigInt st=1, dr = 707106780,mij,ret=-1;
    while(st<=dr)
    {
        //printf("%lld\n",mij*mij*2 - mij + 2 * R * mij);
        mij = (st +dr )/2;
        if(mij*mij*2 - mij + 2 * R * mij <=T)
        {
        ret = mij;
        st = mij + 1;
        }
        else dr = mij - 1;
    }

    printf("Case #%d: ",caz);
    ret.write(stdout);
}

int main()
{
freopen("A.in","r",stdin);
freopen("A.out","w",stdout);
    scanf("%d",&NR);
    while(NR--)
    {
        ++caz;
        scanf("%lld%lld",&R,&T);
        bser();
    }
}
