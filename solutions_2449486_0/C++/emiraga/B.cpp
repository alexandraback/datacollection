#include <iostream>
using namespace std;

int N, M;
int B[110][110];

int max_row(int r) {
  int m = 0;
  for (int j=0;j<M;j++) {
    m = max(m, B[r][j]);
  }
  return m;
}

int max_col(int c) {
  int m = 0;
  for (int i=0;i<N;i++) {
    m = max(m, B[i][c]);
  }
  return m;
}


bool isbad(int x, int y) {
  if (max_row(x) > B[x][y] && max_col(y) > B[x][y]) {
    return true;
  }
  return false;
}


int main() {
  int T;scanf("%d", &T);
  for (int cs=1; cs<= T; cs++) {
    printf("Case #%d: ", cs);

    scanf("%d %d", &N, &M);
    for (int i=0;i<N;i++) {
      for (int j=0; j<M;j++) {
        scanf("%d", &B[i][j]);
      }
    }
    bool bad = false;

    for (int i=0;i<N;i++) {
      for (int j=0; j<M;j++) {
        if (isbad(i, j)) {
          bad = true;
        }
      }
    }

    if (bad) {
      printf("NO\n");
    } else {
      printf("YES\n");
    }
  }
}
