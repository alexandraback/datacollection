#include <cstdio>
#include <cstring>

char s[1000000 + 100];

bool is(char c) {
    return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}

unsigned long long solve(int n) {
    int l = strlen(s);
    int c = is(s[0]);
    unsigned long long ret = 0;
    int m = is(s[0]) ? 0 : -1;
    int p = -1, q = 0;
    while (p < l && q < l) {
        p += 1;
        if (p > 0) {
            if (m < p) {
                m++;
                c--;
            }
        }
        while (c < n && q < l) {
            q++;
            if (is(s[q])) {
                if (m == -1) {
                    m = q;
                }
                c++;
            } else {
                c = 0;
                m = -1;
            }
        }
        //printf("p = %d, q = %d, c = %d, m = %d, l = %d, %d, ret = %llu\n", p, q, c, m, l, l - q, ret);
        if (c >= n && q < l) {
            ret += l - q;
        }
    }
    return ret;
}

int main() {
    int T;
    scanf("%d\n", &T);
    for (int t = 0; t < T; t++) {
        int n;
        scanf("%s %d", s, &n);
        //if (t != 3) continue;
        unsigned long long ans = solve(n);
        printf("Case #%d: %llu\n", t+1, ans);
        //break;
    }
    return 0;
}

