#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <iterator>

#define ALL(v) v.begin(), v.end()
#define DEB(i, j, k) printf("d[%d][%d][%d] = %d\n", i, j, k, d[i][j][k])

using namespace std;

template< typename T > T next() {  T tmp; cin >> tmp; return tmp; }

int bc(int a) { return a == 0 ? 0 : bc(a / 2) + a % 2; }
int weight(int msk) {
  int w = 0;
  for (int i = 0; msk != 0; ++i) {
    w += -(i + 1) * (msk % 2);
    msk /= 2;
  }
  return w;
}

int bit (int msk, int b)               { return (msk >> b) % 2; }
int bit2(int msk, int i, int j, int c) { return bit(msk, i * c + j); }
bool betw(int x, int a, int b) { return a <= x && x <= b; }
bool inch(int i, int j, int r, int c) { 
  return betw(i, 0, r - 1) && betw(j, 0, c - 1); 
}
bool check_free(int msk, int x, int y, int r, int c) {
  int res = 0;
  for (int i = -1; i <= 1; ++i) {
    for (int j = -1; j <= 1; ++j) {
      if (inch(x + i, y + j, r, c)) {
        res |= bit2(msk, x + i, y + j, c);
      }
    }
  }
  return res == 0;
}

vector< vector < bool > > was;

int dfs(int msk, int x, int y, int r, int c) {
  int cnt = 1;
  was[x][y] = true;
  for (int i = -1; i <= 1; ++i) {
    for (int j = -1; j <= 1; ++j) {
      int xp = x + i;
      int yp = y + j;
      if (!inch(xp, yp, r, c) || was[xp][yp]) continue;
      if (check_free(msk, xp, yp, r, c)) {
        cnt += dfs(msk, xp, yp, r, c);
      } else {
        ++cnt;
        was[xp][yp] = 1;
      }
    }      
  }
  return cnt;
}

bool winnable(int msk, int r, int c, int m) {
  if (m == r * c - 1) return true;

  was = vector< vector < bool > >(r, vector< bool >(c, false));
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (check_free(msk, i, j, r, c)) {
        return dfs(msk, i, j, r, c) == r * c - m;
      }
    }
  }
  return false;    
}

void stupid_solve(int r, int c, int m) {
  int sq = r * c;
  int res = -1;
  for (int msk = 0; msk < (1 << sq); ++msk) {
    if (bc(msk) == m && winnable(msk, r, c, m)) {
      if (res == -1 || weight(res) > weight(msk)) {
        res = msk;
      }
    }    
  }
  if (res < 0) {
    printf("Impossible\n");
    return;
  }

  bool sett = false;

  vector< vector < char > > out(r, vector< char >(c, '.'));
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (bit2(res, i, j, c)) {
        out[i][j] = '*';
      } else if (!sett) {
        if (m == r * c - 1) {
          out[i][j] = 'c';
          sett = true;
        } else if (check_free(res, i, j, r, c)) {
          out[i][j] = 'c';
          sett = true;
        }    
      }
    }
  }
  printf("\n");
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      printf("%c", out[i][j]);
    }
    printf("\n");
  }
}

bool d[51][51][2501];
int js[51][51][2500];

void prep() {
  for (int i = 0; i <= 50; ++i) {
    d[0][i][0] = d[i][0][0] = true;
    js[0][i][0] = 0;
    js[i][0][0] = 0;
  }
  for (int i = 1; i <= 50; ++i) {
    for (int j = 2; j <= 50; ++j) {
      d[i][j][i * j] = true;
      js[i][j][i * j] = 0;
      d[i][j][0] = true;
      js[i][j][0] = j;
      for (int f = 1; f < i * j; ++f) {
        for (int k = 2; k <= j; ++k) {
          int rest = j - k;
          if (f - rest * i >= 0 && d[i - 1][k][f - rest * i]) {
            d[i][j][f] = true;
            js[i][j][f] = k;
          } 
        }
      }
    }
  }
}

vector< vector< char > > smart_solve(int r, int c, int m, bool & fail) {
  vector< vector< char > > ans(r, vector< char >(c, '.'));
  if (m == r * c - 1) {
    for (int i = 0; i < r; ++i) {
      fill(ans[i].begin(), ans[i].end(), '*');
    }
    return ans;
  }
  if (r == 1) {
    for (int i = c - m; i < c; ++i) {
      ans[0][i] = '*';
    }
    return ans;
  }
  if (c == 1) {
    for (int i = r - m; i < r; ++i) {
      ans[i][0] = '*';
    }
    return ans;
  }

  int shift = -1;
  for (int start = 2; start <= c; ++start) {
    int rest = c - start;
    if (d[r - 2][start][m - rest * r]) {
      shift = start;
      break;
    }
  }
  if (shift == -1) {
    fail = true;
    return ans;
  }
  for (int i = 0; i < r; ++i) {
    for (int j = shift; j < c; ++j) {
      ans[i][j] = '*';
    }
  }
  m -= (c - shift) * r;
  for (int i = 2; shift != 0; ++i) {
    int nshift = js[r - i][shift][m];
    for (int j = i; j < r; ++j) {
      for (int k = nshift; k < shift; ++k) {
        ans[j][k] = '*';
      }
    }
    m -= (r - i) * (shift - nshift);
    shift = nshift;
  }
  return ans;
}


void solve() {
  int r = next< int >();
  int c = next< int >();
  int m = next< int >();

  bool fail = false;
  vector< vector< char > > ans = smart_solve(r, c, m, fail);
  if (fail) {
    printf("\nImpossible\n");
  } else {
    ans[0][0] = 'c';
    printf("\n");
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        printf("%c", ans[i][j]);
      }
      printf("\n");
    }
  }
}

int main() {

//  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  prep();
  int test = next< int >();
  for (int i = 1; i <= test; ++i) {
    printf("Case #%d: ", i);
    solve();
  }
//  DEB(2, 7, 3);

  return 0;
}

