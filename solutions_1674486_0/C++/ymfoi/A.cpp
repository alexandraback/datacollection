#include <cstdio>
#include <cstdlib>
#include <cstring>

const int MAX_VTX = 2000;
const int MAX_EDGES = MAX_VTX * 10;

struct Edge {

    int to;
    Edge *next;

} edges[MAX_EDGES], *head[MAX_VTX + 1], *edge_new = edges;

void add_edge(int u, int v) {

    Edge *p = edge_new++;
    p -> to = v;
    p -> next = head[u];
    head[u] = p;
}

int n;

void pre_work() {

    int c, t;
    edge_new = edges;
    memset(head, 0, sizeof head);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &c);
        for (int j = 1; j <= c; j++)
        {
            scanf("%d", &t);
            add_edge(i, t);
        }
    }
}

bool vis[MAX_VTX + 1];

bool check(int u) {

    if (vis[u]) return true;
    vis[u] = true;
    for (Edge *p = head[u]; p; p = p -> next)
        if (check(p -> to)) return true;
    return false;
}

void work(int num) {

    bool succ = false;

    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof vis);
        if (!vis[i]) succ |= check(i);
    }

    printf("Case #%d: %s\n", num, succ ? "Yes" : "No");
}

int main() {

    freopen("A.in", "r", stdin);

    int case_num;

    scanf("%d", &case_num);

    for (int i = 1; i <= case_num; i++)
    {
        pre_work();
        work(i);

    }

    return 0;
}
