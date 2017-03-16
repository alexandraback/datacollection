#include <cstdio>


int count_sheep(int n) {
    if (n <= 0) {
        return 0;
    }
    bool digits[10] = {};
    int num_of_digits = 0;
    int cnt = 0;

    while (num_of_digits < 10) {
        cnt += n;
        int test = cnt;
        while(test > 0) {
            int digit = test % 10;
            if (!digits[digit]) {
                digits[digit] = true;
                num_of_digits++;
            }
            if (num_of_digits == 10) {
                break;
            }
            test /= 10;
        }
        //fprintf(stderr, "cnt %d", cnt);
    }

    return cnt;
}


int main() {
    int T, N;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        scanf("%d", &N);
        int count = count_sheep(N);
        if (count > 0) {
            printf("Case #%d: %d\n", i + 1, count);
        } else {
            printf("Case #%d: INSOMNIA\n", i + 1);
        }
    }
}
