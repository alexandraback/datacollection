/// ///////////////////// ///
///                       ///
///      Silver Rain      ///
///                       ///
///         JU            ///
///                       ///
/// ///////////////////// ///

#include<iostream>
#include<sstream>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstdlib>
#include<cctype>

typedef long long ll;
typedef unsigned long long ull;

template <class T> T _diff(T a,T b) {return (a<b?b-a:a-b);}
template <class T> T _abs(T a) {return(a<0?-a:a);}
template <class T> T _max(T a, T b) {return (a>b?a:b);}
template <class T> T _min(T a, T b) {return (a<b?a:b);}
template <class T> T max3(T a, T b, T c) {return (_max(a,b)>c ? _max(a,b) : c);}
template <class T> T min3(T a, T b, T c) {return (_min(a,b)<c ? _min(a,b) : c);}
template< class T >T GCD(T a,T b) {
    a=_abs(a);b=_abs(b);T tmp;while(a%b){ tmp=a%b; a=b; b=tmp; } return b;
}
template< class T >T LCM(T a,T b) {
    a=_abs(a);b=_abs(b);return (a/GCD(a,b))*b;
}

#define read(a) freopen("a.txt","r",stdin)
#define write(a) freopen("a.txt","w",stdout)

#define sz(a) a.size()
#define VC(a) a.clear()
#define pb(a) push_back(a)
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))

#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define S2(a,b) scanf("d",&a,&b)
#define S3(a,b,c) scanf("d%d",&a,&b,&c)
#define SLL(a) scanf("%lld",&a)
#define PLL(a) printf("%lld",a)
#define SLL2(a,b) scanf("lld",&a,&b)
#define SLL3(a,b,c) scanf("lld%lld",&a,&b,&c)

#define PS() printf(" ")
#define PN() puts("")
#define PCASE() printf("Case #%d: ",kk++)
#define rep(i,a,b) for(i=a;i<=b;i++)
#define rev(i,a,b) for(i=a;i>=b;i--)
#define FOR(i,n) for(i=0;i<n;i++)

#define eps 1e-9
#define pi 2.0*acos(0.0)
#define inf 1000000000
#define mod 1000000007

using namespace std;

int dp[12][7],n,r,e,v[12];

int func(int pos, int rem)
{
    if(pos>=n)return 0;
    if(dp[pos][rem]!=-1)return dp[pos][rem];
    dp[pos][rem]=0;
    for(int i=0;i<=rem;i++)
    {
        int j=rem-i+r;
        if(j>e)j=e;
        dp[pos][rem]=max(v[pos]*i+func(pos+1,j),dp[pos][rem]);
    }
    return dp[pos][rem];
}

int main()
{

    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small.out","w",stdout);

    int T,kk=1,i,val;
    cin>>T;
    while(T--)
    {
        cin>>e>>r>>n;
        for(i=0;i<n;i++)cin>>v[i];
        SET(dp);
        val=func(0,e);
        PCASE();
        cout<<val<<endl;
    }
    return 0;
}




















