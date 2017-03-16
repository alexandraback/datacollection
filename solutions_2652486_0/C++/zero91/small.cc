#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>

using namespace std;

#define MAXN 10
#define MAXK 10

int ans[MAXN], product[MAXN];
int R, N, M, K;

bool
check (int p)
{
    int val;

    for (int i = 0; i < (1 << N); ++i) {
        val = 1;
        for (int j = 0; j < N; ++j) {
            if (i & (1 << j)) val *= ans[j];
        }
        if (val == p) return true;
    }
    return false;
}

bool
dfs (int id)
{
    if (id >= N) {
        for (int i = 0; i < K; ++i) {
            if (!check(product[i])) return false;
        }
        return true;
    }
    bool ret = false;
    for (int i = 2; i <= M; ++i) {
        ans[id] = i;
        ret = dfs(id + 1);
        if (ret) return true;
    }
    return false;
}

int
main ()
{
    int T;

    scanf ("%d", &T);
    for (int k = 1; k <= min(T, 1); ++k) {
        scanf ("%d %d %d %d", &R, &N, &M, &K);
        printf ("Case #%d:\n", k);

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < K; ++j) scanf ("%d", &product[j]);
            dfs(0);

            for (int j = 0; j < N; ++j) printf ("%d", ans[j]);
            printf ("\n");
        }
    }
    return 0;
}
