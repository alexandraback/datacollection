#include <cstdio>
#include <iostream>

const int N = 1007;

int main() {
    int T;
    scanf("%d", &T);
    char s[N];
    char res[2 * N];
    for (int i = 0; i < T; ++i) {
        scanf("%s", s);
        int a = N, b = N;
        res[a] = s[0];
        for (int j = 1; s[j]; ++j) {
            char c = s[j];
            if (c >= res[a]) {
                --a;
                res[a] = c;
            } else {
                ++b;
                res[b] = c;
            }
        }
        ++b;
        res[b] = '\0';
        printf("Case #%d: %s", i + 1, res + a);
        if (i + 1 < T) {
            printf("\n");
        }
    }
    return 0;
}
