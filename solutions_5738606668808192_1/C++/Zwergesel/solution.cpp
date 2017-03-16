#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

#define BIGINT_BASE 1000000000
typedef long long ll;
typedef unsigned long long ull;

class BigInt;
ostream& operator<<(ostream& out, const BigInt& x);

class BigInt {
	private:
	/* Member variables */
	bool s;				// sign, false = positive, true = negative
	vector<ll> v;		// data
	
	/* Note to self: add and sub are using unsigned arithmetic */
	void add(const BigInt& x) {
		int carry(0);
		if (x.v.size() > v.size()) v.resize(x.v.size(), 0);
		for (unsigned int u=0; u < x.v.size(); u++) {
			v[u] += x.v[u] + carry;
			carry = v[u] / BIGINT_BASE;
			v[u] %= BIGINT_BASE;
		}
		for (unsigned int u=x.v.size(); u < v.size() && carry; u++) {
			v[u] += carry;
			carry = v[u] / BIGINT_BASE;
			v[u] %= BIGINT_BASE;
		}
		if (carry > 0) v.push_back(carry);
	}
	
	bool sub(const BigInt& x) {
		BigInt& keep(*this), sub(x);
		bool sign_changed(false);

		// Swap keep and sub, if necessary
		if (compareAbs(*this,x)) {
			swap(keep, sub);
			sign_changed = true;
			v.resize(x.size(), 0);
		}

		// Perform subtraction: keep - sub
		int carry(0);
		for (unsigned int u=0; u < sub.v.size(); u++) {
			if (keep.v[u] >= sub.v[u] + carry) {
				v[u] = keep.v[u] - sub.v[u] - carry;
				carry = 0;
			} else {
				v[u] = keep.v[u] + BIGINT_BASE - sub.v[u] - carry;
				carry = 1;
			}
		}
		if (carry) {
			for (unsigned int u=sub.v.size(); u < keep.v.size(); u++) {
				if (keep.v[u] == 0) {
					v[u] = BIGINT_BASE - 1;
				} else {
					v[u] -= 1;
					break;
				}
			}
		}
		
		// Resize v, if necessary
		unsigned int resize = v.size();
		for (;resize && !v[resize-1];resize--);
		v.resize(resize, 0);
		
		// Return sign change
		return sign_changed;
	}
	
	/* Note to self: This uses Karatsuba's algorithm */
	void mul(const BigInt& x) {
		if (x.v.size() == 0 || v.size() == 0) {
			v.clear();
			return;
		}
		int m = min(v.size(), x.v.size()) / 2;
		if (m == 0) {
			// Standard multiplication
			BigInt& n(*this), m(x);
			if (x.v.size() > 1) swap(n, m);
			if (x.v.size() > v.size()) v.resize(x.v.size(), 0);
			
			// Simple linear multiplication
			ll carry(0), factor(m.v[0]);
			for (unsigned int u=0; u < n.size(); u++) {
				v[u] = n.v[u] * factor + carry;
				carry = v[u] / BIGINT_BASE;
				v[u] %= BIGINT_BASE;
			}
			if (carry > 0) v.push_back(carry);
		} else {
			// Karatsuba's Recursion
			// z = z0 * B^m2 + z1 * B^m + z2
			// z0 = x1y1
			// z2 = x2y2
			// z1 = (x1 + x2)(y1 + y2) - z0 - z2
			BigInt x1, x2, y1, y2;
			x2.v.assign(x.v.begin(), x.v.begin() + m);
			x1.v.assign(x.v.begin() + m, x.v.end());
			y2.v.assign(v.begin(), v.begin() + m);
			y1.v.assign(v.begin() + m, v.end());
			BigInt p(x1), q(y1);
			p.add(x2);
			q.add(y2);
			p.mul(q);
			x1.mul(y1);
			x2.mul(y2);
			p.sub(x1);
			p.sub(x2);
			x1.baseLShift(m*2);
			p.baseLShift(m);
			x1.add(p);
			x1.add(x2);
			v.assign(x1.v.begin(), x1.v.end());
		}
	}
	
