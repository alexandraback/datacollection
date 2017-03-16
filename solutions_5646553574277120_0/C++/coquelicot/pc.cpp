#include <cstdio>

int bst = 5;
int dfs(int add, unsigned coin, unsigned avail, unsigned target) {

    if (add >= bst)
        return bst;
    if ((avail & target) == target)
        bst = add;
    if (add + 1 >= bst)
        return bst;

    for (int i = 0; target & (1 << i); i++) if (~coin & (1 << i))
        dfs(add + 1, coin | (1 << i), avail | (avail << i), target);

    return bst;

}

int main() {

    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {

        unsigned coin = 0;
        unsigned avail = 1;

        int c, d, v;
        scanf("%d %d %d", &c, &d, &v);

        for (int i = 1; i <= d; i++) {
            int g;
            scanf("%d", &g);
            avail |= (avail << g);
            coin |= (1U << g);
        }

        bst = 5;
        printf("Case #%d: %d\n", t, dfs(0, coin, avail, (1U << (v + 1)) - 1));

    }

}
