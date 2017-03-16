/* string coder = "Balajiganapathi"; */

//#define LOCAL
#ifdef LOCAL
#   define TRACE
#else
//#   define NDEBUG
#endif

#include<bits/stdc++.h>

using namespace std;

/* aliases */
using vi  = vector<int>;
using pi  = pair<int, int>;
using vs  = vector<string>;
using vpi = vector<pi>;
using ll  = long long int;
using ull  = unsigned long long int;

/* shortcut macros */
#define mp              make_pair
#define fi              first
#define se              second
#define mt              make_tuple
#define gt(t, i)        get<i>(t)
#define all(x)          (x).begin(), (x).end()
#define ini(a, v)       memset(a, v, sizeof(a))
#define re(i, s, n)     for(auto i = s, _##i = (n); i < _##i; ++i)
#define rep(i, s, n)    re(i, s, (n) + 1)
#define fo(i, n)        re(i, 0, n)
#define si(x)           (int)(x.size())
#define pu              push_back
#define is1(mask,i)     ((mask >> i) & 1)

/* trace macro */
#ifdef TRACE
#   define trace(v...)  {cerr << __func__ << ":" << __LINE__ << ": " ;_dt(#v, v);}
#else
#   define trace(...)
#endif

#ifdef TRACE
pi _gp(string s) {
    pi r(0, si(s) - 1);
    int p = 0, s1 = 0, s2 = 0, start = 1;
    fo(i, si(s)) {
        int x = (s1 | s2);
        if(s[i] == ' ' && start) {
            ++r.fi;
        } else {
            start = 0;
            if(s[i] == ',' && !p && !x) {
                r.se = i - 1;
                return r;
            }
            if(x && s[i] == '\\') ++i;
            else if(!x && s[i] == '(') ++p;
            else if(!x && s[i] == ')') --p;
            else if(!s2 && s[i] == '\'') s1 ^= 1;
            else if(!s1 && s[i] == '"') s2 ^= 1;
        }
    }
    return r;
}

template<typename H> void _dt(string u, H&& v) {
    pi p = _gp(u);
    cerr << u.substr(p.fi, p.se - p.fi + 1) << " = " << forward<H>(v) << " |" << endl;
}

template<typename H, typename ...T> void _dt(string u, H&& v, T&&... r) {
    pi p = _gp(u);
    cerr << u.substr(p.fi, p.se - p.fi + 1) << " = " << forward<H>(v) << " | ";
    _dt(u.substr(p.se + 2), forward<T>(r)...);
}

template<typename T> 
ostream &operator <<(ostream &o, vector<T> v) { // print a vector
    o << "{";
    fo(i, si(v) - 1) o << v[i] << ", ";
    if(si(v)) o << v.back();
    o << "}";
    return o;
}

template<typename T1, typename T2> 
ostream &operator <<(ostream &o, map<T1, T2> m) { // print a map
    o << "[";
    for(auto &p: m) {
        o << " (" << p.fi << " -> " << p.se << ")";
    }
    o << " ]";
    return o;
}

template <size_t n, typename... T>
typename enable_if<(n >= sizeof...(T))>::type
    print_tuple(ostream&, const tuple<T...>&) {} 

template <size_t n, typename... T>
typename enable_if<(n < sizeof...(T))>::type
    print_tuple(ostream& os, const tuple<T...>& tup) {
    if (n != 0)
        os << ", ";
    os << get<n>(tup);
    print_tuple<n+1>(os, tup);
}

template <typename... T>
ostream& operator<<(ostream& os, const tuple<T...>& tup) { // print a tuple
    os << "(";
    print_tuple<0>(os, tup);
    return os << ")";
}

template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) { // print a pair
    return os << "(" << p.fi << ", " << p.se << ")";
}
#endif
    
/* util functions */

template<typename T>
string tostr(T x) {
    ostringstream oss;
    oss << x;
    return oss.str();
}

template<typename T1, typename T2, typename T3>
T1 modpow(T1 a, T2 p, T3 mod) {
    T1 ret = 1;

    a %= mod;
    for(; p > 0; p /= 2) {
        if(p & 1) ret = 1ll * ret * a % mod;
        a = 1ll * a * a % mod;
    }

    return ret;
}

