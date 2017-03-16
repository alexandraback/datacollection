#include <stdlib.h>
#include <stdio.h>

int t, p;
int a, b;
int ret;

int calSmall(int a, int b) {
    int fsnum[10] = {1, 4, 9, 121, 484};
    int min = 0, max = 0;    
    int i;
    if (a > 484) return 0;
    for (i=0; i<5; i++) {
        if (fsnum[i] >= a) {
            min = i;
            break;
        }
    }
    for (i=4; i>=0; i--) {
        if (fsnum[i] <= b) {
            max = i;
            break;
        }
    }
    if (max < min) {
        return 0;
    } else {
        return (max - min + 1);
    }
}

int main() {
//    freopen("csmall.in", "r", stdin);
    
    scanf("%d", &t);

    for (p=0; p<t; p++) {
        scanf("%d %d", &a, &b);
        if (b <= 1000) {
            ret = calSmall(a, b);
        }
        printf("Case #%d: %d\n", p+1, ret);
    }
    return 0;
}
