#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <math.h>
#include <time.h>
using namespace std;
typedef long long LL;
const int N = 205;
const int M = 15;
const int INF = 0x3f3f3f3f;
const LL MOD = 1e9 + 7;

int n, m, k;
int ans[20][20][20];

int main() {
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
    int cases;
    scanf ("%d", &cases);
    ans[3][3][1] = 1;
    ans[3][3][2] = 2;
    ans[3][3][3] = 3;
    ans[3][3][4] = 4;
    ans[3][3][5] = 4;
    ans[3][3][6] = 5;
    ans[3][3][7] = 6;
    ans[3][3][8] = 7;
    ans[3][3][9] = 8;

    ans[3][4][1] = 1;
    ans[3][4][2] = 2;
    ans[3][4][3] = 3;
    ans[3][4][4] = 4;
    ans[3][4][5] = 4;
    ans[3][4][6] = 5;
    ans[3][4][7] = 6;
    ans[3][4][8] = 6;
    ans[3][4][9] = 7;
    ans[3][4][10] = 8;
    ans[3][4][11] = 9;
    ans[3][4][12] = 10;

    ans[3][5][1] = 1;
    ans[3][5][2] = 2;
    ans[3][5][3] = 3;
    ans[3][5][4] = 4;
    ans[3][5][5] = 4;
    ans[3][5][6] = 5;
    ans[3][5][7] = 6;
    ans[3][5][8] = 6;
    ans[3][5][9] = 7;
    ans[3][5][10] = 8;
    ans[3][5][11] = 8;
    ans[3][5][12] = 9;
    ans[3][5][13] = 10;
    ans[3][5][14] = 11;
    ans[3][5][15] = 12;

    ans[3][6][1] = 1;
    ans[3][6][2] = 2;
    ans[3][6][3] = 3;
    ans[3][6][4] = 4;
    ans[3][6][5] = 4;
    ans[3][6][6] = 5;
    ans[3][6][7] = 6;
    ans[3][6][8] = 6;
    ans[3][6][9] = 7;
    ans[3][6][10] = 8;
    ans[3][6][11] = 8;
    ans[3][6][12] = 9;
    ans[3][6][13] = 10;
    ans[3][6][14] = 10;
    ans[3][6][15] = 11;
    ans[3][6][16] = 12;
    ans[3][6][17] = 13;
    ans[3][6][18] = 14;

    ans[4][4][1] = 1;
    ans[4][4][2] = 2;
    ans[4][4][3] = 3;
    ans[4][4][4] = 4;
    ans[4][4][5] = 4;
    ans[4][4][6] = 5;
    ans[4][4][7] = 6;
    ans[4][4][8] = 6;
    ans[4][4][9] = 7;
    ans[4][4][10] = 7;
    ans[4][4][11] = 8;
    ans[4][4][12] = 8;
    ans[4][4][13] = 9;
    ans[4][4][14] = 10;
    ans[4][4][15] = 11;
    ans[4][4][16] = 12;

    ans[4][5][1] = 1;
    ans[4][5][2] = 2;
    ans[4][5][3] = 3;
    ans[4][5][4] = 4;
    ans[4][5][5] = 4;
    ans[4][5][6] = 5;
    ans[4][5][7] = 6;
    ans[4][5][8] = 6;
    ans[4][5][9] = 7;
    ans[4][5][10] = 7;
    ans[4][5][11] = 8;
    ans[4][5][12] = 8;
    ans[4][5][13] = 9;
    ans[4][5][14] = 9;
    ans[4][5][15] = 10;
    ans[4][5][16] = 10;
    ans[4][5][17] = 11;
    ans[4][5][18] = 12;
    ans[4][5][19] = 13;
    ans[4][5][20] = 14;

    for (int cas = 1; cas <= cases; cas ++) {
        int n, m, k;
        scanf ("%d %d %d", &n, &m, &k);
        printf ("Case #%d: ", cas);
        if (n > m) {
            swap(n, m);
        }
        if (n <= 2) {
            printf ("%d\n", k);
            continue;
        }
        printf ("%d\n", ans[n][m][k]);

    }
    return 0;
}
