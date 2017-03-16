#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <utility>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int r, c, m;
int g[51][51];

#define M -1

int count(int row, int col) {
    //cout << "Counting " << row << ", " << col << ": ";
    int cnt = 0;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;
            if (row + dx < 0) continue;
            if (row + dx >= r) continue;
            if (col + dy < 0) continue;
            if (col + dy >= c) continue;
            cnt += g[row + dx][col + dy] == M;
        }
    }
    //cout << cnt << endl;
    return cnt;
}

int main(int argc, char* argv[]) {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int cases; cin >> cases;
    for (int cas = 0; cas < cases; ++cas) {
        cout << "Case #" << cas + 1 << ":\n";
        int x = 0, y = 0;
        cin >> r >> c >> m;
        int om = m;
        if (m + 1 == r * c) { for (x = 0; x < r; ++x) { for (y = 0; y < c; ++y) if (x == r - 1 && y == c - 1) cout << "c"; else cout << "*"; cout << "\n"; } continue; } if (r == 1) { int i; for (i = 0; i < m; ++i) { cout << "*"; } for (++i; i < c; ++i) { cout << "."; } cout << "c\n"; continue; } else if (c == 1) { int i; for (i = 0; i < m; ++i) { cout << "*\n"; } for (++i; i < r; ++i) { cout << ".\n"; } cout << "c\n"; continue; } if (r == 2) { if (m % 2 || m + 2 == r * c) { cout << "Impossible\n"; continue; } int i; for (i = 0; i < m / 2; ++i) cout << "*"; for (; i < c; ++i) cout << "."; cout << "\n"; for (i = 0; i < m / 2; ++i) cout << "*"; for (; i < c - 1; ++i) cout << "."; cout << "c\n"; continue; } else if (c == 2) { if (m % 2 || m + 2 == r * c) { cout << "Impossible\n"; continue; } int i; for (i = 0; i < m / 2; ++i) cout << "**\n"; for (; i < r - 1; ++i) cout << "..\n"; cout << ".c\n"; continue; } if (r * c - m <= 3) { cout << "Impossible\n"; continue; } for (x = 0; x < r; ++x) { for (y = 0; y < c; ++y) { g[x][y] = 0; } }
        if (om) {
            for (x = 0; x < r - 2; ++x) {
                for (y = 0; y < c - 2; ++y) {
                    g[x][y] = M;
                    --om;
                    if (!om) { goto out; }
                }
                if (x != r - 3 && om >= 2) {
                    om -= 2;
                    g[x][c - 2] = M;
                    g[x][c - 1] = M;
                    if (!om) { goto out; }
                }
            }
            for (y = 0; y < c - 2; ++y) {
                g[r - 2][y] = M;
                g[r - 1][y] = M;
                om -= 2;
                if (om == -1) {
                    if (y >= c - 3) {
                        cout << "Impossible\n"; goto cont;
                    }
                    g[r - 3][c - 3] = 0;
                    goto out;
                }
                if (om == 0) {
                    goto out;
                }
            }
            if (om == 2) {
                g[r - 3][c - 2] = M;
                g[r - 3][c - 1] = M;
                goto out;
            } else {
                cout << "Impossible\n"; continue;
            }
        } else {
            goto out;
        }
out:
        for (x = 0; x < r; ++x) {
            for (y = 0; y < c; ++y) {
                if (x == r - 1 && y == c - 1) {
                    cout << "c";
                } else {
                    cout << (g[x][y] == M ? "*" : ".");
                }
            }
            cout << "\n";
        }
cont:
        ;
    }
}
