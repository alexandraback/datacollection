/*
  ID: nigo1
  LANG: C++
  TASK: A
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>

using namespace std;

#define MAXA 1000001

int N;
int T;
int A;
int m[MAXA + 10];

int DP[100][MAXA + 10];

int dp(int at, int sz) {
    if (sz > MAXA) sz = MAXA;

    if (at >= N) {
        return 0;
    }
    int &res = DP[at][sz];
    if (res != -1) return res;
    res = N - at;

    if (sz > m[at]) {
        sz = sz + m[at];
        res = dp(at + 1, sz);
    } else {
        res = min(res, dp(at, sz + sz - 1) + 1);
        res = min(res, dp(at + 1, sz) + 1);
    }

    return res;
}

int main()
{
    //freopen ("A.in", "r", stdin);
    //freopen ("A.out", "w", stdout);

    scanf("%d", &T);
    for (int test = 1; test <= T; test++) {
        scanf("%d%d", &A, &N);
        for (int i = 0; i < N; i++) {
            scanf("%d", m + i);
        }
        sort(m, m + N);
        memset(DP, -1, sizeof DP);

        printf("Case #%d: %d\n", test, dp(0, A));
    }

    return 0;
}

