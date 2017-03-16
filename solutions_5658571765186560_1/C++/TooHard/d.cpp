#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define INF (0x3f3f3f3f)

#define SZ(x) ((int)((x).size()))
#define PB(x) push_back(x)
#define MEMSET(x,v) memset(x,v,sizeof(x))
#define REP(i,n) for(int (i)=0;(i)<(n);++(i))

typedef long long LL;
typedef pair<int, int> PII; typedef pair<PII, int> PII2;

#define MAXN (6)
#define MAXB (25)

int X, R, C;
char board[MAXN][MAXN];

int cx[] = {-1, 1, 0, 0}, cy[] = {0, 0, -1, 1};
char pieces[5000][MAXN][MAXN];

int cnt = 0;

bool exactly_match(char a[MAXN][MAXN], char b[MAXN][MAXN]) {
    REP(i, X) REP(j, X) if (a[i][j] != b[i][j]) return false;
    return true;
}

void simplify(char a[MAXN][MAXN]) {
    char temp[MAXN][MAXN];
    int mini = X, minj = X;
    REP(i, X) REP(j, X) if (a[i][j] == 'O') mini = min(mini, i);
    REP(j, X) REP(i, X) if (a[i][j] == 'O') minj = min(minj, j);
    REP(i, X) REP(j, X) temp[i][j] = 'X';
    REP(i, X) REP(j, X) {
        if (a[i][j] == 'O') temp[i - mini][j - minj] = 'O';
    }
    REP(i, X) REP(j, X) a[i][j] = temp[i][j];
}

void rotate90(char a[MAXN][MAXN]) {
    char temp[MAXN][MAXN];
    REP(i, X) REP(j, X) {
        temp[j][X - i - 1] = a[i][j];
    }
    REP(i, X) REP(j, X) a[i][j] = temp[i][j];
    simplify(a);
}
void reflex(char a[MAXN][MAXN]) {
    char temp[MAXN][MAXN];
    REP(i, X) REP(j, X) {
        temp[i][X - j - 1] = a[i][j];
    }
    REP(i, X) REP(j, X) a[i][j] = temp[i][j];
    simplify(a);
}

bool same(char a[MAXN][MAXN], char b[MAXN][MAXN]) {
    if (exactly_match(a, b)) return true;
    for (int i = 0; i < 4; i++) {
        rotate90(b);
        for (int j = 0; j < 2; j++) {
            reflex(b);
            if (exactly_match(a, b)) return true;
        }
    }
    return false;
}

void gen(int si, int sj, int piece) {
    board[si][sj] = 'O';
    if (piece == X) {
        bool good = false;
        REP(j, X) {
            if (board[0][j] == 'O') {
                good = true;
                break;
            }
        }
        if (good) {
            char temp[MAXN][MAXN];

            bool bad = false;
            for (int a = 0; a < cnt; a++) {
                REP(i, X) REP(j, X) temp[i][j] = board[i][j];
                if (same(pieces[a], temp)) {
                    bad = true;
                }
            }

            if (!bad) {
                REP(i, X) REP(j, X) pieces[cnt][i][j] = board[i][j];
                simplify(pieces[cnt]);

                /*

                if (cnt < 10) {
                    cout << X << endl;
                    REP(i, X) {
                        REP(j, X) {
                            cout << pieces[cnt][i][j];
                        }
                        cout << endl;
                    }
                }
                */
                cnt++;
            }
        }
    } else {
        REP(i, X) {
            REP(j, X) {
                if (board[i][j] == 'O') {
                    REP(k, 4) {
                        int ii = i + cx[k];
                        int jj = j + cy[k];
                        if (ii >= 0 && jj >= 0 && ii < X && jj < X && board[ii][jj] == 'X') {
                            gen(ii, jj, piece + 1);
                        }
                    }
                }
            }
        }
    }
    board[si][sj] = 'X';
}

char test_board[MAXB][MAXB];

int dfs_number;

void dfs(int i, int j) {
    dfs_number++;
    test_board[i][j] = 'O';
    REP(k, 4) {
        int ii = i + cx[k];
        int jj = j + cy[k];
        if (ii >= 0 && jj >= 0 && ii < R && jj < C && test_board[ii][jj] == 'X') {
            dfs(ii, jj);
        }
    }
}

bool test(int ii, int jj, int pid) {
    REP(i, R) REP(j, C) test_board[i][j] = 'X';
    REP(i, X) {
        REP(j, X) {
            if (pieces[pid][i][j] == 'O') {
                if (ii + i >= R || jj + j >= C) {
                    return false;
                } else {
                    test_board[i][j] = 'O';
                }
            }
        }
    }
    REP(i, R) REP(j, C) {
        if (test_board[i][j] == 'X') {
            dfs_number = 0;
            dfs(i, j);
            if (dfs_number % X) {
                return false;
            }
        }
    }
    return true;
}


bool can_place(int pid) {
    bool good = false;
    REP(i, R) {
        if (good) break;
        REP(j, C) {
            if (good) break;
            for (int p = 0; p < 4; p++) {
                rotate90(pieces[pid]);
                for (int q = 0; q < 2; q++) {
                    reflex(pieces[pid]);
                    good |= test(i, j, pid);
                }
            }
        }
    }
    return good;
}

void solve() {
    cin >> X >> R >> C;
    if ((R * C) % X) {
        printf("RICHARD\n");
        return ;
    }
    if (R < X && C < X) {
        printf("RICHARD\n");
        return ;
    }
    if (X > MAXN) {
        printf("RICHARD\n");
        return ;
    }
    REP(i, MAXN) REP(j, MAXN) board[i][j] = 'X';
    cnt = 0;
    for (int i = 0; i < X; i++) {
        gen(i, 0, 1);
    }
    //        cout << cnt << endl;

    REP(i, cnt) {
        if (!can_place(i)) {
            printf("RICHARD\n");
            /*
            cout << X << endl;
                    REP(i1, X) {
                        REP(j1, X) {
                            cout << pieces[i][i1][j1];
                        }
                        cout << endl;
                    }
            */
            return ;
        }
    }
    printf("GABRIEL\n");
}

int main() {
    int test;
    cin >> test;
    REP(t, test) {
        printf("Case #%d: ", t + 1);
        solve();
    }
    
    return 0;
}
