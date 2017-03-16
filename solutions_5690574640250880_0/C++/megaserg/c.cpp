#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
using namespace std;

typedef long long int64;
#define PB(a) push_back(a)
#define MP(a, b) make_pair(a, b)
#define PROBLEM "C"

const int MAXN = 64;
const int di[8] = {-1, -1, -1,  0,  0, +1, +1, +1};
const int dj[8] = {-1,  0, +1, -1, +1, -1,  0, +1};

bool mark[MAXN][MAXN];
int n, m, x, f;
char a[MAXN][MAXN];

void dfs(int i, int j) {
    mark[i][j] = true;

    int mines = 0;
    for (int k = 0; k < 8; k++) {
        int ni = i + di[k], nj = j + dj[k];
        if (0 <= ni && ni < n && 0 <= nj && nj < m && a[ni][nj] == '*') {
            mines++;
        }
    }
    if (mines > 0) return;

    for (int k = 0; k < 8; k++) {
        int ni = i + di[k], nj = j + dj[k];
        if (0 <= ni && ni < n && 0 <= nj && nj < m && a[ni][nj] != '*' && !mark[ni][nj]) {
            dfs(ni, nj);
        }
    }
}

bool check() {
    memset(mark, 0, sizeof(mark));
    dfs(0, 0);

    int dots = 0;
    int stars = 0;
    int marked = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            assert(a[i][j] == 'c' || a[i][j] == '.' || a[i][j] == '*');
            if (a[i][j] == 'c' || a[i][j] == '.') {
                dots++;
            }
            if (a[i][j] == '*') {
                stars++;
                assert(!mark[i][j]);
            }
            if (mark[i][j]) {
                marked++;
            }
        }
    }

    assert(dots + stars == n * m);
    assert(dots == f);
    assert(stars == x);

    return marked == dots;
}

int main() {
    freopen(PROBLEM ".in", "rt", stdin);
    freopen(PROBLEM ".out", "wt", stdout);

    int T;
    scanf("%d\n", &T);

    for (int t = 1; t <= T; t++) {
        printf("Case #%d:\n", t);

        cin >> n >> m >> x;
        f = n * m - x;
        bool found = false;
        memset(a, 0, sizeof a);

        if (n == 1 && m == 1) {
            found = true;
            a[0][0] = 'c';
        }
        if (f == 1) {
            found = true;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a[i][j] = '*';
                }
            }
            a[0][0] = 'c';
        }
        if (n == 1 && m > 1) {
            found = true;
            a[0][0] = 'c';
            for (int j = 1; j < f; j++) {
                a[0][j] = '.';
            }
            for (int j = f; j < m; j++) {
                a[0][j] = '*';
            }
        }
        if (n > 1 && m == 1) {
            found = true;
            a[0][0] = 'c';
            for (int j = 1; j < f; j++) {
                a[j][0] = '.';
            }
            for (int j = f; j < n; j++) {
                a[j][0] = '*';
            }
        }
        if (n > 1 && m > 1) {
            for (int height = min(f, n); height >= 2; height--) {
                int fullColumns = f / height;
                int lastColumnHeight = f - fullColumns * height;
                int width = fullColumns + (lastColumnHeight > 0);
                if (width > m) continue;

                memset(a, 0, sizeof(0));
                for (int j = 0; j < fullColumns; j++) {
                    for (int i = 0; i < height; i++) {
                        a[i][j] = 'z';
                    }
                }
                for (int i = 0; i < lastColumnHeight; i++) {
                    a[i][fullColumns] = 'z';
                }

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (a[i][j] == 'z') {
                            a[i][j] = '.';
                        } else {
                            a[i][j] = '*';
                        }
                    }
                }
                a[0][0] = 'c';

                if (check()) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                for (int width = min(f, m); width >= 2; width--) {
                    int fullRows = f / width;
                    int lastRowWidth = f - fullRows * width;
                    int height = fullRows + (lastRowWidth > 0);
                    if (height > n) continue;

                    memset(a, 0, sizeof(0));
                    for (int i = 0; i < fullRows; i++) {
                        for (int j = 0; j < width; j++) {
                            a[i][j] = 'z';
                        }
                    }
                    for (int j = 0; j < lastRowWidth; j++) {
                        a[fullRows][j] = 'z';
                    }

                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            if (a[i][j] == 'z') {
                                a[i][j] = '.';
                            } else {
                                a[i][j] = '*';
                            }
                        }
                    }
                    a[0][0] = 'c';

                    if (check()) {
                        found = true;
                        break;
                    }
                }
            }

            if (!found) {
                for (int height = min(x, n); height >= 1; height--) {
                    int fullColumns = x / height;
                    int lastColumnHeight = x - fullColumns * height;
                    int width = fullColumns + (lastColumnHeight > 0);
                    if (width > m) continue;

                    memset(a, 0, sizeof(0));
                    for (int j = 0; j < fullColumns; j++) {
                        for (int i = 0; i < height; i++) {
                            a[n-1-i][m-1-j] = 'x';
                        }
                    }
                    for (int i = 0; i < lastColumnHeight; i++) {
                        a[n-1-i][m-1-fullColumns] = 'x';
                    }

                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            if (a[i][j] == 'x') {
                                a[i][j] = '*';
                            } else {
                                a[i][j] = '.';
                            }
                        }
                    }
                    a[0][0] = 'c';

                    if (check()) {
                        cerr << "SHIT1 " << t << endl;
                        found = true;
                        break;
                    }
                }
            }

            if (!found) {
                for (int width = min(x, m); width >= 1; width--) {
                    int fullRows = x / width;
                    int lastRowWidth = x - fullRows * width;
                    int height = fullRows + (lastRowWidth > 0);
                    if (height > n) continue;

                    memset(a, 0, sizeof(0));
                    for (int i = 0; i < fullRows; i++) {
                        for (int j = 0; j < width; j++) {
                            a[n-1-i][m-1-j] = 'x';
                        }
                    }
                    for (int j = 0; j < lastRowWidth; j++) {
                        a[n-1-fullRows][m-1-j] = 'x';
                    }

                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            if (a[i][j] == 'x') {
                                a[i][j] = '*';
                            } else {
                                a[i][j] = '.';
                            }
                        }
                    }
                    a[0][0] = 'c';

                    if (check()) {
                        cerr << "SHIT2 " << t << endl;
                        found = true;
                        break;
                    }
                }
            }
        }

        memset(mark, 0, sizeof(mark));
        dfs(0, 0);

        if (found) {
            int dots = 0;
            int stars = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (a[i][j] == 'c' || a[i][j] == '.') {
                        dots++;
                        assert(mark[i][j]);
                    }
                    if (a[i][j] == '*') {
                        stars++;
                        assert(!mark[i][j]);
                    }
                }
            }
            assert(dots + stars == n * m);
            assert(dots == f);
            assert(stars == x);

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    printf("%c", a[i][j]);
                }
                printf("\n");
            }
        } else {
            printf("Impossible\n");
        }
    }

    return 0;
}
