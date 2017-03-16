#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

int a[101][101];
int b[11][11];
int f[11][11];

void display(int field[11][11], int N, int M) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++)
      printf("%d ", field[i][j]);
    printf("\n");
  }
  printf("\n");
}

int main() {
  unsigned int T, N, M, num=1;
  unsigned int i,j,k,n;
  for (cin >> T; T--;) {
    cin >> N >> M;
    for (i = 0; i < N; i++)
      for (j = 0; j < M; j++)
        cin >> a[i][j];

    // base field
    for (i = 0; i < 11; i++)
      for (j = 0; j < 11; j++)
        b[i][j] = 2;

    unsigned int max        = N + M   ;
    unsigned int max_combos = 1 << max;
    for (i = 0; i < max_combos; i++) {
      memcpy(f, b, sizeof(f));
      j = i;
      for (k = 0; k < max; k++, j = j >> 1) {
        //printf("j=%x\n",j);
        if ((j & 1) == 0) continue;

        if (k < N) {
          //cout << "clearing line " << k << endl;
          for (n = 0; n < M; n++)
            f[k][n] = 1;
        } else {
          //cout << "clearing col  " << k << endl;
          for (n = 0; n < N; n++)
            f[n][k-N] = 1;
        }

      }

      //display(f, N, M);

      for (j = 0; j < N; j++)
        for (k = 0; k < M; k++)
          if (a[j][k] != f[j][k])
            goto next_combo;

      goto found;

next_combo:;
    }

    printf("Case #%d: NO\n", num++);
    continue;
found:
    printf("Case #%d: YES\n", num++);
  }
}
