#define _SOLUTION                                           \
                                                            \
                                                            \
vector<int> nums;                                           \
                                                            \
bool is_pal(LL x)                                           \
{                                                           \
    seqvec(a, _rdigits(x));                                 \
    return _seqeq(a, _rev(a));                              \
}                                                           \
                                                            \
void init()                                                 \
{                                                           \
    _fors(i, 1, 10000000) if (_sum(_rdigits(i)) <= 9)       \
        if (is_pal(i) && is_pal(sqr(i))) nums.push_back(i); \
}                                                           \
                                                            \
void solvecase()                                            \
{                                                           \
    $I2(LL, a, b);                                          \
    $$ t = _filter(sqr(_) >= a && sqr(_) <= b, nums);       \
    _w(xlen(t));                                            \
}                                                           \
                                                            \
_GCJ_SOLVE                                                  \
_END_SOL_CL                                                 \
                                                            \
///////////////////////////////////////////////////////////// 
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
#define ITER_SIZE inline int size(int mx = numeric_limits<int>::max()) const { return _count(_take(mx, *this)); }
#define SEQ_TYPE(x) const x
#define FUNC2(x,y) x##y
#define FUNC1(x,y) FUNC2(x,y)
#define FUNC(x) FUNC1(x,__COUNTER__)
#define STRUCT_NAME FUNC(struct_)
typedef long long LL;
struct _DummyType {};
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
#define _wsp printf(" ")
#define _wlf printf("\n")
#define _wstr(s) printf("%s", s)
#define cmp_a(a) this->a < other.a
#define cmp_aa(a, b) cmp_a(a) || (this->a == other.a && this->b < other.b)
template<typename T>
struct strict_item_type { typedef typename T::value_type type; };
template<typename T>
struct strict_item_type<T*> { typedef T type; };
template<typename T, size_t sz>
struct strict_item_type<T[sz]> { typedef T type; };
template<typename T, size_t sz>
struct strict_item_type<T(&)[sz]> { typedef T type; };
template<typename T>
struct strict_item_type<T*&> { typedef T type; };
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
template<typename IterableType>
struct citerator
{
	typedef typename IterableType::value_type value_type;
	static inline value_type resolve(const IterableType &a, typename IterableType::iterator it)
		{ return a.resolve_iterator(it); }
	static inline value_type& xresolve(IterableType &a, typename IterableType::iterator it)
		{ return a.resolve_iterator(it); }
};
template<typename T>
struct citerator<vector<T> >
{
	static inline const T& resolve(const vector<T> &a, typename vector<T>::const_iterator it)
		{ return *it; }
};
template<typename T> struct _IsIterable<vector<T> > { enum { value = 1 }; };
template<>
struct citerator<string>
{
	static inline char resolve(const string &a, gcc_typename string::const_iterator it)
		{ return *it; }
};
template<> struct _IsIterable<string> { enum { value = 1 }; };
template<typename T>
struct citerator<set<T> >
{
	static inline const T& resolve(const set<T> &a, typename set<T>::const_iterator it)
		{ return *it; }
};
template<typename T> struct _IsIterable<set<T> > { enum { value = 1 }; };
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
#define xbreak return false
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
struct tup0 {
	inline void _read(int i) {}
	inline void __write() const { _wstr("("); }
	inline void _write() const { __write(); _wstr(")"); }
	template<typename T> inline bool operator == (const T &other) const { return true; }
};
template<typename T>
struct _is_empty { enum { value = 0 }; };
template<>
struct _is_empty<tup0> { enum { value = 1 }; };
#define extend_fieldr(name, base, type, field_name) \
	struct name : public base \
	{ \
		type field_name; \
		typedef type field_name##_type; \
		name() {} \
		inline void __write() const { base::__write(); if (!_is_empty<base>::value) _wsp; \
			_wstr(#field_name ":"); _io<type>::write(field_name); } \
		inline void _write() const { __write(); _wstr(")"); } \
		inline void _read(int i) { base::_read(i); _io<type>::read(field_name, i); } \
		inline bool operator == (const name &other) const { \
			return base::operator == (*(const base*)&other) && field_name == other.field_name; \
		}
#define _end_extend }
#define _CMP_(name, cmp) bool operator < (const name &other) const { return cmp; }
#define tup1(name, t1, name1) tup1c(name, t1, name1, false)
#define tup1c(name, t1, name1, cmp) \
	extend_fieldr(name, tup0, t1, name1) \
		name(t1 name1) : name1(name1) {} \
		_CMP_(name, cmp) \
	_end_extend
#define tup2c(name, t1, name1, t2, name2, cmp) tup2c_(STRUCT_NAME, name, t1, name1, t2, name2, cmp)
#define tup2c_(bname, name, t1, name1, t2, name2, cmp) \
	tup1(bname, t1, name1); \
	extend_fieldr(name, bname, t2, name2) \
		name(t1 name1, t2 name2) : bname(name1), name2(name2) {} \
		_CMP_(name, cmp) \
	_end_extend
#define seqvec(name, a) \
	const auto &name##_tmp = a; \
	vector<gcc_typename ValueType<decltype(name##_tmp)>::type> name; \
	populate(name, name##_tmp)
#define _fors(i, s, n) for (int i = s; i < n; i++)
template<typename T, typename F> 
typename T::value_type Fold(const T &a, F f, const typename T::value_type &init_val)
{
	typename T::value_type res = init_val;
	xforeach(a, i, res = f(res, i));
	return res;
}
template<typename T>
struct SumFtr
{
	typedef T res_type;
	inline T operator () (const T &a, const T &b) const { return a + b; }
};
template<typename T>
struct _sum_neutral
{
	static T value() { return T(0); }
};
template<typename T>
typename T::value_type _sum(const T &a)
{
	typedef typename T::value_type X;
	return Fold(a, SumFtr<X>(), _sum_neutral<X>::value());
}
#define $$ auto
template<typename T>
struct xlen_
{
	static int size(const T &a, int mx) { return a.size(mx); }
};
template<>
struct xlen_<string>
{
	static int size(const string &s, int mx) { return (int)s.size(); }
};
template<typename T>
struct xlen_<vector<T> >
{
	static int size(const vector<T> &v, int mx) { return (int)v.size(); }
};
template<typename T>
struct xlen_<set<T> >
{
    static int size(const set<T> &s, int mx) { return (int)s.size(); }
};
template<typename T, typename S>
struct xlen_<map<T, S> >
{
    static int size(const map<S, T> &m, int mx) { return (int)m.size(); }
};
template<typename T>
int xlen(const T &a, int mx = numeric_limits<int>::max()) { return xlen_<T>::size(a, mx); }
template<typename T>
struct RevWrapper
{
    T &a;
    int n;
    typedef typename strict_item_type<T>::type value_type;
    RevWrapper(T &a) : a(a) { n = a.size(); }
    inline int size(int mx = numeric_limits<int>::max()) const { return n; }
	inline value_type& operator [] (int i) { return a[n-i-1]; }
	inline value_type operator [] (int i) const { return a[n-i-1]; }
	template<typename F>
    void process(F f) const { for (int i = n-1; i >= 0; i--) if (!f(a[i])) return; }
	ITER_WRITE
};
template<typename T> inline
	RevWrapper<T> _rev(T &a) { return RevWrapper<T>(a); }
template<typename T1, typename T2>
struct _pair
{
    tup2c(type, T1, f, T2, s, cmp_aa(f, s));
};
template<
	typename T, 
	typename Filter  
>
struct FilterWrapper
{
	SEQ_TYPE(T) a;
	Filter filter;
	FilterWrapper(const T &a, Filter filter) : a(a), filter(filter) {}
	typedef typename T::value_type value_type;
	template<typename F>
	inline void process(F f) const
	{
		xforeach(a, x, 
			if (filter(x))
				if (!f(x)) xbreak
		)
	}
	ITER_SIZE
	ITER_WRITE
    typedef FilterWrapper<T, Filter> self_type;
    struct iterator
    {
        typedef typename T::iterator it_type;
        it_type it;
        const self_type &owner;
        iterator(const it_type &it, const self_type &owner) : it(it), owner(owner) {}
        void adjust() { while (it != owner.a.end() && !owner.filter(citerator<T>::resolve(owner.a, it))) ++it; }
		inline bool operator != (const iterator &other) const { return it != other.it; } 
		inline iterator& operator ++ () { ++it; adjust(); return *this; }
        value_type get_value() const { return citerator<T>::resolve(owner.a, it); }
    };
    iterator begin() const { iterator it(a.begin(), *this); it.adjust(); return it; }
    iterator end() const { return iterator(a.end(), *this); }
    value_type resolve_iterator(const iterator &it) const { return it.get_value(); }
};
template<typename A, typename B> struct _IsIterable<FilterWrapper<A, B> > { enum { value = 1 }; };
template<typename T, typename Filter>
inline FilterWrapper<T, Filter> CreateFilterWrapper(const T &t, Filter f)
{
	return FilterWrapper<T, Filter>(t, f);
}
#define _filter(cond, a) \
	CreateFilterWrapper(a, [&](const gcc_typename ValueType<decltype(a)>::type &_) -> bool { return cond; })
template<
    typename T 
>
struct TakeWrapper
{
    SEQ_TYPE(T) a;
    int cnt;
    TakeWrapper(int cnt, const T &a) : cnt(cnt), a(a) { assert(cnt >= 0); }
    typedef typename T::value_type value_type;
    template<typename F>
    inline void process(F f) const
    {
		if (cnt <= 0) return;
        int i = 0;
        xforeach(a, x,
            if (!f(x)) xbreak;
			++i;
			if (i >= cnt) xbreak;
        )
    }
    inline int size(int mx = numeric_limits<int>::max()) const { return min(cnt, (int)a.size(min(cnt, mx))); }
	value_type operator [] (int i) const { assert(i < cnt); return a[i]; }
    typedef _DummyType iterator;
	ITER_WRITE
};
template<typename T>
inline TakeWrapper<T> _take(int cnt, const T &a)
{
    return TakeWrapper<T>(cnt, a);
}
template<
    typename T, 
    typename F 
>
struct TakeWhileWrapper
{
    SEQ_TYPE(T) a;
    F f;
    TakeWhileWrapper(F f, const T &a) : a(a), f(f) {}
    typedef typename T::value_type value_type;
    typedef _DummyType iterator; 
    template<typename Ftr>
    inline void process(Ftr ftr) const
    {
        xforeach(a, x,
            if (!f(x)) xbreak;
            if (!ftr(x)) xbreak;
        );
    }
    ITER_SIZE
	ITER_WRITE
};
template<typename T, typename F>
TakeWhileWrapper<T, F> create_take_while(F f, const T &a)
{
    return TakeWhileWrapper<T, F>(f, a);
}
#define _takewhile(f, a) \
    create_take_while([&](const gcc_typename ValueType<decltype(a)>::type &_) -> bool { return f; }, a)
template<typename T1, typename T2>
struct ZipWrapper
{
    typedef typename _pair<typename T1::value_type, typename T2::value_type>::type value_type;
    typedef _DummyType iterator;
    SEQ_TYPE(T1) a;
    SEQ_TYPE(T2) b;
    ZipWrapper(const T1 &a, const T2 &b) : a(a), b(b) {}
    template<typename F>
    void process(F f) const
    {
        auto it = a.begin();
        typedef value_type f_type; 
        xforeach(b, x,
            if (it == a.end()) xbreak;
            if (!f(f_type(citerator<T1>::resolve(a, it), x))) xbreak;
            ++it;
        );
    }
	value_type operator [] (int i) const { return value_type(a[i], b[i]); }
    ITER_SIZE
	ITER_WRITE
};
template<typename T1, typename T2>
ZipWrapper<T1, T2> _zip(const T1 &a, const T2 &b) 
{
    return ZipWrapper<T1, T2>(a, b);
}
template<
	typename ListType, 
	typename SeqType 
>
void populate(ListType &lst, const SeqType &seq)
{
	xforeach(seq, x, lst.push_back(x));
}
template<typename T>
inline int _count(const T &a)
{
    int res = 0;
    xforeach(a, i, ++res);
    return res;
}
template<typename T1, typename T2>
int _commonpreflen(const T1 &a, const T2 &b)
{
	return _takewhile(_.f == _.s, _zip(a, b)).size();
}
template<typename T>
struct TrivialEnsurer
{
	T operator () (const T &a) const { return a; }
};
template<typename T>
struct VectorEnsurer
{
	typedef typename T::value_type S;
	vector<S> operator () (const T &a) const { seqvec(v, a); return v; }
};
template<typename T>
struct _EnsuredIterable
{
	typedef typename conditional<_IsIterable<T>::value, T, vector<typename T::value_type> >::type type;
	typedef typename conditional<_IsIterable<T>::value, TrivialEnsurer<T>, VectorEnsurer<T> >::type ensurer;
};
template<typename T>
typename _EnsuredIterable<T>::type _ensure_iterable(const T &a)
{
	return typename _EnsuredIterable<T>::ensurer()(a);
}
template<typename T1, typename T2>
bool _seqeq(const T1 &a, const T2 &b)
{
	int n1 = a.size(), n2 = b.size();
	if (n1 != n2) return false;
	$$ a_ = _ensure_iterable(a);
	return _commonpreflen(a_, b) == n1;
}
template<typename T>
struct mul_op
{
	typedef T type;
	inline static type Do(const T &a, const T &b) { return a * b; }
};
template<>
struct mul_op<int>
{
	typedef long long type;
	inline static type Do(int a, int b) { return (long long)a * b; }
};
template<typename T>
inline typename mul_op<T>::type sqr(const T &a)
{
    return mul_op<T>::Do(a, a);
}
template<typename T>
struct RDigitsWrapper
{
    const T a;
	const bool ret_zero;
	const int base;
	RDigitsWrapper(const T &a, bool ret_zero, int base) : 
		a(a), ret_zero(ret_zero), base(base) { assert(a >= 0); assert(base >= 2); }
    typedef int value_type;
    template<typename F>
    inline void process(F f) const
    {
		if (a == 0) { if (ret_zero) f(0); return; }
		T x = a;
		while (x > 0)
		{
			if (!f(x % base)) break;
			x = x / base;
		}
    }
	ITER_SIZE
	typedef _DummyType iterator;
	ITER_WRITE
};
template<typename T> inline
RDigitsWrapper<T> _rdigits(const T &a, bool ret_zero = false, int base = 10)
{
	return RDigitsWrapper<T>(a, ret_zero, base);
}
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
