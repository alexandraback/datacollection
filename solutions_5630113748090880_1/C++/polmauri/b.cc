#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> Vi;
typedef vector<Vi> Mi;

int N;
Mi lines;
Vi used;
Vi rows;
Vi cols;

bool check_cols() {
  int k = 0;
  for (int i = 0; i < N; ++i) {
    while (k < 2*N - 1) {
      if (used[k]) {
        ++k;
        continue;
      }
      bool ok = true;
      for (int j = 0; j < N; ++j) {
        if (rows[j] != -1 and lines[rows[j]][i] != lines[k][j]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        break;
      }
      ++k;
    }
    if (k == 2*N - 1) {
      return false;
    }
    cols[i] = k;
    ++k;
  }
  return true;
}

bool bt(int r, int k, bool can_skip) {
  if (r == N) {
    return check_cols();
  }
  if (k < 2*N - 1) {
    for (int i = k; i < 2*N - 1; ++i) {
      rows[r] = i;
      used[i] = 1;
      if (check_cols() and bt(r + 1, i + 1, can_skip)) {
        return true;
      }
      used[i] = 0;
    }
    rows[r] = -1;
  }
  if (can_skip && bt(r + 1, k, false)) {
    return true;
  }
  return false;
}

int main() {
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    cin >> N;
    lines = Mi(2*N - 1, Vi(N));
    for (int i = 0; i < 2*N - 1; ++i) {
      for (int j = 0; j < N; ++j) {
        cin >> lines[i][j];
      }
    }
    sort(lines.begin(), lines.end());
    used = Vi(2*N - 1, 0);
    rows = cols = Vi(N, -1);
    if (not bt(0, 0, true)) {
      cerr << "ERROR CASE " << cas << endl;
    }
    int p = -1;
    for (int i = 0; i < N; ++i) {
      if (rows[i] == -1) {
        p = i;
      }
    }
    cout << "Case #" << cas << ":";
    for (int i = 0; i < N; ++i) {
      cout << " " << lines[cols[i]][p];
    }
    cout << endl;
  }
}
