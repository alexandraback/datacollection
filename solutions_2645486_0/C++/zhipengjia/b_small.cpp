#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

const int inf = 1000000000;

int f[11][6], v[10];

void work() {
    int e, r, n;
    scanf("%d%d%d", &e, &r, &n);
    for (int i = 0; i < n; i ++)
        scanf("%d", &v[i]);
    for (int i = 0; i <= n; i ++)
        for (int j = 0; j <= e; j ++)
            f[i][j] = -inf;
    f[0][e] = 0;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j <= e; j ++) {
            if (f[i][j] == -inf) continue;
            for (int k = 0; k <= j; k ++) {
                int t = min(e, j - k + r);
                f[i + 1][t] = max(f[i + 1][t], f[i][j] + v[i] * k);
            }
        }
    int ans = -inf;
    for (int i = 0; i <= e; i ++)
        ans = max(ans, f[n][i]);
    printf("%d\n", ans);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int test = 0; test < T; test ++) {
        printf("Case #%d: ", test + 1);
        work();
    }

    return 0;
}