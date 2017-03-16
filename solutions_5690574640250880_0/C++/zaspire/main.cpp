#include <gmpxx.h>
#include <gtk/gtk.h>
#include <cairo.h>

#include "shelly.hpp"

using namespace std;
using namespace shelly;

int count(const vector<string> &board, int i, int k) {
  int res = 0;
#define CHECK(i, k) if (i < (int)board.size() && i >= 0 && k >= 0 && k < (int)board[0].size()) {\
  if (board[i][k] == '*') res++;\
}
  CHECK(i + 1, k + 1);
  CHECK(i + 1, k);
  CHECK(i + 1, k - 1);
  CHECK(i, k + 1);
  CHECK(i, k - 1);
  CHECK(i - 1, k + 1);
  CHECK(i - 1, k);
  CHECK(i - 1, k - 1);
  return res;
}

bool check(const vector<string> &board, int M) {
  vector<vector<bool>> v(board.size(), vector<bool>(board[0].size(), false));

  int m = 0;
  int C = 0, x = -1, y = -1;
  for (size_t i = 0; i < board.size(); i++) {
    for (size_t k = 0; k < board[0].size(); k++) {
      char c = board[i][k];
      if (c == '*')
        m++;
      else if (c == 'c') {
        C++;
        x = i;
        y = k;
      }
    }
  }
  assert(C == 1);
  assert(m == M);

  queue<pair<int, int>> q;
  q.push(make_pair(x, y));
  v[x][y] = true;
  while (q.size()) {
    auto p1 = q.front();
    q.pop();

    if (count(board, p1.first, p1.second))
      continue;

#define WORK(i, k) if (i < (int)board.size() && i >= 0 && k >= 0 && k < (int)board[0].size()) {\
	  if (board[i][k] == '.' && !v[i][k]) {v[i][k] = true; q.push(make_pair(i, k));}\
	}
    WORK(p1.first - 1, p1.second - 1);
    WORK(p1.first - 1, p1.second);
    WORK(p1.first - 1, p1.second + 1);
    WORK(p1.first + 1, p1.second - 1);
    WORK(p1.first + 1, p1.second);
    WORK(p1.first + 1, p1.second + 1);
    WORK(p1.first, p1.second - 1);
    WORK(p1.first, p1.second + 1);
  }

  for (size_t i = 0; i < board.size(); i++) {
    for (size_t k = 0; k < board[i].size(); k++) {
      if (v[i][k])
        continue;
      if (board[i][k] == '*')
        continue;
      return false;
    }
  }
  return true;
}

vector<string> GenerateBoard(int R, int C, int M, int w, int skip) {
  int E = R * C - M;
  vector<string> board(R, string(C, '*'));
  for (size_t i = 0; i < board.size(); i++) {
    for (int k = board[0].size() - 1, j = 1; j <= w && k >= 0 && E; k--, j++) {
      if (skip > 0) {
        skip--;
        continue;
      }
      assert(E > 0);
      E--;
      board[i][k] = '.';
    }
  }
  if (E > 0)
    return vector<string>();

  if (board.size() > 1 && board[0].size() > 2) {
    string &last = board[board.size() - 1], &prev = board[board.size() - 2];
    if (count(last.begin(), last.end(), '*') == last.size() - 1 && last[last.size() - 1] == '.') {
      if (count(prev.begin(), prev.end(), '*') == 0) {
        last[last.size() - 2] = '.';
        prev[0] = '*';
      }
    }
  }

  for (size_t i = 0; i < board.size(); i++) {
    for (size_t k = 0; k < board[0].size(); k++) {
      if (board[i][k] == '.') {
        board[i][k] = 'c';
        if (check(board, M))
          return board;
        board[i][k] = '.';
      }
    }
  }

  return vector<string>();
}

vector<string> GenerateBoard(int R, int C, int M) {
  for (int s = 0; s <= C; s++) {
  for (int i = 1; i <= C; i++) {
    vector<string> t = GenerateBoard(R, C, M, i, s);
    if (t.empty())
      continue;
    if (check(t, M)) {
      assert(t.size() == R && t[0].size() == C);
      return t;
    }
  }
  }
  return vector<string>();
}

vector<string> rotate(const vector<string> &board) {
  vector<string> res(board[0].size(), string(board.size(), ' '));

  for (size_t i = 0; i < board.size(); i++) {
    for (size_t k = 0; k < board[0].size(); k++)
      res[k][i] = board[i][k];
  }

  return res;
}

int main(int argc, char **argv) {
  freopen("input.txt", "r", stdin);
  gtk_init(&argc, &argv);

  int T;
  cin >> T;
  for (int TT = 1; TT <= T; TT++) {
    int R, C, M;
    cin >> R >> C >> M;
    cout << Format("Case #%0:", TT) << endl;
    vector<string> t = GenerateBoard(R, C, M);
    if (t.empty()) {
      t = GenerateBoard(C, R, M);
      if (t.empty()) {
        cout << "Impossible" << endl;
        continue;
      }
      t = rotate(t);
      assert(check(t, M));
    }
    for (string &s: t)
      cout << s << endl;
  }
  return 0;
}
