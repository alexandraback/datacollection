//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <ios>
#include <complex>
#include <iomanip>
#include <ctime>
#include <numeric>
#include <functional>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <bitset>
#include <cstdarg>
using namespace std;

inline int read() {
	static int r;
	static char c;
	r = 0, c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') r = r * 10 + (c - '0'), c = getchar();
	return r;
}

typedef long long ll;
#define pair(x, y) make_pair(x, y)
#define runtime() ((double)clock() / CLOCKS_PER_SEC)


static const unsigned base = 10000, length = 4;
static bool __enoughMemory = false;

typedef vector<int> vi;
typedef vector<int>::iterator viit;
typedef vector<int>::const_iterator vicit;
typedef vector<int>::reverse_iterator virit;
typedef vector<int>::const_reverse_iterator vicrit;
typedef complex<double> comp;
typedef vector<comp> vc;
typedef vector<comp>::iterator vcit;

class Bigint {
public :
    Bigint();
    template<typename _Tp> Bigint(_Tp);
    Bigint(const Bigint&);
    Bigint(const char*);
    Bigint(const string&);
    
    bool& neg();
    const bool& neg() const;
    vi& num();
    const vi& num() const;
    
    bool operator==(const Bigint&) const;
    bool operator!=(const Bigint&) const;
    bool operator<(const Bigint&) const;
    bool operator<=(const Bigint&) const;
    bool operator>(const Bigint&) const;
    bool operator>=(const Bigint&) const;
    
    Bigint& operator+=(const Bigint&);
    Bigint& operator-=(const Bigint&);
    Bigint& operator*=(const Bigint&);
    Bigint& operator/=(const Bigint&);
    Bigint& operator%=(const Bigint&);
    Bigint& operator<<=(const unsigned&);
    Bigint& operator>>=(const unsigned&);
    
    Bigint& operator++();
    Bigint& operator--();
    Bigint operator-() const;
    bool operator!() const;
    
    int compare(const Bigint&) const;
    bool equal(const Bigint&) const;
    bool less(const Bigint&) const;
    bool lessOrEqual(const Bigint&) const;
    bool greater(const Bigint&) const;
    bool greaterOrEqual(const Bigint&) const;
    
    Bigint& abs();
    Bigint& pow(unsigned);
    Bigint& root(const unsigned&);
    Bigint& sqrt();
    void multiply10(const unsigned&);
    void divide2();
    
    void add(const Bigint&);
    void subtract(const Bigint&);
    void multiply(const Bigint&);
    void multiplySlow(const Bigint&);
    void multiplyFast(const Bigint&, const int&, const int&);
    pair<vi, vi> divide(const Bigint&);
    
    Bigint& read(FILE*);
    const Bigint& write(FILE*) const;
    
private :
    bool _m_neg;
    vi _m_num;
    
    void adjust();
    comp exp(const double&);
    void bitrev(const vcit&, const int&, const int&, const int&, const int&);
    void fft(vc&, const int&, const int&, const bool&);
    
    void divideByZero();
    void imaginaryNumberUnsupported();
    void error(const string&);
};

//pre-declaration
Bigint abs(const Bigint&);
Bigint pow(const Bigint&, const unsigned&);
Bigint root(const Bigint&, const unsigned&);
Bigint sqrt(const Bigint&);
istream& operator>>(istream&, Bigint&);
ostream& operator<<(ostream&, const Bigint&);
void enoughMemory();

//operator
inline Bigint operator+(const Bigint& __x, const Bigint& __y) {
    return Bigint(__x) += __y;
}
inline Bigint operator-(const Bigint& __x, const Bigint& __y) {
    return Bigint(__x) -= __y;
}
inline Bigint operator*(const Bigint& __x, const Bigint& __y) {
    return Bigint(__x) *= __y;
}
inline Bigint operator/(const Bigint& __x, const Bigint& __y) {
    return Bigint(__x) /= __y;
}
inline Bigint operator%(const Bigint& __x, const Bigint& __y) {
    return Bigint(__x) %= __y;
}
template<typename _Tp> inline Bigint operator<<(const Bigint& __x, const _Tp& __y) {
    return Bigint(__x) <<= __y;
}
template<typename _Tp> inline Bigint operator>>(const Bigint& __x, const _Tp& __y) {
    return Bigint(__x) >>= __y;
}

//public

