#include <stdio.h>

int inp[15];
int n, m, k;
int cur[15];

bool search(int lay) {
    if (lay == n) {
        for (int i=0; i<k; i++) {
            bool found = false;
            for (int j=0; j<(1<<n); j++) {
                int mul = 1;
                for (int l=0; l<n; l++) {
                    if ((1<<l)&j) {
                        mul *= cur[l];
                    }
                }
                if (mul == inp[i]) {found = true; break;}
            }
            if (!found) return false;
        }
        return true;
    }
    for (int i=2; i<=m; i++) {
        cur[lay] = i;
        if (search(lay+1)) {
            return true;
        }
    }
    return false;
}

int main() {
    scanf("%*d");
    int casN;
    scanf("%d%d%d%d", &casN, &n, &m, &k);
    printf("Case #1:\n");
    for (int casI = 0; casI < casN; casI++) {
        for (int i=0; i<k; i++) scanf("%d", &inp[i]);
        search(0);
        for (int i=0; i<n; i++) printf("%d", cur[i]);
        puts("");
        
    }
    return 0;
}

