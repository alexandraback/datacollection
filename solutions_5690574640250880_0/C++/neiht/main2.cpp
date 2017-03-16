#include <iostream>

#define MAX_SIZE 10 

using namespace std;

int dir[][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1},
                {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

void printBoard(int board[][MAX_SIZE], int r, int c) {
    bool foundEmpty = false;
    for (int i = 0; i < r && !foundEmpty; i++) {
        for (int j = 0; j < c && !foundEmpty; j++) {
            bool isEmpty = true;
            if (board[i][j] == 0) {
                for (int k = 0; k < 8; k++) {
                    int nextR = i + dir[k][0];
                    int nextC = j + dir[k][1];

                    if (nextR >= 0 && nextR < r &&
                        nextC >= 0 && nextC < c &&
                        board[nextR][nextC] == 1) {
                        isEmpty = false;
                        break;
                    }
                }
            } else {
                isEmpty = false;
            }
            if (isEmpty) {
                board[i][j] = 2;
                foundEmpty = true;
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == 0) {
                cout << '.';
            }
            else if (board[i][j] == 1) {
                cout << '*';
            }
            else if (board[i][j] == 2) {
                cout << 'c';
            }
        }
        cout << endl;
    }
}

void fillTable(int board[][MAX_SIZE], int& r, int& c, int curR, int curC) {
    int nextR, nextC;

    // Check if any mine around to stop
    for (int i = 0; i < 8; i++) {
        nextR = curR + dir[i][0];
        nextC = curC + dir[i][1];
                
        if (nextR >= 0 && nextR < r &&
            nextC >= 0 && nextC < c &&
            board[nextR][nextC] == 1) {
            board[curR][curC] = 3;
            return;
        }
    }

    // Mark board as having 0 mine around
    board[curR][curC] = 2;

    // No mine then dfs on the neighbor cells
    for (int i = 0; i < 8; i++) {
        nextR = curR + dir[i][0];
        nextC = curC + dir[i][1];
        if (nextR >= 0 && nextR < r &&
            nextC >= 0 && nextC < c && 
            board[nextR][nextC] == 0) {
            fillTable(board, r, c, nextR, nextC);
        }
    }
}

bool checkboard(int board[][MAX_SIZE], int& r, int& c) {
    int newBoard[MAX_SIZE][MAX_SIZE];
    int startR = -1, startC = -1;
    bool foundEmpty = false;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            bool isEmpty = true;
            if (!foundEmpty && board[i][j] == 0) {
                for (int k = 0; k < 8; k++) {
                    int nextR = i + dir[k][0];
                    int nextC = j + dir[k][1];

                    if (nextR >= 0 && nextR < r &&
                        nextC >= 0 && nextC < c &&
                        board[nextR][nextC] == 1) {
                        isEmpty = false;
                        break;
                    }
                }
            } else {
                isEmpty = false;
            }
            if (isEmpty) {
                startR = i;
                startC = j;
                foundEmpty = true;
            }
            newBoard[i][j] = board[i][j];
        }
    }

    if (!foundEmpty) return false;

    fillTable(newBoard, r, c, startR, startC);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (newBoard[i][j] == 0) {
                return false;
            }
        }
    } 
    return true;
}

bool generateBoard(int board[][MAX_SIZE], int curCell,
                   int r, int c, int remain) {
   if (remain == 0) {
       return checkboard(board, r, c);
   } else if (curCell >= r * c) {
       return false;
   } else {
       int curR = curCell / c;
       int curC = curCell - (c * curR);
       board[curR][curC] = 1;
       bool re = generateBoard(board, curCell + 1, r, c, remain-1);
       if (re) return true;
       board[curR][curC] = 0;
       return generateBoard(board, curCell + 1, r, c, remain);
   }
}

int main() {
    int t; // Number of test cases
    int curCase = 1;
    int r, c, m;

    cin >> t;

    while (t--) {
        int board[MAX_SIZE][MAX_SIZE] = {{0}};
        cin >> r >> c >> m; 
        cout << "Case #" << curCase << ": " << endl;

        if (m == r*c - 1) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (i == r-1 && j == c-1) {
                        cout << 'c';
                    }
                    else {
                        cout << '*';
                    }
                }
                cout << endl;
            }
        } else { 

            bool possible = generateBoard(board, 0, r, c, m);

            if (possible) {
                printBoard(board, r, c);
            } else {
                cout << "Impossible" << endl;
            }
        }

        curCase++;
    }
    return 0;
}
