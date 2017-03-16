#include <iostream>
using namespace std;

#define EMPTY '.'
#define FRONTIER ','
#define MINE '*'
#define CLICK 'c'
#define DEBUG false


int visitable(char** matrix, int x, int y, int rows, int cols) {
  if (matrix[x][y] == EMPTY)
    return true;
  if (matrix[x][y] == FRONTIER) {
    for (int i = max(0, x - 1); i <= min(rows-1, x + 1); i++) 
      for (int j = max(0, y - 1); j <= min(cols-1, y + 1); j++)
	if (matrix[i][j] == EMPTY)
	  return true;
  }
  return false;
}


bool click(char** matrix, int rows, int cols, int free) {
  int visited = 0;
  for (int i = 0; i < rows; i++) 
    for (int j = 0; j < cols; j++)
      if (visitable(matrix, i, j, rows, cols))
	visited += 1;

  if (free == 1) {
    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++)
	if (matrix[i][j] != MINE) {
	  matrix[i][j] = CLICK;
	  return true;
	}
  }

  if (visited != free)
    return false;

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      if (matrix[i][j] == EMPTY) {
	matrix[i][j] = CLICK;
	return visited == free;
      }
  return false;
}

void placeMine(char** matrix, int x, int y, int rows, int cols) {
  for (int i = max(0, x - 1); i <= min(rows - 1, x + 1); i++) {
    for (int j = max(0, y - 1); j <= min(cols - 1, y + 1); j++) {
      if (matrix[i][j] == EMPTY)
	matrix[i][j] = FRONTIER;
    }
  }
  matrix[x][y] = MINE;
}


bool solve(char** matrix, int rows, int cols, int mines) {
  int minDim = min(rows, cols);

  if (mines >= minDim) {
    if (rows > cols) {
      for (int i = 0; i < cols; i++) {
	placeMine(matrix, rows - 1, i, rows, cols);
      }
      return solve(matrix, rows - 1, cols, mines - cols);
    } else {
      for (int i = 0; i < rows; i++) {
	placeMine(matrix, i, cols - 1, rows, cols);
      }
      return solve(matrix, rows, cols - 1, mines - rows);
    }
  }

  if (rows > cols) {
    int nMines = max(0, min(mines, rows - 2));
    for (int i = 0; i < nMines; i++)
      placeMine(matrix, rows - i - 1, cols - 1, rows, cols);
    if (nMines < mines)
      placeMine(matrix, rows - 1, cols - 2, rows, cols);
  } else {
    int nMines = max(0, min(mines, cols - 2));
    for (int i = 0; i < nMines; i++)
      placeMine(matrix, rows - 1, cols - i - 1, rows, cols);
    if (nMines < mines)
      placeMine(matrix, rows - 2, cols - 1, rows, cols);
  }
    
  return click(matrix, rows, cols, rows * cols - mines);
}

int main() {
  int nCases;
  cin >> nCases;

  for (int nCase=1; nCase<=nCases; nCase++) {
    int rows, cols, mines;
    cin >> rows >> cols >> mines;
    
    char** matrix = new char*[rows];
    for (int row = 0; row < rows; row++) {
      matrix[row] = new char[cols];
      for (int col = 0; col < cols; col++)
	matrix[row][col] = EMPTY;
    }

    cout << "Case #" << nCase << ":" << endl;
    if (DEBUG)
      cout << rows << "x" << cols << " with " << mines << " mines" << endl;

    if (solve(matrix, rows, cols, mines) || DEBUG) {
      for (int row = 0; row < rows; row++) {
	for (int col = 0; col < cols; col++)
	  cout << (char)(
            (matrix[row][col] == FRONTIER && !DEBUG) ? EMPTY : matrix[row][col]
	  );
	cout << endl;
      }
    } else {
      cout << "Impossible" << endl;
    }
  }
}