//constructor
inline Bigint::Bigint() {
    neg() = false;
    num().clear();
    num().push_back(0);
}
template<typename _Tp> inline Bigint::Bigint(_Tp __t) {
    if (__t < 0) neg() = true, __t = -__t;
    else neg() = false;
    num().clear();
    while (__t >= base) {
        num().push_back(__t % base);
        __t /= base;
    }
    num().push_back(__t);
}
inline Bigint::Bigint(const Bigint& __t) {
    *this = __t;
}
inline Bigint::Bigint(const char* __c) {
    while (*__c) {
        if (*__c == '-' || *__c == '+' || '0' <= *__c && *__c <= '9')
            break;
        ++__c;
    }
    if (*__c == '-') ++__c, neg() = true;
    else {
        neg() = false;
        if (*__c == '+') ++__c;
    }
    int __n = strlen(__c);
    num().clear();
    if (__n == 0) {
        neg() = false;
        num().push_back(0);
        return ;
    }
    const char* __t = __c + __n;
    while (__c + 1 != __t && *__c == '0') ++__c;
    int __x = 0, __y = 1, __z = 0;
    while (__t-- != __c) {
        if (__z == 4) {
            num().push_back(__x);
            __x = 0, __y = 1, __z = 0;
        }
        __x += (*__t - '0') * __y;
        __y = (__y << 3) + (__y << 1);
        ++__z;
    }
    num().push_back(__x);
}
inline Bigint::Bigint(const string& __s) {
    string::const_iterator i = __s.begin();
    string::const_iterator j = __s.end();
    while (i != j) {
        if (*i == '-' || *i == '+' || '0' <= *i && *i <= '9')
            break;
        ++i;
    }
    if (i != j) {
        if (*i == '-') ++i, neg() = true;
        else {
            neg() = false;
            if (*i == '+') ++i;
        }
    }
    int __n = j - i;
    if (__n == 0) {
        neg() = false;
        num().push_back(0);
        return ;
    }
    while (i + 1 != j && *i == '0') ++i;
    int __x = 0, __y = 1, __z = 0;
    while (j-- != i) {
        if (__z == 4) {
            num().push_back(__x);
            __x = 0, __y = 1, __z = 0;
        }
        __x += (*j - '0') * __y;
        __y = (__y << 3) + (__y << 1);
        ++__z;
    }
    num().push_back(__x);
}

inline bool& Bigint::neg() {
    return _m_neg;
}
inline const bool& Bigint::neg() const {
    return _m_neg;
}
inline vi& Bigint::num() {
    return _m_num;
}
inline const vi& Bigint::num() const {
    return _m_num;
}

//logical operator
inline bool Bigint::operator==(const Bigint& __t) const {
    return neg() == __t.neg() && equal(__t);
}
inline bool Bigint::operator!=(const Bigint& __t) const {
    return neg() != __t.neg() || !equal(__t);
}
inline bool Bigint::operator<(const Bigint& __t) const {
    if (neg() != __t.neg()) return neg();
    if (neg()) return greater(__t);
    return less(__t);
}
inline bool Bigint::operator<=(const Bigint& __t) const {
    if (neg() != __t.neg()) return neg();
    if (neg()) return greaterOrEqual(__t);
    return lessOrEqual(__t);
}
inline bool Bigint::operator>(const Bigint& __t) const {
    if (neg() != __t.neg()) return __t.neg();
    if (neg()) return less(__t);
    return greater(__t);
}
inline bool Bigint::operator>=(const Bigint& __t) const {
    if (neg() != __t.neg()) return __t.neg();
    if (neg()) return lessOrEqual(__t);
    return greaterOrEqual(__t);
}

//arithmetic operators
inline Bigint& Bigint::operator+=(const Bigint& __t) {
    if (neg() == __t.neg()) add(__t);
    else {
        int __x = compare(__t);
        if (__x == 0) *this = Bigint();
        else if (__x == -1) {
            Bigint __y = *this;
            *this = __t;
            subtract(__y);
        }
        else subtract(__t);
    }
    return *this;
}
inline Bigint& Bigint::operator-=(const Bigint& __t) {
    return *this += (-__t);
}
inline Bigint& Bigint::operator*=(const Bigint& __t) {
    if (*this != 0 && __t != 0) {
        neg() = neg() != __t.neg();
        multiply(__t);
    }
    else *this = Bigint();
    return *this;
}
inline Bigint& Bigint::operator/=(const Bigint& __t) {
    if (__t == 0) divideByZero();
    if (less(__t)) *this = Bigint();
    else {
        neg() = neg() != __t.neg();
        num() = divide(__t).first;
        adjust();
    }
    return *this;
}
inline Bigint& Bigint::operator%=(const Bigint& __t) {
    if (__t == 0) divideByZero();
    num() = divide(__t).second;
    adjust();
    if (num().size() == 1 && !*num().rbegin()) neg() = false;
    return *this;
}
inline Bigint& Bigint::operator<<=(const unsigned& __y) {
    return *this *= Bigint(2).pow(__y);
}
inline Bigint& Bigint::operator>>=(const unsigned& __y) {
    for (unsigned i = 0 ; i < __y ; ++i) divide2();
    return *this;
}

