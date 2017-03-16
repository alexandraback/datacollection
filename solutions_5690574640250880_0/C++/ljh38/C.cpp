#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cassert>
#include <limits>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

bool Mines[50][50];
int AdjCount[50][50];

struct Cell {
    Cell(int rr = -1, int cc = -1) : r(rr), c(cc) {}

    int r, c;
};

int dr[9] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
int dc[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

void printGrid(int R, int C, bool counts, int clickR, int clickC) {
    for (int r = 0; r != R; ++r) {
        for (int c = 0; c != C; ++c) {
            if (Mines[r][c]) {
                cout << '*';
            } else if (counts) {
                cout << AdjCount[r][c];
            } else if (r == clickR && c == clickC) {
                cout << 'c';
            } else {
                cout << '.';
            }
        }
        cout << endl;
    }
}

void computeAdjacencies(int R, int C) {
    for (int r = 0; r != R; ++r) {
        for (int c = 0; c != C; ++c) {
            int count = 0;
            
            for (int i = 0; i != 9; ++i) {
                int rr = r + dr[i];
                int cc = c + dc[i];
                if (rr >= 0 && rr < R && cc >= 0 && cc < C) {
                    if (Mines[rr][cc]) {
                        ++count;
                    }
                }
            }
            AdjCount[r][c] = count;
        }
    }
}

bool isWinning(int R, int C, int M, int& clickR, int& clickC) {
    if (M+1 == R*C && !Mines[clickR][clickC]) {
        return true;
    }

    // every empty >0 cell must have a 0 adjacent
    vector<Cell> zeroes;
    for (int r = 0; r != R; ++r) {
        for (int c = 0; c != C; ++c) {
            if (!Mines[r][c] && AdjCount[r][c] > 0) {
                bool foundZero = false;
                for (int i = 0; i != 9; ++i) {
                    int rr = r + dr[i];
                    int cc = c + dc[i];
                    if (rr >= 0 && rr < R && cc >= 0 && cc < C) {
                        if (AdjCount[rr][cc] == 0) {
                            foundZero = true;
                            break;
                        }
                    }
                }
                if (!foundZero) {
                    return false;
                }
            }
            if (AdjCount[r][c] == 0) {
                zeroes.push_back(Cell(r, c));
            }
        }
    }

    // zeroes must be connected
    if (zeroes.empty()) {
        return false;
    }
    queue<Cell> open;
    open.push(zeroes.front());
    bool Visited[50][50] = { 0 };
    clickR = zeroes.front().r;
    clickC = zeroes.front().c;
    Visited[clickR][clickC] = true;

    int numZeroesFound = 0;
    while (!open.empty()) {
        Cell cell = open.front();
        open.pop();
        ++numZeroesFound;
        
        for (int i = 0; i != 9; ++i) {
            int rr = cell.r + dr[i];
            int cc = cell.c + dc[i];
            if (rr >= 0 && rr < R && cc >= 0 && cc < C) {
                if (AdjCount[rr][cc] == 0 && !Visited[rr][cc]) {
                    Visited[rr][cc] = true;
                    open.push(Cell(rr, cc));
                }
            }
        }
    }

    return numZeroesFound == zeroes.size();
}

bool solve(int R, int C, int M, int& clickR, int& clickC) {
    if (R > C) {
        bool result = solve(C, R, M, clickC, clickR);
        for (int i = 0; i != 50; ++i) {
            for (int j = i+1; j != 50; ++j) {
                std::swap(Mines[i][j], Mines[j][i]);
            }
        }
        return result;
    }
    
    if (M == R*C) { return false; }
    else if (M+1 == R*C) {
        for (int r = 0; r != R; ++r) {
            for (int c = 0; c != C; ++c) {
                Mines[r][c] = true;
            }
        }
        Mines[R-1][C-1] = false;
        clickR = R-1;
        clickC = C-1;
        return true;
    }
        
    for (int r = 0; r != R; ++r) {
        for (int c = 0; c != C; ++c) {
            Mines[r][c] = false;
        }
    }
    if (M == 0) {
        clickR = R-1;
        clickC = C-1;
        return true;
    }
    
    if (R == 1) {
        for (int c = 0; c != M; ++c) {
            Mines[0][c] = true;
        }
        clickR = 0;
        clickC = C - 1;
        return M == 0 || (M <= (C-2));
    } else if (R == 2) {
        if (M & 1) {
            return false;
        }
        if (M != 0 && (M >= R*C-2)) {
            return false;
        }
        int placed = 0;
        for (int c = 0; c != M; ++c) {
            if (placed < M) {
                Mines[0][c] = true;
                Mines[1][c] = true;
                placed += 2;
            } else {
                break;
            }
        }
        clickR = R-1;
        clickC = C-1;
        return true;
        
    } else {
        int placed = 0;
        Cell last;
        for (int r = 0; r+3 < R; ++r) {
            for (int c = 0; c != C; ++c) {
                if (placed < M) {
                    Mines[r][c] = true;
                    last = Cell(r, c);
                    ++placed;
                }
            }
        }
        if (placed == M) {
            if ((M % C) == C-1) {
                Mines[last.r][last.c] = false;
                Mines[last.r+1][0] = true;
            }
            clickR = R-1;
            clickC = C-1;
            return true;
        }

        for (int c = 0; c+3 < C; ++c) {
            for (int r = R-3; r < R; ++r) {
                if (placed != M) {
                    Mines[r][c] = true;
                    placed++;
                    last = Cell(r, c);
                } else {
                    break;
                }
            }
        }
        if (placed == M) {
            if (last.r == R-2) {
                Mines[R-2][last.c] = false;
                Mines[R-3][last.c+1] = true;
            }
            clickR = R-1;
            clickC = C-1;
            return true;
        }
        
        int remaining = M - placed;
        assert(remaining < 9 && remaining > 0);
        assert(C >= 3);
        clickR = R-1;
        clickC = C-1;

        if (remaining == 1) {
            Mines[R-3][C-3] = true;
            return true;
        } else if (remaining == 3) {
            Mines[R-3][C-3] = Mines[R-3][C-2] = Mines[R-3][C-1] = true;
            return true;
        } else if (remaining == 5) {
            Mines[R-3][C-3] = Mines[R-3][C-2] = Mines[R-3][C-1] = true;
            Mines[R-2][C-3] = Mines[R-1][C-3] = true;
            return true;
        } else {
            return false;
        }
    }
}

void autotest(int R, int C) {
    for (int m = 0; m != R*C; ++m) {
        int clickR, clickC;

        if (solve(R, C, m, clickR, clickC)) {
            computeAdjacencies(R, C);
            assert(isWinning(R, C, m, clickR, clickC));
        }
    }
}

int main() {
    // ifstream in("sample.in");
    istream& in = cin;

    int T;
    in >> T;
    for (int t = 0; t != T; ++t) {
        int R, C, M;
        in >> R >> C >> M;
        cout << "Case #" << (t+1) << ":" << endl;
        
        int clickR, clickC = 0;
        
        bool result = solve(R, C, M, clickR, clickC);
        if (result) {
            // computeAdjacencies(R, C);
            // assert(isWinning(R, C, M, clickR, clickC));
            printGrid(R, C, false, clickR, clickC);
        } else {
            cout << "Impossible\n";
        }
    }

    return 0;
}
