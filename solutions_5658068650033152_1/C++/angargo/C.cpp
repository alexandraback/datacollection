#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};

int ddi[] = {1, -1, 1, -1};
int ddj[] = {1, -1, -1, 1};

int h, w, k;
VVI m;

inline bool ok(int i, int j) {
  return i >= 0 and j >= 0 and i < h and j < w;
}

bool find1() {
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (m[i][j]) {
        for (int d1 = 0; d1 < 2; ++d1) {
          for (int d2 = 2; d2 < 4; ++d2) {
            if (ok(i + di[d1], j + dj[d1]) and ok(i + di[d2], j + dj[d2])) {
              if (m[i + di[d1]][j + dj[d1]] and m[i + di[d2]][j + dj[d2]]) {
                m[i][j] = 0;
                return true;
              }
            }
          }
        }
      }
    }
  }
  return false;
}

bool find2() {
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (m[i][j]) {
        for (int d1 = 0; d1 < 2; ++d1) {
          for (int d2 = 2; d2 < 4; ++d2) {
            if (ok(i + ddi[d1], j + ddj[d1]) and ok(i + ddi[d2], j + ddj[d2])) {
              if (m[i + ddi[d1]][j + ddj[d1]] and m[i + ddi[d2]][j + ddj[d2]]) {
                m[i][j] = 0;
                m[i + (ddi[d1] + ddi[d2]) / 2][j + (ddj[d1] + ddj[d2]) / 2] = 1;
                return true;
              }
            }
          }
        }
      }
    }
  }
  return false;
}

bool find3() {
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (m[i][j]) {
        for (int d1 = 0; d1 < 4; ++d1) {
          for (int d2 = 0; d2 < 4; ++d2) {
            if (ok(i + di[d1], j + dj[d1]) and ok(i + ddi[d2], j + ddj[d2])) {
              if (m[i + di[d1]][j + dj[d1]] and m[i + ddi[d2]][j + ddj[d2]]) {
                m[i][j] = 0;
                m[i + di[d1] + ddi[d2]][j + dj[d1] + ddj[d2]] = 1;
                return true;
              }
            }
          }
        }
      }
    }
  }
  return false;
}

void show() {
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) cout << m[i][j];
    cout << endl;
  }
  cout << endl;
}

VVI visto;

int dfs(int i, int j) {
  if (m[i][j] or visto[i][j]) return 0;
  visto[i][j] = 1;
  int res = 1;
  for (int d = 0; d < 4; ++d) {
    if (ok(i + di[d], j + dj[d])) res += dfs(i + di[d], j + dj[d]);
  }
  return res;
}

int bt(int i, int j, int st) {
  if (j == w) return bt(i + 1, 0, st);
  if (i == h) {
    visto = VVI(h, VI(w, 0));
    int nr = 0;
    for (int kk = 0; kk < h; ++kk) {
      nr += dfs(kk, 0);
      nr += dfs(kk, w - 1);
    }
    for (int l = 0; l < w; ++l) {
      nr += dfs(0, l);
      nr += dfs(h - 1, l);
    }
    if (h == 4 and w == 4 and k == 10 and h * w - nr == k and st == 6) show();
    if (h * w - nr == k) return st;
    else return h * w;
  }
  else {
    m[i][j] = 0;
    int res = bt(i, j + 1, st);
    m[i][j] = 1;
    res = min(res, bt(i, j + 1, st + 1));
    return res;
  }
}

void solve(int z) {
  cin >> h >> w >> k;
  m = VVI(h, VI(w));
  if (k <= 4 or h <= 2 or w <= 2) {
    cout << k << endl;
    return;
  }
  for (int i = 0; i < h; ++i) m[i][0] = m[i][w - 1] = 1;
  for (int j = 0; j < w; ++j) m[0][j] = m[h - 1][j] = 1;
  int st = 2 * (h + w) - 4, area = h * w;
  while (area > k) {
    if (not find1()) {
      if (not find2()) {
        if (not find3()) cerr << "fail " << z << endl;
      }
    }
    else --st;
    --area;
    // show();
  }
  cout << st << endl;
}

int main() {
  int t;
  cin >> t;
  for (int z = 0; z < t; ++z) {
    cout << "Case #" << z + 1 << ": ";
    solve(z);
    //cout << " " << bt(0, 0, 0) << endl;
  }
}