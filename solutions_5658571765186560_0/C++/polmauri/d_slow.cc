#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

typedef vector<string> Vs;
typedef vector<Vs> Ms;
typedef vector<Ms> MMs;

const int diri[4] = {-1, 0, 1, 0};
const int dirj[4] = {0, 1, 0, -1};

MMs nominoes;

Vs rotate(Vs v) {
  int r = v.size();
  int c = v[0].size();
  Vs n(c, string(r, '.'));
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      n[c - j - 1][i] = v[i][j];
  return n;
}

Vs reflect(Vs v) {
  int r = v.size();
  int c = v[0].size();
  Vs n(r, string(c, '.'));
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      n[i][j] = v[i][c - j - 1];
  return n;
}

Vs normalize(Vs v) {
  int r = v.size();
  int c = v[0].size();
  int i_min = r;
  int i_max = 0;
  int j_min = c;
  int j_max = 0;
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      if (v[i][j] != '.') {
        i_min = min(i_min, i);
        i_max = max(i_max, i);
        j_min = min(j_min, j);
        j_max = max(j_max, j);
      }
  Vs m(i_max - i_min + 1, string(j_max - j_min + 1, '.'));
  for (int i = i_min; i <= i_max; ++i)
    for (int j = j_min; j <= j_max; ++j)
      m[i - i_min][j - j_min] = v[i][j];
  Vs res = m;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 2; ++j) {
      if (m < res) {
        res = m;
      }
      m = reflect(m);
    }
    m = rotate(m);
  }
  return res;
}

bool has_neighbors(int i, int j, Vs v) {
  int r = v.size();
  int c = v[0].size();
  for (int k = 0; k < 4; ++k) {
    int ii = i + diri[k];
    int jj = j + dirj[k];
    if (0 <= ii and ii < r and 0 <= jj and jj < c and v[ii][jj] != '.') {
      return true;
    }
  }
  return false;
}

Ms generate_children(Vs v) {
  int r = v.size();
  int c = v[0].size();
  Vs n(r + 2, string(c + 2, '.'));
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      n[i + 1][j + 1] = v[i][j];
  set<Vs> ch;
  for (int i = 0; i < r + 2; ++i)
    for (int j = 0; j < c + 2; ++j) {
      if (n[i][j] == '.' and has_neighbors(i, j, n)) {
        n[i][j] = '#';
        ch.insert(normalize(n));
        n[i][j] = '.';
      }
    }
  return Ms(ch.begin(), ch.end());
}

void compute_nominoes() {
  nominoes = MMs(8);
  nominoes[1] = Ms(1, Vs(1, "#"));
  for (int k = 2; k <= 7; ++k) {
    set<Vs> s;
    for (int i = 0; i < nominoes[k - 1].size(); ++i) {
      Ms ch = generate_children(nominoes[k - 1][i]);
      for (int j = 0; j < ch.size(); ++j) {
        s.insert(ch[j]);
      }
    }
    nominoes[k] = Ms(s.begin(), s.end());
  }
}

void print_nominoes(bool full = false) {
  for (int i = 1; i <= 7; ++i) {
    cout << i << " " << nominoes[i].size() << endl;
    if (full) {
      for (int j = 0; j < nominoes[i].size(); ++j) {
        cout << "------" << endl;
        for (int k = 0; k < nominoes[i][j].size(); ++k)
          cout << nominoes[i][j][k] << endl;
      }
    }
  }
}

int dfs(int i, int j, Vs& v) {
  int r = v.size();
  int c = v[0].size();
  int res = 1;
  v[i][j] = '#';
  for (int k = 0; k < 4; ++k) {
    int ii = i + diri[k];
    int jj = j + dirj[k];
    if (0 <= ii and ii < r and 0 <= jj and jj < c and v[ii][jj] == '.') {
      res += dfs(ii, jj, v);
    }
  }
  return res;
}

bool check_components(Vs v, int m) {
  int r = v.size();
  int c = v[0].size();
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      if (v[i][j] == '.') {
        int s = dfs(i, j, v);
        if (s%m != 0) {
          return false;
        }
      }
  return true;
}

int count_blocks(Vs v) {
  int r = v.size();
  int c = v[0].size();
  int res = 0;
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      if (v[i][j] != '.') {
        ++res;
      }
  return res;
}

bool can_complete(Vs v, int rows, int cols) {
  int r = v.size();
  int c = v[0].size();
  int x = count_blocks(v);
  for (int i = 0; i + r <= rows; ++i)
    for (int j = 0; j + c <= cols; ++j) {
      Vs m(rows, string(cols, '.'));
      for (int ii = 0; ii < r; ++ii)
        for (int jj = 0; jj < c; ++jj)
          m[i + ii][j + jj] = v[ii][jj];
      if (check_components(m, x)) {
        return true;
      }
    }
  return false;
}

bool solution(int x, int r, int c) {
  if (x >= 7) return false;
  for (int i = 0; i < nominoes[x].size(); ++i)
    if (not can_complete(nominoes[x][i], r, c) and
        not can_complete(nominoes[x][i], c, r)) {
      return false;
    }
  return true;
}

int main() {
  compute_nominoes();
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    int x, r, c;
    cin >> x >> r >> c;
    cout << "Case #" << cas << ": "
         << (solution(x, r, c) ? "GABRIEL" : "RICHARD") << endl;
  }
}
