#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

const int X = 1;
const int O = 2;
const int T = 3;

int check (int i, int j, int di, int dj, const vector <string> &v) {
  int cnt[4] = {0, 0, 0, 0};
  int res = 0;
  for (int d = 1; d <= 4; d++) {
    if (i >= 4 || j >= 4) {
      break;
    }
    if (i < 0 || j < 0) {
      break;
    }
    if (v[i][j] == 'T') {
      cnt[T]++;
    }
    if (v[i][j] == 'X') {
      cnt[X]++;
    }
    if (v[i][j] == 'O') {
      cnt[O]++;
    }
    if (d == 4) {
      if (cnt[X] == 4 || (cnt[X] == 3 && cnt[T] == 1)) {
        res |= X;
      }
      if (cnt[O] == 4 || (cnt[O] == 3 && cnt[T] == 1)) {
        res |= O;
      }
    }
    i += di;
    j += dj;
  }
  return res;
}

void solve() {
  vector <string> v(4);
  for (int i = 0; i < 4; i++) {
    cin >> v[i];
  }
  bool ended = true;
  int mask = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (v[i][j] == '.') {
        ended = false;
      }
      mask |= check (i, j, 0, 1, v);
      mask |= check (i, j, 1, 1, v);
      mask |= check (i, j, 1, -1, v);
      mask |= check (i, j, 1, 0, v);
    }
  }
  assert (mask != (O | X));
  if (mask & X) {
    printf ("X won\n");
    return;
  }
  if (mask & O) {
    printf ("O won\n");
    return;
  }
  if (ended) {
    printf ("Draw\n");
    return;
  }
  printf ("Game has not completed\n");
}
int main (void) {
  int tn;
  scanf ("%d", &tn);
  for (int ti = 1; ti <= tn; ti++) {
    printf ("Case #%d: ", ti);
    solve();
  }
  return 0;
}
