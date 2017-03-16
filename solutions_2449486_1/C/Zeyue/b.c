#include <stdlib.h>
#include <stdio.h>

int p, t, n, m, i, j, ret;
int num[200][200];

int ifPossible() {
    int r;
    int maxh, maxv, minhv;
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            maxh = 0;
            maxv = 0;
            for (r=0; r<m; r++) {
                if (r != j) {
                    maxh = (num[i][r] > maxh) ? num[i][r] : maxh;
                }
            }
            for (r=0; r<n; r++) {
                if (r != i) {
                    maxv = (num[r][j] > maxv) ? num[r][j] : maxv;
                }
            }
            minhv = maxh > maxv ? maxv : maxh;
            if (minhv > num[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}


int main() {
    /* freopen("blarge.in", "r", stdin); */
    scanf("%d", &t);
    
    for (p=0; p<t; p++) {
        /* read */
        ret = 0;
        scanf("%d%d", &n, &m);
        
        for (i=0; i<n; i++) {
            for (j=0; j<m; j++) {
                scanf("%d", &num[i][j]);
            }
        }

        /* cal */
        ret = ifPossible();

        /* output */
        printf("Case #%d: ", p+1);
        if (ret == 0) {
            printf("NO\n");
        }
        if (ret == 1) {
            printf("YES\n");
        }
    }
    
    return 0;
}
