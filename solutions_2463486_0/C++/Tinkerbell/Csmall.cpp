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


#define sz(a) a.size()
#define VC(a) a.clear()
#define pb(a) push_back(a)
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))

#define S(a) scanf("%d",&a)
#define SL(a) scanf("%lld",&a)
#define P(a) printf("%d",a)
#define PCASE() printf("Case #%d: ",kk++)
#define MX 100+5
using namespace std;

int a[MX];

bool isPelin(long long x)
{
    int i,j,l,tm[16];
    l=0;
    while(x)
    {
        l++;
        tm[l]=(x%10);
        x/=10;
    }
    for(i=1,j=l;i<=l && j>0;i++,j--) if(tm[i]!=tm[j])return 0;
    return 1;
}


void preCal()
{
    a[0]=0;
    long long i;
    for(i=1;i<=MX;i++)
    {
        a[i]=a[i-1];
        if(isPelin(i) && isPelin(i*i)) a[i]++;
    }
}

int main()
{
    long long A,B,x;
    int T,kk=1;
    freopen("C-small.in","r",stdin);
    freopen("cout.txt","w",stdout);

    preCal();

    S(T);
    while(T--)
    {
        SL(A);SL(B);
        x=(long long)(sqrt((double)A));
        if(x*x<A) x++;
        B=(long long)(sqrt((double)B));
        PCASE();P(a[B]-a[x-1]);puts("");
    }
    return 0;
}
