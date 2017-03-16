#include <vector>
#include <iostream>
#include <cassert>
#include <map>

using namespace std;


bool has(size_t b, int r, int c, int i, int j) {
  return b & (1 << (i * c + j));
}

int count(size_t b, int r, int c) {
  int res = 0;
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      if (has(b, r, c, i, j))
        res++;
  return res;
}

void mark(size_t& b, int r, int c, int i, int j) {
  b |= (1 << (i * c + j));
}

bool check(int r, int c, int i, int j) {
  return i >= 0 && j >= 0 && i < r && j < c;
}

int around(size_t b, int r, int c, int i, int j) {
  int cnt = 0;
  for (int ii = i - 1; ii <= i + 1; ii++)
    for (int jj = j - 1; jj <= j + 1; jj++)
      if ((ii != i || jj != j) && check(r, c, ii, jj) && has(b, r, c, ii, jj))
        cnt++;
  return cnt;
}

struct pos { int i; int j; };

struct solution { bool can; size_t b; int i; int j; };

solution one(size_t b, int r, int c) {
  vector<pos> q(r * c);

  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++) {
      if (has(b, r, c, i, j))
        continue;
      size_t vis = 0;
      int h = 0; int t = 0;
      
      q[t++] = {i, j};
      mark(vis, r, c, i, j);
      
      while (h != t) {
        auto cur = q[h++];
        assert(!has(b, r, c, cur.i, cur.j));
        if (around(b, r, c, cur.i, cur.j) != 0)
          continue;
        for (int ii = cur.i - 1; ii <= cur.i + 1; ii++)
          for (int jj = cur.j - 1; jj <= cur.j + 1; jj++)
            if (check(r, c, ii, jj) && !has(vis, r, c, ii, jj)) {
              q[t++] = {ii, jj};
              mark(vis, r, c, ii, jj);
            }
      }
      bool good = true;
      for (int ci = 0; ci < r; ci++)
        for (int cj = 0; cj < c; cj++)
          if (!has(b, r, c, ci, cj) && !has(vis, r, c, ci, cj))
            good = false;
      if (good)
        return {true, b, i, j};
    }
  return {false, 0, 0, 0};
}

solution res[5][5][26];

int main() {
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++) {
      int const r = i + 1; int const c = j + 1;
      cerr << r << " " << c << '\n';
      for (size_t b = 0; b < (1 << (r * c)); b++) 
        if (!res[i][j][count(b, r, c)].can) {
          res[i][j][count(b, r, c)] = one(b, r, c);
        }
    }
  int tests = 0;
  cin >> tests;
  for (int t = 0; t < tests; t++) {
    cout << "Case #" << (t + 1) << ":\n";
    int r, c, m;
    cin >> r >> c >> m;
    if (res[r - 1][c - 1][m].can) {
      auto s = res[r - 1][c - 1][m];
      assert(s.can);
      for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
          if (i == s.i && j == s.j)
            cout << 'c';
          else if (has(s.b, r, c, i, j))
            cout << '*';
          else
            cout << '.';
        }
        cout << '\n';
      }
    } else {
      cout << "Impossible\n";
    }
  }
}
