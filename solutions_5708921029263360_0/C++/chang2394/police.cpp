#define LOCAL
#ifdef LOCAL
#   define TRACE
#else
#   define NDEBUG
#endif

#include <cstdio>
#include <sstream>
#include <iostream>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cstring>
#include <bitset>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <cmath>

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

// int dx[] {-1, 0, 1, 0, 1, 1, -1, -1};
// int dy[] {0, -1, 0, 1, 1, -1, 1, -1};

/* constants */
constexpr auto PI  = 3.14159265358979323846L;
constexpr auto oo  = numeric_limits<int>::max() / 2 - 10;
constexpr auto eps = 1e-6;
constexpr auto mod = 1000000007;

/* code */

map<pair<int,vector<int> > ,int> dp;
int dx[] = {7,6,5,3,4,2,1};

int f(int mask,vi &moves){
    int ans = 0;

    if (dp.find(make_pair(mask,moves)) != dp.end())
        return dp[make_pair(mask,moves)];
    for(int x = 0; x < 8; ++x){
        for(int i = 0; i < 3; ++i){
            if (is1(mask,i) and is1(dx[x],0))
                continue;
            for(int j = 3; j < 6; ++j){
                if (is1(mask,j) and is1(dx[x],1))
                    continue;
                for(int k = 6; k < 9; ++k){
                    if (is1(mask,k) and is1(dx[x],2))
                        continue;
                    int cur = (1 << i) + (1 << j) + (1 << k);
                    if (cur == mask) 
                        continue;
                    if (moves[i*9+j] == 0) continue;
                    if (moves[i*9+k] == 0) continue;
                    if (moves[j*9+k] == 0) continue;

                    vi temp = moves;
                    temp[i*9+j] -= 1;
                    temp[i*9+k] -= 1;
                    temp[j*9+k] -= 1;

                    ans = max(ans,1+f(cur,temp));
                    dp[make_pair(mask,moves)] = ans;
                    return ans;
                }
            }
        }
        if (ans != 0){
            dp[make_pair(mask,moves)] = ans;
            return ans;
        }
    }
    dp[make_pair(mask,moves)] = ans;
    return ans;
}

void go(int mask,vi &moves){
    int ans = dp[make_pair(mask,moves)];
    for(int x = 0; x < 8; ++x){
        for(int i = 0; i < 3; ++i){
            if (is1(mask,i) and is1(dx[x],0))
                continue;
            for(int j = 3; j < 6; ++j){
                if (is1(mask,j) and is1(dx[x],1))
                    continue;
                for(int k = 6; k < 9; ++k){
                    if (is1(mask,k) and is1(dx[x],2))
                        continue;
                    int cur = (1 << i) + (1 << j) + (1 << k);
                    if (cur == mask) 
                        continue;
                    if (moves[i*9+j] == 0) continue;
                    if (moves[i*9+k] == 0) continue;
                    if (moves[j*9+k] == 0) continue;

                    vi temp = moves;
                    temp[i*9+j] -= 1;
                    temp[i*9+k] -= 1;
                    temp[j*9+k] -= 1;

                    if (ans == 1+f(cur,temp)){
                        cout << i+1 << " " << j+1-3 << " " << k+1-6 << endl;
                        go(cur,temp);
                        return;
                    }
                }
            }
        }
    }
}

void solve(int tc){
    int j,p,s,allowed;
    vi temp(90,0);

    cin >> j >> p >> s >> allowed;
    // trace(j,p,s,allowed);
    for(int i = 0; i < j; ++i){
        for(int j = 3; j < 3+p; ++j){
            for(int k = 6; k < 6+s; ++k){
                temp[i*9+j] = allowed;
                temp[i*9+k] = allowed;
                temp[j*9+k] = allowed;
            }
        }
    }

    int ans = f(0,temp);
    cout << "Case #" << tc << ": " << ans << endl;
    go(0,temp);
    
}

int main() {
    int tc;
    cin >> tc;
    for(int i = 1; i <= tc; ++i)
        solve(i);
    return 0;
}