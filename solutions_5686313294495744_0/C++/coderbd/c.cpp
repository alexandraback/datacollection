#include <iostream>
#include <string>
#include <map>

using namespace std;

string first_word[1000], second_word[1000];
map<string, int> first_map, second_map;
int first_cnt, second_cnt;

typedef struct Edge * edge_pointer;

struct Edge {
    int u, v, c;
    edge_pointer rev, next;
} edge[300000];

int level[3000], queue[300000], added[3000];
edge_pointer head[3000];

int source, sink;
edge_pointer edge_tail;

void init() {
    source = 0;
    sink = 2888;
    edge_tail = edge;
    for (int i = source; i <= sink; i++)
        head[i] = NULL;
}

void addEdge(int u, int v, int c) {
    edge_pointer edge_ptr1;
    edge_pointer edge_ptr2;

    edge_ptr1 = edge_tail++;
    edge_ptr2 = edge_tail++;

    edge_ptr1->u = u;
    edge_ptr1->v = v;
    edge_ptr1->c = c;
    edge_ptr1->rev = edge_ptr2;
    edge_ptr1->next = head[u];
    head[u] = edge_ptr1;

    edge_ptr2->u = v;
    edge_ptr2->v = u;
    edge_ptr2->c = 0;
    edge_ptr2->rev = edge_ptr1;
    edge_ptr2->next = head[v];
    head[v] = edge_ptr2;
}

bool BFS() {
    edge_pointer edge_ptr;
    int node, *qf, *qb;

    memset(level, 0xff, sizeof level);
    level[source] = 0;
    qf = qb = queue;
    *qb++ = source;

    while (qf < qb) {
        node = *qf++;
        for (edge_ptr = head[node]; edge_ptr != NULL; edge_ptr = edge_ptr->next)
            if (level[edge_ptr->v] == -1 && edge_ptr->c > 0) {
                level[edge_ptr->v] = level[node] + 1;
                if (edge_ptr->v == sink)
                    return true;
                *qb++ = edge_ptr->v;
            }
    }

    return false;
}

int DFS(int node, int minCap) {
    int flow;
    edge_pointer edge_ptr;

    if (node == sink)
        return minCap;

    for (edge_ptr = head[node]; edge_ptr != NULL; edge_ptr = edge_ptr->next)
        if (edge_ptr->c > 0 && level[edge_ptr->v] == level[node] + 1)
            if (flow = DFS(edge_ptr->v, min(minCap, edge_ptr->c))) {
                edge_ptr->c -= flow;
                edge_ptr->rev->c += flow;
                return flow;
            }

    level[node] = -1;

    return 0;
}

int dinic() {
    int f, flow;

    flow = 0;
    while (BFS())
        while (f = DFS(source, 0x7fffffff))
            flow += f;

    return flow;
}

int main() {
    int first_id, second_id;
    int n, t, ans;

    ios::sync_with_stdio(0);
    cin >> t;
    for (int case_no = 1; case_no <= t; case_no++) {
        cin >> n;
        first_map.clear();
        second_map.clear();
        first_cnt = second_cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> first_word[i] >> second_word[i];
            first_map[first_word[i]] = ++first_cnt;
            second_map[second_word[i]] = ++second_cnt;
        }

        init();
        memset(added, 0, sizeof added);
        for (int i = 0; i < n; i++) {
            first_id = first_map[first_word[i]];
            second_id = second_map[second_word[i]] + 1111;
            if (!added[first_id])
                added[first_id] = 1;
            else
                addEdge(source, first_id, 1);
            if (!added[second_id])
                added[second_id] = 1;
            else
                addEdge(second_id, sink, 1);
            addEdge(first_id, second_id, 1);
        }
        ans = dinic();

        cout << "Case #" << case_no << ": " << ans << endl;
    }

    return 0;
}
