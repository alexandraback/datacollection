#include <bits/stdc++.h>
#define ws aosndoasin
using namespace std;

const int N = 2001;
int T, t, n, x, y, wf, ws, c, vst[N], m[N], d;
char u[21], v[21];

map<string, int> dicf, dics;
vector<int> g[N], h[N];

bool match(int u, vector<int> *g) {
    if (vst[u] == x) return 0;
    vst[u] = x;
    for(int i=0; i<g[u].size(); ++i) {
        int v = g[u][i];
        if (!m[v] or match(m[v], g)) {
            m[v] = u;
            return 1;
        }
    }
    return 0;
}

int main() {
    scanf("%d", &T);
    while(t++ < T) {
        dicf.clear(), dics.clear();
        for(int i=0; i < N; ++i) g[i].clear(), h[i].clear();
        wf = ws = 0;

        scanf("%d", &n);

        for(int i=0; i<n; ++i) {
            scanf("%s%s", u, v);
            x = dicf[u];
            if (!x) dicf[u] = x = ++wf;
            y = dics[v];
            if (!y) dics[v] = y = ++ws;
            g[x].push_back(y);
            h[y].push_back(x);
        }

        c = d = 0;
        x = 1;
        memset(vst, 0, sizeof vst);
        memset(m, 0, sizeof m);
        for(int u=1; u<=wf; ++u, ++x) c += match(u, g);

        memset(vst, 0, sizeof vst);
        memset(m, 0, sizeof m);
        x = 1;
        for(int u=1; u<=ws; ++u, ++x) d += match(u, h);

        printf("Case #%d: %d\n", t, n - wf - ws + max(c, d));
    }
    return 0;
}
