#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int r, c, w;
int ans = 10007;
int state[100];

int dfs(int dep) {
    int lset = c, rset = -1, setcount = 0;
    for (int i = 0; i < c; ++i)
    if (state[i] == 1) {
        setcount++;
        rset = max(rset, i);
        lset = min(lset, i);
    }
    if (setcount != 0) {
        if (setcount > w) return -10007;
        if (rset - lset + 1 > w)
            return -10007;
        if (setcount == w && rset - lset + 1 == w)
            return dep;
    }
    int flag = 0;
    for (int i = 0; i < c - w + 1; ++i) {
        if (lset < i || rset > i + w - 1)
            continue;
        int fflag = 1;
        for (int j = 0; j < w; ++j)
            if (state[i + j] == -1)
                fflag = 0;
        if (fflag == 0)
            continue;
        flag = 1;
    }
    if (flag == 0)
        return -10007;
    //for (int i = 0; i < c; ++i)
    //    if (state[i] == -1 && i < rset && i > lset)
    //        return;
    int ret = 10007;
    for (int i = 0; i < c; ++i)
    if (state[i] == 0) {
        state[i] = 1;
        int r1 = dfs(dep + 1);
        state[i] = -1;
        int r2 = dfs(dep + 1);
        state[i] = 0;
        ret = min(ret, max(r1, r2));
    }
    return ret;
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        memset(state, 0, sizeof(state));
        scanf("%d %d %d", &r, &c, &w);
        int r = dfs(0);
        printf("Case #%d: %d\n", Case, r);
    }
    return 0;
}
