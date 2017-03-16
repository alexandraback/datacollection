#include <iostream>
#include <algorithm>

#define MAX 105

using namespace std;

double t[MAX][MAX];
int F[MAX][MAX], C[MAX][MAX];
int H, N, M;

void relax(int i, int j, int x, int y) {
    if (i+x < 0 || i+x >= N || j+y < 0 || j+y >= M)
        return;
    double water = H - 10 * t[i][j];
    double tm = t[i][j];
    if ( F[i+x][j+y] > C[i][j] - 50 || max(F[i][j], F[i+x][j+y]) > C[i+x][j+y]-50 ) {
        return;
    } 
    if (water > C[i+x][j+y]-50) {
        tm += ((water - C[i+x][j+y] + 50) / 10.0);
        water = C[i+x][j+y] - 50;
    }
    // if (t[i][j] == 8) {
    //     cout << i << ' ' << j << ' ';
    //     cout << water << endl;
    // }
    if (water - F[i][j] >= 20) {
        t[i+x][j+y] = min(t[i+x][j+y], tm + 1);
    } else {
        t[i+x][j+y] = min(t[i+x][j+y], tm + 10);
    }
}

void go(int i, int j, int x, int y) {
    if (i+x < 0 || i+x >= N || j+y < 0 || j+y >= M)
        return;
    double water = H - t[i][j];
    if ( F[i+x][j+y] > C[i][j] - 50 || max(F[i][j], F[i+x][j+y]) > C[i+x][j+y]-50 ) {
        return;
    } 
    if (water > C[i+x][j+y]-50) {
        return;
    }
    t[i+x][j+y] = 0;
}

int main() {
    int T;
    cin >> T;

    for (int tt = 1; tt <= T; ++tt) {
        cin >> H >> N >> M;
        for (int n = 0; n < N; ++n) {
            for (int m = 0; m < M; ++m) {
                cin >> C[n][m];
            }
        }
        for (int n = 0; n < N; ++n) {
            for (int m = 0; m < M; ++m) {
                cin >> F[n][m];
                t[n][m] = 1e8;
            }
        }
        t[0][0] = 0;
        for (int k = 0; k < M*N; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    if (t[i][j] > 1e7) continue;
                    go(i, j, 0, 1);
                    go(i, j, 0, -1);
                    go(i, j, 1, 0);
                    go(i, j, -1, 0);
                }
            }
        }
        for (int k = 0; k < M*N; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    if (t[i][j] > 1e7) continue;
                    relax(i, j, 0, 1);
                    relax(i, j, 0, -1);
                    relax(i, j, 1, 0);
                    relax(i, j, -1, 0);
                }
            }
        }
        cout << "Case #" << tt << ": " << t[N-1][M-1] << endl;
    }
}