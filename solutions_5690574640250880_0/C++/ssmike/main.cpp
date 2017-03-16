#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;


#define INF 1e+9
#define mp make_pair
#define lint long long
#define pii pair<int, int>

const int maxn = 60;
char field[60][60];

void output(int r, int c, int i, bool f) {
    printf("Case #%d:\n", i + 1);
    field[0][0] = 'c';
    if (f) {
        printf("Impossible\n");
        return;
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%c", field[i][j]);
        printf("\n");
    }
}

const int moves = 9;
int dx[moves] = {1, 1, 1, -1, -1, -1, 0, 0, 0};
int dy[moves] = {1, 0, -1, 1, 0, -1, 1, 0, -1};
vector< pii > diff;

int mark(int x, int y, int r, int c) {
    int res = 0;
    for (int i = 0; i < moves; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (r > nx && nx >= 0 && c > ny && ny >= 0) {
            if (field[nx][ny] == '*')
                diff.push_back(mp(nx, ny));
            res += field[nx][ny] == '*';
            field[nx][ny] = '.';

        }
    }
    return res;
}

void revert() {
    for (int i = 0; i < diff.size(); i++)
        field[diff[i].first][diff[i].second] = '*';
}

int main() {
    //ios_base::sync_with_stdio(false);
    freopen("inp", "r", stdin);
    freopen("outp", "w", stdout);
    int t;
    cin >> t;
    for (int ii = 0; ii < t; ii++) {
        int r, c, m;
        cin >> r >> c >> m;
        for (int i = 0; i < maxn; i++)
            for (int j = 0; j < maxn; j++)
                field[i][j] = '*';
        if (m == r * c - 1) {
            output(r, c, ii, false);
            continue;
        }
        bool fl = true;
        int ss = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (i < r - 1) {
                    diff.clear();
                    ss += mark(i, 0, r, c);
                    for (int kk = 0; kk < min(c, 4); kk++) {
                        ss += mark(i + 1, kk, r, c);
                        if (ss == r * c - m) {
                            output(r, c, ii, false);
                            fl = false;
                            break;
                        }
                    }
                    if (!fl) break;
                    ss -= diff.size();
                    revert();
                    diff.clear();
                }
                ss += mark(i, j, r, c);
                if (ss == r * c - m) {
                    output(r, c, ii, false);
                    fl = false;
                    break;
                }
            }
            if (!fl) break;
        }

        if (fl) {
            output(r, c, ii, true);
        }
    }
}
