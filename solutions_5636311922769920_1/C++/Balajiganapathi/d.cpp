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
constexpr int mx = -1;

class GoldRange {
    public:
        ll a, b;
        GoldRange(ll _a, ll _b) {
            a = _a;
            b = _b;
        }
};

vector<ll> getBest(int k, int c) {
    vector<GoldRange> g;
    rep(s, 1, k) {
        ll a, b;
        a = b = s;
        re(i, 1, c) {
            a = (1ll * (a - 1) * k + 1);
            b = (1ll * b * k);
        }
        trace(s, a, b);
        g.pu(GoldRange(a, b));
    }

    vector<ll> ret;
    for(GoldRange cur: g) {
        bool covered = false;
        for(ll x: ret) if(cur.a <= x && x <= cur.b) covered = true;
        if(covered) continue;
        ret.pu(cur.b);
    }

    return ret;
}

string str;
string get(int c) {
    if(c == 1) return str;
    string prev = get(c-1);
    string ret;
    for(char c: prev) {
        if(c == 'L') ret += str;
        else ret += string(si(str), 'G');
    }

    return ret;
}

int cnt[1000006];

void simulate(int k, int c) {
    ini(cnt, 0);
    fo(mask, (1 << k)) {
        str = "";
        fo(i, k) str += (is1(mask, i)? 'G': 'L');
        string fin = get(c);
        trace(str, fin);
        fo(i, si(fin)) if(fin[i] == 'G') ++cnt[i];
    }

    int ans = -1;
    fo(i, 1000006) if(cnt[i] == (1 << k) - 1) {
        ans = i;
        break;
    }

    trace(k, c, ans);
}

vector<ll> solve(int k, int c, int s) {
    if(c * s < k) return vector<ll>();
    //simulate(k, c);
    vector<ll> ret;
    int ci = 0;
    int cnt = 0;
    for(; cnt < k; ) {
        ll cur = 0;
        fo(i, c) {
            cur = 1ll * k * cur + ci;
            ++cnt;
            ci = (ci + 1) % k;
        }
        ret.pu(cur + 1);
    }

    return ret;
}

int main() {
    //freopen("sample.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //freopen("D-small-attempt0.in", "r", stdin);
    //freopen("small0.txt", "w", stdout);

    freopen("D-large.in", "r", stdin);
    freopen("large.txt", "w", stdout);
    
    int kases;
    scanf("%d", &kases);
    for(int kase = 1; kase <= kases; ++kase) {
        int k, c, s;
        scanf("%d %d %d", &k, &c, &s);

        printf("Case #%d:", kase);
        vector<ll> ans = solve(k, c, s);
        if(si(ans) == 0) {
            printf(" IMPOSSIBLE\n");
        } else {
            for(ll x: ans) printf(" %lld", x);
            printf("\n");
        }
    }
    
	return 0;
}
