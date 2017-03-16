#include <cstdio>
#include <cassert>
#include <cstring>
#include <queue>
using std::pair;
using std::queue;

const int kDir[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
int r, c, m, total;
char board[55][55];
bool b[55][55];

int Floodfill(int str = 1, int stc = 1) {
  memset(b, 0, sizeof(b));
  queue< pair<int, int> > que;
  b[str][stc] = true;
  que.push({str, stc});
  int ret = 0;
  while (!que.empty()) {
    int r = que.front().first;
    int c = que.front().second;
    que.pop();
    ++ret;
    int mine_cnt = 0;
    for (int i = 0; i < 8; ++i) {
      int tr = r + kDir[i][0];
      int tc = c + kDir[i][1];
      if (board[tr][tc] == '*')
        ++mine_cnt;
    }
    if (!mine_cnt) {
      for (int i = 0; i < 8; ++i) {
        int tr = r + kDir[i][0];
        int tc = c + kDir[i][1];
        if (!b[tr][tc] && board[tr][tc] == '.') {
          b[tr][tc] = true;
          que.push({tr, tc});
        }
      }
    }
  }
  return ret;
}

bool TryR(int width) {
  memset(board, 0, sizeof(board));
  for (int i = 1; i <= r; ++i)
    for (int j = 1; j <= c; ++j)
      board[i][j] = '*';
  int left = total - m;
  for (int j = 1; left > 0 && j <= c; ++j) {
    for (int i = 1; left > 0 && i <= width; ++i) {
      --left;
      board[i][j] = '.';
    }
  }
  if (left) return false;
  bool found = Floodfill() == total - m;
  if (found) {
    board[1][1] = 'c';
    for (int i = 1; i <= r; ++i)
      puts(board[i] + 1);
  }
  return found;

}

bool TryMR(int width) {
  memset(board, 0, sizeof(board));
  for (int i = 1; i <= r; ++i)
    for (int j = 1; j <= c; ++j)
      board[i][j] = '.';
  int left = m;
  for (int j = 1; left > 0 && j <= c; ++j) {
    for (int i = 1; left > 0 && i <= width; ++i) {
      --left;
      board[i][j] = '*';
    }
  }
  if (left) return false;
  bool found = Floodfill(r, c) == total - m;
  if (found) {
    board[r][c] = 'c';
    for (int i = 1; i <= r; ++i)
      puts(board[i] + 1);
  }
  return found;
}

bool TryC(int width) {
  memset(board, 0, sizeof(board));
  for (int i = 1; i <= r; ++i)
    for (int j = 1; j <= c; ++j)
      board[i][j] = '*';
  int left = total - m;
  for (int i = 1; left > 0 && i <= r; ++i) {
    for (int j = 1; left > 0 && j <= width; ++j) {
      --left;
      board[i][j] = '.';
    }
  }
  if (left) return false;
  bool found = Floodfill() == total - m;
  if (found) {
    board[1][1] = 'c';
    for (int i = 1; i <= r; ++i)
      puts(board[i] + 1);
  }
  return found;
}

bool TryMC(int width) {
  memset(board, 0, sizeof(board));
  for (int i = 1; i <= r; ++i)
    for (int j = 1; j <= c; ++j)
      board[i][j] = '.';
  int left = m;
  for (int i = 1; left > 0 && i <= r; ++i) {
    for (int j = 1; left > 0 && j <= width; ++j) {
      --left;
      board[i][j] = '*';
    }
  }
  if (left) return false;
  bool found = Floodfill(r, c) == total - m;
  if (found) {
    board[r][c] = 'c';
    for (int i = 1; i <= r; ++i)
      puts(board[i] + 1);
  }
  return found;
}

bool DFS(int left, int lastr, int lastc) {
  if (!left) {
    int cr = 0, cc = 0;
    for (int i = 1; i <= r; ++i) {
      for (int j = 1; j <= c; ++j) {
        if (board[i][j] == '*') continue;
        int mine_cnt = 0;
        for (int t = 0; t < 8; ++t) {
          mine_cnt += board[i + kDir[t][0]][j + kDir[t][1]] == '*';
        }
        if (!mine_cnt) {
          cr = i;
          cc = j;
          break;
        }
      }
      if (cr) break;
    }
    if (!cr) return false;
    if (Floodfill(cr, cc) == total - m) {
      board[cr][cc] = 'c';
      for (int i = 1; i <= r; ++i)
        puts(board[i] + 1);
      return true;
    }
    return false;
  }
  for (int j = lastc + 1; j <= c; ++j) {
    board[lastr][j] = '*';
    if (DFS(left - 1, lastr, j)) return true;
    board[lastr][j] = '.';
  }
  for (int i = lastr + 1; i <= r; ++i)
    for (int j = 1; j <= c; ++j) {
      board[i][j] = '*';
      if (DFS(left - 1, i, j)) return true;
      board[i][j] = '.';
    }
  return false;
}

bool Search() {
  memset(board, 0, sizeof(board));
  for (int i = 1; i <= r; ++i)
    for (int j = 1; j <= c; ++j)
      board[i][j] = '.';
  return DFS(m, 0, c + 1);
}

void Work() {
  assert(scanf("%d%d%d", &r, &c, &m) == 3);
  total = r * c;
  for (int i = 1; i <= r; ++i) {
    if (TryR(i)) return;
  }
  for (int i = 1; i <= c; ++i) {
    if (TryC(i)) return;
  }
  for (int i = 1; i <= r; ++i) {
    if (TryMR(i)) return;
  }
  for (int i = 1; i <= c; ++i) {
    if (TryMC(i)) return;
  }

  // if (Search()) return;
  puts("Impossible");
}

int main() {
  int cases;
  assert(scanf("%d", &cases) == 1);
  for (int i = 1; i <= cases; ++i) {
    printf("Case #%d:\n", i);
    Work();
  }
  return 0;
}
