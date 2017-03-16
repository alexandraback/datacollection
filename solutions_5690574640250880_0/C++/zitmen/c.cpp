// This is one big mess...it might be better to start over :-/
#include <iostream>
using namespace std;

bool solve(char board[50][50], int R, int C, int M) {
    if(R*C == M) {
        return false;
    }
    // make it empty
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            board[r][c] = '.';
        }
    }
    // fill with mines; keep just the top left corner empty
    int rf = R - 1, cf = C - 1, m = 0, space_col = 0, space_row = 0;
    // 1) fill the longer dimension until a square is created
    while((rf >= 0) && (cf >= 0) && (m < M)) {
        if(rf == cf) {
            break;  // square
        } else if(rf > cf) {
            // start column-wise filling to reduce the number of rows
            int c = cf;
            for( ; (c >= 0) && (m < M); c--) {
                if(board[rf][c] != '*') {
                    board[rf][c] = '*';
                    m++;
                }
            }
            rf--;   // row has been filled
            if(m >= M) {
                space_row = c + 1;
                break;
            }
        } else {
            // start row-wise filling to reduce the number of columns
            int r = rf;
            for( ; (r >= 0) && (m < M); r--) {
                if(board[r][cf] != '*') {
                    board[r][cf] = '*';
                    m++;
                }
            }
            cf--;   // column has been filled
            if(m >= M) {
                space_col = r + 1;
                break;
            }
        }

    }
    // 2) alternate between filling rows and columns to keep the square in place as long as possible
    while((rf >= 0) && (cf >= 0) && (m < M)) {
        int r = rf;
        for( ; (r >= 0) && (m < M); r--) {
            if(board[r][cf] != '*') {
                board[r][cf] = '*';
                m++;
            }
        }
        cf--;
        if(m >= M) {
            space_col = r + 1;
            break;
        }
        int c = cf;
        for( ; (c >= 0) && (m < M); c--) {
            if(board[rf][c] != '*') {
                board[rf][c] = '*';
                m++;
            }
        }
        rf--;
        if(m >= M) {
            space_row = c + 1;
            break;
        }
    }
    // now check if the solution is possible, or not; if not, propose an alternative solution, if possible
    int width = cf + 1, height = rf + 1;
    if((R == 1) || (C == 1)) {  // this is completely different situation than when (w==1 || h==1) !
        // ok!
    } else if((width >= 3) && (height >= 3)) {
        if((space_col != 1) && (space_row != 1)) {
            // ok!
        } else if(space_col == 1) {
            // move the mine to a better position
            board[1][width] = '.';
            board[height-1][width-1] = '*';
        } else if(space_row == 1) {
            // move the mine to a better position
            board[height][1] = '.';
            board[height-1][width-1] = '*';
        }
    } else if((width == 1) || (height == 1)) {
        if((R*C - M) == 1) {
            // ok! (just the top left corner)
        } else {
            return false;
        }
    } else { // w==2 or h==2
        if((space_col == 1) || (space_row == 1)) {
            return false;
        } else {
            // ok! (space can be either 0, or 2)
        }
    }
    board[0][0] = 'c';
    return true;
}

void printBoard(char board[50][50], int R, int C) {
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            cout << board[r][c];
        }
        cout << '\n';
    }
}

int main()
{
    char board[50][50];
    int T, R, C, M;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> R >> C >> M;
        cout << "Case #" << t << ":\n";
        if(!solve(board, R, C, M)) {
            cout << "Impossible\n";
        } else {
            printBoard(board, R, C);
        }
    }
    cout << flush;
    return 0;
}