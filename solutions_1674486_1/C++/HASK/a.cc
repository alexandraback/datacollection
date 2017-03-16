
#include <cstdio>
#include <cstring>

int adj[1001][10];
int adj_l[1001];

int visited[1001];

int search (int s) {

  for (int i = 0; i < adj_l[s]; i++) {
    int v = adj[s][i];

    if (visited[v]) return 1;

    visited[v] = 1;
    int r = search(v);
    if (r > 0) return r;
  }

  return 0;
}

int solve () {

  int in_degree[1001];
  
  memset(adj_l, 0, sizeof(adj_l));
  memset(in_degree, 0, sizeof(in_degree));

  int N;
  scanf ("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &adj_l[i]);

    for (int j = 0; j < adj_l[i]; j++) {
      int v;
      scanf("%d", &v);
      v--;

      adj[i][j] = v;
      in_degree[v]++;
    }
  }

  for (int i = 0; i < N; i++) {
    if (in_degree[i] == 0) {
      memset(visited, 0, sizeof(visited));
      visited[i] = 1;

      int r = search(i);
      if (r > 0) {
        printf("Yes\n");
        return 0;}
    }
  }

  printf("No\n");
  return 0;
}

int main() {

  int T;
  scanf("%d", &T);

  for (int t = 1; t <= T; t++) {
    printf("Case #%d: ", t);
    solve();
  }

  return 0;
}
