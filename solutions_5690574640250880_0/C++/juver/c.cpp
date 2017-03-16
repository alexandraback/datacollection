#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <float.h>

using namespace std;

#define REP(i, from, to) for (int i = (from); i < (to); ++i)
#define FOR(i, n) REP(i, 0, (n))
#define ALL(x) x.begin(), x.end()
#define SIZE(x) (int)x.size()
#define PB push_back
#define MP make_pair

typedef long long i64;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<VS> VVS;
typedef pair<int, int> PII;

void dfs(int r, int c, VS& tmp) {
    if (r < 0 | c < 0 | r >= SIZE(tmp) | c >= SIZE(tmp[r]) || tmp[r][c] == '*' || tmp[r][c] == 'x')
        return;

    tmp[r][c] = 'x';
    int mines = 0;
    REP (di, -1, 2) REP (dj, -1, 2) {
        int const r1 = r + di;
        int const c1 = c + dj;
        if (r1 < 0 | c1 < 0 | r1 >= SIZE(tmp) | c1 >= SIZE(tmp[r]))
                continue;
        mines += tmp[r1][c1] == '*';
    }

    if (mines)
        return;
    REP (di, -1, 2) REP (dj, -1, 2) {
        int const r1 = r + di;
        int const c1 = c + dj;
        if (r1 < 0 | c1 < 0 | r1 >= SIZE(tmp) | c1 >= SIZE(tmp[r]))
                continue;
        dfs(r1, c1, tmp);
    }
}

bool check(VS const& table, int m) {
    VS tmp = table;
    FOR (i, SIZE(table)) FOR (j, SIZE(table[i]))
            if (table[i][j] == 'c')
                dfs(i, j, tmp);
            else if (table[i][j] == '*')
                --m;

    if (m != 0) return false;

    FOR (i, SIZE(tmp)) FOR (j, SIZE(tmp[i]))
            if (table[i][j] == '.' && tmp[i][j] != 'x')
                return false;
    return true;
}

bool solve(int r, int c, int m, VS& table) {
    table.resize(r, string(c, '.'));
    FOR (i, m / c)
        table[i] = string(c, '*');

    int const emptyRows = r - m / c - 1;
    int const fillRow = m / c;
    if (m % c == 0) {
        table[r - 1][c / 2] = 'c';
        if (emptyRows == 0) {
            table.clear();
            return false;
        }
    } else {
        m %= c;
        if (emptyRows == 1) {
            if (m % 2 != 0 || c - m / 2 < 2) {
                table.clear();
                return false;
            }

            REP (i, fillRow, r) FOR (j, m / 2)
                    table[i][j] = '*';
            table[r - 1][c - 1] = 'c';
        } else {
            FOR (j, m)
                    table[fillRow][j] = '*';
            if (emptyRows == 0) {
                if (m != 1) {
                    table.clear();
                    return false;
                }
            } else if (m == c - 1) {
                if (m <= 2) {
                    table.clear();
                    return false;
                }

                table[fillRow][m - 1] = table[fillRow][m - 2] = '*';
                table[fillRow + 1][0] = table[fillRow + 2][0] = '*';
            }

            table[r - 1][c - 1] = 'c';
        }
    }

    return true;
}

bool solve2(int r, int c, int m, VS& table) {
    FOR (full, r) {
        VS can;
        can.resize(r, string(c, '.'));
        FOR (i, full)
                can[i] = string(c, '*');

        int mines = m - full * c;
        int notFull = r - full;
        int const minesOnEach = mines / notFull;
        REP (i, full, r) {
            FOR (j, minesOnEach)
                    can[i][j] = '*';
        }

        FOR (j, mines % notFull)
                can[full][minesOnEach + j] = '*';

        can[r - 1][c - 1] = 'c';
        if (check(can, m)) {
            table = can;
            return true;
        }

        REP (i, full, r) {
            can[i] = string(c, '.');
        }

        if (notFull >= 2 && mines <= c) {
            REP (a, 1, mines + 1) {
                int const b = mines - a;

                FOR (j, c) {
                    if (j < a)
                        can[full][j] = '*';
                    else can[full][j] = '.';
                    if (j < b)
                        can[full + 1][j] = '*';
                    else can[full + 1][j] = '.';
                }

                can[r - 1][c - 1] = 'c';
                if (check(can, m)) {
                    table = can;
                    return true;
                }
            }
        }

    }

    table.clear();
    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tests;
    cin >> tests;

    FOR (t, tests) {
        int r, c, m;
        cin >> r >> c >> m;

        VS result;
        if (!solve2(r, c, m, result)) {
            if (solve2(c, r, m, result)) {
                //// TODO: rotate;
                VS rotated(r, string(c, '.'));
                FOR (i, r) FOR (j, c)
                        rotated[i][j] = result[j][i];
                result = rotated;
            }
        }

        printf("Case #%d:\n", t + 1);
        if (result.empty())
            printf("Impossible\n");
        else {
            FOR (i, r) {
                printf("%s\n", result[i].c_str());
            }
        }
    }

    return 0;
}
