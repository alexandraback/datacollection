#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 50;
const int C = 50;

int r, c, m;
int mines[N][C];
char ans[N][C];
bool found = false;

void display(int mines[][C]) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) cout << (mines[i][j] == -1? '*': (char)(mines[i][j] + '0'));
        cout << endl;
    }
    cout << endl;
}


void init() {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            mines[i][j] = -1;
        }
    }
    mines[r - 1][c - 1] = r == 1 && c == 1? 0: (r == 1 || c == 1? 1 : 3);
}

int find_min(int mines[][C]) {
    int res = r * c + 1;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) if (mines[i][j] > 0 && mines[i][j] < res) {
            res = mines[i][j];
        }
    }
    return res;
}

int click(int mines[][C], int cr, int cc) {
    int res = 1;
    mines[cr][cc] = 0;
    for (int ar = -1; ar <= 1; ++ar) {
        for (int ac = -1; ac <= 1; ++ac) if (ar != 0 || ac != 0) {
            if (cr + ar >= 0 && cr + ar < r && cc + ac >= 0 && cc + ac < c && mines[cr + ar][cc + ac] == -1) {
                ++mines[cr][cc];
            }
            if (cr + ar >= 0 && cr + ar < r && cc + ac >= 0 && cc + ac < c && mines[cr + ar][cc + ac] > 0) {
                --mines[cr + ar][cc + ac];
            }
        }
    }
    if (mines[cr][cc] == 0) {
        for (int ar = -1; ar <= 1; ++ar) {
            for (int ac = -1; ac <= 1; ++ac) if (ar != 0 || ac != 0) {
                if (cr + ar >= 0 && cr + ar < r && cc + ac >= 0 && cc + ac < c && mines[cr + ar][cc + ac] == -1) {
                    res += click(mines, cr + ar, cc + ac);
                }
            }
        }
    }
    return res;
}

void dfs(int mines[][C], int m) {
    if (m == 0) {
        found = true;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                ans[i][j] = mines[i][j] == -1? '*': '.';
            }
        }
        ans[r - 1][c - 1] = 'c';
        return;
    } else {
        int minn = find_min(mines);
        for (int i = 0; i < r; ++i) if (!found) {
            for (int j = 0; j < c; ++j) if (!found && mines[i][j] > 0 && mines[i][j] <= m) {
                int new_mines[N][C];
                memcpy(new_mines, mines, sizeof(new_mines));
                int use = 0;
                for (int ar = -1; ar <= 1; ++ar) {
                    for (int ac = -1; ac <= 1; ++ac) if (ar != 0 || ac != 0) {
                        if (0 <= i + ar && i + ar < r && 0 <= j + ac && j + ac < c && new_mines[i + ar][j + ac] == -1) {
                            use += click(new_mines, i + ar, j + ac);
                        }
                    }
                }
                dfs(new_mines, m - use);
            }
        }
    }
}

int main() {
    int T, cn = 1;
    for (cin >> T; T; --T, ++cn) {
        cin >> r >> c >> m;
        init();
        found = false;
        dfs(mines, r * c - m - 1);
        cout << "Case #" << cn << ":" << endl;
        if (found) {
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    cout << ans[i][j];
                }
                cout << endl;
            }
        } else {
            cout << "Impossible" << endl;
        }
    }
}