	/* Note: positive values of sha/shb shift a/b right, negative values shift left */
	static bool compareAbs(const BigInt& a, int sha, const BigInt& b, int shb) {
		if (a.size()-sha != b.size()-shb) return a.size()-sha < b.size()-shb;
		for (int i=a.size()-1, j=b.size()-1; i>=sha && j>=shb; --i, --j) {
			int x = i >= 0 && i >= sha ? a[i] : 0;
			int y = j >= 0 && j >= shb ? b[j] : 0;
			if (x != y) return x < y;
		}
		return false;
	}
	
	/* Note: Works only for a >= 0, b < BIGINT_BASE */
	static void divideQuick(const BigInt& a, ll b, BigInt* q, BigInt* r) {
		*q = BigInt();
		int u = a.v.size() - 1;
		ll p = 0;
		while (u >= 0) {
			p = p * BIGINT_BASE + a.v[u];
			if (q->v.size() > 0 || p >= b) {
				q->v.push_back(p / b);
			}
			p %= b;
			u--;
		}
		reverse(q->v.begin(), q->v.end());
		*r = BigInt(p);
	}
	
	/* Note: 0 <= a < BASE^n+1 und BASE^n/2 <= b < BASE^n */
	static void divideSub(const BigInt& a, const BigInt& b, BigInt* q, BigInt* r) {
		if (compareAbs(a,0,b,-1)) {
			ll quot = (a.v[a.v.size()-2] + a.v.back() * BIGINT_BASE) / b.v.back();
			if (quot >= BIGINT_BASE) quot = BIGINT_BASE - 1;
			BigInt t(quot);
			t.mul(b);
			if (compareAbs(a,t)) {
				quot--;
				t.sub(b);
			}
			if (compareAbs(a,t)) {
				quot--;
				t.sub(b);
			}
			*r = a;
			r->sub(t);
			*q = BigInt(quot);
		} else {
			BigInt a2(a), b2(b);
			b2.baseLShift(1);
			a2.sub(b2);
			divideAbs(a2,b,q,r);
			BigInt base(BIGINT_BASE);
			q->add(base);
		}
	}
	
	static void divideAbs(const BigInt& a, const BigInt& b, BigInt* q, BigInt* r) {
		if (b.v.size() == 0) {
			throw invalid_argument("BigInt division by zero.");
		} else if (a.v.size() < b.v.size()) {
			*q = BigInt(0);
			*r = a;
		} else if (a.v.size() <= 2) {
			ll ia = a.v.front();
			ll ib = b.v.front();
			if (a.v.size() > 1) ia += BIGINT_BASE * a.v.back();
			if (b.v.size() > 1) ib += BIGINT_BASE * b.v.back();
			*q = BigInt(ia / ib);
			*r = BigInt(ia % ib);
		} else if (b.size() == 1) {
			divideQuick(a, b.v.front(), q, r);
		} else if (b.v.back() < (BIGINT_BASE + 1) / 2) {
			BigInt a2(a), b2(b), r2, r3;
			ll fac = ((BIGINT_BASE + 1) / 2 + b.v.back() - 1) / b.v.back();
			BigInt f(fac);
			a2.mul(f);
			b2.mul(f);
			divideAbs(a2, b2, q, &r2);
			divideQuick(r2, fac, r, &r3);
		} else if (a.v.size() == b.v.size()) {
			if (compareAbs(a,b)) {
				*q = BigInt(0);
				*r = a;
			} else {
				*q = BigInt(1);
				*r = a;
				r->sub(b);
			}
		} else if (a.v.size() == b.v.size() + 1) {
			divideSub(a,b,q,r);
		} else {
			int len = a.v.size() - b.v.size() - 1;
			BigInt a2(a), q2, r2;
			a2.baseRShift(len);
			divideSub(a2, b, &q2, &r2);
			r2.v.insert(r2.v.begin(), a.v.begin(), a.v.begin()+len);
			while (r2.v.size() > 0 && r2.v.back() == 0) r2.v.resize(r2.v.size()-1);
			divideAbs(r2, b, q, r);
			q2.baseLShift(len);
			q->add(q2);
		}
	}	
	
