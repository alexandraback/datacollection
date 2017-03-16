#include <cstdio>

using namespace std;

#define MAX 8

void input(void);
void solve(void);
bool isWon(char player);
bool isFull(void);

int n;
char grid[MAX][MAX];
int case_cnt = 1;

int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    input();
    solve();
  }
  return 0;
}

void input(void) {
  n = 4;
  for (int i = 0; i < n; i++) scanf(" %s", &grid[i][0]);
}

void solve(void) {
  if (isWon('X')) {
    printf("Case #%d: X won\n", case_cnt++);
  } else if (isWon('O')) {
    printf("Case #%d: O won\n", case_cnt++);
  } else if (isFull()) {
    printf("Case #%d: Draw\n", case_cnt++);
  } else {
    printf("Case #%d: Game has not completed\n", case_cnt++);
  }
}

bool isWon(char player) {
  for (int i = 0; i < n; i++) {
    bool good = true;
    for (int j = 0; j < n; j++) {
      if (!(grid[i][j] == player || grid[i][j] == 'T')) good = false;
    }
    if (good) return true;
  }

  for (int j = 0; j < n; j++) {
    bool good = true;
    for (int i = 0; i < n; i++) {
      if (!(grid[i][j] == player || grid[i][j] == 'T')) good = false;
    }
    if (good) return true;
  }

  {
    bool good = true;
    for (int i = 0; i < n; i++) {
      if (!(grid[i][i] == player || grid[i][i] == 'T')) good = false;
    }
    if (good) return true;
  }

  {
    bool good = true;
    for (int i = 0; i < n; i++) {
      if (!(grid[i][n - i - 1] == player || grid[i][n - i - 1] == 'T')) good = false;
    }
    if (good) return true;
  }

  return false;
}

bool isFull(void) {
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
    if (grid[i][j] == '.') return false;
  }
  return true;
}

