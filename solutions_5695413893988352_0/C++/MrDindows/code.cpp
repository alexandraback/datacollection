#pragma comment(linker, "/stack:20000000")
#define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <cmath>
# include <algorithm>
# include <cstdio>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <deque>
# include <functional>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
using namespace std;

// Let's define unordered map
# ifdef __GNUC__
# if __cplusplus > 199711L
# include <unordered_set>
# include <unordered_map>
# else
# include <tr1/unordered_map>
# include <tr1/unordered_set>
using namespace std::tr1;
# endif
# else
# include <unordered_map>
# include <unordered_set>
# endif

#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL_((0,__VA_ARGS__, 5,4,3,2,1))
#define VA_NUM_ARGS_IMPL_(tuple) VA_NUM_ARGS_IMPL tuple
#define VA_NUM_ARGS_IMPL(_0,_1,_2,_3,_4,_5,N,...) N
#define macro_dispatcher(macro, ...) macro_dispatcher_(macro, VA_NUM_ARGS(__VA_ARGS__))
#define macro_dispatcher_(macro, nargs) macro_dispatcher__(macro, nargs)
#define macro_dispatcher__(macro, nargs) macro_dispatcher___(macro, nargs)
#define macro_dispatcher___(macro, nargs) macro ## nargs
#define DBN1(a)         std::cerr<<#a<<"="<<(a)<<"\n"
#define DBN2(a,b)       std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define DBN3(a,b,c)     std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define DBN4(a,b,c,d)   std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define DBN5(a,b,c,d,e) std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
#define DBN(...) macro_dispatcher(DBN, __VA_ARGS__)(__VA_ARGS__)
#define DA(a,n) cout<<#a<<"=["; printarray(a,n); cout<<"]\n"
#define DAR(a,n,s) cout<<#a<<"["<<s<<"-"<<n-1<<"]=["; printarray(a,n,s); cout<<"]\n"

#ifdef _MSC_VER
#define ALIGN(x) __declspec(align(x))
#else
#define ALIGN(x) __attribute__((aligned(x)))
#endif

#define CURTIME() cerr << clock() * 1.0 / CLOCKS_PER_SEC << std::endl
double __begin;
#define DTIME(ccc) __begin = clock(); ccc; std::cerr<<"Time of work = "<<(clock()-__begin)/CLOCKS_PER_SEC<<std::endl;

#define mp make_pair
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

template<typename T1, typename T2, typename T3>
struct triple{ T1 a; T2 b; T3 c; triple(){}; triple(T1 _a, T2 _b, T3 _c) :a(_a), b(_b), c(_c){} };
#define tri triple<int,int,int>
#define trll triple<ll,ll,ll>
template<typename T1, typename T2, typename T3>
bool operator<(const triple<T1, T2, T3> &t1, const triple<T1, T2, T3> &t2){ if (t1.a != t2.a) return t1.a<t2.a; else if (t1.b != t2.b) return t1.b<t2.b; else return t1.c < t2.c; }

#define FI(n) for(int i=0;i<n;++i)
#define FJ(n) for(int j=0;j<n;++j)
#define FK(n) for(int k=0;k<n;++k)
#define all(a) a.begin(), a.end()
//int some_primes[10] = {100271, 500179, 1000003, 2000227, 5000321}

