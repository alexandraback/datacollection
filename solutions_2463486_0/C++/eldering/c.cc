#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <set>
#include <algorithm>
#include <utility>
#include <functional>
#include <numeric>
#include <cmath>
#include <string>
#include <cctype>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef istringstream ISS;

#define PB push_back
#define ALL(x) ((x).begin()),((x).end())
#define FOR(i,c) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)
#define REP(i,n) for(typeof(n) i=0; i<(n); ++i)

template<class T> void minimize(T &a, T b) { a = min(a,b); }
template<class T> void maximize(T &a, T b) { a = max(a,b); }

const int infty = 999999999;

#define DEBUGGING 1

#if defined(DEBUGGING)
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

const int maxdigits = 200;
// keep maxdigits < maxint/100 for correct functioning of *(bignum,bignum)

class bignum;

bignum operator -(bignum a);
bignum abs(bignum a);

// Base 10 bignumber:
class bignum {
public:
	vector<unsigned int> d;
	int sign; // -1: negative, 1: positive, 0: zero

	bignum(): d(maxdigits,0), sign(0) {}
	bignum(long long n): d(maxdigits,0), sign(0) {
		if ( n==0 ) return;
		sign = 1;
		if ( n<0 ) {
			sign = -1;
			n = -n;
		}
		for(size_t i=0; i<d.size(); ++i) { d[i] = n%10; n /= 10; }
	}

	bignum(string str): d(maxdigits,0), sign(1) { // no error check!
		while ( str[0]=='-' ) {
			sign *= -1;
			str.erase(0,1);
		}
		while ( str.length()>1 && str[0]=='0' ) str.erase(0,1);
		if ( str[0]=='0' ) {
			sign = 0;
			return;
		}
		size_t n = str.length();
		for(int i=int(n)-1; i>=0; --i) d[n-1-i] = str[i]-'0';
	}

	operator long long() { // no overflow check!
		long long res = 0, base = 1;
		for(size_t i=0; i<d.size(); ++i) {
			res += d[i]*base;
			base *= 10;
		}
		return sign*res;
	}

	size_t ndigits() const { // does not assume 'sign' variable correct
		int i;
		for(i=int(d.size())-1; (i>=0 && d[i]==0); --i);
		return i+1;
	}

	string str() const {
		if ( sign==0 ) return string("0");
		string res;
		if ( sign==-1 ) res += '-';
		for(int i=int(ndigits())-1; i>=0; --i) res += '0'+d[i];
		return res;
	}

	// shifts digits ndig to the left (like << operator but now base 10)
	bignum& shl(int ndig) {
		int i;
		for(i=int(d.size())-1; i>=ndig; --i) d[i] = d[i-ndig];
		for(; i>=0; --i) d[i] = 0;
		return *this;
	}

	// equivalent shift to right as above
	bignum& shr(int ndig) {
		int i;
		for(i=0; i<int(d.size())-ndig; ++i) d[i] = d[i+ndig];
		for(; i<int(d.size()); ++i) d[i] = 0;
		return *this;
	}

	bignum& operator +=(const bignum& a) {
		if ( a.sign==0 ) return *this;
		if ( sign==0 ) return *this = a;
		if ( a.sign!=sign ) { // differing signs
			return *this -= -a;
		}

		int carry = 0;
		for(size_t i=0; i<d.size(); ++i) {
			d[i] += a.d[i] + carry;
			carry = d[i] / 10;
			d[i] %= 10;
		}
		return *this;
	}

	bignum& operator -=(const bignum& a) {
		if ( a.sign==0 ) return *this;
		if ( sign==0 ) return *this = -a;
		if ( a.sign!=sign ) { // differing signs
			return *this += -a;
		}
		if ( abs(*this)<abs(a) ) { // sign change
			bignum tmp = abs(a) -= abs(*this);
			tmp.sign = -sign;
			if ( tmp.ndigits()==0 ) tmp.sign = 0;
			return *this = tmp;
		}

		int carry = 0;
		for(size_t i=0; i<d.size(); ++i) {
			d[i] += 10 - a.d[i] - carry;
			carry = d[i]>=10 ? 0 : 1;
			d[i] %= 10;
		}
		if ( ndigits()==0 ) sign = 0;
		return *this;
	}

