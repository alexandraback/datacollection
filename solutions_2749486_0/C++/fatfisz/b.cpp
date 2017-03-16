#include <cstdio>

int T, x, y, abs, i, sum, buflen;
char buffer[10000];

int main() {
    scanf("%d\n", &T);
    for (int t = 0; t < T; ++t) {
        scanf("%d %d\n", &x, &y);
        abs = (x > 0 ? x : -x) + (y > 0 ? y : -y);
        sum = 0;
        for (i = 0; abs > sum;) sum += (++i);
        while ((sum - abs) % 2) sum += (++i);
        //printf("%d %d %d\n", i, abs, sum);
        buflen = i;
        for (; i > 0; --i) {
            //printf("%d %d %d %d\n", x, y, sum, i);
            if (x > sum - i) {
                buffer[i - 1] = 'E';
                x -= i;
            } else if (x < i - sum) {
                buffer[i - 1] = 'W';
                x += i;
            } else if (y > 0) {
                buffer[i - 1] = 'N';
                y -= i;
            } else {
                buffer[i - 1] = 'S';
                y += i;
            }
            sum -= i;
        }
        //printf("%d %d\n", x, y);
        printf("Case #%d: %.*s\n", t + 1, buflen, buffer);
    }
    return 0;
}
