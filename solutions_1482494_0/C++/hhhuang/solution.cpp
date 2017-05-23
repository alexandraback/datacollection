#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Level {
    int a, b;
};

int cmp(const void *v1, const void *v2) {
    Level l1 = *((Level *)v1);
    Level l2 = *((Level *)v2);
    return l2.b - l1.b;
}

int pass_a[1010], pass_b[1010];
int n;
Level levels[1010];

int greedy() {
    int i, j;
    int cost = 0;
    int num_passed = 0;
    int change = 0;
    int star = 0;
    while (num_passed < n) {
        while (num_passed < n) {
            int flag1 = 0;
            for (i = 0; i < n; ++i) {
                if (pass_b[i])
                    continue;
                if (levels[i].b <= star) {
                    pass_b[i] = 1;
                    if (pass_a[i])
                        star += 1;
                    else 
                        star += 2;
                    flag1 = 1;
                    cost++;
                    num_passed++;
                }
            }
            if (flag1 == 0)
                break;
        }
        if (num_passed == n)
            return cost;
        change = 0;
        for (i = 0; i < n; ++i)
            if (star >= levels[i].a && pass_a[i] == 0 && pass_b[i] == 0) {
                star++;
                pass_a[i] = 1;
                cost++;
                change = 1;
                break;
            }
        if (change == 0)
            return -1;

    }
    if (num_passed == n)
        return cost;
    else 
        return -1;
}

int count() {
    memset(pass_a, 0, sizeof(pass_a));
    memset(pass_b, 0, sizeof(pass_b));
    qsort(levels, n, sizeof(levels[0]), cmp);
    return greedy();
}

int main() {
    int num_cases;
    int t;
    int ans;
    scanf("%d", &num_cases);

    for (t = 1; t <= num_cases; ++t) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d%d\n", &levels[i].a, &levels[i].b);
        ans = count();
        if (ans == -1)
            printf("Case #%d: Too Bad\n", t);
        else
            printf("Case #%d: %d\n", t, ans);
    }

    return 0;
}
