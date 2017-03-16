#pragma comment(linker,"/STACK:102400000,102400000")
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <bitset>
#include <functional>
#include <numeric>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <iterator>
#include <memory>
#include <utility>
#include <string>
#include <sstream>
 
using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define mset(a) memset(a,0,sizeof(a))
#define mmset(a) memset(a,-1,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))

typedef double lf;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<lf,lf> pdd;
typedef pair<int,pii> pip;
typedef pair<pii,int> ppi;
typedef pair<pii,pii> ppp;
typedef vector<int> vi;
typedef vector<pii> vpii;

const int inf=1000000007;
const ll linf=1000000000000000000LL;
const ull ulinf=(1ULL<<63)-10ULL;
const lf eps=0.000001;
const lf pi=3.14159265358979323846;

template <class T> T abs(T a){return a>=0?a:-a;}
template <class T> int sign(T a){return a>eps?1:a<-eps?-1:0;}
template <class T> T sqr(T a){return a*a;}
template <class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template <class T> T mod(T a,T b){T ret=a%b;if(ret<0)ret+=b;return ret;}
template <class T> T lowbit(T x){return x&-x;}
ll addmod(ll a,ll b,ll c){return ((a+b)%c+c)%c;}
ll mulmod(ll a,ll b,ll c){if(b==0LL)return 0LL;ll ret=mulmod(a,b>>1,c);ret=(ret+ret)%c;if(b&1LL)ret=(ret+a)%c;return ret;}
ll powmod(ll a,ll b,ll c){if(b==0LL)return 1LL;ll ret=powmod(a,b>>1,c);ret=ret*ret%c;if(b&1LL)ret=ret*a%c;return ret;}
ll modinv(ll a,ll b){return powmod(a,b-2LL,b);}
template <class T> void maxe(T &a,T b){if(a<b)a=b;}
template <class T> void mine(T &a,T b){if(a>b)a=b;}
int iszero(lf a){return a<eps&&a>-eps;}

template <class T> void geti(T &a){a=0;int b=0;char c;while((c=getchar())==' '||c=='\n');if(c=='-')b=1;else a=c-48;while((c=getchar())!=' '&&c!='\n')a=a*10+c-48;if(b)a=-a;}

void fileio_in_out(){freopen(".in","r",stdin);freopen(".out","w",stdout);}
void fileio_txt(){freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);}

//==================================================

#define DEBUG(X) 

const int N=333333;
const int M=20;
const int K=20;
const ll md=inf;

int test;
int n,m,k,ans;
int p[333];
char s[N];
const int cal[8][8]=
{
    {0,1,2,3,4,5,6,7},
    {1,4,3,6,5,0,7,2},
    {2,7,4,1,6,3,0,5},
    {3,2,5,4,7,6,1,0},
    {4,5,6,7,0,1,2,3},
    {5,0,7,2,1,4,3,6},
    {6,3,0,5,2,7,4,1},
    {7,6,1,0,3,2,5,4}
};

int getans()
{
    k=n;
    while(m-->1)
    {
        for(int i=1;i<=k;i++)
            s[++n]=s[i];
    }
    int pos1=0,pos3=0;
    k=0;
    for(int i=1;i<=n;i++)
    {
        int t=p[s[i]];
        k=cal[k][t];
        if(!pos1&&k==1)
            pos1=i;
    }
    if(!pos1)
        return 0;
    if(k!=cal[cal[1][2]][3])
        return 0;
    k=0;
    for(int i=n;i>=1;i--)
    {
        int t=p[s[i]];
        k^=t;
        if(!pos3&&k==3)
            pos3=i;
    }
    if(!pos3)
        return 0;
    if(pos1>=pos3-1)
        return 0;
    return 1;
}

int main()
{
    //fileio_in_out();
    fileio_txt();
    //ios::sync_with_stdio(false);cout<<setprecision(15);
    
    p['i']=1;
    p['j']=2;
    p['k']=3;
    scanf("%d",&test);
    for(int tc=1;tc<=test;tc++)
    {
        ll t;
        scanf("%d%I64d%s",&n,&t,s+1);
        m=min(t,t%16+16);
        ans=getans();
        printf("Case #%d: %s\n",tc,ans?"YES":"NO");
    }
    
    //system("pause");
    return 0;
}
