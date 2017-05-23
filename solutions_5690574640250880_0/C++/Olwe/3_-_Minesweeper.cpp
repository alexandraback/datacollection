/* This program should be run with its input piped from the input file and its output piped to the output file. */

#include <iostream>

using namespace std;

//int click(char** pcBoard, int R, int C, int y, int x, int M, int iTotalMines = -1);

int main() {
    int iNumTests;
    int R, C, M;
    char** pcBoard;
    
    cin >> iNumTests;
    
    for (int test = 1; test <= iNumTests; ++test) {
        cin >> R >> C >> M;
        
        pcBoard = new char*[R];
        for (int i = 0; i < R; ++i) {
            pcBoard[i] = new char[C];
        }
        
        cout << "Case #" << test << ':' << endl;
        
        if (M == R * C - 1) {
            for (int y = 0; y < R; ++y) {
                for (int x = 0; x < C; ++x) {
                    pcBoard[y][x] = '*';
                }
                pcBoard[0][0] = 'c';
            }
        } else if (R == 1 && M <= C - 2) {
            pcBoard[0][0] = 'c';
            
            for (int x = 1; x < C; ++x) {
                pcBoard[0][x] = (M >= C - x ? '*' : '.');
            }
        } else if (C == 1 && M <= R - 2) {
            pcBoard[0][0] = 'c';
            
            for (int y = 1; y < R; ++y) {
                pcBoard[y][0] = (M >= R - y ? '*' : '.');
            }
        } else if (M <= (R - 2) * (C - 2) || (M <= R * C - 4 && (M - (R - 2) * (C - 2)) % 2 == 0)) {
            for (int y = 0; y < R; ++y) {
                for (int x = 0; x < C; ++x) {
                    pcBoard[y][x] = '.';
                }
            }
            pcBoard[0][0] = 'c';
            
            for (int y = R - 1; y >= 1; --y) {
                for (int x = C - 1; x >= 1; --x) {
                    if (x == 1 && M >= 2) {
                        pcBoard[y][0] = pcBoard[y][1] = '*';
                        M -= 2;
                    } else if (y == 1 && M >= 2) {
                        pcBoard[0][x] = pcBoard[1][x] = '*';
                        M -= 2;
                    } else if (x > 1) {
                        if (M > 0) {
                            pcBoard[y][x] = '*';
                            --M;
                        }
                    }
                }
            }
        } else if (R > 2 && C > 2 && M <= R * C - 9 && (M - (R - 2) * (C - 2)) % 2 != 0) {
            for (int y = 0; y < R; ++y) {
                for (int x = 0; x < C; ++x) {
                    pcBoard[y][x] = '.';
                }
            }
            pcBoard[0][0] = 'c';
            
            for (int y = R - 1; y >= 1; --y) {
                for (int x = C - 1; x >= 1; --x) {
                    if (x == 2 && y == 2) {
                        break;
                    }
                    
                    if (x == 1 && M >= 2) {
                        pcBoard[y][0] = pcBoard[y][1] = '*';
                        M -= 2;
                    } else if (y == 1 && M >= 2) {
                        pcBoard[0][x] = pcBoard[1][x] = '*';
                        M -= 2;
                    } else if (x > 1) {
                        if (M > 0) {
                            pcBoard[y][x] = '*';
                            --M;
                        }
                    }
                }
            }
        } else {
            cout << "Impossible" << endl;
            goto delete_board;
        }
        
        for (int y = 0; y < R; ++y) {
            for (int x = 0; x < C; ++x) {
                cout << pcBoard[y][x];
            }
            cout << endl;
        }
        
        delete_board:
        for (int i = 0; i < R; ++i) {
            delete[] pcBoard[i];
        }
        delete[] pcBoard;
    }
    
    return 0;
}

/*int click(char** pcBoard, int R, int C, int y, int x, int M, int iTotalMines) {
    bool bFirstCall = (iTotalMines == -1);
    
    int iAdjacentMines = 0;
    
    int iStartY = y > 0 ? y - 1 : 0;
    int iStopY  = y < R - 1 ? y + 1 : y;
    int iStartX = x > 0 ? x - 1 : 0;
    int iStopX  = x < C - 1 ? x + 1 : x;
    
    pcBoard[y][x] = '.';
    
    if (bFirstCall) {
        iTotalMines = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (pcBoard[i][j] == '*') {
                    ++iTotalMines;
                    if (i >= y - 1 && i <= y + 1 && j >= x - 1 && j <= x + 1) {
                        ++iAdjacentMines;
                    }
                }
            }
        }
    } else {
        for (int i = iStartY; i <= iStopY; ++i) {
            for (int j = iStartX; j <= iStopX; ++j) {
                if (pcBoard[i][j] == '*') {
                    ++iAdjacentMines;
                }
            }
        }
    }
    
    if (iTotalMines - iAdjacentMines < M) {
        return iTotalMines;
    }
    
    for (int i = iStartY; i <= iStopY; ++i) {
        for (int j = iStartX; j <= iStopX; ++j) {
            if (pcBoard[i][j] == '*') {
                pcBoard[i][j] = 'c';
                --iTotalMines;
            }
        }
    }
    
    for (int i = iStartY; i <= iStopY; ++i) {
        for (int j = iStartX; j <= iStopX; ++j) {
            if (pcBoard[i][j] != '.') {
                iTotalMines = click(pcBoard, R, C, i, j, M, iTotalMines);
            }
        }
    }
    
    if (bFirstCall) {
        pcBoard[y][x] = 'c';
    }
    
    return iTotalMines;
}*/
