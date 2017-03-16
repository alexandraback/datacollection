#include <cstdio>
#include <cstring>

struct Edge {
  int u, v, next;
} edge[200000];

int c[1005], head[1005];
int en;
bool flag;

void add_edge(int u, int v) {
  edge[en].u = u;
  edge[en].v = v;
  edge[en].next = head[u];
  head[u] = en++;
}

void DFS(int u) {
  c[u]++;
  if (c[u] == 2) {
    flag = true;
    return;
  }
  for (int id = head[u]; id != -1; id = edge[id].next) {
    int v = edge[id].v;
    if (c[v] < 2)
      DFS(v);
  }
}

int main() {
  int n, m, t, v;
  
  scanf("%d", &t);
  for (int ca = 1; ca <= t; ca++) {
    scanf("%d", &n);
    
    memset(head, 0xff, sizeof head);
    en = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &m);
      while (m--) {
        scanf("%d", &v);
        add_edge(i, v);
      }
    }
    
    flag = false;
    for (int i = 1; i <= n; i++) {
      memset(c, 0, sizeof c);
      DFS(i);
    }
    
    if (flag)
      printf("Case #%d: Yes\n", ca);
    else
      printf("Case #%d: No\n", ca);
  }
  
  return 0;
}
