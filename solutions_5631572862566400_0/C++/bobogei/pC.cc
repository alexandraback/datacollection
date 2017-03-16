#include<bits/stdc++.h>
using namespace std;
#define FZ(n) memset((n),0,sizeof(n))
#define FMO(n) memset((n),-1,sizeof(n))
#define MC(n,m) memcpy((n),(m),sizeof(n))
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ALL(x) begin(x),end(x)
#define IOS do { ios_base::sync_with_stdio(0);cin.tie(0); } while (0)
#define SZ(x) ((int)(x).size())
#ifndef OFFLINE
    #define ONLINE_JUDGE
#endif
#ifdef ONLINE_JUDGE
#define FILEIO(name) \
    do { \
        freopen(name".in", "r", stdin); \
        freopen(name".out", "w", stdout); \
    } while (0)
#else
    #define FILEIO(name) do { } while(0)
#endif

#define _TOKEN_CAT2(x, y) x ## y
#define _TOKEN_CAT(x, y) _TOKEN_CAT2(x, y)
#define _MACRO_OVERL3(_1, _2, _3, _N, ...) _N
#define _RANGE1(a) int _TOKEN_CAT(_t, __LINE__)=0; _TOKEN_CAT(_t, __LINE__)<(a); (_TOKEN_CAT(_t, __LINE__))++
#define _RANGE2(i, a) int (i)=0; (i)<(a); (i)++
#define _RANGE3(i, a, b) int (i)=(a); (i)!=(b); (i)+=((b)>(a)?1:-1)
#define loop(...) for (_MACRO_OVERL3(__VA_ARGS__, _RANGE3, _RANGE2, _RANGE1)(__VA_ARGS__))

#ifdef OFFLINE
template<typename T>
void _dump(const char* s, T&& head) { 
    cerr << s << " = " << head << " <<" << endl; 
}

template<typename T, typename... Args>
void _dump(const char* s, T&& head, Args&&... tail) {
    int c = 0;
    while (*s!=',' || c!=0) {
        if (*s=='(' || *s=='[' || *s=='{' || *s=='<') c++;
        if (*s==')' || *s==']' || *s=='}' || *s=='>') c--;
        cerr << *s++;
    }
    cerr << " = " << head << ", ";
    _dump(s+1, tail...);
}

#define dump(...) do { \
    cerr << "\033[32m>> " << __LINE__ << ": " << __PRETTY_FUNCTION__ << endl; \
    cout << "   "; \
    _dump(#__VA_ARGS__, __VA_ARGS__); \
    cout << "\033[0m"; \
} while (0)
#else
#define dump(...) 
#endif

#define au auto
template<class T>
using vec = vector<T>;

template<typename Iter>
ostream& _IterOutput_(ostream &o, Iter b, Iter e, const string ss="", const string se="") {
    o << ss;
    for (auto it=b; it!=e; it++) o << (it==b ? "" : ", ") << *it;
    return o << se;
}

template<typename T1, typename T2>
ostream& operator << (ostream &o, pair<T1, T2> &pair) {
    return o << "(" << pair.F << ", " << pair.S << ")";
}

template<typename T>
ostream& operator << (ostream &o, const vector<T> &vec) {
    return _IterOutput_(o, ALL(vec), "[", "]");
}

template<typename T>
ostream& operator << (ostream &o, const set<T> &st) {
    return _IterOutput_(o, ALL(st), "{", "}");
}

template<typename T, size_t N>
ostream& operator << (ostream &o, const array<T, N> &arr) {
    return _IterOutput_(o, ALL(arr), "|", "|");
}

const int MX = 3333;
int N;
int ip[MX];
vec<int> rel[MX];
int vt[MX];
bool us[MX];
int mem[MX];
int pr[MX];

void init() {
    for (int i=0; i<MX; i++) rel[i].clear();
    FZ(vt);
    FZ(us);
    for (int i=0; i<MX; i++) pr[i] = -1;
}

int dp(int u) {
    if (us[u]) return mem[u];
    us[u] = 0;
    int t = 0;
    for (auto v: rel[u]) {
        if (v == pr[u]) continue;
        t = max(t, dp(v));
    }
    return (mem[u] = t+1);
}

int calc() {
    init();

    int ans = 0;
    int a2 = 0;
    loop(i, N) {
        rel[ip[i]].PB(i);
    }
    int ts = 0;
    loop(i, N) {
        if (vt[i]) continue;
        ts++;
        int nw = i;
        while (!vt[nw]) {
            vt[nw]=ts;
            nw=ip[nw];
        }

        if (vt[nw] != ts) continue;
        ts++;
        int t = 0;
        while (vt[nw] != ts) {
            vt[nw]=ts;
            nw=ip[nw];
            t++;
        }
        if(t>2) ans = max(ans, t);
        else {
            assert(t==2);
            int x = nw, y = ip[nw];
            pr[x] = y; pr[y] = x;
            a2 += dp(x) + dp(y);
        }
    }
    return max(ans, a2);
}

int32_t main() {
    IOS;
    int T;cin>>T;
    loop(cas, 1, T+1) {
        cin>>N;
        loop(i, N) {
            cin >> ip[i];
            ip[i]--;
        }
        cout << "Case #" << cas << ": " << calc() << endl;
    }

    return 0;
}

