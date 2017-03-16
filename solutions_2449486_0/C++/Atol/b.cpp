
#include<algorithm>
#include<cstring>
#include<cstdio>

#define FOR(A, B) for(int A = 0; A < B; A++)

using namespace std;

#define N 256
int ini[N][N], fim[N][N];
int n,m;

int cortaLinha(int i, int j, int h) {
  FOR(col, m) {
    if(fim[i][col] > h) return 0;
  }
  FOR(col, m) {
    ini[i][col] = min(ini[i][col], h);
  }
  return 1;
}

int cortaCol(int i, int j, int h) {
  FOR(linha, n) {
    if(fim[linha][j] > h) return 0;
  }
  FOR(linha, n) {
    ini[linha][j] = min(ini[linha][j], h);
  }
  return 1;
}

void solve() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
    ini[i][j] = 100;
    scanf("%d", &fim[i][j]);
  }
  for(int h = 1; h <= 100; h++) {
    FOR(i, n) FOR(j, m) {
      if(fim[i][j] == h && ini[i][j] != h) {
        if(cortaLinha(i, j, h)) {}
        else if(cortaCol(i, j, h)) {}
        else {
          printf("NO\n");
          return;
        }
      }
    }
  }

  FOR(i, n) FOR(j, m) {
      if(ini[i][j] != fim[i][j]) {
        printf("NO\n");
        return;
      }
  }
  printf("YES\n");
}

int main() {
  int num_testes;
  scanf("%d", &num_testes);
  for(int t = 1; t <= num_testes; t++) {
    printf("Case #%d: ", t);
    solve();
  }
  return 0;
}
