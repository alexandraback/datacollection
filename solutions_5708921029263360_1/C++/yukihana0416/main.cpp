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

#define I64d_OJ

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
const int maxn=(int) 1e2+20;
const int maxm=(int) 1000+15;

LL gcd(LL a,LL b) {LL t; while(b) t=a%b, a=b, b=t; return absx(a);}
inline int sig(double x) {return x<-eps?-1:x>eps;}

//--------------start------------------

#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=11;
struct PP{
    int j,p,s;
    PP(int j=-1,int p=-1,int s=-1):j(j),p(p),s(s){}
}pp[N*N*N];
int num[3][N][N];
int n,j,p,s,k;
int ans[N*N*N],n2;

void work()
{
    int T;scanf("%d",&T);
    int cas=1;
    while(T--){
        scanf("%d%d%d%d",&j,&p,&s,&k);
        n=0;
        for(int i1=0;i1<j;i1++){
            for(int p1=0;p1<p;p1++){
                for(int s1=0;s1<s;s1++){
                    pp[n++]=PP(i1,p1,s1);
                }
            }
        }
        //printf("%d\n",n);
        memset(num,0,sizeof(num));
        n2=0;
        for(int i=0;i<n;i++){
            int x=num[0][pp[i].j][pp[i].p]+1;
            int y=num[1][pp[i].j][pp[i].s]+1;
            int z=num[2][pp[i].p][pp[i].s]+1;
            if(x>k||y>k||z>k)continue;
            else {
                num[0][pp[i].j][pp[i].p]++;
                num[1][pp[i].j][pp[i].s]++;
                num[2][pp[i].p][pp[i].s]++;
                ans[n2++]=i;
            }
        }
        printf("Case #%d: %d\n",cas++,n2);
        for(int i=0;i<n2;i++){
            printf("%d %d %d\n",pp[ans[i]].j+1,pp[ans[i]].p+1,pp[ans[i]].s+1);
        }
    }
}

//--------------end--------------------

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
