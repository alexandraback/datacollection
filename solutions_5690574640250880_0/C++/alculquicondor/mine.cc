#include <iostream>
#include <cstring>

using namespace std;

char T[52][52];

int R, C, M;
void print() {
  T[0][0] = 'c';
  for (int i = 0; i < R; ++i) {
    T[i][C] = 0;
    cout << T[i] << endl;
  }
}

void paint(int r, int c) {
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      T[i][j] = '.';
}

bool gorow(int r, int c, int q, bool p = false) {
  int x, prev = c - 1;
  for ( ; r < R; ++r) {
    x = min(q, prev);
    if (q - x == 1)
      --x;
    if (x == 1)
      return false;
    if (p) {
      for (int i = 0; i < x; ++i)
        T[r][i] = '.';
    }
    q -= x;
    prev = x;
  }
  return q == 0;
}
bool gocol(int r, int c, int q, bool p = false) {
  int x, prev = r - 1;
  for ( ; c < C; ++c) {
    x = min(q, prev);
    if (q - x == 1)
      --x;
    if (x == 1)
      return false;
    if (p) {
      for (int i = 0; i < x; ++i)
        T[i][c] = '.';
    }
    q -= x;
    prev = x;
  }
  return q == 0;
}

bool solve() {
  int q;
  for (int r = 2; r <= R; ++r)
    for (int c = 2; c <= C; ++c) {
      q = M - r * c;
      if (q < 0)
        continue;
      if (gorow(r, c, q)) {
        //cerr << "# " << r << " " << c << ": " << q << endl;
        paint(r, c);
        gorow(r, c, q, true);
        return true;
      }
      if (gocol(r, c, q)) {
        //cerr << "@ " << r << " " << c << ": " << q << endl;
        paint(r, c);
        gocol(r, c, q, true);
        return true;
      }
    }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  int tc;
  cin >> tc;
  for (int caso = 1; caso <= tc; ++caso) {
    cout << "Case #" << caso << ":" << endl;
    cin >> R >> C >> M;
    M = R * C - M;
    memset(T, '*', sizeof T);
    if (R == 1) {
      for (int i = 0; i < M; ++i)
        T[0][i] = '.';
      print();
    } else if (C == 1) {
      for (int i = 0; i < M; ++i)
        T[i][0] = '.';
      print();
    } else if (M == 1) {
      print();
    } else {
      if (solve())
        print();
      else
        cout << "Impossible" << endl;
    }
  }
}

