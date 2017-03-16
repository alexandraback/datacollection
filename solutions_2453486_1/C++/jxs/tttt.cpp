#include <iostream>
#include <string>
#include <cmath>

using namespace std;

char grid[4][4];

void testcase(int _t)
{
    bool empty_squares = false;
    
    for (int i=0; i<4; i++) for (int j=0; j<4; j++) {
        cin >> grid[i][j];
        if (grid[i][j] == '.') { empty_squares = true; }
    }

    bool x_won = false;
    bool o_won = false;

    // check rows
    for (int i=0; i<4; i++) {
        int x_seq = 0;
        int o_seq = 0;
        for (int j=0; j<4; j++) { 
            if (grid[i][j] == 'X') {
                x_seq++;
                o_seq = 0;
            } else if (grid[i][j] == 'O') {
                o_seq++;
                x_seq = 0;
            } else if (grid[i][j] == 'T') {
                x_seq++;
                o_seq++;
            } else {
                x_seq = 0;
                o_seq = 0;
            }
            if (x_seq == 4) { x_won = true; }
            if (o_seq == 4) { o_won = true; }
        }
    }

    // check columns
    for (int j=0; j<4; j++) {
        int x_seq = 0;
        int o_seq = 0;
        for (int i=0; i<4; i++) { 
            if (grid[i][j] == 'X') {
                x_seq++;
                o_seq = 0;
            } else if (grid[i][j] == 'O') {
                o_seq++;
                x_seq = 0;
            } else if (grid[i][j] == 'T') {
                x_seq++;
                o_seq++;
            } else {
                x_seq = 0;
                o_seq = 0;
            }
            if (x_seq == 4) { x_won = true; }
            if (o_seq == 4) { o_won = true; }
        }
    }
    
    // check diagonals
    int x_seq = 0;
    int o_seq = 0;
    for (int i=0; i<4; i++) {
        if (grid[i][i] == 'X') {
            x_seq++;
            o_seq = 0;
        } else if (grid[i][i] == 'O') {
            o_seq++;
            x_seq = 0;
        } else if (grid[i][i] == 'T') {
            x_seq++;
            o_seq++;
        } else {
            x_seq = 0;
            o_seq = 0;
        }
        if (x_seq == 4) { x_won = true; }
        if (o_seq == 4) { o_won = true; }
    }
    
    x_seq = 0;
    o_seq = 0;
    for (int i=0; i<4; i++) {
        if (grid[i][3-i] == 'X') {
            x_seq++;
            o_seq = 0;
        } else if (grid[i][3-i] == 'O') {
            o_seq++;
            x_seq = 0;
        } else if (grid[i][3-i] == 'T') {
            x_seq++;
            o_seq++;
        } else {
            x_seq = 0;
            o_seq = 0;
        }
        if (x_seq == 4) { x_won = true; }
        if (o_seq == 4) { o_won = true; }
    }
    
    string result;
    if (x_won) {
        result = "X won";
    } else if (o_won) {
        result = "O won";
    } else if (!empty_squares) {
        result = "Draw";
    } else {
        result = "Game has not completed";
    }

    cout << "Case #" << _t << ": ";
    cout << result;
    cout << endl;
}

int main(int argc, char** argv) {
    int T;
    cin >> T;

    for (int t=1; t<=T; t++) {
        testcase(t);
    } 
}
