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

#define MAXN 100

int E, R, N;
int v[MAXN];
int ans;

void
dfs (int id, int energy, int sum)
{
    if (id >= N) {
        if (sum > ans) ans = sum;
        return;
    }
    for (int i = 0; i <= energy; ++i) {
        dfs (id + 1, min (E, energy - i + R), sum + i * v[id]);
    }
}

int
main ()
{
    int T;

    scanf ("%d", &T);
    for (int k = 1; k <= T; ++k) {
        ans = 0;
        scanf ("%d %d %d", &E, &R, &N);
        for (int j = 0; j < N; ++j) scanf ("%d", v + j);

        dfs (0, E, 0);

        printf ("Case #%d: %d\n", k, ans);
    }
    return 0;
}
