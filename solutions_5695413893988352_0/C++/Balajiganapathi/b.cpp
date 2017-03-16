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
string s1, s2;
ll p10[20];

string to(int x, int n) {
    string s;
    fo(i, n) {
        s.pu(char('0' + x % 10));
        x /= 10;
    }
    reverse(all(s));
    return s;
}

pair<string, string> brute(string s1, string s2) {
    int n = si(s1);
    int best = oo;
    pair<string, string> ans;
    fo(i, int(p10[n])) fo(j, int(p10[n])) {
        string n1 = to(i, n), n2 = to(j, n);
        bool ok = true;
        fo(i, si(s1)) if(s1[i] != n1[i] && s1[i] != '?') ok = false;
        fo(i, si(s2)) if(s2[i] != n2[i] && s2[i] != '?') ok = false;

        if(!ok) continue;
        if(abs(best) > abs(i - j) || (abs(best) == abs(i - j) && mp(n1, n2) < ans)) {
            ans = mp(n1, n2);
            best = i - j;
            //trace(best, n1, n2);
        }
    }

    return ans;
}

int main() {
    //freopen("sample.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    freopen("B-small-attempt1.in", "r", stdin);
    freopen("small1.txt", "w", stdout);

    //freopen("B-large.in", "r", stdin);
    //freopen("large.txt", "w", stdout);
    
    p10[0] = 1;
    re(i, 1, 20) p10[i] = 10ll * p10[i-1];
    int kases;
    scanf("%d", &kases);
    for(int kase = 1; kase <= kases; ++kase) {
        trace(kase);
        cin >> s1 >> s2;
        pair<string, string> bans = brute(s1, s2);

        /*
        int n = si(s1);
        ll diff = 0;
        fo(i, n) {
            int f1 = 0, t1 = 9, f2 = 0, t2 = 9;
            if(s1[i] != '?') f1 = t1 = s1[i] - '0';
            if(s2[i] != '?') f2 = t2 = s2[i] - '0';

            ll m = p10[n - 1 - i];
            ll best = oo;
            rep(d1, f1, t1) rep(d2, f2, t2) {
                ll cur = diff + m * (d1 - d2);
                if(abs(cur) < abs(best)) {
                    best = cur;
                    s1[i] = char(d1 + '0');
                    s2[i] = char(d2 + '0');
                }
            }

            diff = best;
        }
        */

        printf("Case #%d: %s %s\n", kase, bans.fi.c_str(), bans.se.c_str());

    }
    
	return 0;
}