//self operator
inline Bigint& Bigint::operator++() {
    return *this += 1;
}
inline Bigint& Bigint::operator--() {
    return *this -= 1;
}
inline Bigint Bigint::operator-() const {
    Bigint __t = *this;
    if (__t != 0) __t.neg() ^= true;
    return __t;
}
inline bool Bigint::operator!() const {
    return *this == 0;
}

//comparator
inline int Bigint::compare(const Bigint& __t) const {
    if (num().size() < __t.num().size()) return -1;
    else if (num().size() > __t.num().size()) return 1;
    vicrit i = num().rbegin();
    vicrit j = __t.num().rbegin();
    while (i != num().rend()) {
        if (*i < *j) return -1;
        else if (*i > *j) return 1;
        ++i, ++j;
    }
    return 0;
}
inline bool Bigint::equal(const Bigint& __t) const {
    return compare(__t) == 0;
}
inline bool Bigint::less(const Bigint& __t) const {
    return compare(__t) == -1;
}
inline bool Bigint::lessOrEqual(const Bigint& __t) const {
    int __r = compare(__t);
    return __r == -1 || __r == 0;
}
inline bool Bigint::greater(const Bigint& __t) const {
    return compare(__t) == 1;
}
inline bool Bigint::greaterOrEqual(const Bigint& __t) const {
    int __r = compare(__t);
    return __r == 1 || __r == 0;
}

//math
inline Bigint& Bigint::abs() {
    if (neg()) neg() = false;
    return *this;
}
inline Bigint& Bigint::pow(unsigned __y) {
    Bigint __x = *this;
    *this = 1;
    while (__y) {
        if (__y & 1) *this *= __x;
        __x *= __x;
        __y >>= 1;
    }
    return *this;
}
inline Bigint& Bigint::root(const unsigned& __y = 2) {
    if (!__y) divideByZero();
    if (*this == 0 || __y == 1) return *this;
    bool __n = neg();
    if (__n)
        if (__y & 1) neg() = false;
        else imaginaryNumberUnsupported();
    const double log2_10 = 3.3219280948873623478703194294893901758648313930245806;
    size_t __s = num().size();
    if (double(__s << 2) * log2_10 < __y) return *this = 1;
    __s = __s / __y + (__s % __y ? 1 : 0);
    int __l, __r, __m;
    Bigint __a = *this, __b, __c;
    num().clear();
    for (int i = __s - 1 ; i >= 0 ; --i) {
        __l = 1, __r = base - 1;
        while (__l <= __r) {
            __m = __l + __r >> 1;
            __b = *this;
            __b.num().insert(__b.num().begin(), __m);
            __b.pow(__y);
            __b.multiply10(i * __y << 2);
            if (__b <= __a) __l = __m + 1;
            else __r = __m - 1;
        }
        num().insert(num().begin(), __r);
    }
    neg() = __n;
    return *this;
}
inline Bigint& Bigint::sqrt() {
    root();
    return *this;
}
inline void Bigint::multiply10(const unsigned& __t) {
    if (!__t) return ;
    size_t __s = num().size();
    size_t __r = (__t >> 2) + (__t & 3 ? 1 : 0);
    int __x = 0, __y, __z, __a, __b;
    if ((__t & 3) == 0) __a = 1, __b = 10000;
    else if ((__t & 3) == 1) __a = 1000, __b = 10;
    else if ((__t & 3) == 2) __a = 100, __b = 100;
    else if ((__t & 3) == 3) __a = 10, __b = 1000;
    num().resize(__s + __r);
    virit i = num().rbegin();
    virit j = i + __r;
    while (i != num().rbegin() + __s) {
        __y = *j++;
        __z = __y / __a;
        __x += __z;
        *i++ = __x;
        __x = (__y - __z * __a) * __b;
    }
    *i++ = __x;
    fill(i, num().rend(), 0);
    adjust();
}
inline void Bigint::divide2() {
    int __t = 0;
    for (virit i = num().rbegin() ; i != num().rend() ; ++i) {
        __t = (__t & 1 ? base : 0) + *i;
        *i = __t >> 1;
    }
    adjust();
}

