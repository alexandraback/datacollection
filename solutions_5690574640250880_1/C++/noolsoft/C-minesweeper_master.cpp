#include <iostream>
#include <set>
#include <vector>

using namespace std;

int t = 0, r = 0, c = 0, m = -1;
char board[50][50];
int rowColDiffForLoop[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

void ResetBoard() {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      board[i][j] = '*';
    }
  }
}

bool IsValidRowCol(int row, int col) {
  if (row >= 0 && row < r && col >= 0 && col < c) {
    return true;
  }

  return false;
}

void PrintBoard() {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cout << board[i][j];
    }

    cout << endl;
  }
}

bool MakeBoardHelper(int row, int col, int numOfSafeCells) {
  int numOfRevealed = 0;
  vector<pair<int, int> > modifiedCells;

  for (int i = 0; i < 8; ++i) {
    int safeCellRow = row + rowColDiffForLoop[i][0];
    int safeCellCol = col + rowColDiffForLoop[i][1];

    if (IsValidRowCol(safeCellRow, safeCellCol) && '*' == board[safeCellRow][safeCellCol]) {
      board[safeCellRow][safeCellCol] = '.';
      numOfRevealed++;
      modifiedCells.push_back(pair<int, int>(safeCellRow, safeCellCol));
    }
  }

  if (0 == numOfRevealed) {
    return false;
  }

  if (numOfSafeCells - numOfRevealed == 0) {
    return true;
  } else if (numOfSafeCells - numOfRevealed < 0) {
    for (int i = 0; i < numOfRevealed; ++i) {
      const pair<int, int>& modifiedCell = modifiedCells[i];

      board[modifiedCell.first][modifiedCell.second] = '*';
    }

    return false;
  }

  set<pair<int, int> > failedCells;

  for (int i = 0; i < numOfRevealed; ++i) {
    const pair<int, int>& modifiedCell = modifiedCells[i];
    set<pair<int, int> > cellsToCheck;

    for (int j = 0; j < 8; ++j) {
      int row = modifiedCell.first + rowColDiffForLoop[j][0];
      int col = modifiedCell.second + rowColDiffForLoop[j][1];

      if (IsValidRowCol(row, col) && '*' == board[row][col]) {
        cellsToCheck.insert(pair<int, int>(row, col));
      }
    }

    bool areSameCells = true;

    if (cellsToCheck.size() == failedCells.size()) {
      for (set<pair<int, int> >::iterator cellToCheck = cellsToCheck.begin(); cellToCheck != cellsToCheck.end();
           ++cellToCheck) {
        if (failedCells.count(*cellToCheck) == 0) {
          areSameCells = false;
          break;
        }
      }
    } else {
      areSameCells = false;
    }

    if (areSameCells) {
      continue;
    }

    if (MakeBoardHelper(modifiedCell.first, modifiedCell.second, numOfSafeCells - numOfRevealed)) {
      return true;
    } else {
      failedCells = cellsToCheck;
    }
  }

  for (int i = 0; i < numOfRevealed; ++i) {
    const pair<int, int>& modifiedCell = modifiedCells[i];

    board[modifiedCell.first][modifiedCell.second] = '*';
  }

  return false;
}

bool MakeBoard() {
  ResetBoard();

  board[0][0] = 'c';

  if (r * c - m == 1) {
    return true;
  }

  return MakeBoardHelper(0, 0, r * c - m - 1);
}

int main() {
  cin >> t;

  for (int caseNum = 1; caseNum <= t; ++caseNum) {
    cin >> r >> c >> m;

    cout << "Case #" << caseNum << ":" << endl;

    if (MakeBoard()) {
      PrintBoard();
    } else {
      cout << "Impossible" << endl;
    }
  }

  return 0;
}

