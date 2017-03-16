#pragma comment(linker,"/STACK:102400000,102400000")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <list>
#include <bitset>
#include <vector>
using namespace std;

//#define I64d_OJ

#ifdef I64d_OJ
#define LL __int64
#endif // I64d_OJ
#ifndef I64d_OJ
#define LL long long
#endif // I64d_OJ

#define fi first
#define se second
#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
#define ls id<<1
#define rs id<<1|1
#define MID(a,b) (((a)+(b))>>1)
#define maxx(a,b) ((a)<(b)?(b):(a))
#define minx(a,b) ((a)<(b)?(a):(b))
#define absx(a) ((a)<0?-(a):(a))
#define MK(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define lowbit(x) ((x)&-(x))

typedef unsigned LL ULL;
typedef unsigned uint;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<LL,LL> pLL;
typedef vector<int> vi;

template< typename T >
inline void read(T &res)
{
    T x=0; bool f=0; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-')f=!f; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    res = f ? -x : x ;
}

template< typename T >
inline void swapt(T &a,T &b) {T c=a;a=b;b=c;}
template< typename T >
inline void Max(T &a, T b) {if(a<b) a=b;}
template< typename T >
inline void Min(T &a, T b) {if(b<a) a=b;}
template< typename T >
inline T maxt(T a,T b) {if(a<b) return b; else return a;}
template< typename T >
inline T mint(T a,T b) {if(a<b) return a; else return b;}

const double pi=(double) acos(-1.0);
const int MOD=(int) 1e9+7;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(LL) 0x3f3f3f3f3f3f3f3f;
const int SINF=(uint) ~0U>>1;
const LL  SLINF=(ULL) (-1)>>1;
const double DINF=(double) 1e50;
const double eps=(double) 1e-8;
const int maxn=(int) 1000+15;
const int maxm=(int) 1000+15;

LL fpow(LL a,LL n,LL mod) { LL res=1; for(;n;n>>=1,a=a*a%mod) if(n&1) res=res*a%mod; return res; }
LL gcd(LL a,LL b) {LL t; while(b) t=a%b, a=b, b=t; return absx(a);}
inline int sig(double x) {return x<-eps?-1:x>eps;}

//--------------start------------------

char a[23],b[23];
int aa[23],bb[23];
LL ans;
string anss;
int n;
void check()
{
    LL a1=0,b1=0;
    for(int i=0; i<n; i++)
    {
        a1=a1*10+aa[i];
        b1=b1*10+bb[i];
    }
    a1=abs(a1-b1);
    if(a1<ans)
    {
        ans=a1;
        anss="";
        for(int i=0; i<n; i++)
        {
            anss+=aa[i]+'0';
        }
        for(int i=0; i<n; i++)
        {
            anss+=bb[i]+'0';
        }
    }
    else if(a1==ans)
    {
        string temp="";
        for(int i=0; i<n; i++)
        {
            temp+=aa[i]+'0';
        }
        for(int i=0; i<n; i++)
        {
            temp+=bb[i]+'0';
        }
        if(anss.compare(temp)>0)anss=temp;
    }
}
void update1(int i)
{
    if(a[i]=='?'&&b[i]=='?')
    {
        aa[i]=1;
        bb[i]=0;
        check();
    }
    else if(a[i]=='?')
    {
        if(b[i]!='9')
        {
            aa[i]=b[i]-'0'+1;
            bb[i]=b[i]-'0';
            check();
        }
    }
    else if(b[i]=='?')
    {
        if(a[i]!='0')
        {
            aa[i]=a[i]-'0';
            bb[i]=a[i]-'0'-1;
            check();
        }
    }
    else if(a[i]>b[i])
    {
        aa[i]=a[i]-'0';
        bb[i]=b[i]-'0';
        check();
    }
}
void update2(int i)
{
    if(a[i]=='?'&&b[i]=='?')
    {
        aa[i]=0;
        bb[i]=1;
        check();
    }
    else if(a[i]=='?')
    {
        if(b[i]!='0')
        {
            aa[i]=b[i]-'0'-1;
            bb[i]=b[i]-'0';
            check();
        }
    }
    else if(b[i]=='?')
    {
        if(a[i]!='9')
        {
            aa[i]=a[i]-'0';
            bb[i]=a[i]-'0'+1;
            check();
        }
    }
    else if(a[i]<b[i])
    {
        aa[i]=a[i]-'0';
        bb[i]=b[i]-'0';
        check();
    }
}
void work()
{
    int tc; read(tc);
    int T_T=0;
    while(tc--)
    {
        ans=SLINF;
        scanf("%s%s",a,b);
        n=strlen(a);
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(a[j]=='?'&&b[j]=='?')aa[j]=bb[j]=0;
                else if(a[j]=='?')aa[j]=bb[j]=b[j]-'0';
                else if(b[j]=='?')aa[j]=bb[j]=a[j]-'0';
                else aa[j]=bb[j]=a[j]-'0';
            }
            if(i==n)
            {
                check();
                continue;
            }
            for(int j=i+1; j<n; j++)
            {
                if(a[j]!='?')aa[j]=a[j]-'0';
                else aa[j]=0;
                if(b[j]!='?')bb[j]=b[j]-'0';
                else bb[j]=9;
            }
            update1(i);
            for(int j=i+1; j<n; j++)
            {
                if(a[j]!='?')aa[j]=a[j]-'0';
                else aa[j]=9;
                if(b[j]!='?')bb[j]=b[j]-'0';
                else bb[j]=0;
            }
            update2(i);
            if(a[i]!='?'&&b[i]!='?'&&a[i]!=b[i])break;
        }
        printf("Case #%d: ",++T_T);
        for(int i=0; i<n; i++)printf("%c",anss[i]);
        printf(" ");
        for(int i=0; i<n; i++)printf("%c",anss[n+i]);
        printf("\n");
    }
}

//--------------end------------------

#define yukihana0416
int main()
{
#ifdef yukihana0416
//freopen("in.txt","r",stdin);
freopen("B-large.in","r",stdin);
freopen("out.txt","w",stdout);
#endif // yukihana0416
    work();
    return 0;
}
