#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<string>
#include<bitset>
#include<iomanip>
#include<iostream>
#include<cmath>
using namespace std;
#define rep(i,x,y) for(i=x;i<=y;i++)
#define _rep(i,x,y) for(i=x;i>=y;i--)
#define REP(i,x,y) for(int i=(x);i<=(y);i++)
#define _REP(i,x,y) for(int i=(x);i>=(y);i--)
#define CL(S,x) memset(S,x,sizeof(S))
#define CP(S1,S2) memcpy(S1,S2,sizeof(S2))
#define ALL(x,S) for(x=S.begin();x!=S.end();x++)
#define pb push_back
#define IN insert
#define ER erase
#define BE begin()
#define ED end() 
#define LB lower_bound
#define UB upper_bound
#define mp make_pair
#define fi first
#define se second
#define upmin(x,y) x=min(x,y)
#define upmax(x,y) x=max(x,y)
#define COUT(S,x) cout<<fixed<<setprecision(x)<<S<<endl
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
inline char getc(){char c;for(c=getchar();c<=32;c=getchar());return c;}

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int inf=int(1e9);
int T,n,m,i,j,K,l,r,p,ca;

bool v[30][30][30][450];
int f[30][30][30][450];
int dp(int i,int x,int y,int g)
{
    if(g<0)return -inf;
    if(i>n)
        if(abs(x-y)<=1)return 0;
        else return -inf;
    
    if(v[i][x][y][g])return f[i][x][y][g];
    v[i][x][y][g]=1;
    
    int x1,y1,ans=-inf,v;
    if(abs(x-y)<=1)ans=0;
    rep(x1,x-1,x+1)
    rep(y1,y-1,y+1)
    if(x1<=y1)
    {
        if(x1==y1)v=1;else v=2;
        upmax(ans,dp(i+1,x1,y1,g-v)+(y1-x1+1));
    }
    return f[i][x][y][g]=ans;
}
int ok(int L)
{
    int x,y,t;
    rep(x,1,m)
    rep(y,x,m)
    {
        t=y-x+1;
        if(dp(2,x,y,L-t)+t>=K)return 1;
    }
    return 0;
}
int main()
{
    freopen("1.in","r",stdin);freopen("1.out","w",stdout);
    read(T);
    rep(ca,1,T)
    {
        printf("Case #%d: ",ca);
        
        read(n,m,K);
        if(n==1||m==1)
        {
            printf("%d\n",K);
            continue;
        }
        for(l=0,r=n*m;l<r;)
        {
            int mid=(l+r)/2;
            if(ok(mid))r=mid;else l=mid+1;
        }
        printf("%d\n",l);
    }
    return 0;
}
