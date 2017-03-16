#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int tc, n, arr[21];

struct node {
    int id;
    long long val;
} f[1 << 21];

bool cmp(const node &a, const node &b) {
    return a.val < b.val;
}

int main() {
    freopen("D:\\C-small-attempt0.in","r",stdin);
    freopen("D:\\C-small-attempt0.out","w",stdout);
    int c = 0;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", arr + i);
        f[0].val = f[0].id = 0;
        int top = (1 << n);
        for (int i = 1; i < top; i++) {
            f[i].id = i;
            for (int j = 0; j < n; j++)
                if (i & (1 << j)) {
                    f[i].val = f[i ^ (1 << j)].val + arr[j];
                    break;
                }
        }
        printf("Case #%d:\n", ++c);
        sort(f, f + top, cmp);
        bool exist = false;
        for (int i = 1; i < top; i++)
            if (f[i - 1].val == f[i].val) {
                exist = true;
                int ii = f[i - 1].id, jj = f[i].id;
                bool flag = true;
                for (int j = 0; j < n; j++)
                    if (ii & (1 << j)) {
                        if (flag)
                            printf("%d", arr[j]);
                        else
                            printf(" %d", arr[j]);
                        flag = false;
                    }
                putchar('\n');
                flag = true;
                for (int j = 0; j < n; j++)
                    if (jj & (1 << j)) {
                        if (flag)
                            printf("%d", arr[j]);
                        else
                            printf(" %d", arr[j]);
                        flag = false;
                    }
                putchar('\n');
                break;
            }
        if (!exist)
            puts("Impossible");
    }
}