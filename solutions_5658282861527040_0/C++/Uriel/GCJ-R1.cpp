#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int fg[1010];

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-s.txt", "w", stdout);
    int cse, g = 1, i, j, a, b, k, tp, res;
    scanf("%d", &cse);
    while(cse--) {
        memset(fg, 0, sizeof(fg));
        scanf("%d %d %d", &a, &b, &k);
        for(i = 0; i < a; ++i) {
            for(j = 0; j < b; ++j) {
                tp = i & j;
                fg[tp]++;
            }
        }
        res = 0;
        for(i = 0; i < k; ++i) {
            res += fg[i];
        }
        printf("Case #%d: %d\n", g++, res);
    }
    return 0;
}
