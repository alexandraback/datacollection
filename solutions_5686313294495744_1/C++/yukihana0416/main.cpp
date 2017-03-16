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
const int maxn=(int) 5000+15;
const int maxm=(int) 1000+15;

LL fpow(LL a,LL n,LL mod) { LL res=1; for(;n;n>>=1,a=a*a%mod) if(n&1) res=res*a%mod; return res; }
LL gcd(LL a,LL b) {LL t; while(b) t=a%b, a=b, b=t; return absx(a);}
inline int sig(double x) {return x<-eps?-1:x>eps;}

//--------------start------------------

int n;
map<string,int> mp1,mp2;
int mnt1,mnt2;

struct adjs
{
    int to,next;
}ad[maxn<<1];
int head[maxn],adcnt;

inline void adjs_init()
{
    memset(head,-1,sizeof(head));
    adcnt=0;
}

inline void add_edge(int a,int b)
{
    ad[adcnt].to=b; ad[adcnt].next=head[a];
    head[a]=adcnt++;
}

bool vis[maxn];
int match[maxn];

bool dfs(int x)
{
    for(int i=head[x];~i;i=ad[i].next)
    {
        int v=ad[i].to;
        if(vis[v]) continue;
        vis[v]=1;
        if(match[v]==-1 || dfs(v))
        {
            match[v]=x;
            return 1;
        }
    }
    return 0;
}

int dance(int x)
{
    int ret=0;
    memset(match,-1,sizeof(match));
    for(int i=1;i<=x;i++)
    {
        memset(vis,0,sizeof(vis));
        if(dfs(i)) ret++;
    }
    return ret;
}

string s1,s2;
void work()
{
    int tc; read(tc);
    int T_T=0;
    while(tc--)
    {
        read(n);
        adjs_init();
        mnt1=mnt2=0;
        for(int i=0;i<n;i++)
        {
            cin >>s1 >>s2;
            int idx1,idx2;
            if(mp1.find(s1)==mp1.end()) mp1[s1]=idx1=++mnt1;
            else idx1=mp1[s1];
            if(mp2.find(s2)==mp2.end()) mp2[s2]=idx2=++mnt2;
            else idx2=mp2[s2];

            add_edge(idx1,idx2);
        }

        int temp=dance(mnt1);

        printf("Case #%d: %d\n",++T_T,n-temp-(mnt1+mnt2-temp*2));
    }
}

//--------------end------------------

//#define yukihana0416
int main()
{
#ifdef yukihana0416
//freopen("in.txt","r",stdin);
freopen("C-large.in","r",stdin);
freopen("out.txt","w",stdout);
#endif // yukihana0416
    work();
    return 0;
}
