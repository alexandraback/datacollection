#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

char res[52][52];
int n, m;

int DFS(int x, int y) {
    if (!(1 <= x && x <= n && 1 <= y && y <= m) || res[x][y] != 'e') {
        return 0;
    }
    res[x][y] = '.';
    int cntm = 0, cnte = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int dx = x + i, dy = y + j;
            if (res[dx][dy] == '*') {
                ++ cntm;
            }
        }
    }
    if (cntm) {
        return 1;
    }
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int dx = x + i, dy = y + j;
            cnte += DFS(dx, dy);
        }
    }
    return cnte + 1;
}

void solve() {
    int a, b, c, M;
    memset(res, 0, sizeof(res));
    cin >> n >> m >> M;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1;j <= m; ++j) {
            res[i][j] = 'e';
        }
    }
    a = n, b = m, c = M;
    while (c) {
        if (a == b) { // 正方形
            if (c >= 2 * a - 1) { // 够填右、下两边
                for (int i = 1; i <= a; ++i) {
                    res[a][i] = res[i][b] = '*';
                }
                c -= 2 * a - 1;
                -- a, -- b;
            } else if (c >= a) { // 够填一边
                for (int i = 1; i <= a; ++i) { // 填右边
                    res[i][b] = '*';
                }
                c -= a;
                -- b;
            } else { // 不够填一边
                for (int i = 0; i < c; ++i) { // 填右边
                    res[a - i][b] = '*';
                }
                if (c == a - 1 && a != 2) { // 特判, 不能在右上角留一个
                    res[2][b] = 'e';
                    res[a][b - 1] = '*';
                }
                c -= c;
            }
        } else if (a < b) { // 矩形
            if (c >= a) { // 够填短边
                for (int i = 1; i <= a; ++i) {
                    res[i][b] = '*';
                }
                -- b;
                c -= a;
            } else {  // 不够填短变，则填长边
                for (int i = 0; i < c; ++i) {
                    res[a][b - i] = '*';
                }
                c -= c;
            }
        } else { // 矩形
            if (c >= b) { // 够填短边
                for (int j = 1; j <= b; ++j) {
                    res[a][j] = '*';
                }
                -- a;
                c -= b;
            } else { // 不够填短变，则填长边
                for (int i = 0; i < c; ++i) {
                    res[a - i][b] = '*';
                }
                c -= c;
            }
        }
    }
    // cout << DFS(1, 1) << endl;
    if (DFS(1, 1) == n * m - M) {
        cout << endl;
        res[1][1] = 'c';
        for (int i = 1; i <= n; ++i) {
            cout << res[i] + 1 << endl;
        }
    } else {
        //cout << n << " " << m << " " << M << endl;
        cout << endl << "Impossible" << endl;
    }
}

int main() {
    int testcase;
    freopen("/Users/xhSong/Downloads/C-small-attempt1.in", "r", stdin);
    freopen("/Users/xhSong/gcj/out.txt", "w", stdout);
    cin >> testcase;
    for (int test = 1; test <= testcase; ++test) {
        cout << "Case #" << test << ":";
        solve();
    }
    return 0;
}
