/******************************************************************************\
*                         Author:  Dumbear                                     *
*                         Email:   dumbear[#at]163.com                         *
*                         Website: http://dumbear.com                          *
\******************************************************************************/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>

using namespace std;

#define output(x) cout << #x << ": " << (x) << endl;

typedef long long LL;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<string> VS;

int t, r, c, m;
char board[64][64];

void solve() {
    scanf("%d%d%d", &r, &c, &m);
    if (m == 1) {
        // fprintf(stderr, "%d %d %d\n", r, c, m);
    }
    printf("Case #%d:\n", ++t);
    if (r == 1) {
        putchar('c');
        for (int i = 1; i < c - m; ++i) {
            putchar('.');
        }
        for (int i = 0; i < m; ++i) {
            putchar('*');
        }
        puts("");
        return;
    }
    if (c == 1) {
        puts("c");
        for (int i = 1; i < r - m; ++i) {
            puts(".");
        }
        for (int i = 0; i < m; ++i) {
            puts("*");
        }
        return;
    }
    if (m == r * c - 1) {
        memset(board, '*', sizeof(board));
        board[0][0] = 'c';
        for (int i = 0; i < r; ++i) {
            board[i][c] = '\0';
            puts(board[i]);
        }
        return;
    }
    if (m == r * c - 2 || m == r * c - 3) {
        puts("Impossible");
        return;
    }
    int k_r = -1, k_c = -1, acc = 0, rc = -1;
    for (int i = 2; i <= r && k_r == -1; ++i) {
        for (int j = 2; j <= c && k_r == -1; ++j) {
            int k = r * c - m - i * j;
            if (k == 0) {
                k_r = i;
                k_c = j;
            } else if (k > 1) {
                if (i != r && k < j) {
                    k_r = i;
                    k_c = j;
                    rc = 0;
                } else if (j != c && k < i) {
                    k_r = i;
                    k_c = j;
                    rc = 1;
                }
            }
        }
    }
    if (k_r == -1) {
        for (int i = 2; i <= r && k_r == -1; ++i) {
            for (int j = 2; j <= c && k_r == -1; ++j) {
                int k = r * c - m - i * j;
                if (k == 1) {
                    if (i > 2 && j > 2) {
                        k_r = i;
                        k_c = j;
                        rc = 2;
                    }
                }
            }
        }
    }
    if (k_r == -1) {
        // if (r * c - m != 5 && r * c - m != 7)
            // fprintf(stderr, "!!! %d %d %d\n", r, c, m);
        puts("Impossible");
        return;
    }
    memset(board, '*', sizeof(board));
    for (int i = 0; i < k_r; ++i)
        for (int j = 0; j < k_c; ++j)
            board[i][j] = '.';
    board[0][0] = 'c';
    if (rc == 0) {
        for (int i = 0; i < r * c - m - k_r * k_c; ++i)
            board[k_r][i] = '.';
    } else if (rc == 1) {
        for (int i = 0; i < r * c - m - k_r * k_c; ++i)
            board[i][k_c] = '.';
    } else if (rc == 2) {
        if (k_r != r) {
            board[k_r][0] = '.';
            board[k_r][1] = '.';
            board[k_r - 1][k_c - 1] = '*';
        } else {
            board[0][k_c] = '.';
            board[1][k_c] = '.';
            board[k_r - 1][k_c - 1] = '*';
        }
    }
    for (int i = 0; i < r; ++i) {
        board[i][c] = '\0';
        puts(board[i]);
    }
    // int cnt = 0;
    // for (int i = 0; i < r; ++i)
    //     for (int j = 0; j < c; ++j)
    //         if (board[i][j] == '*')
    //             ++cnt;
    // if (cnt != m)
    //     while (1);
}

int main() {
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
        solve();
    return 0;
}
