#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#include <string>
using namespace std;

int getPossible(int size) {
  int result = 1;
  while (--size) {
    for (int i = 0; i < size; i++) {
      result *= 3;
    }
  }
  return result;
}

void build(int nth, vector<vector<int>>& board) {
  int x = 1;
  int y = 0;
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      board[i][j] = 0;
    }
  }

  while (nth) {
    int thiz = nth % 3;
    nth /= 3;
    if (thiz == 1) {
      board[y][x] = 1;
    }
    else if (thiz == 2) {
      board[x][y] = 1;
    }
    x++;
    if (board.size() == x) {
      y++;
      x = y + 1;
    }
  }
}

int numPath(vector<vector<int>>& board, int s, int e) {
  queue<int> path;
  path.push(0);
  int result = 0;
  int limit = board.size() + 1;
  while (!path.empty()) {
    int size = path.size();
    for (int i = 0; i < size; i++) {
      int here = path.front(); path.pop();
      if (here == board.size() - 1) {
        result++;
        if (result > 100) break;
      }
      for (int i = 0; i < board[here].size(); i++) {
        if (board[here][i] == 1) {
          path.push(i);
        }
      }
    }
    limit--;
    if (limit == 0) return -1;
  }

  return result;
}

int main()
{
  int n;
  
  cin >> n;

  for (int kase = 1; kase <= n; kase++) {
    int B, M;
    cin >> B >> M;
    int possible = getPossible(B);
    bool result = false;
    vector < vector<int>> board(B, vector<int>(B, 0));

    for (int i = 0; i < possible; i++) {
      build(i, board);
      if (numPath(board, 0, B - 1) == M) {
        result = true;
        break;
      }

    }
    cout << "Case #" << kase << ": ";
    if (result) {
      cout << "POSSIBLE" << endl;
      for (int i = 0; i < B; i++) {
        for (int j = 0; j < B; j++) {
          cout << board[i][j];
        }
        cout << endl;
      }
    }
    else {
      cout << "IMPOSSIBLE" << endl;
    }
    fprintf(stderr, "now : %d\n", kase);
  }

  return 0;
}
