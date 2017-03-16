#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAX_R = 60;
const int CUTOFF = 4;

char A[MAX_R][MAX_R];

int fillRight(char a[MAX_R][MAX_R], int R, int C, int toFill) {
    if (toFill == 0)
        return 0;

    for (int c = C - 1; c >= CUTOFF; --c) {
        for (int r = 0; r < R; ++r) {
            a[r][c] = '*';
            --toFill;
            if (toFill == 0) {
                if (r == R - 2) {
                    a[r][c] = '.';
                    if (R == 2) {
                        return 1;
                    }
                    else {
                        a[0][c-1] = '*';
                        return 0;
                    }
                }

                return 0;
            }
        }
    }

    return toFill;
}

int fillBottom(char a[MAX_R][MAX_R], int R, int C, int toFill) {
    if (toFill == 0)
        return 0;

    for (int r = R - 1; r >= CUTOFF; --r) {
        for (int c = min(C - 1, CUTOFF - 1); c >= 0; --c) {
            a[r][c] = '*';
            --toFill;
            if (toFill == 0) {
                if (c == 1) {
                    a[r][c] = '.';
                    if (C == 2) {
                        return 1;
                    } else {
                        a[r-1][min(C - 1, CUTOFF - 1)] = '*';
                        return 0;
                    }
                }

                return 0;
            }
        }
    }

    return toFill;
}

int dx[8] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dy[8] = {0, -1, 0, 1, 1, -1, 1, -1};

bool hasBadNeighbor(char a[MAX_R][MAX_R], int R, int C, int r, int c) {
    for (int dir = 0; dir < 8; ++dir) {
        int nr = r + dx[dir];
        int nc = c + dy[dir];

        //cout << "CheckNeighbor: " << r << ", " << c << " / " << nr << "," << nc << endl;

        if (nr >= 0 && nr < R && nc >= 0 && nc < C &&
            a[nr][nc] == '*') {
            //cout << "BadNeighbor: " << r << ", " << c << " / " << nr << "," << nc << endl;
            return true;
        }
    }

    return false;
}

bool getStart(char a[MAX_R][MAX_R], int R, int C, int& startR, int& startC) {
    for (int r = 0; r < R; ++r)
        for (int c = 0; c < C; ++c) {
            bool badNeighbor = hasBadNeighbor(a, R, C, r, c);
            if (!badNeighbor && a[r][c] != '*') {
                startR = r;
                startC = c;
                return true;
            }
        }

    return false;
}

void printMatrix2(char A[MAX_R][MAX_R], int R, int C, int startC, int startR) {
    cout << endl;
    cout << "Checking board: " << endl;
    for (int i = 0; i < R; ++i, cout << endl)
        for (int j = 0; j < C; ++j)
            cout << A[i][j];
}

int viz[MAX_R][MAX_R];
#define enq(r, c) viz[r][c] = 1, q.push(make_pair(r, c))

bool checkBoard(char a[MAX_R][MAX_R], int R, int C, int remaining, int& startR, int& startC) {
    //printMatrix2(a, R, C, startR, startC);
    bool hasStart = getStart(a, R, C, startR, startC);
    if (!hasStart)
        return false;

    //cout << "Start: " << startR << ", " << startC << endl;

    memset(viz, 0, sizeof(viz));
    int vizCount = 1;

    queue< pair<int, int> > q;
    enq(startR, startC);

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int r = p.first, c = p.second;

        for (int dir = 0; dir < 8; ++dir) {
            int nr = r + dx[dir];
            int nc = c + dy[dir];

            if (nr >= 0 && nr < R && nc >= 0 && nc < C && !viz[nr][nc]) {
                viz[nr][nc] = 1;
                vizCount++;
                if (!hasBadNeighbor(a, R, C, nr, nc))
                    q.push(make_pair(nr, nc));
            }
        }
    }

    //cout << "VizCount: " << vizCount << " out of " << remaining;
    return vizCount == remaining;
}

int fillBackTrack(char a[MAX_R][MAX_R], int R, int C, int toFill, int empty, int& startR, int& startC) {
    int actualR = min(R, CUTOFF);
    int actualC = min(C, CUTOFF);

    for (int i = 0; i < actualR; ++i)
        for (int j = 0; j < actualC; ++j)
            if (a[i][j] == '*') {
                toFill++;
                a[i][j] = '.';
                cerr << "Found" << endl;
            }

    for (int cfg = 0; cfg < 1 << (actualR * actualC); ++cfg)
        if (__builtin_popcount(cfg) == toFill) {
            for (int i = 0; i < actualR * actualC; ++i) {
                if (cfg & (1 << i))
                    a[i / actualC][i % actualC] = '*';
            }

            if (checkBoard(a, R, C, empty, startR, startC))
                return 0;

            for (int i = 0; i < actualR * actualC; ++i) {
                if (cfg & (1 << i))
                    a[i / actualC][i % actualC] = '.';
            }
        }

    return toFill;
}

void printMatrix(char A[MAX_R][MAX_R], int R, int C, int M,int startC, int startR) {
    int bombs = 0;
    for (int r = 0; r < R; ++r)
        for (int c = 0; c < C; ++c)
            if (A[r][c] == '*')
                bombs++;

    if (bombs != M)
        cerr << "Bombs != M: " << bombs << " " << M << endl;

    A[startC][startR] = 'c';
    for (int i = 0; i < R; ++i, cout << endl)
        for (int j = 0; j < C; ++j)
            cout << A[i][j];
}

void solve(int testNo, int R, int C, int M) {
    int m = M;
    
    if (R*C - 1 == M) {
        memset(A, '*', sizeof(A));
        A[0][0] = 'c';
        m = 0;
    }
    else {
        memset(A, '.', sizeof(A));
    }
    
    if (m > 0)
        m = fillRight(A, R, C, m);
    if (m > 0)
        m = fillBottom(A, R, C, m);
    
    int startR = 0, startC = 0;
    if (m > 0)
        m = fillBackTrack(A, R, C, m, R*C - M, startR, startC);

    cout << "Case #" << testNo << ": " << endl;
    if (m == 0)
        printMatrix(A, R, C, M, startR, startC);
    else
        cout << "Impossible" << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int R, C, M;
        cin >> R >> C >> M;
        solve(i, R, C, M);
    }
    return 0;
}
