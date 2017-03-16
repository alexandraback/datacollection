#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define gc getchar
int getint() { unsigned int c; int x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getint(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }
int getstr(char *s) { int c, n = 0; while ((c = gc()) <= ' ') { if (!~c) exit(0); } do { s[n++] = c; } while ((c = gc()) > ' ' ); s[n] = 0; return n; }
template<class T> inline bool chmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template<class T> inline bool chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }

void print_case(int test_case) { printf("Case #%d: ", test_case); }

template<class T> struct IndexGetter {
    map<T, int> fmp;
    vector<T> rmp;
    int n;
    IndexGetter() { n = 0; }
    int get(T a) {
        if (!fmp.count(a)) { fmp[a] = n, rmp.push_back(a); return n++; }
        return fmp[a];
    }
    T rget(int idx) { return rmp[idx]; }
    int size() { return n; }
    void clear() { n = 0, fmp.clear(), rmp.clear(); }
};

template<typename Ft> struct MaxFlow {
    static const int V = 3000;
    static const Ft feps = (Ft)1e-10, finf = (Ft)(1 << 28);
    Ft tof;
    int nv, dst[V], srt[V], que[V], qs, qe, src, snk;
    struct edge { int to, rv; Ft cap; edge(int to, int rv, Ft cap) : to(to), rv(rv), cap(cap) {} };
    vector<edge> graph[V];
    void init(int v = V) {
        nv = v, tof = 0;
        for (v = 0; v < nv; v++) graph[v].clear();
    }
    void add_edge(int fr, int to, Ft fcap, Ft rcap = 0) {
        if (fr == to) return;
        int fe = graph[fr].size(), te = graph[to].size();
        graph[fr].push_back(edge(to, te, fcap));
        graph[to].push_back(edge(fr, fe, rcap));
    }
    Ft aug(int u, Ft flo) {
        if (u == snk) return flo;
        Ft df;
        for (int &i = srt[u]; i < graph[u].size(); i++) {
            edge &e = graph[u][i];
            if (e.cap > feps and dst[u] < dst[e.to]) {
                if (flo > e.cap) flo = e.cap;
                if ((df = aug(e.to, flo)) > feps) { e.cap -= df, graph[e.to][e.rv].cap += df; return df; }
            }
        }
        return 0;
    }
    Ft dinic(int source, int sink, Ft flo_lim = finf) {
        int i, v;
        src = source, snk = sink;
        Ft df;
        for ( ; tof + feps < flo_lim; ) {
            memset(dst, ~0, sizeof(dst));
            for (dst[src] = 0, qs = qe = 0, que[qe++] = src; qs != qe; ) {
                v = que[qs++];
                for (i = 0; i < graph[v].size(); i++) {
                    const edge &e = graph[v][i];
                    if (e.cap > feps and !~dst[e.to]) {
                        dst[e.to] = dst[v] + 1, que[qe++] = e.to;
                        if (v == snk) { qs = qe = 0; break; }
                    }
                }
            }
            if (!~dst[snk]) return tof;
            memset(srt, 0, sizeof(srt));
            for (; (df = aug(src, flo_lim - tof)) > feps; ) tof += df;
        }
        return tof;
    }
};


int n;
char in[100];

IndexGetter<string> ig1, ig2;

int words[1 << 10][2];

void solve_case() {
    int i, j;
    n = getint();
    ig1.clear(), ig2.clear();
    for (i = 0; i < n; ++i) {
        getstr(in), words[i][0] = ig1.get(string(in));
        getstr(in), words[i][1] = ig2.get(string(in));
    }
    int s = 0, t = s + 1, m1 = t + 1, m2 = m1 + ig1.size(), nv = m2 + ig2.size();

    const int inf = 1 << 28;
    MaxFlow<int> mf;
    mf.init(nv);
    for (i = 0; i < ig1.size(); ++i) mf.add_edge(s, m1 + i, 1);
    for (i = 0; i < ig2.size(); ++i) mf.add_edge(m2 + i, t, 1);
    for (i = 0; i < n; ++i) {
        int u = words[i][0] + m1;
        int v = words[i][1] + m2;
        mf.add_edge(u, v, 1);
    }
    int flw = mf.dinic(s, t);
    int res = n - flw;
    for (auto e: mf.graph[s]) if (e.cap) res--;
    for (auto e: mf.graph[t]) if (e.cap == 0) res--;

    cout << res << endl;

    return;
}

int main () {
    int test_count, test_case = getint();
    for (test_count = 0; test_count < test_case; test_count++) {
        print_case(test_count + 1);
        solve_case();
    }
    return 0;
}
