#include <stdio.h>

int N, kejs, n, i;
int res, cnt;
char s[1005];

int main() {
    scanf("%d", &N);
    for (kejs = 1; kejs <= N; kejs++) {
        printf("Case #%d: ", kejs);
        res = cnt = 0;
        scanf("%d%s", &n, s);
        for (n = 0; s[n]; n++) {
            i = s[n] - '0';
            if (cnt < n) {
                res += n - cnt;
                cnt = n;
            }
            cnt += i;
        }
        printf("%d\n", res);
    }
    return 0;
}