	public:
	/* Constructors */
	BigInt():s(false){}
	BigInt(ll n):s(false){
		if (n < 0) {
			n = -n;
			s = true;
		}
		while (n) {
			v.push_back(n % BIGINT_BASE);
			n /= BIGINT_BASE;
		}
	}
	BigInt(const string& n):s(false){
		int f(0);
		if (n[0] == '-') {
			s = true;
			f = 1;
		} else if (n[0] == '+') {
			f = 1;
		}
		ll mul(1), seg(0);
		while (n[f] == '0') ++f; // Eliminate leading zeros
		for (int i = n.length() - 1; i >= f; --i) {
			seg += mul * ll(n[i] - '0');
			mul *= 10;
			if (mul == BIGINT_BASE) {
				v.push_back(seg);
				seg = 0;
				mul = 1;
			}
		}
		if (seg > 0) v.push_back(seg);
	}
	
	/* Public Methods */
	size_t size() const { return v.size(); }
	bool negative() const { return s; }
	void negative(bool set) { s = set; }
	void negate() { s = !s; }
	
	bool even() const { return (v.size() == 0) || ((v[0] & 1ull) == 0); }
	bool odd() const { return (v.size() > 0) && (v[0] & 1ull); }
	
	void baseLShift(unsigned int sh) {
		if (v.size() > 0) v.insert(v.begin(), sh, 0);
	}
	void baseRShift(unsigned int sh) {
		if (v.size() > sh) {
			v.erase(v.begin(), v.begin()+sh);
		} else {
			v.clear();
		}
	}	
	
	static bool compareAbs(const BigInt& a, const BigInt& b) {
		if (a.size() != b.size()) return a.size() < b.size();
		for (int i = a.size() - 1; i >= 0; --i) {
			if (a[i] != b[i]) return a[i] < b[i];
		}
		return false;
	}
	
	void pow(ull exp) {
		BigInt raise(*this);
		v.assign(1,1);
		for (unsigned int u = 0; u < 64 && exp; u++) {
			if (exp & (1ULL << u)) {
				mul(raise);
				exp &= exp-1;
			}
			raise.mul(raise);
		}
	}
	
	static void divide(const BigInt& a, const BigInt& b, BigInt* q, BigInt* r) {
		divideAbs(a,b,q,r);
		r->s = a.negative();
		q->s = a.negative() ^ b.negative();
	}
	
	/* Member operators */
	int operator[](int p) const { return v[p]; }
	
	void operator+=(const BigInt& x) {
		if (&x == this) {
			mul(BigInt(2));
		} else if (s == x.s) {
			add(x);
		} else {
			s ^= sub(x);
		}
	}
	
	void operator-=(const BigInt& x) {
		if (&x == this) {
			v.clear();
			s = false;
		} else if (s == x.s) {
			s ^= sub(x);
		} else {
			add(x);
		}
	}
	
	void operator*=(const BigInt& x) {
		if (&x == this) {
			BigInt tmp(x);
			mul(tmp);
			s ^= tmp.s;
		} else {
			mul(x);
			s ^= x.s;
		}
	}
	
	void operator+=(ll x) { BigInt tmp(x); *this+=tmp; }
	void operator-=(ll x) { BigInt tmp(x); *this-=tmp; }
	void operator*=(ll x) { BigInt tmp(x); *this*=tmp; }
	
	void operator<<=(ull x) {
		if (x > 0) {
			BigInt m(2);
			m.pow(x);
			mul(m);
		}
	}
	void operator>>=(ull x) {
		if (x > 0) {
			BigInt d(2), q, r;
			d.pow(x);
			divide(*this, d, &q, &r);
			*this = q;
		}
	}
};

/* BigInt operators */
/* Note: -0 should behave the same as +0 */
bool operator==(const BigInt& a, const BigInt& b) {
	if (a.size() != b.size()) return false;
	if (a.negative() != b.negative()) return a.size() == 0;
	for (unsigned int u=0; u < a.size(); u++) {
		if (a[u] != b[u]) return false;
	}
	return true;
}

