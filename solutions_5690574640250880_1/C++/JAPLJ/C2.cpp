#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <array>

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }

void mark(vector<string>& field) {
  int R = field.size(), C = field[0].size();
  vector<vector<int>> num(R, vector<int>(C, 0));

  int num_empty = 0, er = -1, ec = -1, sr = -1, sc = -1;
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      if (field[i][j] == '*') {
        for (int dr = -1; dr <= 1; ++dr) {
          for (int dc = -1; dc <= 1; ++dc) {
            int ii = i + dr, jj = j + dc;
            if ((dr == 0 && dc == 0) || ii < 0 || jj < 0 || ii >= R || jj >= C) {
              continue;
            }
            ++num[ii][jj];
          }
        }
      } else {
        er = i; ec = j;
        ++num_empty;
      }
    }
  }
  if (num_empty == 1) {
    field[er][ec] = 'c';
    return;
  }

  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      if (num[i][j] == 0 && field[i][j] == '.') {
        sr = i;
        sc = j;
      }
    }
  }
  field[sr][sc] = 'c';
}

int dp[55][55][2505];
int link[55][55][2505];

bool dfs(int R, int C, int M) {
  if (M == 0) return true;
  if (R == 1 || C == 1) return true;
  if (M == R * C - 1) return true;
  if (R == 2) return (M % 2 == 0 && M < 2 * C - 2);
  if (C == 2) return (M % 2 == 0 && M < 2 * R - 2);
  if (R == C && M == C - 1) return R >= 4;
  if (M < R - 1 || M < C - 1) return true;

  if (dp[R][C][M] != 0) return dp[R][C][M] == 1;
  dp[R][C][M] = -1;
  if (M >= R && dfs(R, C - 1, M - R)) {
    link[R][C][M] = 0;
    dp[R][C][M] = 1;
  }
  if (M >= C && dfs(R - 1, C, M - C)) {
    link[R][C][M] = 1;
    dp[R][C][M] = 1;
  }
  return dp[R][C][M] == 1;
}

vector<string> construct(int R, int C, int M) {
  vector<string> field(R, string(C, '.'));
  if (M == 0) return field;
  if (M == R * C - 1) {
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        field[i][j] = (i < R - 1 || j < C - 1) ? '*' : '.';
      }
    }
    return field;
  }
  if (R == 2) {
    for (int i = 0; i < M / 2; ++i) {
      field[0][i] = field[1][i] = '*';
    }
    return field;
  }
  if (C == 2) {
    for (int i = 0; i < M / 2; ++i) {
      field[i][0] = field[i][1] = '*';
    }
    return field;
  }
  if (R == 1 || M < C - 1) {
    for (int i = 0; i < M; ++i) {
      field[0][i] = '*';
    }
    return field;
  }
  if (C == 1 || M < R - 1) {
    for (int i = 0; i < M; ++i) {
      field[i][0] = '*';
    }
    return field;
  }
  if (R == C && M == C - 1) {
    for (int i = 0; i < M - 1; ++i) {
      field[0][i] = '*';
    }
    field[1][0] = '*';
    return field;
  }

  if (link[R][C][M] == 0) {
    for (int i = 0; i < R; ++i) {
      field[i][0] = '*';
    }
    vector<string> tmp = construct(R, C - 1, M - R);
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C - 1; ++j) {
        field[i][j + 1] = tmp[i][j];
      }
    }
  } else {
    for (int i = 0; i < C; ++i) {
      field[0][i] = '*';
    }
    vector<string> tmp = construct(R - 1, C, M - C);
    for (int i = 0; i < R - 1; ++i) {
      for (int j = 0; j < C; ++j) {
        field[i + 1][j] = tmp[i][j];
      }
    }
  }

  return field;
}

void solve() {
  int R, C, M;
  R = in();
  C = in();
  M = in();
  // cerr<<R<<' '<<C<<' '<<M<<endl;

  if (!dfs(R, C, M)) {
    puts("Impossible");
  } else {
    vector<string> s = construct(R, C, M);
    mark(s);
    for (int i = 0; i < R; ++i) {
      cout << s[i] << endl;
    }
  }
}

int main()
{
  int T = in();

  for (int CN = 1; CN <= T; ++CN) {
    printf("Case #%d:\n", CN);
    solve();
  }

  return 0;
}
