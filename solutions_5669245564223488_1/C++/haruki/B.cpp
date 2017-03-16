
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <cmath>

using namespace std;

using lli = long long int ;
template <class T> T get() { T x ; cin >> x ; return x ; }
template <class T> lli size(T const& c) { return c.size() ; }
#define rep0(i,n) for (lli i = 0; i < lli(n); ++i)
#define rep1(i,n) for (lli i = 1; i <= lli(n); ++i)
#define rep rep0
#define fromto(i,a,b) for (lli i = a; i <= lli(b); ++i)
#define show(x) #x " = " << x
#define all(c) (c).begin(), (c).end()
#define print(e) cout << e << endl ;
// mod
template <unsigned int m> // ëfêîÇ™ñ]Ç‹ÇµÇ¢
class mod {
    long long x ;
public:
    mod() : x(0) { }
    mod(long long x) : x((x % m + m) % m) { }
    long long value() const { return x ; }
    bool operator==(mod<m> rhs) const { return x == rhs.x ; }
    bool operator!=(mod<m> rhs) const { return x != rhs.x ; }
    mod<m> operator+() { return *this ; }
    mod<m> operator-() { return -x ; }
    mod<m>& operator+=(mod<m> rhs) { (x += rhs.x) %= m ;return *this ; }
    mod<m>& operator-=(mod<m> rhs) { (x += m - rhs.x) %= m ; return *this ; }
    mod<m>& operator*=(mod<m> rhs) { (x *= rhs.x) %= m; return *this ; }
    mod<m> operator+(mod<m> rhs) const { mod<m> t = *this ; t += rhs ; return t ; }
    mod<m> operator-(mod<m> rhs) const { mod<m> t = *this ; t -= rhs ; return t ; }
    mod<m> operator*(mod<m> rhs) const { mod<m> t = *this ; t *= rhs ; return t ; }
} ;

template <unsigned int m>
ostream& operator<<(ostream& os, mod<m> rhs) {
    return os << rhs.value() ;
}

const int M = 1e9 + 7;

mod<M> factor[101];

int main() {
    factor[0] = 1;
    rep (i,100) factor[i+1] = factor[i]*mod<M>(i+1);
    
    int T;
    cin >> T;
    rep (test,T) {
        cout << "Case #" << test+1 << ": ";
        int N; cin >> N;
        list<string> v;
        rep (_,N) v.push_back(get<string>());
        mod<M> ans = 1;
        for (char c = 'a'; c <= 'z'; c++) {
            auto x = v.end(), y = v.end(), z = v.end();
            vector<list<string>::iterator> wits;
            for (auto it = v.begin(); it != v.end(); it++) {
                auto const& s = *it;
                auto b = s.find(c);
                if (b == string::npos) continue;
                auto e = b;
                while (s[++e] == c) ;
                auto r = s.find(c, e);
                if (r != string::npos) goto impossible;
                if (b == 0 && e != s.size()) {
                    if (x != v.end()) goto impossible;
                    x = it;
                } else if (b != 0 && e != s.size()) {
                    if (y != v.end()) goto impossible;
                    y = it;
                } else if (b != 0 && e == s.size()) {
                    if (z != v.end()) goto impossible;
                    z = it;
                } else {
                    wits.push_back(it);
                }
            }
            if (y != v.end()) {
                if (x != v.end() || z != v.end() || !wits.empty()) goto impossible;
            } else {
                ans *= factor[wits.size()];
                if (!wits.empty())  {
                    if (x != v.end() || z != v.end()) {
                        for (auto const& it : wits) v.erase(it);
                    } else {
                        rep (i,wits.size()-1) v.erase(wits[i]);
                    }
                }
                if (x != v.end() && z != v.end()) {
                    *z += *x;
                    v.erase(x);
                }
            }
        }
        ans *= factor[v.size()];
        cout << ans << endl;
        continue;
    impossible:
        cout << 0 << endl;
    }
}
