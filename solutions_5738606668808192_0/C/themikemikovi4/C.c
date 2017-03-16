#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define N 16
#define J 50

#define int long long int

typedef struct {
    char *s;
    int divs[9];
} ansstr;

char s[N];
ansstr answers[J];
int answers_ptr = 0;

int divisor(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return i;
        }
    }
    return 0;
}

int conv(int base) {
    int ret = 0, bp = 1;
    for (int i = N - 1; i >= 0; --i, bp *= base) {
        ret += (s[i] - '0') * bp;
    }
    return ret;
}

char check(void) {
    ansstr ans;
    for (int base = 2; base <= 10; ++base) {
        ans.divs[base - 2] = divisor(conv(base));
        if (ans.divs[base - 2] == 0) {
            return 0;
        }
    }
    ans.s = malloc(N + 1);
    memcpy(ans.s, s, N);
    ans.s[N] = 0;
    answers[answers_ptr++] = ans;
    return 1;
}

char gen(int i) {
    if (i == N - 1) {
        check();
        return answers_ptr >= J;
    } else {
        s[i] = '0';
        if (gen(i + 1)) {
            return 1;
        }
        s[i] = '1';
        return gen(i + 1);
    }
}

int32_t main(void) {
    s[0] = s[N - 1] = '1';
    gen(1);
    printf("Case #1:\n");
    for (int i = 0; i < J; ++i) {
        printf("%s ", answers[i].s);
        free(answers[i].s);
        for (int j = 0; j < 9; ++j) {
            printf("%lld ", answers[i].divs[j]);
        }
        printf("\n");
    }

    return 0;
}