inline int bits_count(int v){ v = v - ((v >> 1) & 0x55555555); v = (v & 0x33333333) + ((v >> 2) & 0x33333333); return((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; }
inline int bits_count(ll v){ int t = v >> 32; int p = (v & ((1LL << 32) - 1)); return bits_count(t) + bits_count(p); }
unsigned int reverse_bits(register unsigned int x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
inline int sign(int x){ return x > 0; }
inline bool isPowerOfTwo(int x){ return (x != 0 && (x&(x - 1)) == 0); }
#define checkbit(n, b) ((n >> b) & 1)
#define reunique(v) v.resize(std::unique(v.begin(), v.end()) - v.begin())

//STL output ********************************
template<typename T1, typename T2> inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p);
template<typename T> inline std::ostream &operator<<(std::ostream &os, const std::vector<T>& v);
template<typename T>inline std::ostream &operator<<(std::ostream &os, const std::set<T>&v);
template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os, const std::map<T1, T2>& v);
template<typename T1, typename T2, typename T3> inline std::ostream& operator << (std::ostream& os, const triple<T1, T2, T3>& t);
template<typename T1, typename T2> inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p){ return os << "(" << p.first << ", " << p.second << ")"; }
template<typename T>inline std::ostream &operator<<(std::ostream &os, const std::vector<T>& v){ bool first = true; os << "["; for (unsigned int i = 0; i<v.size(); i++){ if (!first)os << ", "; os << v[i]; first = false; }return os << "]"; }
template<typename T>inline std::ostream &operator<<(std::ostream &os, const std::set<T>&v){ bool first = true; os << "["; for (auto ii = v.begin(); ii != v.end(); ++ii){ if (!first)os << ", "; os << *ii; first = false; }return os << "]"; }
template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os, const std::map<T1, T2>& v){ bool first = true; os << "["; for (auto ii = v.begin(); ii != v.end(); ++ii){ if (!first)os << ", "; os << *ii; first = false; }return os << "]"; }
template<typename T, typename T2>void printarray(T  a[], T2 sz, T2 beg = 0){ for (T2 i = beg; i<sz; i++) cout << a[i] << " "; cout << endl; }
template<typename T1, typename T2, typename T3>
inline std::ostream& operator << (std::ostream& os, const triple<T1, T2, T3>& t){ return os << "(" << t.a << ", " << t.b << ", " << t.c << ")"; }

//Pair magic
template<typename T1, typename T2> inline pair<T1, T2> operator+(const pair<T1, T2> &p1 , const pair<T1, T2> &p2) { return pair<T1, T2>(p1.first + p2.first, p1.second + p2.second); }
template<typename T1, typename T2> inline pair<T1, T2> operator-(const pair<T1, T2> &p1 , const pair<T1, T2> &p2) { return pair<T1, T2>(p1.first - p2.first, p1.second - p2.second); }

#define FREIN(FILE) freopen(FILE, "rt", stdin)
#define FREOUT(FILE) freopen(FILE, "wt", stdout)

#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(1.0 * (x))
#define pow(x, n) pow(1.0 * (x), n)

