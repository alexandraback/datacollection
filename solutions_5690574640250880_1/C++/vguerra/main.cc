// Victor Guerra <vguerra@gmail.com>
// 2014-04-12
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


#define MAX_ROWS 50 
#define MAX_COLS 50
#define MOVES 8

int moves_x[MOVES] = {-1, -1, -1,  0, 0,  1, 1, 1};
int moves_y[MOVES] = {-1,  0,  1, -1, 1, -1, 0, 1};
int board[MAX_ROWS][MAX_COLS];

void initBoard(int R, int C) {
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      board[i][j] = -1;
    }
  }
}

void printBoard(int R, int C) {
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      switch (board[i][j]) {
        case -1:  cout << "*";
                  break;
        case 0:   cout << ".";
                  break;
        case 1:   cout << "c";
                  break;
      } 
    }
    cout << "\n";
  }
}

bool validSquare(int i, int j, int R, int C) {
  return (i >= 0 && i < R && j >= 0 && j < C);
}

void propagateSquares(int row, int col, int& squaresLeft, int R, int C) {
  if (squaresLeft < 1) return;
  queue<int> queue;
  int needed = 0;
  for (int m = 0; m < MOVES; ++m) {
    int r = row + moves_x[m];
    int c = col + moves_y[m];
    if (validSquare(r, c, R, C) && board[r][c] == -1) {
      ++needed;
      board[r][c] = 0;
      queue.push(r*C + c);
    }
  }
  squaresLeft -= needed;
 
  while (!queue.empty() && squaresLeft > 0) {
    int square = queue.front(); 
    queue.pop();
    int r = square / C;
    int c = square % C;
    propagateSquares(r, c, squaresLeft, R, C); 
  }
}

int main() {
  int T;
  cin >> T;


  for (int j = 1; j <= T; ++j) {
    int R,C, M;
    
    cin >> R >> C >> M;
    bool valid = false;
    for (int square = 0; square < R*C; ++square) {
      initBoard(R, C);
      int r = square / C; 
      int c = square % C; 
      board[r][c] = 1;
      int squaresAvailable = R*C - M - 1;
      propagateSquares(r, c, squaresAvailable, R, C); 
      if (squaresAvailable == 0) {
        valid = true;
        break;
      }
    }
    cout << "Case #" << j << ":\n";
    if (valid) {
      printBoard(R, C);
    } else {
      cout << "Impossible\n";
    }
  }
  return 0;
}
