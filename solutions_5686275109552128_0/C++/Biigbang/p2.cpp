#include <stdio.h>

const int MAXD = 40001;

int p[MAXD];
int T, D;

inline int max(int a, int b) {
    return a > b ? a : b;
}

inline int min(int a, int b) {
    return a < b ? a : b;
}

int find(int i, int m, int sp) {
    if (i == D)
        return m + sp;

    int ans = 987654321; 
    for(int c = 1; c <= p[i]; c++) {
        int b = (p[i] - 1) / c + 1;
        ans = min(ans, find(i + 1, max(m, b), sp + c - 1));
    }

    return ans;
}

int main() {
    int ans;

    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%d", &D);
        for(int i = 0; i < D; ++i)
            scanf("%d", p + i);

        printf("Case #%d: %d\n", t, find(0, 0, 0)) ;
    }

    return 0;
}
