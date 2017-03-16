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

struct Bigint {
    // representations and structures
    string a; // to store the digits
    int sign; // sign = -1 for negative numbers, sign = 1 otherwise

    // constructors
    Bigint() {} // default constructor
    Bigint( string b ) { (*this) = b; } // constructor for string

    // some helpful methods
    int size() { // returns number of digits
        return a.size();
    }
    Bigint inverseSign() { // changes the sign
        sign *= -1;
        return (*this);
    }
    Bigint normalize( int newSign ) { // removes leading 0, fixes sign
        for( int i = a.size() - 1; i > 0 && a[i] == '0'; i-- )
            a.erase(a.begin() + i);
        sign = ( a.size() == 1 && a[0] == '0' ) ? 1 : newSign;
        return (*this);
    }

    // assignment operator
    void operator = ( string b ) { // assigns a string to Bigint
        a = b[0] == '-' ? b.substr(1) : b;
        reverse( a.begin(), a.end() );
        this->normalize( b[0] == '-' ? -1 : 1 );
    }

    // conditional operators
    bool operator < ( const Bigint &b ) const { // less than operator
        if( sign != b.sign ) return sign < b.sign;
        if( a.size() != b.a.size() )
            return sign == 1 ? a.size() < b.a.size() : a.size() > b.a.size();
        for( int i = a.size() - 1; i >= 0; i-- ) if( a[i] != b.a[i] )
            return sign == 1 ? a[i] < b.a[i] : a[i] > b.a[i];
        return false;
    }
    bool operator == ( const Bigint &b ) const { // operator for equality
        return a == b.a && sign == b.sign;
    }

    // mathematical operators
    Bigint operator + ( Bigint b ) { // addition operator overloading
        if( sign != b.sign ) return (*this) - b.inverseSign();
        Bigint c;
        for(int i = 0, carry = 0; i<a.size() || i<b.size() || carry; i++ ) {
            carry+=(i<a.size() ? a[i]-48 : 0)+(i<b.a.size() ? b.a[i]-48 : 0);
            c.a += (carry % 10 + 48);
            carry /= 10;
        }
        return c.normalize(sign);
    }
    Bigint operator - ( Bigint b ) { // subtraction operator overloading
        if( sign != b.sign ) return (*this) + b.inverseSign();
        int s = sign; sign = b.sign = 1;
        if( (*this) < b ) return ((b - (*this)).inverseSign()).normalize(-s);
        Bigint c;
        for( int i = 0, borrow = 0; i < a.size(); i++ ) {
            borrow = a[i] - borrow - (i < b.size() ? b.a[i] : 48);
            c.a += borrow >= 0 ? borrow + 48 : borrow + 58;
            borrow = borrow >= 0 ? 0 : 1;
        }
        return c.normalize(s);
    }
    Bigint operator * ( Bigint b ) { // multiplication operator overloading
        Bigint c("0");
        for( int i = 0, k = a[i] - 48; i < a.size(); i++, k = a[i] - 48 ) {
            while(k--) c = c + b; // ith digit is k, so, we add k times
            b.a.insert(b.a.begin(), '0'); // multiplied by 10
        }
        return c.normalize(sign * b.sign);
    }
    Bigint operator / ( Bigint b ) { // division operator overloading
        if( b.size() == 1 && b.a[0] == '0' ) b.a[0] /= ( b.a[0] - 48 );
        Bigint c("0"), d;
        for( int j = 0; j < a.size(); j++ ) d.a += "0";
        int dSign = sign * b.sign; b.sign = 1;
        for( int i = a.size() - 1; i >= 0; i-- ) {
            c.a.insert( c.a.begin(), '0');
            c = c + a.substr( i, 1 );
            while( !( c < b ) ) c = c - b, d.a[i]++;
        }
        return d.normalize(dSign);
    }
    Bigint operator % ( Bigint b ) { // modulo operator overloading
        if( b.size() == 1 && b.a[0] == '0' ) b.a[0] /= ( b.a[0] - 48 );
        Bigint c("0");
        b.sign = 1;
        for( int i = a.size() - 1; i >= 0; i-- ) {
            c.a.insert( c.a.begin(), '0');
            c = c + a.substr( i, 1 );
            while( !( c < b ) ) c = c - b;
        }
        return c.normalize(sign);
    }

    // output method
    void print() {
        if( sign == -1 ) putchar('-');
        for( int i = a.size() - 1; i >= 0; i-- ) putchar(a[i]);
    }
};

Bigint r,t;

string s1,s2;

int main()
{

READ("A-large.in");
WRITE("Alargeout.txt");

cin>>ts;
while(ts--)
{
    cin>>s1>>s2;

    r=s1;
    t=s2;

    Bigint ans,low,high,mid,zero,one,two,lim,area;

    zero="0";
    one="1";
    two="2";
    lim="1000000000000";

    ans=zero;

    low=zero;
    high=lim;

    while(low<high || low==high)
    {

        mid=(low+high)/two;

        area=mid*((two*r)+(two*mid)-(one));

        if(area<t || area==t)
        {
            if(!(mid<ans))
            {
                ans=mid;
            }
            low=mid+one;
        }
        else high=mid-one;
    }

    string tmp=ans.a;

    reverse(all(tmp));

    PHASH();

    cout<<tmp<<endl;
}

return 0;
}
