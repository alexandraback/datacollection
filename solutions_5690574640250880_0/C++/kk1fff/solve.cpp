#include <iostream>

using namespace std;

template<size_t N>
bool mime(int r, int c, int R, int C, char buf[N][N]) {
  if (r < 0) return false;
  if (r >= R) return false;
  if (c < 0) return false;
  if (c >= C) return false;
  return buf[r][c] == '*';
}

template<size_t N>
void visit(int r, int c, int R, int C, char buf[N][N]) {
  if (r < 0) return;
  if (r >= R) return;
  if (c < 0) return;
  if (c >= C) return;
  if (buf[r][c] == 'c' || buf[r][c] == '.') {
    // can visit.
    buf[r][c] = 'x';

    // we are zero.
    if (mime(r + 1 , c, R, C, buf)) return;
    if (mime(r - 1, c, R, C, buf)) return;
    if (mime(r, c + 1, R, C, buf)) return;
    if (mime(r, c - 1, R, C, buf)) return;
    if (mime(r + 1, c + 1, R, C, buf)) return;
    if (mime(r + 1, c - 1, R, C, buf)) return;
    if (mime(r - 1, c + 1, R, C, buf)) return;
    if (mime(r - 1, c - 1, R, C, buf)) return;
    visit(r + 1, c + 1, R, C, buf);
    visit(r - 1, c - 1, R, C, buf);
    visit(r - 1, c + 1, R, C, buf);
    visit(r + 1, c - 1, R, C, buf);
    visit(r + 1, c, R, C, buf);
    visit(r - 1, c, R, C, buf);
    visit(r, c - 1, R, C, buf);
    visit(r, c + 1, R, C, buf);
  }
}

template<size_t N>
bool verify(int R, int C, int M, char buf[N][N]) {
  int cr = -1, cc = -1;
  int mine = 0;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (buf[i][j] == 'c') {
        cr = i;
        cc = j;
      } else if (buf[i][j] == '*') {
        mine++;
      }
    }
  }

  if ((cr == -1) || (cc == -1)) {
    cout << "no c" << endl;
    return false;
  }

  if (mine != M) {
    cout << "wrong mine, expected: " << M << ", actual: " << mine;
    return false;
  }

  // start from c
  char b[N][N];
  bool ret = true;
  memcpy((char**)b, (char**)buf, sizeof(char) * N * N);
  visit(cr, cc, R, C, b);
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cout << b[i][j];
      if (b[i][j] == '.') {
        cout << "not visited" << endl;
        ret = false;
      }
    }
    cout << endl;
  }  
  return ret;
}

template<size_t N>
void full_dot(int R, int C, char buf[N][N]) {
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      buf[i][j] = '.';
    }
  }
}

template<size_t N>
void full_star(int R, int C, char buf[N][N]) {
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      buf[i][j] = '*';
    }
  }
}

template<size_t N>
bool play(int R, int C, int M, char buf[N][N]) {
  int S = R * C - M; // Space

  if (M == 0) {
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        buf[i][j] = '.';
      }
    }
    buf[0][0] = 'c';
    return true;
  }

  if (S == 1) {
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        buf[i][j] = '*';
      }
    }
    buf[0][0] = 'c';
    return true;
  }

  if (S == 2) {
    if (C != 1) return false;
    // from now, C = 1, S == 2
    buf[0][0] = 'c';
    buf[1][0] = '.';
    for (int i = 2; i < R; ++i) {
      buf[i][0] = '*';
    }
    return true;
  }

  // from now, S > 2, M >= 1
  if (C == 1) {
    // c 0
    // . 1 -> S - 1
    // .
    // * S -> R - 1
    // *
    buf[0][0] = 'c';
    for (int i = 1; i < S; ++i) {
      buf[i][0] = '.';
    }
    for (int i = S; i < R; ++i) {
      buf[i][0] = '*';
    }
    return true;
  }

  if (R == 1) return false; // don't handle for now.
  // from now, S > 2, C > 2, R > 2
  
  if (C == 2) {
    if (S % 2) return false;

    // from now, C = 2, R >= 2, S >= 4, M > 0

    // c. 0 -> S/2-1
    // ..
    // ** S/2 -> R-1
    // **
    for (int j = 0; j < C; ++j) {
      for (int i = 0; i < S/2; ++i) {
        buf[i][j] = '.';
      }

      for (int i = S/2; i < R; ++i) {
        buf[i][j] = '*';
      }
    }
    buf[0][0] = 'c';
    return true;
  }

  // from now, C > 2, R >= 2, S > 2, M > 0
  if (R == 2) return false; // don't handle for now.

  // from now, C > 2, R > 2, S > 2, M > 0
  // buf[H][W]
  for (int W = 2; W <= C; ++W) {
    if (S % W == 0) {
      int H = S / W;
      if (H > R) continue;
      if (H == 1) continue;

      // ok, we got a rect
      full_star(R, C, buf);
      for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
          buf[i][j] = '.';
        }
      }
      buf[0][0] = 'c';
      return true;
    }
  }

  for (int W = 2; W <= C; ++W) {
    int H = S / W;
    // cout << "W = " << W << " H = " << H << endl;
    if ((H > 1) && (S % W > 1) && (H < R)) {
      full_star(R, C, buf);
      for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
          buf[i][j] = '.';
        }
      }
      for (int j = 0; j < S % W; ++j) {
        buf[H][j] = '.';
      }
      buf[0][0] = 'c';
      return true;
    }
  }

  int mr = R - 1, mc = C - 1, m = M;
  full_dot(R, C, buf);
  while (m > 0) {
    if (mr <= 1) {
      mr = R - 1;
      mc--;
    }
    if (mc <= 1) {
      break;
    }
    buf[mr][mc] = '*';
    m--;
    mr--;
  }

  buf[0][0] = 'c';
  if (m > 0) {
    int s = (R - 2) * 2 - m;
    if (s % 2) return false;
    for (int i = 2 + s/2; i < R; ++i) {
      for (int j = 0; j < 2; ++j) {
        buf[i][j] = '*';
      }
    }
    return true;
  }
  return true;
}

void run(istream& in, int T) {
  int R, C, M;
  char buf[50][50]; // buf[R][C]
  in >> R >> C >> M;

  cout << "Case #" << T << ": " << endl;
  if (!play(R, C, M, buf)) {
    char buf2[50][50];
    if (play(C, R, M, buf2)) {
      // flip
      for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
          buf[i][j] = buf2[j][i];
        }
      }
    } else {
      cout << "Impossible" << endl;
      return;
    }
  }
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      cout << buf[i][j];
    }
    cout << endl;
  }

  // if (!verify(R, C, M, buf)) {
  //   abort();
  // }
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    run(cin, i + 1);
  }
}
