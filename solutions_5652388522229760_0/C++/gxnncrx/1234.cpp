#pragma comment(linker,"/STACK:102400000,102400000")
#include <cassert>
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
#define itype(x) __typeof((x).begin())
#define forit(it,x) for(itype(x) it=(x).begin();it!=(x).end();it++)

typedef double lf;
typedef long double llf;
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
const ll linf=1000000000000000001LL;
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

template <class T> void geti(T &a){a=0;int b=0;char c;while((c=getchar())!='-'&&(c<'0'||c>'9'));if(c=='-')b=1;else a=c-48;while((c=getchar())>='0'&&c<='9')a=a*10+c-48;if(b)a=-a;}

void fileio_in_out(){freopen(".in","r",stdin);freopen(".out","w",stdout);}
void fileio_txt(){freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);}

//==================================================

#define DEBUG(X)

const int N=2000022;
const int M=33;
const int K=333;
const ll md=inf;

int test;
int n,m,k,ans;
int a[11];

int main()
{
    //fileio_in_out();
    fileio_txt();
    //ios::sync_with_stdio(false);cout<<setprecision(30);
    
    scanf("%d",&test);
    for(int tc=1;tc<=test;tc++)
    {
        scanf("%d",&n);
        printf("Case #%d: ",tc);
        if(n==0)
        {
            puts("INSOMNIA");
        }
        else
        {
            mset(a);
            m=0;
            for(ans=n;;ans+=n)
            {
                for(k=ans;k;k/=10)
                {
                    int t=k%10;
                    if(!a[t])
                    {
                        a[t]=1;
                        m++;
                    }
                }
                if(m==10)
                    break;
            }
            printf("%d\n",ans);
        }
    }
    
    //system("pause");
    return 0;
}
