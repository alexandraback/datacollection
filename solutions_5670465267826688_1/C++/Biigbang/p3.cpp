#include <stdio.h>

const int MAXL = 10001;

char str[MAXL];

int dat[MAXL];
int rst[MAXL];
int sgn[MAXL];
int cnt[4];

int T, L;
long long X;

const int tbl_m[4][4] = {
    { 0, 1, 2, 3 },
    { 1, 0, 3, 2 },
    { 2, 3, 0, 1 },
    { 3, 2, 1, 0 },
};

const int tbl_s[4][4] = {
    { 1,  1,  1,  1 },
    { 1, -1,  1, -1 },
    { 1, -1, -1,  1 },
    { 1,  1, -1, -1 },
};

int s2d(char a) {
    if (a == 'i') return 1;
    if (a == 'j') return 2;
    if (a == 'k') return 3;
    return 0;
}

int main() {
    int r, s, nr, ns, c, d;

    scanf("%d", &T);

    for(int t = 1; t <= T; ++t) {
        scanf("%d%lld%s", &L, &X, str);

        for(int i = 0; i < L; ++i) {
            dat[i] = s2d(str[i]);
        }

        r = 0;  s = 1;
        for(int i = 0; i < L; ++i) {
            nr = tbl_m[r][dat[i]];
            ns = s * tbl_s[r][dat[i]];
            r = nr; s = ns;
        }

        if ((r == 0 && s == 1)
            || (r == 0 && s == -1 && !(X % 2))
            || ((r != 0 || s != -1) && ((X % 2) || !((X / 2) % 2)))) {
            printf("Case #%d: NO\n", t);
            continue;
        }

        X = X < 16 ? X : 16;
        r = 0;  s = 1;  d = 1;
        for(int j = 0; j < X; ++j) {
            for(int i = 0; i < L; ++i) {
                nr = tbl_m[r][dat[i]];
                ns = s * tbl_s[r][dat[i]];
                if (nr == d && ns == 1) {
                    if (d == 3) break;
                    d++; r = 0; s = 1;
                } else {
                    r = nr; s = ns;
                }
            }
        }

        if (d == 3)
            printf("Case #%d: YES\n", t);
        else
            printf("Case #%d: NO\n", t);
    }

    return 0;
}
