#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;

int n, f[MAXN];
int best;

struct Edge {
    int v, next;
} edge[MAXN];
int head[MAXN], edgeNum;

inline void clearEdge() {
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v) {
    edge[edgeNum].v = v;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

int cnt[MAXN];

int getLoopNum(int u) {
    int idx = 0;
    memset(cnt, -1, sizeof(cnt));
    while (cnt[u] == -1) {
        cnt[u] = idx++;
        u = f[u];
    }
    return cnt[u] ? 0 : idx;
}

int maxHeight(int u, int p) {
    int h = 0;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (v != p) {
            h = max(h, maxHeight(v, u));
        }
    }
    return h + 1;
}

int main() {
    int T;
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d", &n);
        clearEdge();
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &f[i]);
            addEdge(f[i], i);
        }
        best = 0;
        for (int i = 1; i <= n; ++i) {
            best = max(best, getLoopNum(i));
        }
        for (int i = 1; i <= n && best != n; ++i) {
            for (int j = i + 1; j <= n && best != n; ++j) {
                if (f[i] == j && f[j] == i) {
                    best = max(best, maxHeight(j, i) + maxHeight(i, j));
                }
            }
        }
        printf("Case #%d: %d\n", t, best);
    }
    return 0;
}
