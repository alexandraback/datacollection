#include <iostream>
#include <vector>

using namespace std;

int R, C, M;

int DP[100][100][100];
int MO[100][100][100];

bool solve(int row, int prevlen, int left) {
  if (left < 0) {
    return false;
  }
  if (row == R) {
    return left == 0;
  }
  auto& ans = DP[row][prevlen][left];
  if (ans != -1) {
    return ans == 1;
  }
  for (int newlen = 0; newlen <= prevlen; newlen++) {
    if (newlen == 1 && C != 1)
      continue;
    if (solve(row + 1, newlen, left - prevlen)) {
      ans = 1;
      MO[row][prevlen][left] = newlen;
      return true;
    }
  }
  ans = 0;
  return false;
}

int main(int argc, char* argv[]) {
  int T;
  cin >> T;
  for (int c = 1; c <= T; c++) {
    memset(DP, -1, sizeof(DP));
    cout << "Case #" << c << ":" << endl;
    cin >> R >> C >> M;

    int empty = R * C - M;
    if (empty == 1) {
      cout << "c";
      for (int i = 1; i < C; i++)
        cout << "*";
      cout << endl;
      for (int r = 1; r < R; r++) {
        for (int i = 0; i < C; i++) {
          cout << "*";
        }
        cout << endl;
      }
      continue;
    }

    bool found = false;
    for (int len = 1; len <= C; len++) {
      if (len == 1 && C != 1)
        continue;
      if (solve(1, len, empty - len)) {
        found = true;

        int prevlen = len;
        int left = empty - len;
        cout << "c";
        for (int i = 1; i < len; i++)
          cout << ".";
        for (int i = len; i < C; i++)
          cout << "*";
        cout << endl;

        for (int row = 1; row < R; row++) {
          for (int i = 0; i < len; i++)
            cout << ".";
          for (int i = len; i < C; i++)
            cout << "*";
          cout << endl;
          int newlen = MO[row][len][left];
          left -= len;
          len = newlen;
        }
        found = true;
        break;
      }
    }
    if (!found) {
      cout << "Impossible" << endl;
    }
  }
}
