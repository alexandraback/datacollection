#include<stdio.h>
#include<string.h>


void main() {
    int i, t;
    int p, q, a;
    scanf("%d", &t);
    for (i = 1 ; i <= t ; i++) {
        scanf("%d/%d", &p, &q);
        int ans = 0;
        while (p < q) {
            p = p * 2;
            ans++;
        }
        for (a = 1; a < q ; a = a *2) {
        
        }
        if (a == q) {
            printf("Case #%d: %d\n", i, ans);   
        } else {
            printf("Case #%d: impossible\n", i);   
        }
    }
}
