#include <cstdio>

int main() {
    int T;
    scanf("%d", &T);

    for (int I = 1; I <= T; I++) {
        int N;
        scanf("%d", &N);

        int appearedCount = 0;
        bool appeared[10] = {};
        int i = 0;

        for (i = N; appearedCount < 10 && N != 0; i += N) {
            int tmp = i;
            while (tmp > 0) {
                if (!appeared[tmp % 10]) {
                    ++appearedCount;
                    appeared[tmp % 10] = true;
                }

                tmp /= 10;
            }
        }

        if (appearedCount != 10) {
            printf("Case #%d: INSOMNIA\n", I);
        } else {
            printf("Case #%d: %d\n", I, i - N);
        }
    }

    return 0;
}
