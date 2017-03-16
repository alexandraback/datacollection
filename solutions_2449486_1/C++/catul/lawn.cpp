#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

unsigned int a[101][101];

void display(int field[101][101], int N, int M) {
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

    for (i = 0; i < N; i++)
      for (j = 0; j < M; j++) {
        // for each element of the lawn, there has to be one direction either horizontal
        // or vertical, where the grass has a value lower or equal than this spot.
        n = a[i][j];
        for (k = 0; k < M; k++)
          if (a[i][k] > n)
            goto try_vertical;
        // ok on the horizontal !
        continue;
try_vertical:
        for (k = 0; k < N; k++)
          if (a[k][j] > n)
            goto impossible;
      }

    printf("Case #%d: YES\n", num++);
    continue;
impossible:
    printf("Case #%d: NO\n", num++);
  }
}
