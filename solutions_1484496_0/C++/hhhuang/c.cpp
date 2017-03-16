#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int items[600];
char map[10000000];
int path[10000000];
char used[600];

int check(int n, int k, int ans[600]) {
    int i, j;
    int size;
    memset(map, 0, sizeof(map));
    memset(path, 0, sizeof(path));
    memset(ans, 0, sizeof(ans));

    map[0] = 1;

    for (int i = 0; i < n; ++i) {
        if (used[i])
            continue;
        for (int j = k; j >= items[i]; --j)
            if (map[j] == 0 && map[j - items[i]] == 1) {
                path[j] = i;
                map[j] = 1;
            }
        if (map[k] == 1)
            break;
    }

    if (map[k]) {
        size = 0;
        i = k;
        while (i > 0) {
            ans[size++] = path[i];
            i -= items[path[i]];
        }
        ans[size++] = -1;
        return 1;
    }
    else {
        return 0;
    }
}

int cmp(const void *a, const void *b)
{
    int v1 = *((int *)a);
    int v2 = *((int *)b);
    if (v1 > v2)
        return 1;
    else if (v1 == v2)
        return 0;
    else 
        return -1;
}

int main() {
    int num_cases;
    int turn;
    int n;
    int possible[1000000]; 
    int sum = 0;
    int ans1[600], ans2[600];

    scanf("%d", &num_cases);

    for (turn = 1; turn <= num_cases; ++turn) {
        memset(possible, 0, sizeof(possible));
        scanf("%d", &n);
        sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &items[i]);
            sum += items[i];
        }
        qsort(items, n, sizeof(items[0]), cmp);

        possible[0] = 1;
        for (int i = 0; i < n; ++i)
            for (int j = sum / 2; j >= items[i]; --j)
                if (possible[j - items[i]])
                    possible[j] = 1;

        int found = 0;
        for (int i = 1; i <= sum / 2; ++i) {
            if (possible[i] == 0)
                continue;
            memset(used, 0, sizeof(used));
            if (!check(n, i, ans1))
                continue;
            for (int j = 0; ; ++j) {
                if (ans1[j] < 0)
                    break;
                used[ans1[j]] = 1;
            }
            if (!check(n, i, ans2))
                continue;
            found = 1;
            break;
        }
        printf("Case #%d:\n", turn);
        if (found == 0) 
            puts("Impossible");
        else {
            for (int i = 0; ; ++i) {
                if (ans1[i] < 0)
                    break;
                if (i > 0)
                    printf(" ");
                printf("%d", items[ans1[i]]);
            }
            printf("\n");
            for (int i = 0; ; ++i) {
                if (ans2[i] < 0)
                    break;
                if (i > 0)
                    printf(" ");
                printf("%d", items[ans2[i]]);
            }
            printf("\n");
        }
    }
    return 0;
}
