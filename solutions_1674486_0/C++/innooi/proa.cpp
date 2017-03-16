#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T, n;
int mark[1010];

struct edg {
    int to;
    edg *next;
} edge[1000010], *vert[1010];

void Add_Edge(int u, int v, int &top) {
    edg *p = &edge[++top];
    p->to = v;
    p->next = vert[u];
    vert[u] = p;
}

void DFS(int u) {
    for (edg *p = vert[u]; p; p = p->next) {
        if (!mark[p->to]) {
            mark[p->to] = 1;
            DFS(p->to);
        } else {
            mark[p->to] = 2;
            return;
        }
    }
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.out", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        memset(vert, 0, sizeof (vert));
        memset(mark, 0, sizeof (mark));
        int top = -1;

        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            int m;
            scanf("%d", &m);
            for (int j = 1; j <= m; ++j) {
                int b;
                scanf("%d", &b);
                Add_Edge(i, b, top);
            }
        }

        bool ans = 0;
        for (int i = 1; i <= n; ++i) {
            memset(mark, 0, sizeof (mark));
            mark[i] = 1;
            DFS(i);
            for (int j = 1; j <= n; ++j) {
                if (mark[j] == 2) {
                    ans = 1;
                    break;
                }
            }
            if (ans) break;
        }
        printf("Case #%d: ", cas);
        if (ans) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}