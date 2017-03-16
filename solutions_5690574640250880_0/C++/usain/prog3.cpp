#include <iostream>
#include <fstream>
using namespace std;

char a[50][50];

void clean(int r, int c) {
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      a[i][j] = '*';
}

int basic(int r, int c, int s) {
  if (s < 1)
    return -1;

  a[0][0] = 'c';
  s--;
  for (int i = 1; i < r && s > 0; i++) {
    s--;
    a[i][0] = '.';
  }

  for (int i = 1; i < c && s > 0; i++) {
    s--;
    a[0][i] = '.';
  }

  if (s == 0)
    return 0;

  return -1;
}

int put_space(int x, int y, int r, int c) {
  int v = 0;
  if (a[x][y] == '*')
    v++;

  a[x][y] = 0;
  if (x+1 < r) {
    if (a[x+1][y] == '*')
      v++;
    a[x+1][y] = 1;
  }

  if (y+1 < c) {
    if (a[x][y+1] == '*')
      v++;
    a[x][y+1] = 1;
  }

  if (x+1 < r && y+1 < c) {
    if (a[x+1][y+1] == '*')
      v++;
    a[x+1][y+1] = 1;
  }

  return v;
}

int solution(int r, int c) {
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++) {
      if (a[i][j] != '*')
        a[i][j] = '.';
    }

  a[0][0] = 'c';
  return 0;
}

int solve(int r, int c, int m) {
  int s = r * c - m;

  clean(r, c);
  if (r == 1 || c == 1)
    return basic(r, c, s);

  if (s == 1) {
    a[0][0] = 'c';
    return 0;
  }

  if (s < 4)
    return -1;

  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++) {
      s -= put_space(i, j, r, c);
      if (s < 0)
        return -1;

      if (s == 0)
        return solution(r, c);

      if (s == 3 && i == 0 && c > 2 && j > 0) {
        s -= put_space(i+1, 0, r, c);
        s -= put_space(i+1, 1, r, c);
        if (s == 0)
          return solution(r, c);
        else
          return -1;
      }

      if (s == 2 && i > 0 && i+1 < r && j+3 >= c) {
        s -= put_space(i+1, 0, r, c);
        if (s == 0)
          return solution(r, c);
        else
          return -1;
      }
    }

  return -1;
}

int main() {
  ifstream in("C-small-attempt2.in");
  ofstream out("C-small-attempt2.out");

  int tests;
  in >> tests;
  for (int i = 1; i <= tests; i++) {
    int r, c, m;
    in >> r >> c >> m;
    out << "Case #" << i << ":" << endl;
    if (solve(r, c, m) != 0)
      out << "Impossible" << endl;
    else {
      for (int j = 0; j < r; j++) {
        for (int k = 0; k < c; k++)
          out << a[j][k];
        out << endl;
      }
    }
  }

  in.close();
  out.close();

  return 0;
}
