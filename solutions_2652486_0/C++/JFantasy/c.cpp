#include <cstdio>
#include <cstring>

int a[10], b[10], n, m, k, r;

bool check(int x, int y, int z) {
    b[0] = 1;
    b[1] = x;
    b[2] = y;
    b[3] = z;
    b[4] = x * y;
    b[5] = x * z;
    b[6] = y * z;
    b[7] = x * y * z;
    for (int i = 0; i < 7; ++ i) {
        int flag = 0;
        for (int j = 0; j <= 7; ++ j) {
            if (a[i] == b[j]) flag = 1;
        }
        if (flag == 0) return 0;
    }
    return 1;
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas --) {
        scanf("%d%d%d%d", &r, &n, &m, &k);
        printf("Case #1:\n");
        while (r --) {
            for (int i = 0; i < k; ++ i) scanf("%d", &a[i]);
            int flag = 0;
            for (int x = 2; x <= m && !flag; ++ x) {
                for (int y = 2; y <= m && !flag; ++ y) {
                    for (int z = 2; z <= m && !flag; ++ z) {
                        if (check(x, y, z)) {
                            printf("%d%d%d\n", x, y, z);
                            flag = 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
