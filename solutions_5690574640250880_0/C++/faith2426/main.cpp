#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int R, C, M;
vector<char> status;
int trueCount;
vector< vector<char> > board;
vector< vector<char> > boardForSim;
bool result;
int ccc;

void clickOnBoard(int r, int c) {
    if (board[r][c] == '*') {
        return;
    }

    if (boardForSim[r][c] != ' ') {
        return;
    }

    int mines = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }

            int r1 = r + i;
            int c1 = c + j;
            if (r1 < 0 || r1 >= R || c1 < 0 || c1 >= C) {
                continue;
            }

            if (board[r1][c1] == '*') {
                ++mines;
            }
        }
    }

    boardForSim[r][c] = '0' + mines;
    if (mines == 0) {
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }

                int r1 = r + i;
                int c1 = c + j;
                if (r1 < 0 || r1 >= R || c1 < 0 || c1 >= C) {
                    continue;
                }

                clickOnBoard(r1, c1);
            }
        }
    }
}

bool verifyBoard() {
    if (trueCount < M) {
        return false;
    }

    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            int index = r * C + c;
            if (status[index] == 0) {
                board[r][c] = '.';
            } else {
                board[r][c] = '*';
            }
        }
    }

    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (board[r][c] == '*') {
                continue;
            }

            for (int x = 0; x < R; ++x) {
                for (int y = 0; y < C; ++y) {
                    boardForSim[x][y] = ' ';
                }
            }

            clickOnBoard(r, c);

            int notRevealed = 0;
            for (int x = 0; x < R; ++x) {
                for (int y = 0; y < C; ++y) {
                    if (boardForSim[x][y] == ' ') {
                        ++notRevealed;
                    }
                }
            }

            if (notRevealed == M) {
                board[r][c] = 'c';
                return true;
            }
        }
    }

    return false;
}

void dfs(int level) {
    for (char s = 0; s <= 1 && !result; ++s) {
        if (trueCount == M && s == 1) {
            continue;
        }

        status[level] = s;
        trueCount += s;

        if (level == R * C - 1) {
            result = verifyBoard();
        } else {
            dfs(level + 1);
        }

        trueCount -= s;
    }
}

int main() {
    ifstream ifs("in.in");
    ofstream ofs("out.out");

    int T;
    ifs >> T;
    for (int t = 1; t <= T; ++t) {
        ifs >> R >> C >> M;

        for (int r = 0; r < R; ++r) {
            vector<char> row;
            for (int c = 0; c < C; ++c) {
                row.push_back(' ');
            }
            board.push_back(row);
            boardForSim.push_back(row);
        }

        status.resize(R * C);
        trueCount = 0;
        result = false;
        dfs(0);

        ofs << "Case #" << t << ":" << endl;
        if (!result) {
            ofs << "Impossible" << endl;
        } else {
            for (int r = 0; r < R; ++r) {
                for (int c = 0; c < C; ++c) {
                    ofs << board[r][c];
                }
                ofs << endl;
            }
        }
    }

    return 0;
}
