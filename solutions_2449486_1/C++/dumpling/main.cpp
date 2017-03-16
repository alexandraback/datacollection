/*
 * @author: zhenpeng.fang
 * @nickname: dumpling
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <time.h>
#include <stdlib.h>
#include <stack>
#include <queue>
using namespace std;

//%llu
typedef unsigned long long uint64;
typedef long long int64;

const double eps = 1e-8;
int T, N, M;
int a[128][128];

void init() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            scanf("%d", &a[i][j]);
}

bool checkRow(int r, int c) {
    for (int i = 0; i < M; ++i)
        if (a[r][c] < a[r][i])
            return false;
    return true;
}

int checkCol(int r, int c) {
    for (int i = 0; i < N; ++i)
        if (a[r][c] < a[i][c])
            return false;
    return true;
}

bool check(int x, int y) {
    if (checkRow(x, y) || checkCol(x, y))
        return true;
    return false;
}

bool check() {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (!check(i, j))
                return false;
    return true;
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        init();
        printf("Case #%d: %s\n", t, check() ? "YES" : "NO");
    }

    return 0;
}