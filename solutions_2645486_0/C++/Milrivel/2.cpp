#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int v[11];

int dfs(int depth, int e, int r, int n, int cur) {
    if (depth == n) {
        return 0;
    }
    int ret = 0;
    for (int i = 0; i <= cur; i++) {
        int tmp = dfs(depth + 1, e, r, n, (cur - i + r) > e ? e : (cur - i + r))
            + i * v[depth];
        if (tmp > ret) {
            ret = tmp;
        }
    }
    return ret;
}

int main(void) {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("dataout.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int cases = 1; cases <= T; cases++) {
        int e, r, n;
        scanf("%d%d%d", &e, &r, &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }
        printf("Case #%d: %d\n", cases, dfs(0, e, r, n, e));
    }
    return 0;
}
