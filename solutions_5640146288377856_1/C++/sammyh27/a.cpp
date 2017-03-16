#include <stdio.h>

int tc, cases, r, c, w, res;

int main() {
    cases = 1;
    scanf("%d\n", &tc);
    while(tc--) {
        scanf("%d %d %d\n", &r, &c, &w);
        res = (c/w) * r;
        if(c%w!=0) res++;
        res += w-1;
        printf("Case #%d: %d\n", cases++, res);
    }
    return 0;
}
