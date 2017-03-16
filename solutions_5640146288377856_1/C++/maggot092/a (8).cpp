#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

#define hmap unordered_map
#define hset unordered_set
#define ll long long
#define mkveci mkvec<int>
#define vpri vpr<int>
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define ford(i, n) for (int i = (n) - 1; i >= 0; --i)

using std::sort;
using std::vector;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::cin;
using std::cout;
using std::endl;


template <class T>
inline T gcd_impl(T a, T b) {
    T buf;
    // a >= b, a >= 0, b >= 0
    while (b) {
        buf = a % b;
        a = b;
        b = buf;
    }
    return a;
}

template <class T>
T gcd(T a, T b) {
    if (a < 0) {
        a *= -1;
    }
    if (b < 0) {
        b *= -1;
    }
    if (a < b) {
        return gcd_impl(b, a);
    }
    return gcd_impl(a, b);
}

template <class T>
struct rational {
    T p;
    T q;
    rational(T a = 0, T b = 1)
        : p(a)
        , q(b) {
        normalize();
    }
    rational& operator = (rational other) {
        p = other.p;
        q = other.q;
        return *this;
    }
    rational& operator = (T a) {
        p = a;
        q = 1;
        return *this;
    }
    void normalize() {
        if (q < 0) {
            q *= -1;
            p *= -1;
        }
        T d = gcd(p, q);
        p /= d;
        q /= d;
    }
    rational operator * (rational other) const {
        rational result;
        result.p = p * other.p;
        result.q = q * other.q;
        result.normalize();
        return result;
    }
    rational operator / (rational other) const {
        T buf = other.p;
        other.p = other.q;
        other.q = buf;
        return *this * other;
    }
    rational operator + (rational other) const {
        rational res;
        res.p = p * other.q + q * other.p;
        res.q = q * other.q;
        res.normalize();
        return res;
    }
    rational operator - (rational other) const {
        other.p *= -1;
        return *this + other;
    }
    bool operator == (rational other) const {
        return p == other.p && q == other.q;
    }
    bool operator != (rational other) const {
        return !(*this == other);
    }
    bool operator < (rational other) const {
        rational diff = *this - other;
        return diff.p < 0;
    }
    bool operator <= (rational other) const {
        rational diff = *this - other;
        return diff.p <= 0;
    }
    bool operator > (rational other) const {
        rational diff = *this - other;
        return diff.p > 0;
    }
    bool operator >= (rational other) const {
        rational diff = *this - other;
        return diff.p >= 0;
    }
};


template<class T>
std::istream& operator >> (std::istream& in, vector<T>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        in >> v[i];
    }
    return in;
}

template<class T>
std::ostream& operator << (std::ostream& out, const vector<T>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        out << v[i];
    }
    return out;
}

template<class T>
vector<T> mkvec(int n) {
    return vector<T>(n);
}

template<class T>
vector<vector<T> > mkvec(int n, int m) {
    return vector<vector<T> >(n, vector<T>(m));
}

template<class T>
vector<vector<vector<T> > > mkvec(int n, int m, int k) {
    return vector<vector<vector<T> > >(n, vector<vector<T> >(m, vector<T>(k)));
}

template<class T>
class vpr {
  public:
    vpr(const vector<T>& v, const string& sep)
        : vec1(v)
        , sep1(sep) {
    }

    const vector<T>& vec1;
    const string& sep1;

};

template<class T>
std::ostream& operator << (std::ostream& out, const vpr<T>& pr) {
    for (int i = 0; i < pr.vec1.size(); ++i) {
        if (i > 0) {
            out << pr.sep1;
        }
        out << pr.vec1[i];
    }
    return out;
}

void solve();

void runTests() {
    int t;
    cin >> t;
    forn(i, t) {
        cout << "Case #" << i + 1 << ": ";
        solve();
        cout << endl;
    }
}

void solve() {
    int r, c, w;
    cin >> r >> c >> w;
    int ans = r * ((c) / w);
    ans += w;
    if (c % w == 0) ans--;
    cout << ans; 
}

int main() {
    runTests();
    //solve();
    return 0;
}
