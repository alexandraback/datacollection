//#pragma comment(linker,"/STACK:102400000,102400000")
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
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
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<lf,lf> pdd;
typedef pair<int,pii> pip;
typedef pair<pii,int> ppi;
typedef pair<pii,pii> ppp;
typedef vector<int> vi;
typedef vector<pii> vpii;

const int inf=1000000007;
const ll linf=1LL<<62;
const ull ulinf=1ULL<<63;
const lf eps=0.000001;
const lf pi=3.14159265358979323846;

template <class T> T abs(T a){return a>=0?a:-a;}
template <class T> T sqr(T a){return a*a;}
template <class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template <class T> T mod(T a,T b){return (a%b+b)%b;}
template <class T> T lowbit(T x){return x&-x;}
ll addmod(ll a,ll b,ll c){return ((a+b)%c+c)%c;}
ll mulmod(ll a,ll b,ll c){if(b==0LL)return 0LL;ll ret=mulmod(a,b>>1,c);ret=(ret+ret)%c;if(b&1LL)ret=(ret+a)%c;return ret;}
ll powmod(ll a,ll b,ll c){if(b==0LL)return 1LL;ll ret=powmod(a,b>>1,c);ret=ret*ret%c;if(b&1LL)ret=ret*a%c;return ret;}
ll modinv(ll a,ll b){return powmod(a,b-2LL,b);}
template <class T> void maxe(T &a,T b){if(a<b)a=b;}
template <class T> void mine(T &a,T b){if(a>b)a=b;}
int iszero(lf a){return abs(a)<=eps;}

template <class T> void geti(T &a){a=0;T b=1;char c=getchar();if(c=='-')b=-1;else a=c-48;while((c=getchar())!=' '&&c!='\n')a=a*10+c-48;a*=b;}

void fileio_in_out(){freopen(".in","r",stdin);freopen(".out","w",stdout);}
void fileio_txt(){freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);}

//==================================================

#define DEBUG(X) 

const int N=1111;
const int M=N*N;
const int K=33;
const ll md=inf;

int test;
int n,m,k,ans;
lf a[N],b[N];

int calc(lf *a,lf *b)
{
    int ret=0;
    for(int i=1,j=1;i<=n;i++)
        if(a[i]>b[j])
        {
            j++;
            ret++;
        }
    return ret;
}

int main()
{
    //fileio_in_out();
    fileio_txt();
    //ios::sync_with_stdio(false);
    
    scanf("%d",&test);
    for(int tc=1;tc<=test;tc++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%lf",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%lf",&b[i]);
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        int t1=calc(a,b);
        int t2=n-calc(b,a);
        printf("Case #%d: %d %d\n",tc,t1,t2);
    }
    
    //system("pause");
    return 0;
}