//+, -, *, /
inline void Bigint::add(const Bigint& __t) {
    if (num().size() < __t.num().size())
        num().resize(__t.num().size());
    viit i = num().begin();
    vicit j = __t.num().begin();
    while (i != num().end() && j != __t.num().end())
        *i++ += *j++;
    for (i = num().begin() ; i + 1 != num().end() ; ++i)
        if (*i >= base) {
            *i -= base;
            ++*(i + 1);
        }
    if (*i >= base) {
        *i -= base;
        num().push_back(1);
    }
}
inline void Bigint::subtract(const Bigint& __t) {
    viit i = num().begin();
    vicit j = __t.num().begin();
    while (j != __t.num().end())
        *i++ -= *j++;
    for (i = num().begin() ; i + 1 != num().end() ; ++i)
        if (*i < 0) {
            *i += base;
            --*(i + 1);
        }
    adjust();
}
inline void Bigint::multiply(const Bigint& __t) {
    int __n = max(num().size(), __t.num().size());
    int __l = 0;
    while ((1 << __l) < __n) ++__l;
    __n = 1 << ++__l;
    if ((long long)num().size() * __t.num().size() <= (long long)__n * __l * 20)
        multiplySlow(__t);
    else
        multiplyFast(__t, __n, __l);
    adjust();
}
inline void Bigint::multiplySlow(const Bigint& __t) {
    int __n = num().size() + __t.num().size(), i, j, k;
    vi __x, __y;
    if (__t.num().size() * 4 < num().size())
        __x = __t.num(), __y = num();
    else
        __x = num(), __y = __t.num();
    num().clear();
    num().resize(__n);
    for (i = 0 ; i < __x.size() ; ++i) {
        k = __x[i];
        for (j = 0 ; j < __y.size() ; ++j)
            num()[i + j] += k * __y[j];
        k = i + 1 + __y.size();
        for (j = 0 ; j < k ; ++j) {
            num()[j + 1] += num()[j] / base;
            num()[j] %= base;
        }
    }
}
inline void Bigint::multiplyFast(const Bigint& __t, const int& __n, const int& __l) {
    vc a, b;
    a.reserve(__n);
    b.reserve(__n);
    for (viit i = num().begin() ; i != num().end() ; ++i)
        a.push_back(comp(*i, 0));
    for (vicit i = __t.num().begin() ; i != __t.num().end() ; ++i)
        b.push_back(comp(*i, 0));
    a.resize(__n);
    b.resize(__n);
    fft(a, __l, __n, true);
    fft(b, __l, __n, true);
    vcit i = a.begin(), j = b.begin();
    while (i != a.end()) *i++ *= *j++;
    fft(a, __l, __n, false);
    long long __x = 0;
    num().resize(__n);
    i = a.begin();
    viit k = num().begin();
    while (i != a.end()) {
        __x = (long long)(i++ ->real() / __n + 0.5) + __x / base;
        *k++ = __x % base;
    }
}
inline pair<vi, vi> Bigint::divide(const Bigint& __t) {
    int __l, __r, __m, __n = num().size() - __t.num().size() + 1;
    Bigint __x = *this, __y = __t, __z;
    vi __v;
    __v.resize(__n);
    if (__enoughMemory) {
        Bigint __p[10];
        for (__m = 0 ; __m < 10 ; ++__m) __p[__m] = __m * __y;
        for (int i = __n - 1 ; i >= 0 ; --i) {
            int k = 0;
            for (int j = 3 + (i << 2) ; j >= (i << 2) ; --j) {
                __l = 1, __r = 9;
                while (__l <= __r) {
                    __m = __l + __r >> 1;
                    __z = __p[__m];
                    __z.multiply10(j);
                    if (__z.greater(__x)) __r = __m - 1;
                    else __l = __m + 1;
                }
                k = (k << 3) + (k << 1) + __r;
                __z = __p[__r];
                __z.multiply10(j);
                __x.subtract(__z);
            }
            __v[i] = k;
        }
    }
    else {
        for (int i = __n - 1 ; i >= 0 ; --i) {
            __l = 1, __r = base - 1;
            while (__l <= __r) {
                __m = __l + __r >> 1;
                __z = __m * __y;
                __z.multiply10(i << 2);
                if (__z.greater(__x)) __r = __m - 1;
                else __l = __m + 1;
            }
            __v[i] = __r;
            __z = __r * __y;
            __z.multiply10(i << 2);
            __x.subtract(__z);
        }
    }
    return make_pair(__v, __x.num());
}