bool operator<(const BigInt& a, const BigInt& b) {
	if (b.size() == 0) return a.size() > 0 && a.negative();
	if (a.negative()) {
		return b.negative() ? BigInt::compareAbs(b,a) : true;
	} else {
		return b.negative() ? false : BigInt::compareAbs(a,b);
	}
}

bool operator!=(const BigInt& a, const BigInt& b) { return !(a == b); }
bool operator>(const BigInt& a, const BigInt& b) { return b < a; }
bool operator<=(const BigInt& a, const BigInt& b) { return !(b < a); }
bool operator>=(const BigInt& a, const BigInt& b) { return !(a < b); }
BigInt operator+(BigInt a, const BigInt& b) { a += b; return a; }
BigInt operator-(BigInt a, const BigInt& b) { a -= b; return a; }
BigInt operator*(BigInt a, const BigInt& b) { a *= b; return a; }
BigInt pow(BigInt a, ull exp) { a.pow(exp); return a; }
BigInt operator+(const BigInt& a, ll x) { BigInt r(x); r += a; return r; }
BigInt operator-(const BigInt& a, ll x) { BigInt r(x); r -= a; r.negate(); return r; }
BigInt operator*(const BigInt& a, ll x) { BigInt r(x); r *= a; return r; }
BigInt operator+(ll x, const BigInt& a) { BigInt r(x); r += a; return r; }
BigInt operator-(ll x, const BigInt& a) { BigInt r(x); r -= a; return r; }
BigInt operator*(ll x, const BigInt& a) { BigInt r(x); r *= a; return r; }
BigInt abs(BigInt a) { a.negative(false); return a; }
BigInt operator<<(BigInt a, ull x) { a <<= x; return a; }
BigInt operator>>(BigInt a, ull x) { a >>= x; return a; }


ostream& operator<<(ostream& out, const BigInt& x) {
	if (x.size() == 0) {
		out << '0';
	} else {
		if (x.negative()) out << '-';
		int i = x.size() - 1;
		out << x[i];
		for (--i; i >= 0; --i) {
			out << setfill('0') << setw(log10(BIGINT_BASE)) << x[i];
		}
	}
	return out;
}


#define FOR(i,n) for (int i=0; i<n; ++i)
#define FORVEC(it,v) for (auto it=(v).begin(); it != (v).end(); ++it)
#define NUL(arr) memset(arr, 0, sizeof(arr));
#define SORT(x) sort((x).begin(), (x).end());

const ll MAX = 500;
vector<ll> primes;
bool isprime[MAX];

void sieve()
{
	fill(isprime, isprime+MAX, true);
	isprime[0] = isprime[1] = false;
	
	ll m = (ll) ceil(sqrt(MAX));
	for (ll i=2; i<m; i++) {
		if (isprime[i]) {
			for (ll j=i*i; j<MAX; j+=i) isprime[j] = false;
		}
	}
	for (ll i=2; i<MAX; i++) {
		if (isprime[i]) primes.push_back(i);
	}
}

bool test(ull n)
{
	string bits;
	stringstream ss;
	ss << bitset<32>(n);
	ss >> bits;
	ll divs[11] = {0};
	bool correct = true;
	for (ll b=2; b<=10; ++b) {
		BigInt n(0);
		BigInt m(1);
		for (int p=bits.size() - 1; p>=0; --p) {
			if (bits[p] == '1') n += m;
			m *= b;
		}
		//cout << bits << " in base " << b << " is " << n << endl;
		divs[b] = 0;
		for (ll p : primes) {
			BigInt pr(p), q, r;
			BigInt::divide(n, pr, &q, &r);
			if (r == 0) {
				divs[b] = p;
				//cout << "Divisor of " << n << " is " << p << endl;
				break;
			}
		}
		if (divs[b] == 0) {
			correct = false;
			break;
		}
	}
	if (correct) {
		cout << bits;
		for (int b=2; b<=10; ++b) {
			cout << " " << divs[b];
		}
		cout << endl;
	}
	return correct;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	sieve();
	
	int op = 0;
	cout << "Case #1:\n";
	for (ull i=(1ULL<<31)+1; i<(1ULL<<32); i+=2) {
		if (test(i)) {
			if (++op == 500) break;
		}
	}
	
	return 0;
}
