#include <cstdio>
#include <cstring>
#include <algorithm>

struct Item {
    int row, col;
    int val;

    Item() {};
    Item(int a, int b, int c) : row(a), col(b), val(c) {}

    bool operator<(const Item& r) const {
        return val < r.val;
    }
};

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int n, m;
        scanf("%d%d", &n, &m);
        //printf("%d %d\n", n, m);
        int k = 0;
        static int a[200][200];
        static int row_max[200];
        static int col_max[200];
        static Item q[11000];
        std::fill(row_max, row_max + n, 0);
        std::fill(col_max, col_max + m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &a[i][j]);
                row_max[i] = std::max(row_max[i], a[i][j]);
                col_max[j] = std::max(col_max[j], a[i][j]);
                //printf("%d ", a[i][j]);
                q[k++] = Item(i, j, a[i][j]);
            }
            //printf("\n");
        }
        std::sort(q, q + n * m);
        bool failed = false;
        for (int i = n * m - 1; i >= 0; i--) {
            Item& it = q[i];
            if (row_max[it.row] > it.val && col_max[it.col] > it.val) {
                failed = true;
                break;
            }
        }
        printf("Case #%d: %s\n", t, failed ? "NO" : "YES");
        //printf("Case #%d: %d %d %s\n", t, n, m, failed ? "NO" : "YES");
    }
}
