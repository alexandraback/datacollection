#include <stdio.h>
#include <string.h>

const char sign[3] = {'.', '*', 'c'};
int grid[50][50], R, C, M;
int visited[50][50];
int solved;
int revealed;

void printGrid() {
  int r, c;
  for (r = 0; r < R; r++) {
    for (c = 0; c < C; c++) {
      printf("%c%s", sign[grid[r][c]], c == C - 1 ? "\n" : "");
    }
  }
}

int inRange(int r, int c) {
  return r >= 0 && r < R && c >= 0 && c < C;
}

int countMine(int r, int c) {
  int i, j, count = 0;
  for (i = -1; i <= 1; i++) {
    for (j = -1; j <= 1; j++) {
      if ((i || j) && inRange(r + i, c + j)) {
        count += (grid[r + i][c + j] == 1);
      }
    }
  }
  return count;
}

void fill(int r, int c) {
  if (!inRange(r, c)) {
    return;
  }
  if (visited[r][c]) {
    return;
  }
  visited[r][c] = 1;
  revealed++;
  if (!countMine(r, c)) {
    int i, j;
    for (i = -1; i <= 1; i++) {
      for (j = -1; j <= 1; j++) {
        fill(r + i, c + j);
      }
    }
  }
}

void check() {
  int r, c;
  for (r = 0; r < R; r++) {
    for (c = 0; c < C; c++) {
      if (!grid[r][c]) {
        memset(visited, 0, sizeof(visited));
        revealed = 0;
        fill(r, c);
        if (revealed == R * C - M) {
          solved = 1;
          grid[r][c] = 2;
          printGrid();
          return;
        }
      }
    }
  }
}

int min(int a, int b) {
  return a < b ? a : b;
}

int main() {
  int T, Case = 1;
  scanf("%d", &T);
  while (T--) {
    printf("Case #%d:\n", Case++);
    scanf("%d%d%d", &R, &C, &M);
    solved = 0;
    int useR, useC;
    for (useR = 0; useR < R && !solved; useR++) {
      for (useC = 0; useC < C && !solved; useC++) {
        int fillR, fillC;
        for (fillR = 0; fillR < R && !solved; fillR++) {
          for (fillC = 0; fillC < C && !solved; fillC++) {
            if (fillR * useC + fillC * useR - min(fillR, fillC) * min(fillR, fillC) < M) {
              continue;
            }
            memset(grid, 0, sizeof(grid));
            int r, c, m = M;
            for (r = 0; r <= useR && m; r++) {
              for (c = 0; c <= fillC && m; c++, m--) {
                grid[r][c] = 1;
              }
            }
            for (c = 0; c <= useC && m; c++) {
              for (r = 0; r <= fillR && m; r++) {
                m -= !grid[r][c];
                grid[r][c] = 1;
              }
            }
            if (!m) {
              check();
            }
          }
        }
      }
    }
    if (!solved) {
      puts("Impossible");
    }
  }
  return 0;
}
