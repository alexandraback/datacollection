#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

void mineRow(vector<vector<char> > &grid, int r, int c) {
    for (int i = 0; i < grid[r-1].size(); i++)
        grid[r-1][i] = '*';
}

void mineCol(vector<vector<char> > &grid, int r, int c) {
    for (int i = 0; i < grid.size(); i++) 
        grid[i][c-1] = '*';
}

void printGrid(vector<vector<char> > &grid) {
    grid[0][0] = 'c';
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

void minesweep(vector<vector<char> > &grid, int r, int c, int m) {
    if ((r == 1 && grid.size() != 1) || (c == 1 && grid[0].size() != 1)) {
        cout << "Impossible" << endl;
        return;
    }
    if ((r == 2 || c == 2) && m % 2 == 1) {
        cout << "Impossible" << endl;
        return;
    }
    if (m == 0) {
        printGrid(grid);
        return;
    }
    if (r > c) {
        if (m >= r && c > 3) {
            mineCol(grid,r,c);
            minesweep(grid,r,c-1,m-r);
            return;
        }
        else if (m >= c) {
            mineRow(grid,r,c);
            minesweep(grid,r-1,c,m-c);
            return;
        }
    }
    else {
        if ((m >= c) && (r > 3)) {
            mineRow(grid,r,c);
            minesweep(grid,r-1,c,m-c);
            return;
        }
        else if (m >= r) {
            mineCol(grid,r,c);
            minesweep(grid,r,c-1,m-r);
            return;
        }
    }
    if (m == r-1 && m == c-1) {
        if (r == 3) {
            cout << "Impossible" << endl;
            return;
        }
        else {
            for (int i = 0; i < m-1; i++) {
                grid[r-1][c-1-i] = '*';
            }
            grid[r-2][c-1] = '*';
            printGrid(grid);
            return;
        }
    }
    if (m < c-1) {
        for (int i = 0; i < m; i++) 
            grid[r-1][c-1-i] = '*';
        printGrid(grid);
        return;
    }
    if (m < r-1) {
        for (int i = 0; i < m; i++)
            grid[r-1-i][c-1] = '*';
        printGrid(grid);
        return;
    }
}

int main () {
    ifstream input;
    input.open("C-large.in");
    int numCases;
    input >> numCases;
    for (int i = 0; i < numCases; i++) {
        int r,c,m;
        input >> r >> c >> m;
        vector<vector<char> > grid (r,vector<char>(c,'.'));
        cout << "Case #" << (i+1) << ":" << endl;
        if (m == r*c - 1) {
            for (int row = 0; row < r; row++) {
                for (int col = 0; col < c; col++) {
                    grid[row][col] = '*';
                }
            }
            printGrid(grid);
        }
        else 
            minesweep(grid,r,c,m);
    }
}
