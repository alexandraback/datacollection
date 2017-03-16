#include <bits/stdc++.h>

#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define for1(i, n) for(int i = 1; i <= (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define prev asdfsdf
#define x first
#define y second

using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long i64;
typedef unsigned long long ull;

template <class T>
bool remin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool remax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}

ll gcd(ll a, ll b) {
    a = abs(a);
    b = abs(b);
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}


typedef ll ptdata;

struct pt {
    ptdata x, y;
    pt() {}
    pt(ptdata x, ptdata y) : x(x), y(y) {}

    pt operator - (const pt &r) const {
        return pt(x - r.x, y - r.y);
    }
    pt operator + (const pt &r) const {
        return pt(x + r.x, y + r.y);
    }
    pt operator * (const ld &r) const {
        return pt(x * r, y * r);
    }
    ptdata sqlen() const {
        return abs(x * x + y * y);
    }
    ld len() const {
        return sqrtl(sqlen());
    }

    bool operator < (const pt &r) const {
        if (x != r.x) return x < r.x;
        return y < r.y;
    }
    bool operator == (const pt &r) const {
        return x == r.x && y == r.y;
    }
};

ptdata cross(const pt &l, const pt &r) {
    return l.x * r.y - l.y * r.x;
}

ptdata dot(const pt &l, const pt &r) {
    return l.x * r.x + l.y * r.y;
}


ll pwmod(ll a, ll n, ll mod) {
    ll ret = 1;
    while (n) {
        if (n & 1) ret = ret * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}

template<typename T>
inline T sqr(T x) {
    return x * x;
}


const int N = 3000;
struct G {
    struct edge {
        int a, b, cap, cost, flow;
    };

    vector<edge> e;
    vector<int> g[N];
    int s, t;
    int d[N];
    int p[N];
    int q[N];
    char u[N];

    void add_edge (int a, int b, int cap, int cost) {
        edge e1 = { a, b, cap, cost, 0 };
        edge e2 = { b, a, 0, -cost, 0 };
        g[a].push_back ((int) e.size());
        e.push_back (e1);
        g[b].push_back ((int) e.size());
        e.push_back (e2);
    }

    bool fb() {
        memset(u, 0, sizeof(u));
        memset(d, 0x3f, sizeof(d));
        memset(p, -1, sizeof(p));
        int inf = d[0];
        int q1 = 0, q2 = 0;
        u[s] = 1;
        q[q2++] = s;
        d[s] = 0;
        while (q1 != q2) {
            int v = q[q1++];
            u[v] = 0;
            if (q1 == N) q1 = 0;
            for (int id : g[v]) {
                int to = e[id].b;
                int len = e[id].cost;
                if (e[id].flow >= e[id].cap) {
                    continue;
                }
                if (d[to] > d[v] + len) {
                    d[to] = d[v] + len;
                    p[to] = id;
                    if (!u[to]) {
                        q[q2++] = to;
                        u[to] = 1;
                        if (q2 == N) q2 = 0;
                    }
                }
            }
        }
        return p[t] != -1;
    }

    int push() {
        int v = t;
        while (v != s) {
            e[p[v]].flow += 1;
            e[p[v] ^ 1].flow -= 1;
            v = e[p[v]].a;
        }
        return d[t];
    }

    pair<int, int> minCost(int S, int T) {
        s = S;
        t = T;
        int flow = 0;
        int cost = 0;
        while (fb()) {
            flow += 1;
            cost += push();
        }
        return mp(flow, cost);
    }
};

inline void solve(int test) {
    cout << "Case #" << test << ": ";
    int n;
    cin >> n;
    vector<pair<string, string> > vs(n);
    forn(i, n) {
        cin >> vs[i].x >> vs[i].y;
    }
    map<string, int> le;
    map<string, int> ri;
    forn(i, n) {
        if (!le.count(vs[i].x)) {
            le[vs[i].x] = (int)le.size() - 1;
        }
        if (!ri.count(vs[i].y)) {
            ri[vs[i].y] = (int)ri.size() - 1;
        }
    }
    G g;
    int s = le.size() + ri.size();
    int t = s + 1;
    int s2 = t + 1;
    int t2 = s2 + 1;

    forn(i, n) {
        g.add_edge(le[vs[i].x], le.size() + ri[vs[i].y], 1, 0);
        //cerr << le[vs[i].x] << " " << ri[vs[i].y] << endl;
    }
    forn(i, le.size()) {
        g.add_edge(s2, i, 1, 0);
        g.add_edge(s, t2, 1, 0);
        g.add_edge(s, i, INT_MAX / 2, 0);
    }
    forn(i, ri.size()) {
        g.add_edge(s2, t, 1, 0);
        g.add_edge(i + le.size(), t2, 1, 0);
        g.add_edge(i + le.size(), t, INT_MAX / 2, 0);
    }
    g.add_edge(t, s, INT_MAX / 2, 1);
    auto res = g.minCost(s2, t2);
    assert(res.x == le.size() + ri.size());

    cout << n - res.y << "\n";
}



int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    forn(i, t) {
        solve(i + 1);
    }

    cerr << "Time " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}
