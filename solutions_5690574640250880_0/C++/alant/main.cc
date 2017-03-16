#include <iostream>
#include <cstring>

using namespace std;

struct C {

    int r, c;
    int L;
    int ar[5][5];
    int ans[26];

    C() {}

    C(int r, int c)
        :r(r), c(c)
    {
        L = 1 << (r * c);
        memset(ans, 255, sizeof(ans));
        preProcess();
    }

    int get(int y, int x, int mask) {
        return (mask >> (y * c + x)) & 1;
    }

    void print() {
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cerr << (ar[i][j] == 1 ? '*' : ar[i][j] == -1 ? '.' : '-');
            }
            cerr << "\n";
        }
    }

    int countPositive(int y, int x) {
        int count = 0;
        for (int dy = -1; dy <= 1; ++dy) {
            for (int dx = -1; dx <= 1; ++dx) {
                if ((y + dy < 0) | (y + dy >= r) || (x + dx < 0) || (x + dx >= c)) {
                    continue;
                }
                if (ar[y + dy][x + dx] > 0) {
                    ++count;
                }
            }
        }
        return count;
    }

    int countNegative(int y, int x) {
        int count = 0;
        for (int dy = -1; dy <= 1; ++dy) {
            for (int dx = -1; dx <= 1; ++dx) {
                if ((y + dy < 0) | (y + dy >= r) || (x + dx < 0) || (x + dx >= c)) {
                    continue;
                }
                if (ar[y + dy][x + dx] < 0) {
                    ++count;
                }
            }
        }
        return count;
    }

    void dfs(int y, int x) {
        if ((y < 0) || (y >= r) || (x < 0) || (x >= c)) {
            return;
        }
        if (ar[y][x] != -1) {
            return;
        }
        ar[y][x] = -2;
        for (int i = y - 1; i <= y + 1; ++i) {
            for (int j = x - 1; j <= x + 1; ++j) {
                dfs(i, j);
            }
        }
    }

    void preProcess() {
        for (int mask = 0; mask < L; ++mask) {
            int ones = 0;
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    ones += ar[i][j] = get(i, j, mask);
                }
            }
            if (ans[ones] >= 0) {
                continue;
            }
            bool atLeastOne = false;
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    if ((ar[i][j] == 0) && (countPositive(i, j) == 0)) {
                        ar[i][j] = -1;
                        atLeastOne = true;
                    }
                }
            }
            bool cont = atLeastOne;
            for (int i = 0; cont && (i < r); ++i) {
                for (int j = 0; cont && (j < c); ++j) {
                    if ((ar[i][j] == 0) && (countNegative(i, j) == 0)) {
                        cont = false;
                    }
                }
            }
            dfs(r - 1, c - 1);
            bool ok = cont;
            for (int i = 0; ok && (i < r); ++i) {
                for (int j = 0; ok && (j < c); ++j) {
                    if (ar[i][j] == -1) {
                        ok = false;
                    }
                }
            }
            /*
            if ((r == 4) && (c == 1)) {
                cerr << mask << " " << ones << "\n";
                print();
                cerr << atLeastOne << " " << cont << " " << ok << "\n";
                cerr << "\n";
            }
            */
            if (ok) {
                ans[ones] = mask;
            }
        }
    }
};

C cr[5][5];

int main() {
    int M = 5;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            cr[i][j] = C(i + 1, j + 1);
        }
    };
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int r, c, m;
        cin >> r >> c >> m;
        cout << "Case #" << t << ":\n";
        if (m == r * c - 1) {
            for (int i = 0; i < r - 1; ++i) {
                for (int j = 0; j < c; ++j) {
                    cout << "*";
                }
                cout << "\n";
            }
            for (int i = 0; i < c - 1; ++i) {
                cout << "*";
            }
            cout << "c\n";
            continue;
        }
        if (cr[r - 1][c - 1].ans[m] == -1) {
            cout << "Impossible\n";
        } else {
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    cout << ((i+1)*(j+1) == r*c ? 'c' : cr[r - 1][c - 1].get(i, j, cr[r - 1][c - 1].ans[m]) ? '*' : '.');
                }
                cout << "\n";
            }
        }
    }
}

