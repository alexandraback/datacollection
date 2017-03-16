#include <bits/stdc++.h>

using namespace std;

int mat[55][55], n, fila[55];
long long m;
long long paths[55], outdeg[55], outdeg_aux[55];

long long num_paths() {
  memcpy(outdeg_aux, outdeg, sizeof outdeg);
  memset(paths, 0, sizeof paths);
  int start = 0, end = 0;
  
  fila[end++] = n - 1;
  paths[n - 1] = 1;

  while (start < end) {
    int u = fila[start++];
    for (int i = 0; i < n; ++i) {
      if (mat[i][u] == 1) {
        paths[i] += paths[u];
        --outdeg_aux[i];
        if (outdeg_aux[i] == 0) fila[end++] = i;
      }
    }
  }
  return paths[0];
}

bool go(int at) {
  if (at == n - 1) {
    return num_paths() == m;
  }
  int lim = n - 1 - at;
  for (int mask = 0, fim = 1 << n; mask < fim; ++mask) {
    for (int i = at + 1; i < n; ++i) {
      int x = i; // - (at + 1);
      if ((mask >> x) & 1) {
        ++outdeg[i];
        mat[at][i] = 1;
      }
    }
    if (go(at + 1)) return true;
    for (int i = at + 1; i < n; ++i) {
      int x = i; // - (at + 1);
      if ((mask >> x) & 1) {
        --outdeg[i];
        mat[at][i] = 0;
      }
    }
  }
  return false;
}

int main() {
  int nt; scanf("%d", &nt);
  for (int caso = 1; caso <= nt; ++caso) {
    memset(mat, 0, sizeof mat);
    memset(outdeg, 0, sizeof outdeg);
    scanf("%d %lld", &n, &m);
    bool ok = go(0);
    printf("Case #%d: %s\n", caso, ok ? "POSSIBLE" : "IMPOSSIBLE");
    if (ok) {
      for (int i = 0; i < n; ++i, puts("")) {
        for (int j = 0; j < n; ++j) {
          printf("%d", mat[i][j]);
        }
      }
    }

    cerr << "done " << caso << endl;
  }
  return 0;
}