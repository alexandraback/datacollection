#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<iomanip>
#include<fstream>

#include<string>
#include<utility>
#include<vector>
#include<list>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#define ii long long int
#define uii unsigned long long int
#define pi 2*acos(0.0)
#define eps 1e-9
#define mem(x,y) memset(x,y,sizeof(x))
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz(a) (int)a.size()
#define inf 2147483640

#define mx 1414213560

using namespace std;

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
};

const int debug= 0;
ii r,tt;

ii call(ii x,ii y);
bool calc(ii st,ii end);
string toString(ii n)
{
	string res;
	while (n)
	{
		res+= n%10+'0';
		n/= 10;
	}
	reverse(all(res));
	return res;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int x,t;
	scanf("%d",&t);
	
	for (x=1;x<=t;++x)
	{
		scanf("%lld %lld",&r,&tt);
		ii hi= (ii)(mx-1)*2+r;
		
		ii ans= call(r,hi);
		//puts("--");
		//cout<<calc(r,r)<<endl;
		
		printf("Case #%d: %d\n",x,ans);
	}
	
	return 0;	
}

ii call(ii x,ii y)
{
	ii st= x,end= y,mid;
	int loop= 0;
	
	while (st<end)
	{
		loop++;
		
		mid= (st+end)/2;
		if ((mid&1)!=(r&1)) mid--;
		
		if (debug) cout<<st<<" "<<end<<" "<<mid<<endl;
		
		if (calc(x,mid)) st= mid+2;
		else end= mid-2;
		if (debug) cout<<st<<" "<<end<<endl;
		
		//if (loop==100) break;
	}
	
	if (!calc(x,st)) st-= 2;
	
	if (debug) cout<<x<<" -- "<<st<<endl;
	if (debug) cout<<calc(x,st)<<endl;
	
	if (st<x) return 0;
	return (st-x)/2+1;
}

bool calc(ii st,ii end)
{
	ii n= (end-st)/2+1;
	
	Bigint a= toString((st+end)/2);
	Bigint b= toString(n);
	Bigint sum= a*b;
	Bigint two= toString(2);
	
	a= two*sum+b;
	
	if (debug) cout<<(st+end)<<endl;
	
	Bigint ttt= toString(tt);
	
	if (ttt<a) return 0;
	return 1;
}
