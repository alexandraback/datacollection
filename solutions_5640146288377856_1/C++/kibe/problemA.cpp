#include <stdio.h>

int main() {
    int t, r, c, w, coun, res, aux;

    coun = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &r, &c, &w);
        aux = c / w;
        if (c % w == 0) {
            res = w - 1;
        } else {
            res = w;
        }
        res = res + aux * r;
        printf("Case #%d: %d\n", coun, res);
        coun++;
    }
    return 0;
}
