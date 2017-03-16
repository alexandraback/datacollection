#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int movesX[] = {0, 0, -1, 1, -1, 1, -1, 1};
int movesY[] = {-1, 1, 0, 0, -1, 1, 1, -1};

int r, c, m;
char grid[100][100];
bool used[100][100];
int usedCount;

bool isInTheGrid(int i, int j) {
    return !(i < 1 || i > r || j < 1 || j > c);
}

bool isEmpty(int i, int j) {
    if (!isInTheGrid(i, j)) {
        return false;
    }

    return grid[i][j] != '.' &&
        grid[i][j] != 'c';
}

int getPoints(int i, int j) {
    int points = 0;
    if (isEmpty(i, j - 1)) {
        points++;
    }
    if (isEmpty(i, j + 1)) {
        points++;
    }
    if (isEmpty(i -1, j)) {
        points++;
    }
    if (isEmpty(i + 1, j)) {
        points++;
    }
    if (isEmpty(i - 1, j - 1)) {
        points++;
    }
    if (isEmpty(i - 1, j + 1)) {
        points++;
    }
    if (isEmpty(i + 1, j - 1)) {
        points++;
    }
    if (isEmpty(i + 1, j + 1)) {
        points++;
    }
    return points;
}

void setFreePoint(int i, int j) {
    if (isInTheGrid(i, j)) {
        grid[i][j] = '.';
    }
}

int getBombsCount(int i, int j) {
    int bombsCount = 0;
    for (int moveIndex = 0; moveIndex < 8; moveIndex++) {
        if (grid[i + movesX[moveIndex]][j + movesY[moveIndex]] == '*') {
            bombsCount++;
        }
    }
    return bombsCount;
}

bool isInside(int i, int j) {
    return i >= 1 && i <= r && j >= 1 && j <= c;
}

void dfs(int i, int j) {
    if (!isInside(i, j) || used[i][j] || grid[i][j] == '*')
        return;

    usedCount++;
    used[i][j] = true;

    if (getBombsCount(i, j) > 0)
        return;

    for (int moveIndex = 0; moveIndex < 8; moveIndex++) {
        dfs(i + movesX[moveIndex], j + movesY[moveIndex]);
    }
}

int getGridBombsCount() {
    int bombsCount = 0;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (grid[i][j] == '*')
                bombsCount++;
        }
    }
    return bombsCount;
}

bool valid() {
    if (getGridBombsCount() != m) {
        return false;
    }

    memset(used, 0, sizeof(used));
    usedCount = 0;

    int clickX, clickY;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (grid[i][j] == 'c') {
                clickX = i;
                clickY = j;
            }
        }
    }

    dfs(clickX, clickY);

    return usedCount == r * c - m;
}

void printGrid() {
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (isEmpty(i, j)) {
                grid[i][j] = '*';
            }
            cout << grid[i][j];
        }
        cout << endl;
    }

    if (!valid()) {
        cout << " BANG !!!\n";
    }
}

void tryToBuildIt_R_more_than_C() {
    int free = r * c - m;

    memset(grid, 0, sizeof(grid));

    grid[r][c] = 'c';
    grid[r][c - 1] = '.';
    grid[r - 1][c] = '.';
    grid[r - 1][c - 1] = '.';
    free -= 4;

    int moveDiagR = -1;
    int moveDiagC = 0;

    int diagR = r + moveDiagR;
    int diagC = c + moveDiagC;

    while(diagR >= 1 && diagC >= 1) {
        int i = diagR;
        int j = diagC;

        bool flag = false;
        while(i <= r && j >= 1) {
            if (!isEmpty(i, j)) {

                int newPoints = getPoints(i, j);
                if (newPoints > 0 && newPoints <= free) {
                    setFreePoint(i, j - 1);
                    setFreePoint(i - 1, j - 1);
                    setFreePoint(i - 1, j);
                    free -= newPoints;
                    flag = true;
                }

                if (free == 0) {
                    printGrid();
                    return;
                }
            }

            i++;
            j--;
        }

        if (!flag) {
            cout << "Impossible" << endl;
            return;
        }


        if (diagR == 1) {
            moveDiagR = 0;
            moveDiagC = -1;
        }

        diagR += moveDiagR;
        diagC += moveDiagC;
    }
    printGrid();
}

void tryToBuildIt_C_more_than_R() {
    int free = r * c - m;

    memset(grid, 0, sizeof(grid));

    grid[r][c] = 'c';
    grid[r][c - 1] = '.';
    grid[r - 1][c] = '.';
    grid[r - 1][c - 1] = '.';
    free -= 4;

    int moveDiagR = 0;
    int moveDiagC = -1;

    int diagR = r + moveDiagR;
    int diagC = c + moveDiagC;

    while(diagR >= 1 && diagC >= 1) {
        int i = diagR;
        int j = diagC;

        bool flag = false;
        while(i >= 1 && j <= c) {
            if (!isEmpty(i, j)) {

                int newPoints = getPoints(i, j);

                if (newPoints > 0 && newPoints <= free) {
                    setFreePoint(i, j - 1);
                    setFreePoint(i - 1, j - 1);
                    setFreePoint(i - 1, j);
                    free -= newPoints;
                    flag = true;
                }

                //cout << i << ", " << j << " : " << newPoints << " " << free << endl;

                if (free == 0) {
                    printGrid();
                    return;
                }
            }

            i--;
            j++;
        }

        if (!flag) {
            cout << "Impossible" << endl;
            return;
        }

        if (diagC == 1) {
            moveDiagR = -1;
            moveDiagC = 0;
        }

        diagR += moveDiagR;
        diagC += moveDiagC;
    }
    printGrid();
}

void tryToBuildIt() {
    if (r > c) {
        tryToBuildIt_R_more_than_C();
    }
    else {
        tryToBuildIt_C_more_than_R();
    }
}

void handle1D() {
    if (r == c) {
        cout << "c\n";
    }
    else if (r > c) {
        int free = r * c - m;
        cout << "c\n";
        free--;

        while(free) {
            cout << ".\n";
            free--;
        }

        while(m) {
            cout << "*\n";
            m--;
        }
    }
    else if (r < c) {
        int free = r * c - m;
        cout << "c";
        free--;

        while(free) {
            cout << ".";
            free--;
        }

        while(m) {
            cout << "*";
            m--;
        }

        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    for (int test = 1; test <= t; test++) {
        cin >> r >> c >> m;

        cout << "Case #" << test << ":" << endl;
        if (r == 1 || c == 1) {
            if (r == 1 && c == 1 && m == 0) {
                cout << "c" << endl;
            }
            else if (r * c - m < 1) {
                cout << "Impossible" << endl;
            } else {
                handle1D();
            }
        } else {
            if (r * c - m == 1) {
                memset(grid, 0, sizeof(grid));
                grid[1][1] = 'c';
                printGrid();
            }
            else if (r * c - m < 4) {
                cout << "Impossible" << endl;
            } else {
                tryToBuildIt();
            }
        }
    }
    return 0;
}