	bignum& operator *=(const bignum& a) {
		if ( sign==0 || a.sign==0 ) {
			return *this = bignum(0);
		}

		bignum res;
		int carry = 0;

		for(size_t i=0; i<d.size(); ++i) {
			res.d[i] = carry;
			for(size_t j=0; j<=i; ++j) res.d[i] += d[j] * a.d[i-j];
			carry = res.d[i] / 10;
			res.d[i] %= 10;
		}
		res.sign = sign*a.sign;
		return *this = res;
	}

	int operator ==(const bignum &a) const {
		if ( sign!=a.sign ) return 0;
		for(size_t i=0; i<d.size(); ++i) if ( d[i]!=a.d[i] ) return 0;
		return 1;
	}

	int operator <(const bignum &a) const {
		if ( sign!=a.sign ) return sign<a.sign;
		if ( sign==0 ) return 0;
		size_t i;
		for(i=d.size()-1; (i>0 && d[i]==a.d[i]); --i);
		return (sign==1) ? (d[i] < a.d[i]) : (d[i] > a.d[i]);
	}

	int operator <=(const bignum &a) const {
		if ( sign!=a.sign ) return sign<=a.sign;
		if ( sign==0 ) return 1;
		size_t i;
		for(i=d.size()-1; (i>0 && d[i]==a.d[i]); --i);
		return (sign==1) ? (d[i] <= a.d[i]) : (d[i] >= a.d[i]);
	}

	int divide(bignum div, bignum &quotient, bignum &remainder) {
		bignum tmp;
		int nshift;

		if ( div.sign==0 ) {
			cerr << "Bignum error: division by zero!" << endl;
			return 1;
		}

		quotient  = bignum(0);
		remainder = abs(*this);

		tmp = abs(div);
		nshift = 0;
		while ( tmp<=remainder && tmp.ndigits()<d.size() ) {
			tmp.shl(1);
			nshift++;
		}
		tmp.shr(1);
		nshift--;

		while ( !(remainder<abs(div)) ) {
			while ( tmp<=remainder ) {
				quotient.d[nshift]++;
				remainder -= tmp;
			}
			tmp.shr(1);
			nshift--;
		}

		quotient.sign  = sign*div.sign;
		remainder.sign = sign;
		if (  quotient.ndigits()==0 )  quotient.sign = 0;
		if ( remainder.ndigits()==0 ) remainder.sign = 0;
		return 0;
	}

	bignum& operator /=(const bignum& a) {
		bignum quot, rem;
		divide(a,quot,rem);
		return *this = quot;
	}

	bignum& operator %=(const bignum& a) {
		bignum quot, rem;
		divide(a,quot,rem);
		return *this = rem;
	}

};

bignum operator -(bignum a)
{
	if ( a.sign==0 ) return a;
	a.sign *= -1;
	return a;
}

bignum abs(bignum a)
{
	if ( a.sign==-1 ) a.sign = 1;
	return a;
}

bignum operator +(bignum a, bignum b) { return a += b; }
bignum operator -(bignum a, bignum b) { return a -= b; }
bignum operator *(bignum a, bignum b) { return a *= b; }
bignum operator /(bignum a, bignum b) { return a /= b; }
bignum operator %(bignum a, bignum b) { return a %= b; }

ostream &operator <<(ostream &s, const bignum &a)
{
	s << a.str();
	return s;
}

istream &operator >>(istream &s, bignum &a)
{
	string str;
	s >> str;
	a = bignum(str);
	return s;
}

bignum A,B;

bool fairsquare(const bignum& X, const bignum& Y)
{
	string Xs = X.str();

	for(int i=0; i<Xs.length()/2; i++)
		if ( Xs[i]!=Xs[Xs.length()-1-i] ) return false;

//	cerr << "found " << X << " = sqr( " << Y << " )\n";
	return true;
}

int main()
{
	int nruns;
	cin >> nruns;

	for(int run=1; run<=nruns; run++) {

		int res = 0;
		cin >> A >> B;

		bignum X,Y,Z;
		for(int z=1; X<=B; z++) {
			Z = z;
			string Zs = Z.str(), Zsrev = Zs;
			reverse(ALL(Zsrev));
			Y = bignum(Zs + Zsrev);
			X = Y*Y;
			if ( A<=X && X<=B && fairsquare(X,Y) ) res++;
			Zsrev.erase(0,1);
			Y = bignum(Zs + Zsrev);
			X = Y*Y;
			if ( A<=X && X<=B && fairsquare(X,Y) ) res++;
		}

		cout << "Case #" << run << ": " << res << endl;
	}

	return 0;
}
