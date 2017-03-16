#include <stdio.h>

int T;
int xa, xb;
int num;
long long ta, tb;
int n;

int main()
{
    scanf("%d", &T);
    for(int z=1;z<=T;z++) {
        scanf("%d", &n);
        if (n == 1) {
            scanf("%d%d%d", &xa, &num, &ta);
            if (num == 2) {
                xb = xa;
                tb = ta+1;
            } else {
                printf ("Case #%d: 0\n", z);
                continue;
            }
        } else if (n == 2) {
            scanf("%d%*d%d%d%*d%d", &xa, &ta, &xb, &tb);
        }

        if (ta > tb) {
            int t = xa;
            xa = xb;
            xb = t;
            t = ta;
            ta = tb;
            tb = t;
        }

        long long ma = (360 - xa) * ta;
        long long mb = (360 - xb) * tb;
        if (ma < mb) {
            ma = (720 - xa) * ta;
            if (ma <= mb) {
                printf ("Case #%d: 1\n", z);
            } else {
                printf ("Case #%d: 0\n", z);
            }
        } else {
            printf ("Case #%d: 0\n", z);
        }
    }
	return 0;
}

