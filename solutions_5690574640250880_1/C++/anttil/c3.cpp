#include <iostream>

using namespace std;

int t;
char d[200][200];

void tutki(int r, int c, int q) {
    if (q == r*c-1) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (i == 0 && j == 0) cout << "c";
                else cout << "*";
            }
            cout << endl;
        }
        return;
    }
    int n = r, m = c;
    if (n < m) swap(n, m);
    if (m == 1) {
        for (int i = 0; i < n; i++) {
            if (q > 0) {
                d[i][0] = '*';
                q--;
            } else if (i == n-1) {
                d[i][0] = 'c';
            } else {
                d[i][0] = '.';
            }
        }
    } else if (m == 2) {
        if (q%2 == 1) {
            cout << "Impossible\n";
            return;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                if (q > 0) {
                    d[i][j] = '*';
                    q--;
                } else if (i == n-1 && j == 0) {
                    d[i][j] = 'c';
                } else {
                    d[i][j] = '.';
                }
            }
        }
    } else if (m == 3) {
        if (n*m-q == 2 || n*m-q == 3 || n*m-q == 5 || n*m-q == 7) {
            cout << "Impossible\n";
            return;
        }
        int vy = 0, vx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (q > 0) {
                    d[i][j] = '*';
                    q--;
                    vy = i; vx = j;
                } else {
                    d[i][j] = '.';
                }
            }
        }
        if (vx == 1) {
            d[vy][vx] = '.';
            d[vy+1][vx-1] = '*';
        }
        d[n-1][m-1] = 'c';
    } else {
        if (n*m-q == 2 || n*m-q == 3 || n*m-q == 5 || n*m-q == 7) {
            cout << "Impossible\n";
            return;
        }
        if (q <= n*m-2*m) {
            int vy = 0, vx = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (q > 0) {
                        d[i][j] = '*';
                        q--;
                        vy = i; vx = j;
                    } else {
                        d[i][j] = '.';
                    }
                }
            }
            if (vx == m-2 && vy == n-3) {
                d[vy][vx+1] = '*';
                d[vy+1][vx+1] = '*';
                d[vy+2][vx+1] = '*';
                d[vy][0] = '.';
                d[vy][1] = '.';
                d[vy][2] = '.';
            } else if (vx == m-2) {
                d[vy][vx] = '.';
                d[vy+1][0] = '*';
            }
            d[n-1][0] = 'c';
        } else {
            bool x = false;
            if ((n*m-q)%2 == 1) {
                q += 2;
                x = true;
            }
            for (int i = 0; i < n-2; i++) {
                for (int j = 0; j < m; j++) {
                    if (q > 0) {
                        d[i][j] = '*';
                        q--;
                    } else {
                        d[i][j] = '.';
                    }
                }
            }
            for (int j = m-1; j >= 0; j--) {
                if (q > 0) {
                    d[n-2][j] = '*';
                    d[n-1][j] = '*';
                    q -= 2;
                } else {
                    d[n-2][j] = '.';
                    d[n-1][j] = '.';
                }
            }
            if (x) {
                d[n-3][0] = '.';
                d[n-3][1] = '.';
                d[n-3][2] = '.';
            }
            d[n-1][0] = 'c';
        }
    }
    if (r == n && c == m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << d[i][j];
            }
            cout << "\n";
        }
    } else {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << d[j][i];
            }
            cout << "\n";
        }
    }
}

int main() {
    cin >> t;
    for (int x = 1; x <= t; x++) {
        cout << "Case #" << x << ":\n";
        int r, c, m;
        cin >> r >> c >> m;
        tutki(r, c, m);
    }
}
