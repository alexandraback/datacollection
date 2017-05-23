#include<stdio.h>
int main() {
    int T, n, t = 1;
    int chk[10];
    for(scanf("%d", &T); (T--); ++t) {
        scanf("%d", &n);
        int res = -1;
        for(int i = 0; i <= 9; ++i) chk[i] = 0;
        for(int i = 0, x = n; i < 100; ++i, x+=n) {
            for(int tmp = x; tmp > 0; tmp /= 10) chk[tmp%10] ++;
            int flag = 1;
            for(int j = 0; j <= 9; ++j) if(chk[j] == 0) flag = 0;
            if(flag) { res = i+1; break; }
        }
        if(res == -1) printf("Case #%d: INSOMNIA\n", t);
        else printf("Case #%d: %d\n", t, res*n);
    }
    return 0;
}
