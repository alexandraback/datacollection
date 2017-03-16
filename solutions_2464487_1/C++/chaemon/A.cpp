// #includes {{{
#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cmath>
using namespace std;
// }}}
// pre-written code {{{
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define RREP(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define LET(x,a) __typeof(a) x(a)
//#define IFOR(i,it,c) for(__typeof((c).begin())it=(c).begin();it!=(c).end();++it,++i)
#define ALL(c) (c).begin(), (c).end()
#define MP make_pair

#define EXIST(e,s) ((s).find(e)!=(s).end())

#define RESET(a) memset((a),0,sizeof(a))
#define SET(a) memset((a),-1,sizeof(a))
#define PB push_back
#define DEC(it,command) __typeof(command) it=command

const int INF=0x3f3f3f3f;

typedef long long Int;
typedef unsigned long long uInt;
#ifdef __MINGW32__
typedef double rn;
#else
typedef long double rn;
#endif

typedef pair<int,int> pii;

#ifdef MYDEBUG
#include"debug.h"
#include"print.h"
#endif
// }}}

//{{{ bigint
const long double PI=3.14159265358979323846264338;
#define FFT
#include <iomanip>
#include <sstream>
#include <vector>
// bigint_base and bigint_base_digits must be consistent
const int bigint_base = 1000000000, bigint_base_digits = 9;

typedef long long ll;
//{{{ convert_base function
vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
	vector<long long> p(max(old_digits, new_digits) + 1);
	p[0] = 1;
	for (int i = 1; i < (int) p.size(); i++)
		p[i] = p[i - 1] * 10;
	vector<int> res;
	long long cur = 0;
	int cur_digits = 0;
	for (int i = 0; i < (int) a.size(); i++) {
		cur += a[i] * p[cur_digits];
		cur_digits += old_digits;
		while (cur_digits >= new_digits) {
			lldiv_t d = lldiv(cur,p[new_digits]);
			res.push_back((int)d.rem);
			cur = d.quot;
			cur_digits -= new_digits;
		}
	}
	res.push_back((int) cur);
	while (!res.empty() && !res.back()) res.pop_back();
	return res;
}
//}}}

typedef vector<long long> vll;
#ifdef FFT
//{{{ FFT
struct C { rn x, y; };
inline void add(C &lhs, const C &rhs) { lhs.x += rhs.x, lhs.y += rhs.y; }
inline void mul(C &lhs, const C &rhs) {  
	rn rx = lhs.x*rhs.x - lhs.y*rhs.y, ry = lhs.x*rhs.y + lhs.y*rhs.x;
	lhs.x = rx, lhs.y = ry;
}

const int logB=5;
const int B = 100000;
int pw[] = {1, 10, 100, 1000,10000,100000,1000000,10000000};
//C va[S], vb[S], vc[S];
C *va,*vc;

