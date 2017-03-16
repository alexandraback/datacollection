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
const int maxn=(int) 100000+15;
const int maxm=(int) 1000+15;

LL fpow(LL a,LL n,LL mod) { LL res=1; for(;n;n>>=1,a=a*a%mod) if(n&1) res=res*a%mod; return res; }
LL gcd(LL a,LL b) {LL t; while(b) t=a%b, a=b, b=t; return absx(a);}
inline int sig(double x) {return x<-eps?-1:x>eps;}

//--------------start------------------

int n;

int cnt[26];
int num[10];

char s[maxn];

inline int idx(char c) {return c-'A';}

void sub(string ss,int t)
{
    int sz=ss.size();
    for(int i=0;i<sz;i++)
    {
        int c=idx(ss[i]);
        cnt[c]-=t;
    }
}

void work()
{
    int tc; scanf("%d",&tc);
    int T_T=0;
    while(tc--)
    {
        memset(num,0,sizeof(num));
        memset(cnt,0,sizeof(cnt));
        scanf("%s",s);
        for(char *p=s;*p;p++)
        {
            int c=idx(*p);
            cnt[c]++;
        }

        int x;
        //ZERO
        x=cnt[idx('Z')];
        sub("ZERO",x);
        num[0]+=x;


        //SIX
        x=cnt[idx('X')];
        sub("SIX",x);
        num[6]+=x;

        //EIGHT
        x=cnt[idx('G')];
        sub("EIGHT",x);
        num[8]+=x;

        //FOUR
        x=cnt[idx('U')];
        sub("FOUR",x);
        num[4]+=x;

        //TWO
        x=cnt[idx('W')];
        sub("TWO",x);
        num[2]+=x;

        //THREE
        x=cnt[idx('T')];
        sub("THREE",x);
        num[3]+=x;

        //ONE
        x=cnt[idx('O')];
        sub("ONE",x);
        num[1]+=x;

        //FIVE
        x=cnt[idx('F')];
        sub("FIVE",x);
        num[5]+=x;

        //SEVEN
        x=cnt[idx('S')];
        sub("SEVEN",x);
        num[7]+=x;

        //NINE
        x=cnt[idx('I')];
        sub("NINE",x);
        num[9]+=x;

        printf("Case #%d: ",++T_T);
        for(int i=0;i<10;i++)
        {
            while(num[i]--) printf("%d",i);
        }
        printf("\n");
    }
}

//--------------end------------------

//#define yukihana0416
int main()
{
#ifdef yukihana0416
//freopen("in.txt","r",stdin);
freopen("A-large.in","r",stdin);
freopen("out.txt","w",stdout);
#endif // yukihana0416
    work();
    return 0;
}
