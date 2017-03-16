#include <bits/stdc++.h>
using namespace std;

#ifdef ILIKEGENTOO
#   define Eo(x) { cerr << #x << " = " << (x) << endl; }
#   define E(x) { cerr << #x << " = " << (x) << "   "; }
#   define FREOPEN(x)
#else
#   define Eo(x)
#   define E(x)
#   define FREOPEN(x) (void)freopen(x ".in", "r", stdin);(void)freopen(x ".out", "w", stdout);
#endif
#define EO(x) Eo(x)
#define Sz(x) (int((x).size()))
#define All(x) (x).begin(),(x).end()

template<class A, class B> ostream &operator<<(ostream &os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }

template<class C> void operator<<(vector<C> &v, const C &x){v.push_back(x);}
template<class D> void operator>>(vector<D> &v, D &x){assert(!v.empty()); x=v.back(); v.pop_back();}
template<class E> void operator<<(set<E> &v, const E &x){v.insert(x);}
template<class F> void operator<<(queue<F> &c, const F& v){v.push(v);}
template<class G> void operator>>(queue<G> &c, const G& v){const G r=v.front();v.pop();return r;}

typedef double flt;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const int64 inf64 = 0x3f3f3f3f3f3f3f3fLL;
const flt eps = 1e-8;
const flt pi = acos(-1.0);
const int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

constexpr int bit(int t) { return 1 << t; }

const int maxn = 8;
string zip[maxn];
set<int> g[maxn];
vector<pii> gonext[maxn];
string curres;
string res;

int n, m;
pii edges[maxn * maxn];

bool visit[maxn];
void dfs(int v) {
    visit[v] = true;
    curres += zip[v];
    for (const pii& i : gonext[v]) {
        int u = i.second;
        if (!visit[u]) dfs(u);
    }
}

int ids[maxn];
void go(int id, int bound) {
    if (id == 0) {
        for (int i = 0; i < n; ++i) gonext[i].clear();
        for (int i = 0; i < n-1; ++i) {
            int u = edges[ids[i]].first;
            int v = edges[ids[i]].second;
            int zipu = atoi(zip[u].c_str());
            int zipv = atoi(zip[v].c_str());
            gonext[u] << pii(zipv, v);
            gonext[v] << pii(zipu, u);
        }
        for (int i = 0; i < n; ++i) sort(All(gonext[i]));
        for (int start = 0; start < n; ++start) {
            memset(visit, 0, sizeof(visit));
            curres = "";
            dfs(start);
            //E(ids[0]); E(ids[1]); E(ids[2]); E(ids[3]); E(start); Eo(curres);
            if (Sz(res) == Sz(curres))
                res = min(res, curres);
        }
        return ;
    }
    for (int i = bound; i < m; ++i) {
        ids[id - 1] = i;
        go(id - 1, i + 1);
    }
}

int main() {
	ios_base::sync_with_stdio(false);

    int T; cin >> T;
    for (int test = 1; test <= T; ++test) {
        cout << "Case #" << test << ": ";

        cin >> n >> m;
        set<string> codes;
        int minid = 0;
        for (int i = 0; i < n; ++i) {
            cin >> zip[i];
            codes << zip[i];
            if (zip[i] < zip[minid]) minid = i;
        }
        assert(Sz(codes) == n);
        for (int i = 0; i < m; ++i) {
            int u, v; cin >> u >> v; --u; --v;
            edges[i] = pii(u, v);
        }

        res = string(n * 5, '9');
        go(n - 1, 0);
        cout << res << endl;
    }

	return 0;
}
