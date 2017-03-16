#include <bits/stdc++.h>

#define rep(i,n) for(i=0; i<n; i++)
#define repl(i,n) for(i=1; i<=n; i++)
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin(); i!=(n).end(); i++)

#define sz(x) (int) x.size()
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define uu first
#define vv second
#define mem(x, y) memset(x, y, sizeof(x));

#define sdi(x) scanf("%d", &x)
#define sdii(x, y) scanf("%d %d", &x, &y)
#define sdiii(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sdl(x) scanf("%lld", &x)
#define sdll(x, y) scanf("%lld %lld", &x, &y)
#define sdlll(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define sds(x) scanf("%s", x)
#define pfi(x) printf("%d\n", x)
#define pfii(x, y) printf("%d %d\n", x, y)
#define pfiii(x, y, z) printf("%d %d %d\n", x, y, z)
#define pfl(x) printf("%lld\n", x)
#define pfll(x, y) printf("%lld %lld\n", x, y)
#define pflll(x, y, z) printf("%lld %lld %lld\n", x, y, z)

#define eps 1e-9
#define OK printf("ok\n")
#define DB(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int, int> pii;

inline int setBit(int N, int pos) { return N=N | (1<<pos); }
inline int resetBit(int N, int pos) { return N= N & ~(1<<pos); }
inline bool checkBit(int N, int pos) { return (bool)(N & (1<<pos)); }

//int kx[] = {+2, +1, -1, -2, -2, -1, +1, +2};
//int ky[] = {+1, +2, +2, +1, -1, -2, -2, -1}; //Knight Direction
//int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
//int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1}; //Four & Eight Direction


const int MAXN = 1205, MAXE = 5000+5005; // MAXE = twice the number of edges
int src, snk, nNode, nEdge;
int Q[MAXN], fin[MAXN], pro[MAXN], dist[MAXN];
int flow[MAXE], cap[MAXE], nxt[MAXE], to[MAXE];
pair <string, string> arr[1005];
int n;
map <string, int> mapp, cnt;
unordered_set <string> l, r;

inline void init(int _src, int _snk, int _n) {
    src = _src, snk = _snk, nNode = _n, nEdge = 0;
    mem(fin, -1);
}

inline void add(int u, int v, int _cap) {
    to[nEdge] = v, cap[nEdge] = _cap, flow[nEdge] = 0; nxt[nEdge] = fin[u], fin[u] = nEdge++;
    to[nEdge] = u, cap[nEdge] =    0, flow[nEdge] = 0; nxt[nEdge] = fin[v], fin[v] = nEdge++; // for directed cap[nEdge]=0 here
}

bool bfs() {
    int st, en, i, u, v;
    mem(dist, -1);
    dist[src] = st = en = 0;
    Q[en++] = src;
    while(st < en) {
        u = Q[st++];
        for(i=fin[u]; i>=0; i=nxt[i]) {
            v = to[i];
            if(flow[i] < cap[i] && dist[v]==-1) {
                dist[v] = dist[u]+1;
                Q[en++] = v;
            }
        }
    }
    return dist[snk]!=-1;
}

int dfs(int u, int fl) {
    if(u==snk) return fl;
    for(int &e=pro[u], v, df; e>=0; e=nxt[e]) {
        v = to[e];
        if(flow[e] < cap[e] && dist[v]==dist[u]+1) {
            df = dfs(v, min(cap[e]-flow[e], fl));
            if(df>0) {
                flow[e] += df;
                flow[e^1] -= df;
                return df;
            }
        }
    }
    return 0;
}

int dinitz() { // 1-based indexing
    int ret = 0;
    int df;
    while(bfs()) {
        for(int i=1; i<=nNode; i++) pro[i] = fin[i];
        while(true) {
            df = dfs(src, INT_MAX);
            if(df) ret += df;
            else break;
        }
    }
    return ret;
}

int main() {
    freopen("C-small.in","r",stdin);
    freopen("C-small.out","w",stdout);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int test, kase=1, i;

    sdi(test);
    while(test--) {
        mapp.clear();
        l.clear();
        r.clear();
        cnt.clear();

        sdi(n);
        rep(i, n) {
            cin >> arr[i].uu >> arr[i].vv;
            mapp[ arr[i].uu ] = 1;
            mapp[ arr[i].vv ] = 1;
            l.insert( arr[i].uu );
            r.insert( arr[i].vv );
            cnt[ arr[i].uu ]++;
            cnt[ arr[i].vv ]++;
        }
        int key = 2;
        for(auto &x : mapp) {
            x.vv = key++;
        }
        init(1, key, key);

        int mxL = 0, mxR = 0;

        for(auto x : l) {
            add(1, mapp[ x ], 1);
            mxL = max(mxL, cnt[x]);
        }
        for(auto x: r) {
            add(mapp[x], key, 1);
            mxR = max(mxR, cnt[x]);
        }

//        pfii(mxL, mxR);

        if(mxL == 1 || mxR == 1) {
            printf("Case #%d: 0\n", kase++);
            continue;
        }

        rep(i, n) {
            add(mapp[ arr[i].uu ], mapp[ arr[i].vv ], 1);
        }
        printf("Case #%d: %d\n", kase++, max(0, n - dinitz()));
    }

    return 0;
}
