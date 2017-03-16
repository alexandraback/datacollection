#include <stdio.h>

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int n, m, p = 0, f = 0, j, k;
        int a[100][100];
        int b[100][100] = {0};
        
        scanf("%d %d", &n, &m);
        
        for (j = 0; j < n; j++) {
            for (k = 0; k < m; k++) {
                scanf("%d", &a[j][k]);
                
                if (a[j][k] > p) p = a[j][k];
            }
        }
        
        for (j = 0; j < n; j++) {
            for (k = 0; k < m - 1; k++) {
                if (a[j][k] != a[j][k + 1]) break;
            }
            
            if (k == m - 1) {
                for (k = 0; k < m; k++) b[j][k] = 1;
            }
        }
        
        for (j = 0; j < m; j++) {
            for (k = 0; k < n - 1; k++) {
                if (a[k][j] != a[k + 1][j]) break;
            }
            
            if (k == n - 1) {
                for (k = 0; k < n; k++) b[k][j] = 1;
            }
        }
        
        for (j = 0; j < n; j++) {
            for (k = 0; k < m; k++) {
                if (a[j][k] != p && b[j][k] == 0) {
                    f = 1;
                }
            }
        }
        
        if (f == 0) {
            printf("Case #%d: YES\n", i + 1);
        } else {
            printf("Case #%d: NO\n", i + 1);
        }
    }
    
    return 0;
}
