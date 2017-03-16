#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int movesX[] = {0, 0, -1, 1, -1, 1, -1, 1};
int movesY[] = {-1, 1, 0, 0, -1, 1, 1, -1};

int r, c, m;
char grid[100][100];
bool used[100][100];
int usedCount;

long steps[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432};

void clean() {
    memset(grid, 0, sizeof(grid));
    memset(used, 0, sizeof(used));
    usedCount = 0;
}

void convertTheGrid(long code) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (code & steps[i * c + j]) {
                grid[i + 1][j + 1] = '*';
            }
            else {
                grid[i + 1][j + 1] = '.';
            }
        }
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

void print() {
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++)
            cout << grid[i][j];
        cout << endl;
    }
}

int getFreeCellsCount() {
    return r * c - m;
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

bool tryIt() {
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (grid[i][j] == '.') {
                int bombsCount = getBombsCount(i, j);
                if (bombsCount == 0) {
                    memset(used, 0, sizeof(used));
                    usedCount = 0;

                    dfs(i, j);
                    if (usedCount == getFreeCellsCount()) {
                        grid[i][j] = 'c';
                        print();
                        return true;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
    }
    return false;
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

void gen() {
    long maxi = 1 << (r * c);
    for (long i = 0; i <= maxi; i++) {
        convertTheGrid(i);
        if (getGridBombsCount() == m) {
            if (tryIt()) {
                return;
            }
        }
    }
    cout << "Impossible" << endl;
}

int main() {
    int t;
    cin >> t;
    for (int test = 1; test <= t; test++) {
        clean();
        cout << "Case #" << test << ":" << endl;
        cin >> r >> c >> m;
        if (m == r * c - 1) {
            for (int i = 1; i <= r; i++)
                for (int j = 1; j <= c; j++)
                    grid[i][j] = '*';
            grid[1][1] = 'c';
            print();
        }
        else {
            gen();
        }
    }
    return 0;
}
