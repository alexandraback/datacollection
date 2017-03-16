
#include <iostream>

using namespace std;

int R, C, M;
char grid[50][50];
int neighbors[50][50];
bool visited[50][50];
int last_r, last_c;

void print_grid() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            cout << grid[i][j];
        cout << endl;
    }
}

void dfs(int i, int j) {
    if (i < 0 || j < 0 || i >= R || j >= C || visited[i][j])
        return;
    visited[i][j] = true;
    if (grid[i][j] != '.' || neighbors[i][j] > 0)
        return;
    for (int dr = -1; dr <= 1; dr++)
        for (int dc = -1; dc <= 1; dc++)
            if (dr != 0 || dc != 0)
                dfs(i + dr, j + dc);
}

bool expand(int i0, int j0) {
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            visited[i][j] = false;

    dfs(i0, j0);
    last_r = i0, last_c = j0;

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (!visited[i][j] && grid[i][j] == '.')
                return false;
    return true;
}

bool can_finish() {
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (grid[i][j] == '.' && expand(i, j))
                return true;
    return false;
}

bool can_finish_any() {
    for (int mask = 0; mask < (1 << (R * C)); mask++) {
        if (__builtin_popcount(mask) != M)
            continue;

        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                if (mask & (1 << (i * C + j)))
                    grid[i][j] = '*';
                else
                    grid[i][j] = '.';

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                neighbors[i][j] = 0;
                if (grid[i][j] == '*')
                    continue;
                for (int dr = -1; dr <= 1; dr++) {
                    for (int dc = -1; dc <= 1; dc++) {
                        if (dr == 0 && dc == 0)
                            continue;
                        int ii = i + dr, jj = j + dc;
                        if (ii >= 0 && jj >= 0 && ii < R && jj < C && grid[ii][jj] == '*')
                            neighbors[i][j]++;
                    }
                }
            }
        }
        if (can_finish())
            return true;
    }
    return false;
}

bool can_solve() {
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            grid[i][j] = '*';

    int n = R * C - M;
    if (n == 1 || R == 1 || C == 1) {
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) {
                grid[i][j] = '.';
                n--;
                if (n == 0)
                    return true;
            }
    }

    for (int r = 2; r <= R; r++)
        for (int c = 2; c <= C; c++) {
            if (n == r * c) {
                for (int i = 0; i < r; i++)
                    for (int j = 0; j < c; j++)
                        grid[i][j] = '.';
                return true;
            }
            else if (c < C && n >= r * c + 2 && n < r * (c + 1)) {
                for (int i = 0; i < r; i++)
                    for (int j = 0; j < c; j++)
                        grid[i][j] = '.';
                for (int i = 0; i < n - r * c; i++)
                    grid[i][c] = '.';
                return true;
            }
            else if (r < R && n >= r * c + 2 && n < (r + 1) * c) {
                for (int i = 0; i < r; i++)
                    for (int j = 0; j < c; j++)
                        grid[i][j] = '.';
                for (int j = 0; j < n - r * c; j++)
                    grid[r][j] = '.';
                return true;
            }
            else if (r < R && c < C && n >= r * c + 4 && n < (r + 1) * (c + 1)) {
                for (int i = 0; i < r; i++)
                    for (int j = 0; j < c; j++)
                        grid[i][j] = '.';
                int nr = 2, nc = 2;
                int left = n - r * c - nr - nc;
                while (nr < r && left > 0)
                    nr++, left--;
                while (nc < c && left > 0)
                    nc++, left--;
                for (int i = 0; i < nr; i++)
                    grid[i][c] = '.';
                for (int j = 0; j < nc; j++)
                    grid[r][j] = '.';
                return true;
            }
        }

    return false;
}

void solve() {
    cin >> R >> C >> M;

    if (can_solve()) {
        grid[0][0] = 'c';
        print_grid();
    }
    else
        cout << "Impossible" << endl;
}

void verify() {
    for (R = 1; R <= 5; R++)
        for (C = 1; C <= 5; C++)
            for (M = 0; M < R * C; M++)
                if (can_solve() != can_finish_any()) {
                    cerr << R << " " << C << " " << M << " MISMATCH" << endl;
                    return;
                }
    cerr << "ALL MATCHED" << endl;
}

int main() {
    // verify();

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << endl;
        solve();
    }
}