#define x1 _asdfzx1
#define y1 _ysfdzy1

int dx[] {-1, 0, 1, 0, 1, 1, -1, -1};
int dy[] {0, -1, 0, 1, 1, -1, 1, -1};

/* constants */
constexpr auto PI  = 3.14159265358979323846L;
constexpr auto oo  = numeric_limits<int>::max() / 2 - 10;
constexpr auto eps = 1e-6;
constexpr auto mod = 1000000007;

/* code */
int miller_a[] =  {2, 325, 9375, 28178, 450775, 9780504, 1795265022};


/* this function calculates (a*b)%c taking into account that a*b might overflow */
inline ull mulmod(ull a, ull b, ull c){
    ull x = 0;
    while(b > 0){
        if(b & 1){
            x += a; if(x >= c) x -= c;
        }
        a += a; if(a >= c) a -= c;
        b >>= 1;
    }
    return x;
}

/* This function calculates (a^b)%c */
ull modulo(ull a, ull b,ull c){
    ull x = 1;
    while(b > 0) {
        if(b & 1) x = mulmod(x, a, c);
        a = mulmod(a, a, c); // squaring the base
        b >>= 1;
    }
    return x;
}

bool Miller(ull p){
    //cerr << p << endl;
    if(p < 2) return false;
    if(p % 2 == 0) return p == 2;
    
    ull s = p - 1, mod, temp;
    while((s & 1) == 0) s >>= 1;
    
    for(int i = 6; i >= 0; --i) if(miller_a[i] < p) {
        temp = s;
        mod = modulo(miller_a[i], temp, p);
        while(temp != p - 1 && mod != 1 && mod != p - 1) {
            mod = mulmod(mod, mod, p);
            temp <<= 1;
        }
        //cerr << i << endl;
        if(mod != p - 1 && (temp & 1) == 0) return false;
    }
    return true;
}

class Solution {
    public:
    vi num;
    vi factors;
    Solution(vi n, vi f) {
        num = n; factors = f;
    }
};

vector<Solution> ret;
vi cur;
unordered_set<ll> seen;
#define divides afsdfasdfsdsdadfsd

bool divides(int b, int x) {
    ll rem = 0;
    fo(i, si(cur)) {
        rem = (b * rem + cur[i]) % x;
    }
    return rem == 0;
}

int get(int base) {
    if(divides(base, 2)) return 2;
    for(int x = 3; x <= 1000000; x += 2)
        if(divides(base, x)) return x;

    return 1;
}

bool brute_check(int base, int f) {
    ll num = 0;
    fo(i, si(cur)) num = base * num + cur[i];
    return num % f == 0;
}

void check() {
    int dsum = accumulate(all(cur), 0);
    if(dsum % 2 != 0) return;
    ll num = 0;
    fo(i, si(cur)) num = 10 * num + cur[i];
    if(seen.count(num)) return;
    seen.insert(num);

    vi f;
    rep(i, 2, 10) {
        int cf = get(i);
        if(cf == 1) break;
        f.pu(cf);
        //assert(brute_check(i, cf));
    }

    if(si(f) == 9) ret.pu(Solution(cur, f));

}

vector<Solution> solve(int n, int j) {
    ret.clear();

    cur = vi(n, 0);
    cur[0] = cur[n-1] = 1;
    while(si(ret) < j) {
        rep(i, 1, n - 2) cur[i] = rand() % 2;
        check();
        trace(si(seen), si(ret));
    }

    return ret;
}

int main() {
    //freopen("sample.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //freopen("C-small-attempt0.in", "r", stdin);
    //freopen("small0.txt", "w", stdout);

    freopen("C-large.in", "r", stdin);
    freopen("large.txt", "w", stdout);
    
    int kases;
    scanf("%d", &kases);
    for(int kase = 1; kase <= kases; ++kase) {
        int n, j;
        scanf("%d %d", &n, &j);
        vector<Solution> ans = solve(n, j);
        //vector<Solution> ans = solve(16, 50);
        printf("Case #%d:\n", kase);
        fo(i, si(ans)) {
            for(int d: ans[i].num) printf("%d", d);
            for(int x: ans[i].factors) printf(" %d", x);
            printf("\n");

        }
    }
    
	return 0;
}
