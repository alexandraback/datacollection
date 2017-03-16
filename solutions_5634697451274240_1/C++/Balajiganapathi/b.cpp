/* string coder = "Balajiganapathi"; */

//#define LOCAL
#ifdef LOCAL
#   define TRACE
#else
#   define NDEBUG
#endif

#include<bits/stdc++.h>

using namespace std;

/* aliases */
using vi  = vector<int>;
using pi  = pair<int, int>;
using vs  = vector<string>;
using vpi = vector<pi>;
using ll  = long long int;

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
constexpr int mx = 102;
char cakes[mx];
int n;
int dp[mx][mx][2];
int cost[2][2] = {{2, 3}, {3, 4}};

int check(int a, int b, int f) {
    rep(i, a, b) {
        int x = (cakes[i] == '+');
        x ^= f;
        if(x == 0) return oo;
    }

    return 0;
}

int solve(int a, int b, int f) {
    int &ret = dp[a][b][f];
    if(ret != -1) return ret;
    ret = check(a, b, f);

    if(!ret) return ret;

    re(i, a, b) {
        fo(f1, 2) fo(f2, 2) {
            ret = min(ret, cost[f1][f2] + solve(a, i, f ^ f1) + solve(i + 1, b, f ^ f2));
            ret = min(ret, f1 + solve(a, i, f ^ f1) + check(i + 1, b, f));
        }
    }

    //trace(a, b, f, ret);
    return ret;
}

int main() {
    //freopen("sample.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //freopen("B-small-attempt0.in", "r", stdin);
    //freopen("small0.txt", "w", stdout);

    freopen("B-large.in", "r", stdin);
    freopen("large.txt", "w", stdout);
    
    int kases;
    scanf("%d", &kases);
    for(int kase = 1; kase <= kases; ++kase) {
        trace(kase);
        scanf("%s", cakes);
        n = strlen(cakes);
        ini(dp, -1);
        int ans = min(solve(0, n - 1, 0), 1 + solve(0, n - 1, 1));

        printf("Case #%d: %d\n", kase, ans);

    }
    
	return 0;
}
