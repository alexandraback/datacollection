#include <stdio.h>

const int maxs = 1001;

char shy[maxs];
int T, S;

int main() {
    int c, a;

    scanf("%d", &T);

    for(int t = 1; t <= T; ++t) {
        scanf("%d%s", &S, shy);
        c = a = 0;
        for(int i = 0; i <= S; ++i) {
            if (shy[i] > '0') {
                if (c >= i) {
                    c += shy[i] - '0';
                } else {
                    a += i - c;
                    c += shy[i] - '0' + a;
                }
            }
        }
        printf("Case #%d: %d\n", t, a);
    }

    return 0;
}
