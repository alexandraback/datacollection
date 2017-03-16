#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void run(int t) {
  cout << "Case #" << t << ":\n";
  int R, C, M;
  cin >> R >> C >> M;
  int empty = R * C - M;
  vector<vector<char>> grid(R, vector<char>(C, '*'));
  if (R == 1 || C == 1 || empty == 1) {
    int e = 0;
    for (int r = 0; r < R; r++) {
      for (int c = 0; c < C; c++) {
        if (e < empty) {
          grid[r][c] = '.';
        }
        e++;
      }
    }
  } else if (empty < 4) {
    cout << "Impossible\n";
    return;
  } else if (R == 2 || C == 2 || empty < 9) {
    if (empty % 2 == 1) {
      cout << "Impossible\n";
      return;
    }
    grid[0][1] = '.';
    grid[1][0] = '.';
    grid[1][1] = '.';
    int remaining = empty - 4;
    for (int c = 2; c < C; c++) {
      for (int r = 0; r < 2; r++) {
        if (remaining > 0) {
          grid[r][c] = '.';
          remaining--;
        }
      }
    }
    for (int r = 2; r < R; r++) {
      for (int c = 0; c < C; c++) {
        if (remaining > 0) {
          grid[r][c] = '.';
          remaining--;
        }
      }
    }
  } else {
    int min_d = R * C;
    int I, J;
    for (int i = 3; i <= ceil(sqrt(empty)); i++) {
      int j = empty / i;
      if ((i > R || j > C) && (i > C || j > R)) continue;
      if (i * j == empty) {
        I = i; J = j; break;
      }
      j++;
      if ((i > R || j > C) && (i > C || j > R)) continue;
      int d = i * j - empty;
      if (d < min_d) {
        I = i; J = j; min_d = d;
      }
    }
    if (I > R) swap(I, J);
    if ((I - 1) * J - empty == 1 && I * (J - 1) - empty == 1) {
      cout << "Impossible\n";
      return;
    }
    for (int r = 0; r < I; r++) {
      for (int c = 0; c < J; c++) {
        grid[r][c] = '.';
      }
    }
    int add = I * J - empty;
    if (add + 1 == I + J - 1) {
      // this should never happen
      cout << "Impossible\n";
      return;
    }
    for (int i = I - 1; i >= 2; i--) {
      if (add > 0) {
        grid[i][J-1] = '*';
        add--;
      }
    }
    for (int j = J - 2; j >= 2; j--) {
      if (add > 0) {
        grid[I-1][j] = '*';
        add--;
      }
    }
  }

  grid[0][0] = 'c';
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      cout << grid[r][c];
    }
    cout << "\n";
  }
}

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    run(t);
  }
}
