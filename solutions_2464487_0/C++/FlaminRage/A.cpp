///===========================///
///                           ///
///    ID     : FlaminRage    ///
///    School : JU            ///
///                           ///
///===========================///

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<assert.h>
#include<limits.h>
#include<float.h>
#include<string>
#include<algorithm>
#include<sstream>
#include<fstream>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<stack>
#include<list>
#include<utility>
#include<iterator>
#include<iomanip>
#include <limits>

#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)
#define SZ(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define REV(a) reverse(all(a))
#define countbit(x) __builtin_popcount(x)
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define pi (2.0*acos(0.0))
#define SET(a) memset(a,-1,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define in(a,x,y) (a>=x && a<=y)
#define eq(a,b) (fabs(a-b)<eps)
#define less(a,b) (a+eps<b)
#define great(a,b) (a>b+eps)
#define first xx
#define second yy
#define root 1

#define PHASH() printf("Case #%d: ",kk++) ///codejam

#define MAX(a) *max_element(all(a))
#define MIN(a) *min_element(all(a))

using namespace std;

int ts,kk=1;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vst;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<string,int> psi;
typedef vector<pii> vii;

template< class T > inline T _sq(T a) { return a * a; }
template< class T > inline T _sqrt(T a) { return (T) sqrt( (double) a); }
template< class T, class X > inline T _pow(T a,X y) {T z=1; rep(i,1,y){z*=a;} return z; }
template< class T > inline T _gcd(T a,T b) {a=abs(a);b=abs(b); if(!b) return a; return _gcd(b,a%b);}
template< class T > inline T _lcm(T a,T b) {a=abs(a);b=abs(b); return (a/_gcd(a,b))*b;}

template< class T > inline T _extended(T a,T b,T &x,T &y) {a=abs(a);b=abs(b); T g,x1,y1; if(!b) {x=1;y=0;g=a; return g;} g=_extended(b,a%b,x1,y1); x=y1; y=x1-(a/b)*y1; return g;}

template< class T, class X > inline bool getbit(T a, X i) { T t=1; return ((a&(t<<i))>0); }
template< class T, class X > inline T setbit(T a, X i) { T t=1;return (a|(t<<i)); }
template< class T, class X > inline T resetbit(T a, X i) { T t=1;return (a&(~(t<<i))); }
template< class T, class X > inline T togglebit(T a, X i) { T t=1;return (a^(t<<i)); }

///========CONSTANT=========///
///  power    0123456789    ///
#define MX  ( 1000  +3 )
#define inf   2000000000
#define MOD   1000000007

#define inval 1000000000

#define eps 1e-9
///=========================///

template< class T,class X > inline T _bigmod(T n,X m){ll ret=1, a = n ; while(m){ if(m&1)ret=(ret*a)%MOD; m>>=1; a=(a*a)%MOD; }ret%=MOD;return (T)ret;}
template< class T > inline T _modinv(T n) {return _bigmod(n,MOD-2);}

///===============///
///End of template///
///===============///

ll r,t;

int main()
{

READ("A-small-attempt0.in");
WRITE("Asmallout.txt");

cin>>ts;
while(ts--)
{
    cin>>r>>t;

    ll ans=0;

    while(1)
    {
        ll area=_sq(r+1)-_sq(r);
        if(area>t) break;
        r+=2;
        ans++;
        t-=area;
    }

    PHASH();

    cout<<ans<<endl;
}

return 0;
}