inline ll mulmod(ll x, ll n, ll _mod){ ll res = 0; while (n){ if (n & 1)res = (res + x) % _mod; x = (x + x) % _mod; n >>= 1; }return res; }
inline ll powmod(ll x, ll n, ll _mod){ ll res = 1; while (n){ if (n & 1)res = (res*x) % _mod; x = (x*x) % _mod; n >>= 1; }return res; }
inline ll gcd(ll a, ll b){ ll t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline int gcd(int a, int b){ int t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline ll lcm(ll a, ll b){ return a / gcd(a, b)*b; }
inline ll gcd(ll a, ll b, ll c){ return gcd(gcd(a, b), c); }
inline int gcd(int a, int b, int c){ return gcd(gcd(a, b), c); }

// Useful constants

#define INF         1011111111
#define LLINF       1000111000111000111LL
#define EPS         (double)1e-10
#define mod         1000000007
#define PI          3.14159265358979323
#define link        asaxlaj
//*************************************************************************************

//const int MAXN = ...; // число вершин
//const int INF = 1000000000; // константа-бесконечность
//
//struct edge {
//    int a, b, cap, flow;
//};
//
//int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
//vector<edge> e;
//vector<int> g[MAXN];
//
//void add_edge (int a, int b, int cap) {
//    edge e1 = { a, b, cap, 0 };
//    edge e2 = { b, a, 0, 0 };
//    g[a].push_back ((int) e.size());
//    e.push_back (e1);
//    g[b].push_back ((int) e.size());
//    e.push_back (e2);
//}
//
//bool bfs() {
//    int qh=0, qt=0;
//    q[qt++] = s;
//    memset (d, -1, n * sizeof d[0]);
//    d[s] = 0;
//    while (qh < qt && d[t] == -1) {
//        int v = q[qh++];
//        for (size_t i=0; i<g[v].size(); ++i) {
//            int id = g[v][i],
//            to = e[id].b;
//            if (d[to] == -1 && e[id].flow < e[id].cap) {
//                q[qt++] = to;
//                d[to] = d[v] + 1;
//            }
//        }
//    }
//    return d[t] != -1;
//}
//
//int dfs (int v, int flow) {
//    if (!flow)  return 0;
//    if (v == t)  return flow;
//    for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
//        int id = g[v][ptr[v]],
//        to = e[id].b;
//        if (d[to] != d[v] + 1)  continue;
//        int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
//        if (pushed) {
//            e[id].flow += pushed;
//            e[id^1].flow -= pushed;
//            return pushed;
//        }
//    }
//    return 0;
//}
//
//int dinic() {
//    int flow = 0;
//    for (;;) {
//        if (!bfs())  break;
//        memset (ptr, 0, n * sizeof ptr[0]);
//        while (int pushed = dfs (s, INF))
//            flow += pushed;
//    }
//    return flow;
//}

int cnt[10101];
int n;
string a, b;
ll bestDif;
ll ansx, ansy;
void go(int cur, ll x, ll y) {
    if (cur == n) {
        ll dif = abs(x - y);
        if (dif < bestDif || (dif == bestDif && (x < ansx || (x == ansx && y < ansy)))) {
            bestDif = dif;
            ansx = x;
            ansy = y;
        }
        return;
    }
    int curx = a[cur] - '0';
    int cury = b[cur] - '0';
    if (curx < 10 && cury < 10) {
        go(cur + 1, x * 10 + curx, y * 10 + cury);
    } else if (curx > 10 && cury > 10) {
        if (x == y) {
            go(cur + 1, x * 10 + 0, y * 10 + 1);
            go(cur + 1, x * 10 + 0, y * 10 + 0);
            go(cur + 1, x * 10 + 1, y * 10 + 0);
        } else if (x > y) {
            go(cur + 1, x * 10 + 0, y * 10 + 9);
        } else {
            go(cur + 1, x * 10 + 9, y * 10 + 0);
        }
    } else {
        if (x == y) {
            if (curx > 10) {
                if (cury - 1 >= 0)
                    go(cur + 1, x * 10 + cury - 1, y * 10 + cury);
                go(cur + 1, x * 10 + cury, y * 10 + cury);
                if (cury + 1 < 10)
                    go(cur + 1, x * 10 + cury + 1, y * 10 + cury);
            } else {
                if (curx - 1 >= 0)
                    go(cur + 1, x * 10 + curx, y * 10 + curx - 1);
                go(cur + 1, x * 10 + curx, y * 10 + curx);
                if (curx + 1 < 10)
                    go(cur + 1, x * 10 + curx, y * 10 + curx + 1);
            }
        } else if (x > y) {
            if (curx > 10) {
                go(cur + 1, x * 10 + 0, y * 10 + cury);
            } else {
                go(cur + 1, x * 10 + curx, y * 10 + 9);
            }
        } else if (x < y) {
            if (curx > 10) {
                go(cur + 1, x * 10 + 9, y * 10 + cury);
            } else {
                go(cur + 1, x * 10 + curx, y * 10 + 0);
            }
        }
    }
}
int main() {
    FREIN("in.txt");
    FREOUT("out.txt");
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ": ";
        cin >> a >> b;
        n = a.size();
        bestDif = 2e18;
        go(0, 0, 0);
        string sa = to_string(ansx);
        string sb = to_string(ansy);
        while (sa.size() < n) sa = "0" + sa;
        while (sb.size() < n) sb = "0" + sb;
        cout << sa << " " << sb << endl;
//        for (int i = 0; i < (1 << n); ++i) {
//            
//        }
    }
    
    return 0;
}