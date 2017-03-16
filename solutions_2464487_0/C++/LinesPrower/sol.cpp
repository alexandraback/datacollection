#define _SOLUTION                                                          \
                                                                           \
                                                                           \
void init()                                                                \
{                                                                          \
}                                                                          \
                                                                           \
void solvecase()                                                           \
{                                                                          \
    $I2(Num, r, t);                                                        \
    $$ res = bs_max(Num(1), t, k, (2 * r + 1) * k + 2 * k * (k - 1) <= t); \
    _w(res);                                                               \
}                                                                          \
                                                                           \
                                                                           \
_GCJ_SOLVE                                                                 \
_END_SOL_CL                                                                \
                                                                           \
//////////////////////////////////////////////////////////////////////////// 
//
// ====== <<< PREWRITTEN CODE >>> ============================================
//
#pragma comment(linker, "/STACK:32000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <stdarg.h>
#include <memory.h>
#include <string.h>
#include <assert.h>
#include <type_traits>
#include <climits>
#include <hash_map>
#include <hash_set>
#include <functional>
using namespace std;
#define gcc_typename typename
using namespace __gnu_cxx;
#define LL_SPEC "%I64d"
#define ITER_WRITE inline void _write() const { _wstr("["); write_iterable(*this, SepComma()); _wstr("]"); }
template<typename T>
struct ValueType {
    typedef typename remove_const<T>::type clean_type1;
	typedef typename remove_reference<clean_type1>::type clean_type;
	typedef typename clean_type::value_type type;
};
template<typename T>
struct _CleanType {
    typedef typename remove_const<T>::type _type;
    typedef typename remove_reference<_type>::type type;
};
template<typename T>
struct _IsIterable { enum { value = 0 }; };
#define _wlf printf("\n")
#define _wstr(s) printf("%s", s)
template<typename T>
struct item_type { typedef typename T::value_type type; };
template<typename T>
struct item_type<T*> { typedef T type; };
template<typename T, size_t sz>
struct item_type<T[sz]> { typedef T type; };
template<typename T, size_t sz>
struct item_type<T(&)[sz]> { typedef T type; };
template<typename T>
struct item_type<T*&> { typedef T type; };
template<typename T>
struct item_type<T**> { typedef T type; };
template<typename T>
struct item_type<T**&> { typedef T type; };
template<typename T>
struct _seq
{
    template<typename F>
    static inline void process(T &t, F f) { t.process(f); }
};
template<typename T>
struct _seq<const T>
{
	template<typename F>
	static inline void process(const T &t, F f) { t.process(f); }
};
template<typename T>
struct _seq<vector<T> >
{
    template<typename F>
    static void process(vector<T> &t, F f)
    {
        for (typename vector<T>::iterator it = t.begin(); it != t.end(); ++it)
            if (!f(*it)) break;
    }
};
template<typename T>
struct _seq<const vector<T> >
{
    template<typename F>
    static void process(const vector<T> &t, F f)
    {
        for (typename vector<T>::const_iterator it = t.begin(); it != t.end(); ++it)
            if (!f(*it)) break;
    }
};
template<typename T>
struct _seq<set<T> >
{
    template<typename F>
    static void process(set<T> &t, F f)
    {
        for (typename set<T>::iterator it = t.begin(); it != t.end(); ++it)
            if (!f(*it)) break;
    }
};
template<typename T>
struct _seq<const set<T> >
{
    template<typename F>
    static void process(const set<T> &t, F f)
    {
        for (typename set<T>::const_iterator it = t.begin(); it != t.end(); ++it)
            if (!f(*it)) break;
    }
};
template<typename T1, typename T2>
struct _seq<const map<T1, T2> >
{
    template<typename F>
    static void process(const map<T1, T2> &t, F f)
    {
        for (typename map<T1, T2>::const_iterator it = t.begin(); it != t.end(); ++it)
            if (!f(*it)) break;
    }
};
template<>
struct _seq<string>
{
    template<typename F>
    static void process(string &s, F f)
    {
        for (size_t i = 0; i < s.length(); i++)
            if (!f(s[i])) break;
    }
};
template<>
struct _seq<const string>
{
    template<typename F>
    static void process(const string &s, F f)
    {
        for (size_t i = 0; i < s.length(); i++)
            if (!f(s[i])) break;
    }
};
template<typename T, typename F>
inline void _seq_process_c(const T &t, F f)
{
	_seq<const T>::template process<F>(t, f);
}
#define xforeach_(a, v) \
	{ \
	const auto &__a__ = a; \
    _seq_process_c(__a__, [&](const gcc_typename ValueType<decltype(__a__)>::type &v) -> bool {
#define x_endfe return true; }); }
#define xforeach(a, v, ...)  xforeach_(a, v) __VA_ARGS__; x_endfe
#define xfor(a, v, ...) xforeach(a, v, __VA_ARGS__)
struct SepComma { inline static void Print() { _wstr(", "); } };
template<typename T>
struct Range
{
	typedef T iterator;
	typedef T value_type;
	Range(T a, T b) : a(a), b(b) {}
	inline iterator begin() const { return a; }
	inline iterator end() const { return b; }
	inline value_type resolve_iterator(const iterator &it) const { return it; }
	inline int size(int mx = numeric_limits<int>::max()) const { return b < a ? 0 : b - a; }
	value_type operator [] (int i) const { return a + i; }
    template<typename F>
    inline void process(F f) const
    {
        for (T i = a; i < b; ++i)
            if (!f(i)) break;
    }
	Range<T> isect(const Range<T> other)
	{
		return Range<T>(max(a, other.a), min(b, other.b));
	}
	const T a, b;
	ITER_WRITE
};
template<typename T> struct _IsIterable<Range<T> > { enum { value = 1 }; };
static char __strbuf[1000001];
template<typename T>
struct _io
{
	inline static void read(T &x, int i) { x._read(i); }
	inline static void write(const T &x) { x._write(); }
};
template<>
struct _io<int>
{
	inline static void read(int &x, int i) { scanf("%d", &x); }
	inline static void write(const int &x) { printf("%d", x); }
};
template<>
struct _io<long long>
{
	inline static void read(long long &x, int i) { scanf(LL_SPEC, &x); }
	inline static void write(const long long &x) { printf(LL_SPEC, x); }
};
template<>
struct _io<double>
{
	inline static void read(double &x, int i) { scanf("%lf", &x); }
	inline static void write(const double &x) { printf("%.9f", x); }
};
template<>
struct _io<char>
{
	inline static void read(char &c, int i) { char buf[3]; scanf("%s", buf); c = buf[0]; }
	inline static void write(const char &c) { printf("%c", c); }
};
template<>
struct _io<bool>
{
	inline static void read(bool &b, int i) { int t; scanf("%d", &t); b = t != 0; }
	inline static void write(const bool &b) { printf("%s", b ? "#t" : "#f"); }
};
template<>
struct _io<string>
{
    inline static void read(string &s, int i) { scanf("%s", __strbuf); s = string(__strbuf); }
    inline static void write(const string &s) { printf("%s", s.c_str()); }
};
template<size_t x>
struct _io<char[x]>
{
	inline static void write(const char s[x]) { printf("%s", s); }
};
template<>
struct _io<const char*>
{
    inline static void write(const char *s) { printf("%s", s); }
};
template<typename T> inline void _w(const T &a) { _io<typename _CleanType<T>::type>::write(a); }
#define $I(type, name) \
	type name; \
	_io<type>::read(name, 0)
#define $I2(type, name1, name2) $I(type, name1); $I(type, name2)
template<typename T, typename sep>
void write_array(const T &a, int n)
{
	typedef typename item_type<T>::type X;
	for (int i = 0; i + 1 < n; i++)
	{
		_io<X>::write(a[i]);
		sep::Print();
	}
	if (n > 0) _io<X>::write(a[n-1]);
}
template<typename T, typename Sep>
void write_iterable(const T &a, Sep sep)
{
	bool first = true;
    typedef typename T::value_type i_type;
	xforeach(a, i,
		if (!first) sep.Print();
		_io<i_type>::write(i);
		first = false;
	)
}
template<typename T>
struct _io<vector<T> >
{
	inline static void read(vector<T> &x, int idx)
    {
        int sz;
        _io<int>::read(sz, 0);
        assert(sz >= 0);
        x.resize(sz);
        for (int i = 0; i < sz; i++) _io<T>::read(x[i], i);
    }
	inline static void write(const vector<T> &x) { _wstr("["); write_array<vector<T>, SepComma>(x, x.size()); _wstr("]"); }
};
template<typename T1, typename T2>
struct _io<map<T1, T2> >
{
    inline static void write(const map<T1, T2> &x) { _wstr("{"); write_iterable(x, SepComma()); _wstr("}"); }
};
template<typename T1, typename T2>
struct _io<pair<T1, T2> >
{
    inline static void write(const pair<T1, T2> &x) { _w("("); _w(x.first); _w(", "); _w(x.second); _w(")"); }
};
#define $$ auto
struct Mod {} mod;
template<typename T> struct _mod
{
	T a;
	_mod(T a) : a(a) {}
    template<typename S>
	inline S operator % (const S &b) { S res = a % b; if (res < 0) res += b; return res; }
};
template<typename T> inline _mod<T> operator % (const T &a, Mod) { return _mod<T>(a); }
template<typename T, typename F>
inline T BS_MAX(const T &_l, const T &_r, F f)
{
	T l(_l), r(_r);
	assert(l <= r);
	if (f(r)) return r;
	while (l + 1 < r)
	{
		T m = (l + r) / 2;
		if (f(m)) l = m; else r = m;
	}
	return l;
}
#define bs_max(l, r, name, ftr) \
	BS_MAX(l, r, [&](const gcc_typename _CleanType<decltype(r)>::type &name) -> bool { return ftr; })
string sgets()
{
	gets(__strbuf);
	return string(__strbuf);
}
struct
{
	template<typename T>
	inline Range<T> operator() (T a, T b) const
	{
		return Range<T>(a, b+1);
	}
	template<typename T1, typename T2>
	struct Sig2
	{
		typedef Range<T1> ret_type;
	};
} _seg;
#define GET_SIZES int sa = (int)a.a.size(), sb = (int)b.a.size()
template<typename T>
class BigInt
{    
public:
    enum { bigbaselen = 4, base = 10, bigbase = 10000 };
	BigInt(long long x)
	{
		if (x < 0) { x = -x; sgn = -1; }
		else sgn = x > 0 ? 1 : 0;
		while (x) 
		{
			a.push_back(x % bigbase);
			x /= bigbase;
		}
	}
	BigInt(const string &s)
	{
        Init(s);        
	}
	inline bool _is_zero() const { return sgn == 0; }
	inline int _mod2() const { return sgn == 0 ? 0 : (int)a[0] & 1; }
	static bool lesseqabs(const BigInt &a, const BigInt &b, bool eq)
	{
		GET_SIZES;
		if (sa != sb) return sa < sb;
		for (int i = sa - 1; i >= 0; i--)
			if (a.a[i] != b.a[i])
				return a.a[i] < b.a[i];
		return eq;
	}
	static BigInt addabs(const BigInt &a, const BigInt &b, int sgn)
	{
		if (a.a.size() < b.a.size()) return addabs(b, a, sgn);
		BigInt res;
		res.sgn = sgn;
		GET_SIZES;
		res.a.reserve(sa + 1);
		T carry = 0;
		for (int i = 0; i < sa; i++)
		{
			T t = a.a[i] + carry;
			if (i < sb) t += b.a[i];
			if (t >= bigbase) 
			{
				carry = 1;
				t -= bigbase;
			}
			else
			{
				carry = 0;
			}
			res.a.push_back(t);
		}
		if (carry) res.a.push_back(carry);
		return res;
	}
	static BigInt subabs(const BigInt &a, const BigInt &b, int sgn)
	{
		BigInt res;
		res.sgn = sgn;
		GET_SIZES;
		res.a.resize(sa);
		T borrow = 0;
		for (int i = 0; i < sa; i++)
		{
			T t = a.a[i] - borrow;
			if (i < sb) t -= b.a[i];
			if (t < 0)
			{
				borrow = 1;
				t += bigbase;
			}
			else
			{
				borrow = 0;
			}
			res.a[i] = t;
		}
		res.pop_back();
		return res;
	}
	static BigInt divmod(const BigInt &a, T b, T &mod)
	{
		if (b == 0) { mod = -1; return BigInt(0); }
		BigInt res;
		res.sgn = a.sgn;
		if (b < 0)
		{
			res.sgn = -res.sgn;
			b = -b;
		}
		int sz = (int)a.a.size();
		res.a.resize(sz);
		long long cur = 0;
		for (int i = sz - 1; i >= 0; i--)
		{
			cur = cur * bigbase + a.a[i];
			res.a[i] = (T)(cur / b);
			cur %= b;
		}
		mod = (T)cur;
		if (res.sgn < 0 && mod != 0)
		{
			mod = b - mod;
			res.incabs();
		}
		res.pop_back();
		return res;
	}
	void incabs()
	{
		int sz = (int)a.size();
		for (int i = 0; i < sz; i++)
			if (a[i] == bigbase - 1)
			{
				a[i] = 0;
			}
			else
			{
				a[i]++;
				return;
			}
		a.push_back(1);
	}
	static BigInt gcd(BigInt a, BigInt b)
	{
		int pow = 0;
		if (a.sgn < 0) a.sgn = 1;
		if (b.sgn < 0) b.sgn = 1;
		while (true)
		{			
			if (a._is_zero()) return (BigInt(2) ^ pow) * b;
			if (b._is_zero()) return (BigInt(2) ^ pow) * a;
			bool f1 = a._mod2() == 0, f2 = b._mod2() == 0;
			if (f1 || f2)
			{
				if (f1 && f2) pow++;
				if (f1) a = a / 2;
				if (f2) b = b / 2;
			}
			else
			{
				if (a < b) b = b - a; else a = a - b;
			}
		}
		return BigInt(0);
	}
	friend bool operator < (const BigInt &a, const BigInt &b)
	{
		if (a.sgn != b.sgn) return a.sgn < b.sgn;
		if (a.sgn > 0) return lesseqabs(a, b, false);
		if (a.sgn < 0) return lesseqabs(b, a, false);
		return false;
	}
	friend bool operator <= (const BigInt &a, const BigInt &b)
	{
		if (a.sgn != b.sgn) return a.sgn < b.sgn;
		if (a.sgn > 0) return lesseqabs(a, b, true);
		if (a.sgn < 0) return lesseqabs(b, a, true);
		return true;
	}
	friend bool operator > (const BigInt &a, const BigInt &b)
	{
		return b < a;
	}
	friend bool operator >= (const BigInt &a, const BigInt &b)
	{
		return b <= a;
	}
	friend bool operator == (const BigInt &a, const BigInt &b)
	{
		return a.sgn == b.sgn && a.a == b.a;
	}
	friend bool operator != (const BigInt &a, const BigInt &b)
	{
		return a.sgn != b.sgn || a.a != b.a;
	}
	friend T operator % (const BigInt &a, T b)
	{
		T mod;
		divmod(a, b, mod);
		return mod;
	}
	friend BigInt operator / (const BigInt &a, T b)
	{
		T dummy;
		return divmod(a, b, dummy);
	}
	friend BigInt operator ^ (const BigInt &a, long long x)
	{
		if (x < 0) return BigInt(0);
		BigInt res(1), t(a);
		while (x)
		{
			if (x & 1) res = res * t;
			t = t * t;
			x /= 2;
		}
		return res;
	}
	friend BigInt operator + (const BigInt &a, const BigInt &b) 
	{
		if (a.sgn == 0) return b;
		if (b.sgn == 0) return a;
		if (a.sgn == b.sgn) return addabs(a, b, a.sgn);
		if (lesseqabs(a, b, false)) return subabs(b, a, b.sgn);
		return subabs(a, b, a.sgn);
	}
	friend BigInt operator - (const BigInt &a, const BigInt &b)
	{
		return a + Neg(b);
	}
	friend BigInt operator * (const BigInt &a, const BigInt &b)
	{
		BigInt res;
		res.sgn = a.sgn * b.sgn;
		if (res.sgn == 0) return res;
		GET_SIZES;
		res.a.resize(sa + sb);
		for (int i = 0; i < sa; i++)
			for (int j = 0; j < sb; j++)
			{
				T t = a.a[i] * b.a[j];
				res.a[i + j] += t % bigbase;
				res.a[i + j + 1] += t / bigbase;
			}
		for (int i = 0; i < sa + sb - 1; i++) 
			res.a[i+1] += res.a[i] / bigbase, res.a[i] %= bigbase;
		res.pop_back();
		return res;
	}
	static BigInt Neg(const BigInt &a)
	{
		BigInt res(a);
		res.sgn *= -1;
		return res;
	}
	static BigInt Abs(const BigInt &a)
	{
		BigInt res(a);
		if (res.sgn == -1) res.sgn = 1;
		return res;
	}
	string ToString() const
	{
		if (sgn == 0) return "0";
		string res;
		if (sgn < 0) res = "-";
		int k = (int)a.size();
		for (int i = k - 1; i >= 0; i--)
		{
			int mx = i == k - 1 ? 0 : bigbaselen;
			string s;
			T t = a[i];
			for (int i = 0; i < mx || t; i++)
			{
				s += (t % base) + '0';
				t /= base;
			}
			reverse(s.begin(), s.end());
			res.append(s);
		}
		return res;
	}	
	friend ostream& operator <<(ostream &out, const BigInt &a)
	{
		out << a.ToString();
		return out;
	}
    void _write() const { _w(ToString()); }
    void _read(int idx) { $I(string, tmp); Init(tmp); }
    BigInt() : sgn(0) {}
private:
	vector<T> a;
	int sgn;
	void pop_back()
	{
		while (!a.empty() && a.back() == 0) a.pop_back();
		if (a.empty()) sgn = 0;
	}    
    void Init(const string &s)
    {
        a.clear();
		int n = (int)s.size();
		int i;
		T k = 1;
		T cur = 0;
		for (i = n-1; i >= 0 && isdigit(s[i]); i--)
		{
			cur = cur + k * (s[i] - '0');
			k *= base;
			if (k == bigbase)
			{
				a.push_back(cur);
				cur = 0;
				k = 1;
			}
		}
		if (cur > 0) a.push_back(cur);
		while (!a.empty() && a.back() == 0) a.pop_back();		
		if (i > 0) { sgn = 0; a.clear(); return; }
		if (i == 0 && s[i] != '-' && s[i] != '+') { sgn = 0; a.clear(); return; }
		sgn = 1;
		if (i == 0 && s[i] == '-') sgn = -1;
		if (a.empty()) sgn = 0;
    }	
};
typedef BigInt<int> Num;
#define _GCJ_SOLVE \
void solve() { \
	init(); \
	$I(int, n); sgets(); \
	xfor(_seg(1, n), i, \
		printf("Case #%d: ", i); \
		solvecase(); \
		_wlf; \
		fflush(stdout); \
	); \
}
#define _END_SOL_CL \
int main(int argc, char **argv) { \
	if (argc == 2) { \
		freopen(argv[1], "r", stdin); \
		freopen((string(argv[1]) + ".out").c_str(), "w", stdout); \
	} else { \
		freopen("test.in", "r", stdin); \
		freopen("test.out", "w", stdout); \
	} \
	solve(); \
	return 0; \
}
_SOLUTION