//io
inline Bigint& Bigint::read(FILE *in = stdin) {
    string __s = "";
    char __c = fgetc(in);
    while (true) {
        if (__c == '-' || __c == '+' || '0' <= __c && __c <= '9' || __c == EOF)
            break;
        __c = fgetc(in);
    }
    while (true) {
        __s += __c;
        __c = fgetc(in);
        if (__c < '0' || __c > '9') break;
    }
    return *this = Bigint(__s.c_str());
}
inline const Bigint& Bigint::write(FILE *out = stdout) const {
    vicrit i = num().rbegin();
    if (neg()) fprintf(out, "-");
    fprintf(out, "%d", *i++);
    while (i != num().rend()) fprintf(out, "%04d", *i++);
    return *this;
}

//private

//other
inline void Bigint::adjust() {
    virit i = num().rbegin();
    while (i + 1 != num().rend()) {
        if (*i) break;
        ++i;
    }
    num().erase(i.base(), num().end());
}
inline comp Bigint::exp(const double& u) {
    return comp(cos(u), sin(u));
}
inline void Bigint::bitrev(const vcit& i, const int& __l, const int& __p, const int& __x, const int& __y) {
    if (__p == 0) {
        if (__x < __y) swap(*(i + __x), *(i + __y));
        return ;
    }
    bitrev(i, __l, __p - 1, __x << 1, __y);
    bitrev(i, __l, __p - 1, __x << 1 | 1, __y | (1 << __l - __p));
}
inline void Bigint::fft(vc& __a, const int& __l, const int& __n, const bool& __r) {
    const double __p = 3.141592653589793238462643383279;
    bitrev(__a.begin(), __l, __l, 0, 0);
    for (int i = 1 ; i <= __l ; ++i) {
        int __m = 1 << i;
        comp wm = exp((__r ? -2 : 2) * __p / __m);
        for (int k = 0 ; k < __n ; k += __m) {
            comp w = 1;
            for (int j = 0 ; j < __m / 2 ; ++j) {
                comp t = w * __a[k + j + __m / 2];
                comp u = __a[k + j];
                __a[k + j] = u + t;
                __a[k + j + __m / 2] = u - t;
                w *= wm;
            }
        }
    }
}

//error
inline void Bigint::divideByZero() {
    error("divide by zero");
}
inline void Bigint::imaginaryNumberUnsupported() {
    error("imaginary number unsupported");
}
inline void Bigint::error(const string& __s) {
    fprintf(stderr, "%s\n", __s.c_str());
    cerr << __s << endl;
    abort();
}

//math
inline Bigint abs(const Bigint& __x) {
    return Bigint(__x).abs();
}
inline Bigint pow(const Bigint& __x, const unsigned& __y) {
    return Bigint(__x).pow(__y);
}
inline Bigint root(const Bigint& __x, const unsigned& __y = 2) {
    return Bigint(__x).root(__y);
}
inline Bigint sqrt(const Bigint& __x) {
    return Bigint(__x).sqrt();
}

//io
inline istream& operator>>(istream& __s, Bigint& __t) {
    string __r;
    __s >> __r;
    __t = Bigint(__r);
    return __s;
}
inline ostream& operator<<(ostream& __s, const Bigint& __t) {
    if (__t.neg()) __s << '-';
    vicrit i = __t.num().rbegin();
    __s << *i;
    while (++i != __t.num().rend()) {
        __s.width(length);
        __s.fill('0');
        __s << *i;
    }
    return __s;
}

//optimization
inline void enoughMemory() {
    __enoughMemory = true;
}


int T, tc = 0;
ll R, t;

Bigint calc(Bigint x) {
	Bigint ret = 0;
	ret += 2 * Bigint(R) * x;
	ret += 2 * (x + 1) * x;
	ret -= 3 * x;
	return ret;
}

int main() {
#ifdef KANARI
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	cin >> T;
	while (T--) {
		cin >> R >> t;
		ll l = 1LL, r = t;
		while (l < r) {
			ll mid = l + r + 1 >> 1;
			if (calc(Bigint(mid)) > t) r = mid - 1;
			else l = mid;
		}
		ll x = l;
		/*
		ll u = -(2 * r - 1) + floor(sqrt(4.0 * (double)r * r - 4.0 * (double)r + 1 + 8.0 * (double)t));
		ll x = floor(u) / 4;
		*/
		cout << "Case #" << ++tc << ": " << x << endl;
		//cout << 2 * r * x + 2 * (1 + x) * x - 3 * x << endl;
	}
	
	return 0;
}

