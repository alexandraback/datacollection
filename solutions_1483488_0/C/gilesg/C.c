#include <stdio.h>

int main(int argc, const char *argv[])
{
    int T;
    scanf("%d", &T);
    for (int case_num = 1; case_num <= T; ++case_num) {
        int A, B;
        scanf("%d %d", &A, &B);
        int exp = 0;
        int pow = 1;
        while (10 * pow <= A) {
            pow *= 10;
            exp += 1;
        }
        int digits = exp + 1;
        int total = 0;
        for (int n = A; n < B; ++n) {
            int period = digits;
            int shift = 1;
            for (int i = 1; i <= digits / 2; ++i) {
                shift *= 10;
                if (i < digits && n == n / shift + (10 * pow / shift) * (n % shift)) {
                    period = i;
                    break;
                }
            }
            int count = 0;
            int m = n;
            for (int i = 0; i < digits - 1; ++i) {
                m = m / 10 + pow * (m % 10);
                if (n < m && m <= B) {
                    count += 1;
                }
            }
            total += (count * period) / digits;
        }
        printf("Case #%d: %d\n", case_num, total);
    }
    return 0;
}
