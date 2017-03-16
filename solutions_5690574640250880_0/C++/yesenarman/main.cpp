#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

#define debug(x) cerr << #x << "=" << x << endl
#define sz(c) ((int)(c).size())
#define pb push_back
#define mp make_pair
#define endl '\n'

typedef long long int64;

using namespace std;

const vector<int> dx = {-1, 0, +1, +1, +1, 0, -1, -1};
const vector<int> dy = {+1, +1, +1, 0, -1, -1, -1, 0};

const int maxR = 60;
const int maxC = 60;

int R, C, M;
char board[maxR][maxC];
bool was[maxR][maxC];

bool isMine(int i, int j) {
  return !(i < 0 || j < 0 || i >= R || j >= C) && board[i][j] == '*';
}

int flood(int i, int j) {
  if (i < 0 || j < 0 || i >= R || j >= C || was[i][j])
    return 0;
  assert(board[i][j] != '*');
  was[i][j] = true;
  for (int k = 0; k < sz(dx); ++k)
    if (isMine(i + dx[k], j + dy[k])) return 1;
  int res = 1;
  for (int k = 0; k < sz(dx); ++k)
    res += flood(i + dx[k], j + dy[k]);
  return res;
}

void solve(int testcase) {
  debug(testcase);
  printf("Case #%d:\n", testcase);
  scanf("%d %d %d", &R, &C, &M);
  memset(board, 0, sizeof(board));
  for (int i = 0; i < R; ++i)
    for (int j = 0; j < C; ++j)
      board[i][j] = '.';
  board[0][0] = 'c';
  if (M == 0) {
    // Do nothing
  } else if (M == R * C - 1) {
    for (int i = 0; i < R; ++i)
      for (int j = 0; j < C; ++j)
        if (i > 0 || j > 0)
          board[i][j] = '*';
  } else if (R == 1) {
    if (M > C - 2) goto impossible;
    for (int i = C - M; i < C; ++i)
      board[0][i] = '*';
  } else if (C == 1) {
    if (M > R - 2) goto impossible;
    for (int i = R - M; i < R; ++i)
      board[i][0] = '*';
  } else if (R == 2) {
    if (M % 2 != 0 || M > 2 * (C - 2))
      goto impossible;
    int k = M / 2;
    for (int i = C - k; i < C; ++i)
      board[0][i] = board[1][i] = '*';
  } else if (C == 2) {
    if (M % 2 != 0 || M > 2 * (R - 2))
      goto impossible;
    int k = M / 2;
    for (int i = R - k; i < R; ++i)
      board[i][0] = board[i][1] = '*';
  } else if (M <= (R - 2) * (C - 2)) {
    int k = M;
    for (int i = R - 1; k > 0 && i >= 2; --i)
      for (int j = C - 1; k > 0 && j >= 2; --j) {
        board[i][j] = '*';
        --k;
      }
    assert(k == 0);
  } else if (M <= R * C - 9) {
    for (int i = 2; i < R; ++i)
      for (int j = 2; j < C; ++j)
        board[i][j] = '*';
    int k = M - (R - 2) * (C - 2);
    if (k % 2 != 0) {
      ++k;
      board[2][2] = '.';
    }
    int r = R - 1;
    int c = C - 1;
    while (k > 0 && r > 2) {
      board[r][0] = board[r][1] = '*';
      --r;
      k -= 2;
    }
    while (k > 0 && c > 2) {
      board[0][c] = board[1][c] = '*';
      --c;
      k -= 2;
    }
    assert(k == 0);
  } else if (M <= R * C - 4) {
    for (int i = 0; i < R; ++i)
      for (int j = 0; j < C; ++j)
        if (i > 2 || j > 2)
          board[i][j] = '*';
    int k = M - (R * C - 9);
    if (k == 1) {
      board[2][2] = '*';
    } else if (k == 3) {
      board[2][2] = '*';
      board[2][0] = board[2][1] = '*';
    } else if (k == 5) {
      board[2][2] = '*';
      board[2][0] = board[2][1] = '*';
      board[0][2] = board[1][2] = '*';
    } else {
      goto impossible;
    }
  } else {
    goto impossible;
  }

  {
    assert(board[0][0] == 'c');
    int mines = 0;
    for (int i = 0; i < R; ++i)
      for (int j = 0; j < C; ++j)
        if (board[i][j] == '*')
          ++mines;
    assert(mines == M);
    memset(was, 0, sizeof(was));
    assert(flood(0, 0) == R * C - M);
  }

  for (int i = 0; i < R; ++i)
    puts(board[i]);

  return;

impossible:
  fprintf(stderr, "%d %d %d\n", R, C, M);
  puts("Impossible");
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t)
    solve(t);
  return 0;
}
