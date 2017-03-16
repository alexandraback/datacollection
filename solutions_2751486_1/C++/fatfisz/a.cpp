#include <cstdio>

int T, n, last, i, cons;
long long int res;
char s[1000001];

int main() {
    scanf("%d\n", &T);
    for (int t = 0; t < T; ++t) {
        scanf("%s %d\n", s, &n);
        last = 0;
        res = 0;
        cons = 0;
        for (i = 0; s[i]; ++i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                cons = 0;
            } else {
                ++cons;
                if (cons >= n) {
                    last = i - n + 2;
                }
            }
            res += last;
        }
        printf("Case #%d: %lld\n", t + 1, res);
    }
    return 0;
}