C *vtemp, eqo[2][30];
void fft_sub(C to[], C vd[], int u, int depth, int binder, int inverse) {
	if (depth == u) { to[0] = vd[binder]; return; }
	int n = 1<<(u-depth);
	fft_sub(vtemp + 2*n, vd, u, depth+1, binder, inverse);
	fft_sub(vtemp + 3*n, vd, u, depth+1, binder | (1<<depth), inverse);

	C omega, argu = eqo[inverse][u-depth];
	omega.x = 1.0, omega.y = 0.0;

	REP(bit, n) {
		int y = bit; if (y >= n/2) y -= n/2;
		C tt = vtemp[3*n+y];
		mul(tt, omega);
		add(tt, vtemp[2*n+y]);
		to[bit] = tt;
		mul(omega, argu);
	}
}
void fft(C vd[], int u) { fft_sub(vd, vd, u, 0, 0, 0); }
void ifft(C vd[], int u) {
	int N = 1<<u;
	fft_sub(vd, vd, u, 0, 0, 1);
	REP(j, N) vd[j].x /= N, vd[j].y /= N;
}
//{{{ FFT_MUL
static vll fftMultiply(const vector<int> &a,const vector<int> &b){
	static bool FFT_MUL_LOOKUP=false;
	if(!FFT_MUL_LOOKUP){
		FFT_MUL_LOOKUP=true;
		// initialization
		REP(j, 30) {
			int n = 1 << j;
			eqo[0][j].x = cos(-2*PI / n), eqo[0][j].y = sin(-2*PI / n);
			eqo[1][j].x = cos(2*PI / n),  eqo[1][j].y = sin(2*PI / n);
		}
	}
//	int N=(a.size()*logB+logB-1)/logB
//		+(b.size()*logB+logB-1)/logB;
	int N=a.size()+b.size()+3;
	int u = 2;
	for (; ; u++) if ((1<<u) > N) break;
	N = 1<<u;
	va=(C*)realloc(va,N*sizeof(C));
	vc=(C*)realloc(vc,N*sizeof(C));
	vtemp=(C*)realloc(vtemp,N*4*sizeof(C));
	memset(va,0,sizeof(C)*N);
	REP(i,a.size())va[i].x=a[i];
	REP(i,b.size())va[i].y=b[i];
	fft(va, u);
	for(int m=1;m<N;m++){
		vc[m].x=(va[m].x*va[m].y+va[N-m].x*va[N-m].y)/2;
		vc[m].y=(va[N-m].x*va[N-m].x+va[m].y*va[m].y
				-(va[m].x*va[m].x+va[N-m].y*va[N-m].y))/4;
	}
	vc[0].x=va[0].x*va[0].y;
	vc[0].y=0;
	ifft(vc, u);
	
	vll ret;
	REP(j, N) ret.push_back((ll)(vc[j].x+0.5));
	return ret;
}
//}}}
//}}}
#else
//{{{ karatsuba

