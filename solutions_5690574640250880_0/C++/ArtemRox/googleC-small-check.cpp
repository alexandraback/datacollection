#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

const int N = 5;

int ans[N + 1][N + 1][N * N + 1][3];
char a[N][N];

int main() {
    ifstream f("output.txt");
    for (int r = 1; r <= N; r++)
        for (int c = 1; c <= N; c++)
            for (int x = r * c; x >= 0; x--)
                    f >> ans[r][c][x][0] >> ans[r][c][x][1] >> ans[r][c][x][2];
    f.close();
    freopen("input.txt", "r", stdin);
    freopen("google.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int r, c, x;
        cin >> r >> c >> x;
        cout << "Case #" << i + 1 << ":" << endl;
        if (x == r * c - 1) {
            for (int j = 0; j < r; j++)
                for (int k = 0; k < c; k++)
                    a[j][k] = '*';
            a[0][0] = 'c';
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++)
                    cout << a[j][k];
                cout << endl;
            }
            continue;
        }
        int p = ans[r][c][x][0], startX = ans[r][c][x][1], startY = ans[r][c][x][2];
        if (p == -1) {
            cout << "Impossible" << endl;
            // cout << r << ' ' << c << ' ' << x << endl;
            continue;
        }
        for (int j = 0; j < r; j++)
            for (int k = 0; k < c; k++) {
                a[j][k] = p & 1 ? '*' : '.';
                p >>= 1;
            }
        a[startX][startY] = 'c';
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++)
                cout << a[j][k];
            cout << endl;
        }
    }
    return 0;
}
