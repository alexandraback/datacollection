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

#define mp make_pair

//%llu
typedef unsigned long long uint64;
typedef long long int64;
typedef pair<int, int> pair2;

const double eps = 1e-8;
int T, A, N;
int a[128];

void init() {
    scanf("%d%d", &A, &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", a + i);
    }
    sort(a, a + N);
}

int Count(int a, int b, int &c) {
    int ret = 0;
    if (a == 1)
        return -1;
    while (a <= b) {
        a += a - 1;
        ++ret;
    }
    c = a;
    return ret;
}

int solve() {
    int ret = 0, cnt, cur;
    for (int i = 0; i < N; ++i) {
        cnt = Count(A, a[i], cur);
        if (cnt == -1) {
            ret += N - i;
            break;
        }
        if (cnt < N - i) {
            ret += cnt;
            A = cur;
            A += a[i];
        } else {
            ret += N - i;
            break;
        }
    }
    return ret;
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        init();
        printf("Case #%d: %d\n", t, solve());
    }

    return 0;
}