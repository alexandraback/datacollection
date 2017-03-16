#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int T, A, B;
int i, j, k;
int num[2000002];

int nbits(int a)
{
    int nb = 0;
    while (a > 0) {
        a /= 10;
        nb++;
    }
    return nb;
}

int shift(int num, int offset)
{
    offset = offset % nbits(num);
    int mod = (int)pow(10, offset);
    int m = num / mod, n = num % mod;
    return n * pow(10, nbits(m)) + m;
}

int calculate()
{
    int cnt = 0;
    memset(num, 0, sizeof(num));
    for (k = A; k <= B; k++) {
        if (num[k])
            continue;

        num[k] = 1;
        int kcnt = 1;
        for (j = 0; j < 8; j++) {
            int kk = shift(k, j);
            if (kk >= A && kk <= B && !num[kk]) {
                num[kk] = 1;
                kcnt++;
            }
        }
        cnt += (kcnt * (kcnt - 1)) / 2;
    }

    return cnt;
}

int main()
{
    scanf("%d", &T);
    for (i = 0; i < T; i++) {
        scanf("%d %d", &A, &B);
        printf("Case #%d: %d\n", i+1, calculate());
    }
}