static vll karatsubaMultiply(const vll &a, const vll &b) {
	int n = a.size();
	vll res(n + n);
	if (n <= 32) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				res[i + j] += a[i] * b[j];
		return res;
	}

	int k = n >> 1;
	vll a1(a.begin(), a.begin() + k), a2(a.begin() + k, a.end());
	vll b1(b.begin(), b.begin() + k), b2(b.begin() + k, b.end());

	vll a1b1 = karatsubaMultiply(a1, b1), a2b2 = karatsubaMultiply(a2, b2);

	for (int i = 0; i < k; i++) a2[i] += a1[i];
	for (int i = 0; i < k; i++) b2[i] += b1[i];

	vll r = karatsubaMultiply(a2, b2);
	for (int i = 0; i < (int) a1b1.size(); i++) r[i] -= a1b1[i];
	for (int i = 0; i < (int) a2b2.size(); i++) r[i] -= a2b2[i];

	for (int i = 0; i < (int) r.size(); i++) res[i + k] += r[i];
	for (int i = 0; i < (int) a1b1.size(); i++) res[i] += a1b1[i];
	for (int i = 0; i < (int) a2b2.size(); i++) res[i + n] += a2b2[i];
	return res;
}
//}}}
#endif
//{{{ bigint 
struct bigint {
	vector<int> a;
	int sign;
	//{{{ constructor
	bigint():sign(1){}
	bigint(long long v) { *this = v; }
	bigint(const string &s) {read(s);}
	//}}}
	//{{{ substitution
	template<class T>
		void operator=(const T &t){
			*this=bigint(t);
		}
	void operator=(const bigint &v) { sign = v.sign; a = v.a; }
	void operator=(long long v) {
		sign = 1;
		if (v < 0) sign = -1, v = -v;
		for (; v > 0;){
			lldiv_t d = lldiv(v, bigint_base);
			a.push_back(d.rem);
			v=d.quot;
		}
	}
	//}}}
	//{{{ convertion
	long long longValue() const {
		long long res = 0;
		for (int i = a.size() - 1; i >= 0; i--)
			res = res * bigint_base + a[i];
		return res * sign;
	}
	string to_string(){
		stringstream ss;
		ss<<*this;
		return ss.str();
	}
	void read(const string &s) {
		sign = 1;
		a.clear();
		int pos = 0;
		while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
			if (s[pos] == '-')
				sign = -sign;
			++pos;
		}
		for (int i = s.size() - 1; i >= pos; i -= bigint_base_digits) {
			int x = 0;
			for (int j = max(pos, i - bigint_base_digits + 1); j <= i; j++)
				x = x * 10 + s[j] - '0';
			a.push_back(x);
		}
		trim();
	}
	//}}}
	//{{{ add and subtract operation, minus-operator
	bigint operator+(const bigint &v) const {
		if (sign == v.sign) {
			bigint res = v;
			for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {
				if (i == (int) res.a.size()) res.a.push_back(0);
				res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
				carry = res.a[i] >= bigint_base;
				if (carry) res.a[i] -= bigint_base;
			}
			return res;
		}
		return *this - (-v);
	}

	bigint operator-(const bigint &v) const {
		if (sign == v.sign) {
			if (abs() >= v.abs()) {
				bigint res = *this;
				for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) {
					res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
					carry = res.a[i] < 0;
					if (carry) res.a[i] += bigint_base;
				}
				res.trim();
				return res;
			}
			return -(v - *this);
		}
		return *this + (-v);
	}
	bigint operator-() const {
		bigint res = *this;
		res.sign = -sign;
		return res;
	}

	//}}}
	//{{{ multiplication
	void operator*=(int v) {
		if (v < 0)
			sign = -sign, v = -v;
		for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
			if (i == (int) a.size())
				a.push_back(0);
			long long cur = a[i] * (long long) v + carry;
			lldiv_t d = lldiv(cur,bigint_base);
			carry = d.quot;a[i] = d.rem;
			//			carry = (int) (cur / bigint_base);
			//			a[i] = (int) (cur % bigint_base);
			//			asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
		}
		trim();
	}

	bigint operator*(int v) const {
		bigint res = *this;
		res *= v;
		return res;
	}

	void operator*=(long long v){
		*this=*this*bigint(v);
	}

	bigint operator*(long long v)const {
		bigint res = *this;
		res=*this*bigint(v);
		return res;
	}
#ifdef FFT
	static const int D=5;
	static const ll B=100000;
#else
	static const int D=6;
	static const ll B=1000000;
