#include <iostream>

using namespace std;

int n, m;
int t[10][10];
int q[10][10];

bool v[10][10][25];
int s[10][10][25][10][10];
int aa[10][10][25][2];

void kopioi(int c) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s[n][m][c][i][j] = t[i][j];
        }
    }
}

int tc;

void tayta(int y, int x) {
    if (y < 1 || x < 1 || y > n || x > m) return;
    if (q[y][x] == -1) return;
    tc++;
    int w = q[y][x];
    q[y][x] = -1;
    if (w == 0) {
        tayta(y-1, x-1);
        tayta(y-1, x);
        tayta(y-1, x+1);
        tayta(y, x-1);
        tayta(y, x+1);
        tayta(y+1, x-1);
        tayta(y+1, x);
        tayta(y+1, x+1);
    }
}

void tutki() {
    int c = 0;
    int ay, ax;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (t[i][j]) c++;
            if (t[i][j]) q[i][j] = -1;
            else {ay = i; ax = j; q[i][j] = 0;}
        }
    }
    if (c == n*m) return;
    if (v[n][m][c]) return;
    if (c == n*m-1) {
        v[n][m][c] = true;
        kopioi(c);
        aa[n][m][c][0] = ay;
        aa[n][m][c][1] = ax;
        return;
    }
    bool ok = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (q[i][j] == -1) continue;
            q[i][j] += t[i-1][j-1];
            q[i][j] += t[i-1][j];
            q[i][j] += t[i-1][j+1];
            q[i][j] += t[i][j-1];
            q[i][j] += t[i][j+1];
            q[i][j] += t[i+1][j-1];
            q[i][j] += t[i+1][j];
            q[i][j] += t[i+1][j+1];
            if (q[i][j] == 0) {ok = true; ay = i; ax = j;}
        }
    }
    if (!ok) return;
    tc = 0;
    tayta(ay, ax);
    if (tc != n*m-c) return;
    v[n][m][c] = true;
    kopioi(c);
    aa[n][m][c][0] = ay;
    aa[n][m][c][1] = ax;
}

void haku(int y, int x) {
    if (y == n) {
        tutki();
        return;
    } else if (x == m) {
        haku(y+1, 0);
        return;
    }
    t[y+1][x+1] = 0;
    haku(y, x+1);
    t[y+1][x+1] = 1;
    haku(y, x+1);
}

int main() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            n = i;
            m = j;
            for (int a = 0; a < 10; a++) {
                for (int b = 0; b < 10; b++) {
                    t[a][b] = q[a][b] = 0;
                }
            }
            haku(0, 0);
        }
    }
    int t;
    cin >> t;
    for (int x = 1; x <= t; x++) {
        cout << "Case #" << x << ":\n";
        int r, c, m;
        cin >> r >> c >> m;
        if (!v[r][c][m]) {
            cout << "Impossible\n";
            continue;
        }
        int ay = aa[r][c][m][0];
        int ax = aa[r][c][m][1];
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                int u = s[r][c][m][i][j];
                if (u == 0 && i == ay && j == ax) cout << "c";
                else if (u == 0) cout << ".";
                else cout << "*";
            }
            cout << endl;
        }
    }
}
