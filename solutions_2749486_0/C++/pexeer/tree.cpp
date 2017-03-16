#include <cstdio>
#include <cstring>

char buf[502][502][502];

int f[502][502];

char ans[502];

int main(void) {
    int t, x, y;
    
    scanf("%d", &t);
    buf[0][250][250] = 'X';

    for (int i=1; i<502; ++i) {
        for (int l=0; l<502; ++l) {
            for (int j=0; j<502; ++j) {
                if (buf[i-1][l][j]) {
                    if (!f[l][j]) {
                        f[l][j] = i-1;
                    }
                    if (l+i<502) {
                        buf[i][l+i][j] = 'E';
                    }
                    if (j+i<502) {
                    buf[i][l][j+i] = 'N';
                    }
                    if (l-i>0) {
                    buf[i][l-i][j] = 'W';
                    }
                    if (j-i>0) {
                    buf[i][l][j-i] = 'S';
                    }
                }
            }
        }
    }

    for (int ti=1; ti<=t; ++ti) {
        scanf("%d %d", &x, &y);
        x += 250;
        y += 250;
        int i = f[x][y];
        if (!i) {
            printf("Not E\n");
            return 1;
        }
        //printf("i:%d\n", i);
        ans[i+1] = 0;
        for (int j=i; j>0; --j) {
            ans[j] = buf[j][x][y];
            //printf("%c\n", ans[j]);
            if (ans[j] == 'N') {
                y -= j;
            } else if (ans[j] == 'S') {
                y += j;
            } else if (ans[j] == 'E') {
                x -= j;
            } else  if (ans[j] == 'W'){
                x += j;
            } else {
                printf("Error\n");
                return 1;
            }
        }
        printf("Case #%d: %s\n", ti, ans+1);

    }
    return 0;
}