#endif
	bigint operator*(const bigint &v) const {
		vector<int> a6 = convert_base(this->a, bigint_base_digits, D);
		vector<int> b6 = convert_base(v.a, bigint_base_digits, D);
		vll a(a6.begin(), a6.end()), b(b6.begin(), b6.end());
		while (a.size() < b.size()) a.push_back(0);
		while (b.size() < a.size()) b.push_back(0);
		while (a.size() & (a.size() - 1)) a.push_back(0), b.push_back(0);
#ifdef FFT
		vll c = fftMultiply(a6, b6);
#else
		vll c = karatsubaMultiply(a, b);
#endif
		bigint res;
		res.sign = sign * v.sign;
		for (int i = 0, carry = 0; i < (int) c.size(); i++) {
			long long cur = c[i] + carry;
			lldiv_t d = lldiv(cur,B);
			res.a.push_back((int) d.rem);
			carry = (int) d.quot;
		}
		res.a = convert_base(res.a, D, bigint_base_digits);
		res.trim();
		return res;
	}
	//}}}
	//{{{ division and remainder
	friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
		int norm = bigint_base / (b1.a.back() + 1);
		bigint a = a1.abs() * norm, b = b1.abs() * norm;
		bigint q, r;
		q.a.resize(a.a.size());
		for (int i = a.a.size() - 1; i >= 0; i--) {
			r *= bigint_base;
			r += a.a[i];
			int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
			int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
			int d = ((long long) bigint_base * s1 + s2) / b.a.back();
			r -= b * d;
			while (r < 0)
				r += b, --d;
			q.a[i] = d;
		}
		q.sign = a1.sign * b1.sign;
		r.sign = a1.sign;
		q.trim();r.trim();
		return make_pair(q, r / norm);
	}

	bigint operator/(const bigint &v) const {
		return divmod(*this, v).first;
	}

	bigint operator%(const bigint &v) const {
		return divmod(*this, v).second;
	}

	void operator/=(int v) {
		if (v < 0)
			sign = -sign, v = -v;
		for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i) {
			long long cur = a[i] + rem * (long long) bigint_base;
			lldiv_t d = lldiv(cur,v);
			a[i] = (int) d.quot;rem = (int) d.rem;
		}
		trim();
	}

	bigint operator/(int v) const {
		bigint res = *this;
		res /= v;
		return res;
	}

	int operator%(int v) const {
		if (v < 0) v = -v;
		int m = 0;
		for (int i = a.size() - 1; i >= 0; --i) m = (a[i] + m * (long long) bigint_base) % v;
		return m * sign;
	}
	//}}}
	//{{{ increment decrement etc
	void operator+=(const bigint &v) { *this = *this + v; }
	void operator-=(const bigint &v) { *this = *this - v; }
	void operator*=(const bigint &v) { *this = *this * v; }
	void operator/=(const bigint &v) { *this = *this / v; }
	//}}}
	//{{{ compare operator
	bool operator<(const bigint &v) const {
		if (sign != v.sign) return sign < v.sign;
		if (a.size() != v.a.size()) return a.size() * sign < v.a.size() * v.sign;
		for (int i = a.size() - 1; i >= 0; i--)
			if (a[i] != v.a[i]) return a[i] * sign < v.a[i] * sign;
		return false;
	}

	bool operator>(const bigint &v) const { return v < *this; }
	bool operator<=(const bigint &v) const { return !(v < *this); }
	bool operator>=(const bigint &v) const { return !(*this < v); }
	bool operator==(const bigint &v) const { return !(*this < v) && !(v < *this); }
	bool operator!=(const bigint &v) const { return *this < v || v < *this; }
	bool isZero() const { return a.empty() || (a.size() == 1 && !a[0]); }
	//}}}
	//{{{ gcd, lcm and abs
	bigint abs() const {
		bigint res = *this;
		res.sign *= res.sign;
		return res;
	}
	friend bigint abs(const bigint &r){
		return r.abs();
	}
	friend bigint gcd(const bigint &a, const bigint &b) {
		return b.isZero() ? a : gcd(b, a % b);
	}
	friend bigint lcm(const bigint &a, const bigint &b) {
		return a / gcd(a, b) * b;
	}
	//}}}
	//{{{ input,output
	friend istream& operator>>(istream &stream, bigint &v) {
		string s;
		stream >> s;
		v.read(s);
		return stream;
	}

	friend ostream& operator<<(ostream &stream, const bigint &v) {
		if (v.sign == -1)
			stream << '-';
		stream << (v.a.empty() ? 0 : v.a.back());
		for (int i = (int) v.a.size() - 2; i >= 0; --i)
			stream << setw( bigint_base_digits) << setfill('0') << v.a[i];
		return stream;
	}
	//}}}
	//{{{ cocnvert base and trimming
	void trim() {
		while (!a.empty() && !a.back()) a.pop_back();
		if (a.empty()) sign = 1;
	}
	//}}}
};
//}}}
//}}}

bigint f(bigint r,bigint n){
	return n*(r*2-3)+n*2*(n+1);
}

void main2(){
	uInt r,t;
	cin>>r>>t;
	bigint left("0"),right("4000000000000000000");
	while(right-left>1){
		bigint mid=(right+left)/2;
		if(f(r,mid)<=t)left=mid;
		else right=mid;
	}
	cout<<left<<endl;
}

// main function {{{
int main() {
	int T;cin>>T;
	REP(ct, T){
		cout<<"Case #"<<ct+1<<": ";
		main2();
	}
	return 0;
}
//}}}
