#include <stdlib.h>
#include <stdio.h>

int p, t, n, m, i, j, ret;
int num[200][200];


int ifVsame(int x, int y) {
    int r;
    int k = -1;
    int sameCount = 0;
    for (r=0; r<n; r++) {
        if (num[r][y] == num[x][y]) {
            sameCount++;
        } else {
            if (k == -1) k = num[r][y];
        }
        if (num[r][y] == k && sameCount > 2) {
            return 0;
        }
        if (num[r][y] != k && num[r][y] != num[x][y]) {
            return 0;
        }
    }
    return 1;
}

int ifHsame(int x, int y) {
    int r;
    int k = -1;
    int sameCount = 0;
    for (r=0; r<m; r++) {
        if (num[x][r] == num[x][y]) {
            sameCount++;
        } else {
            if (k == -1) k = num[x][r];
        }
        if (num[x][r] == k && sameCount > 2) {
            return 0;
        }
        if (num[x][r] != k && num[x][r] != num[x][y]) {
            return 0;
        }
    }
    return 1;
}

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
//    freopen("bsmall.in", "r", stdin);
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
