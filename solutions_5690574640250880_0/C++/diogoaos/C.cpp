#include <cstdio>
#include <cstring>

char ans[60][60];

int main() {
    int ntests, r, c, m;
    
    scanf("%d", &ntests);
    
    for (int test = 1; test <= ntests; test++) {
        scanf("%d %d %d", &r, &c, &m);
        int p = r * c - m;
        
        printf("Case #%d:\n", test);
        
        if (r == 1 || c == 1) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (i + j == 0) putchar('c'), p--;
                    else if (p) putchar('.'), p--;
                    else putchar('*');
                }
                putchar('\n');
            }
        } else {
            if (p == 2 || p == 3 || p == 5 || p == 7) {
                puts("Impossible");
                continue;
            }
            
            if (p == 1) {
                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        if (i + j == 0) putchar('c'), p--;
                        else putchar('*');
                    }
                    putchar('\n');
                }
                continue;
            }
            
            if ( (r == 2 || c == 2) && (p & 1) ){
                puts("Impossible");
                continue;
            }
            
            memset(ans, 0, sizeof(ans));
            
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    if (i + j == 0) ans[i][j] = 'c';
                    else ans[i][j] = '.';
                    
                    p--;
                }
            }
            
            for (int j = 2; j < c; j++) {
                if (p > 3 || p == 2) {
                    for (int i = 0; i < 2; i++) {
                        ans[i][j] = '.';
                        p--;
                    }
                }
            }
            
            for (int i = 2; i < r; i++) {
                if (p > 1) {
                    for (int j = 0; j < 2; j++) {
                        ans[i][j] = '.';
                        p--;
                    }
                }
            }
            
            for (int i = 2; i < r; i++) {
                for (int j = 2; j < c; j++) {
                    if (p) {
                        ans[i][j] = '.';
                        p--;
                    } else {
                        ans[i][j] = '*';
                    }
                }
            }
            
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (!ans[i][j]) {
                        ans[i][j] = '*';
                    }
                }
            }
            
            for (int i = 0; i < r; i++) {
                puts(ans[i]);
            }
        }
    }
    
    return 0;
}
