#include <bits/stdc++.h>

typedef long long lli;

int cs[100];

int main() {
    int ct;
    scanf("%d", &ct);
    for (int nt = 1; nt <= ct; nt++) {
        lli n;
        scanf("%I64d", &n);
        lli res = 0;
        if (n < 10) res = n;
        else {
            res = 9;
            int scs = 2;
            lli now = 10;
            lli dest = 99;
            while (1) {
                if (dest > n) {
                    break;
                }
                lli tmp = 0;
                for (int i = 0; i < scs/2; i++) tmp = tmp*10+9;
                res += tmp+1;
                tmp = 0;
                for (int i = 0; i < scs-scs/2; i++) tmp = tmp*10+9;
                res += tmp;
                if (dest == n) break;
                scs++;
                now = now*10;
                dest = dest*10+9;
            }
            if (dest > n) {
                if (n == now) res++;
                else {
                    lli res2 = res + (n-now+1);
                    dest = n;
                    if (n % 10 == 0) {
                        res++;
                        dest--;
                    }
                    for (int i = 0; i < scs; i++) {
                        cs[i] = dest%10;
                        dest /= 10;
                    }
                    lli tmp = 0;
                    for (int i = scs/2-1; i >= 0; i--)
                        tmp = tmp*10 + cs[i];
                    res += tmp+1;
                    tmp = 0;
                    for (int i = scs/2; i < scs; i++) {
                        tmp = tmp*10 + cs[i];
                    }
                    res += tmp;
                    if (res > res2) res = res2;
                }
            }
        }
        printf("Case #%d: %I64d\n", nt, res);
    }
    return 0;
}
