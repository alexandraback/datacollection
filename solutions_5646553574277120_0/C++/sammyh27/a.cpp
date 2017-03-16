#include <stdio.h>

int c, d, v, tc, cases, i, j, ct;
int a[35], coin[35];
bool b;

void fu() {
    for(i=0; i<=v; i++) {
        a[i] = 0;
    }
    a[0] = 1;
    for(i=0; i<d; i++) {
        for(j=v-coin[i]; j>=0; j--) {
            if(a[j]==1) {
                a[j+coin[i]] = 1;
            }
        }
    }
}

int main() {
    cases = 1;
    scanf("%d\n", &tc);
    while(tc--) {
        scanf("%d %d %d\n", &c, &d, &v);
        for(i=0; i<d; i++) {
            scanf("%d \n",  &coin[i]);
        }
        ct = 0;
        b = true;
        fu();
        while(b) {
            b = false;
            for(i=0; i<=v; i++) {
                if(a[i]==0) {
                    coin[d++] = i;
                    ct++;
                    b = true;
                    fu();
                    break;
                }
            }
        }
        printf("Case #%d: %d\n", cases++, ct);
    }
    return 0;
}
