#include <stdio.h>

int main() {
  int T;
  char map[50][50];
  scanf("%d", &T);
  for (int N = 1; N <= T; ++N) {
    int r, c, m;
    printf("Case #%d:\n", N);
    scanf("%d%d%d", &r, &c, &m);
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        map[i][j] = '.';
      }
    }
    map[r-1][c-1] = 'c';

    if (m == r*c - 1) {
      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
          map[i][j] = '*';
        }
      }
      m = 0;
      map[r-1][c-1] = 'c';
    } else if (r == 1) {
      for (int j = 0; j < c - 1 && m; ++j) {
        --m;
        map[0][j] = '*';
      }
    } else if (c == 1) {
      for (int i = 0; i < r - 1 && m; ++i) {
        --m;
        map[i][0] = '*';
      }
    } else {
      int i = 0, j = 0;
      int flag = 0;
      // printf("m = %d\n", m);
      for (i = 0 ; i < r - 2 && m; ++i) {
        for (j = 0; j < c - 2 && m; ++j) {
          --m;
          map[i][j] = '*';
        }
      }
      if (m % 2 == 1 && r > 2 && c > 2) {
        ++m;
        map[r-3][c-3] = '.';
        flag = 1;
      }
      // printf("m = %d\n", m);
      i = 0;
      while (m >= 2 && i < r - 2 - flag) {
        map[i][c-2] = map[i][c-1] = '*';
        ++i;
        m -= 2;
      }
      // printf("m = %d\n", m);
      i = 0;
      while(m >= 2 && i < c - 2 - flag) {
        map[r-2][i] = map[r-1][i] = '*';
        ++i;
        m -= 2;
      }
      // printf("m = %d\n", m);
    }
    if (m == 0) {
      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
          printf("%c", map[i][j]);
        }
        printf("\n");
      }
    } else {
      printf("Impossible\n");
    }
  }
  return 0;
}
