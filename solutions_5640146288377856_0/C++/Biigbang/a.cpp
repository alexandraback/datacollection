#include <stdio.h>

int T, R, C, W;

int main() {
    int a1, a2, ans, r, c;

    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%d%d%d", &R, &C, &W);
        r = R / W;
        c = C / W;
        if (R%W) r++;
        if (C%W) c++;

        a1 = r * C + W - 1; 
        a2 = c * R + W - 1;
   
        ans = a1 < a2 ? a1 : a2;
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
