#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

typedef enum cell_t {
  MINE, EMPTY, INIT
} cell_t;

void fill_block(cell_t board[50][50], int r0, int r1, int c0, int c1) {
  for (int i=r0;i<r1;i++)
    for (int j=c0;j<c1;j++)
      board[i][j] = EMPTY;
}


int main () {
  ifstream input;
  input.open("input");

  int ntest;
  input >> ntest;

  cell_t board[50][50];

  for (int k=0;k<ntest;k++) {
    int rows, columns, mines, empty;
    input >> rows >> columns >> mines;
    empty = rows * columns - mines;

    // To be able to consider one case only.
    bool permute = false;
    if (columns > rows) {
      permute = true;
      int tmp = columns;
      columns = rows;
      rows = tmp;
    }

    // In all that follows, rows >= columns

    for (int i=0;i<50;i++)
      for (int j=0;j<50;j++)
        board[i][j] = MINE;


    bool impossible = false;

    // Easy cases
    if (columns == 1) {
      for (int i=0;i<rows-mines;i++)
        board[i][0] = EMPTY;
    } else if (empty == 1) {
      impossible = false; // only one empty space
    } else if (empty == 2 || empty == 3 || empty == 5 || empty == 7) {
      impossible = true; // 2 or 3 spaces: impossible

    // When two columns / rows and odd number of spaces: impossible
    } else if (columns == 2 && empty % 2 == 1) {
      impossible = true;
    }

    // Enough to form two rows.
    else if (empty >= 2 * columns) {
      int rem = empty % columns, qot = empty / columns;
      if (rem > 1) {
        fill_block(board, 0, qot, 0, columns);
        fill_block(board, qot, qot+1, 0, rem);
      } else if (rem == 1 && qot == 2 && columns > 3) {
        fill_block(board, 0, qot, 0, columns-1);
        fill_block(board, qot, qot+1, 0, 3);
      } else if (rem == 1 && qot > 2) {
        fill_block(board, 0, qot-1, 0, columns);
        fill_block(board, qot-1, qot, 0, columns-1);
        fill_block(board, qot, qot+1, 0, 2);
      } else if (rem == 0) {
        fill_block(board, 0, qot, 0, columns);
      } else
        impossible = true;


    // At this point, we can gather: columns > rows > 2, empty < 2*rows
    // Two cases:
    //   - empty is even  -> make a chocolate bar
    //   - empty is odd   -> put 3 on top, bar on bottom
    } else {
      int qot = empty / 2, rem = empty % 2;
      if (rem == 0) {
        fill_block(board, 0, 2, 0, qot);
      } else {
        fill_block(board, 0, 2, 0, qot-1);
        fill_block(board, 2, 3, 0, 3);
      }
    }
    board[0][0] = INIT;

    // Printing
    cout << "case #" << k+1 << ":" << endl;
    if (impossible)
     cout << "Impossible" << endl;
    else {
      if (permute) {
        for (int i=0;i<columns;i++) {
          for (int j=0;j<rows;j++) {
            if (board[j][i] == MINE) cout << "*";
            else if (board[j][i] == EMPTY) cout << ".";
            else cout << "c";
          }
          cout << endl;
        }
      } else {
        for (int i=0;i<rows;i++) {
          for (int j=0;j<columns;j++) {
            if (board[i][j] == MINE) cout << "*";
            else if (board[i][j] == EMPTY) cout << ".";
            else cout << "c";
          }
          cout << endl;
        }
      }
    }
  }

  input.close();
  return 0;
}
