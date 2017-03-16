#include <stdio.h>
#include <algorithm>
#include <vector>

const int VMAX = 1000011;
int a, n;
int var[VMAX];
int ret;

int find_move(int from, int p, int &sum) {
    if (from == 1)
        return -1;

    int q = from;
    int t = 0;
    while (q <= p) {
        q += q - 1;
        //printf("%d %d\n", q, p);
        t++;
    }

    sum = q;

    return t;
}

void dfs(int dep, int cur, int move) {
    if (dep == n) {
        if (move < ret) {
            ret = move;
        }
        return;
    }

    //printf("?%d %d %d\n", dep, cur, move);

    if (move >= ret) return;

    if (var[dep] < cur) {
        dfs(dep + 1, cur + var[dep], move);
    } else {
        int leave = n - dep;
        //printf("??leave: %d\n", leave);
        if (move + leave < ret) {
            ret = move + leave;
        }

        int sum;
        int t = find_move(cur, var[dep], sum);
        //printf("??t: %d %d\n", t, move);
        if (t != -1) {
            dfs(dep + 1, sum + var[dep], move + t);
        }
    }
}

int main() {
    freopen("A-large (1).in", "r", stdin);
    freopen("result.txt", "w", stdout);

    int t;
    scanf("%d", &t);
    //printf("%d\n", t);
    for (int idx = 1; idx <= t; idx++) {
        scanf("%d %d", &a, &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &var[i]);
            //printf("%d\n", var[i]);
        }

        std::sort(var, var + n);

        ret = 1000;
        dfs(0, a, 0);

        printf("Case #%d: %d\n", idx, ret);
    }
}
