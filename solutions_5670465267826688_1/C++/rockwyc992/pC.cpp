#include <stdio.h>
#include <string.h>

int T;
long long X;
int l;
int L[5];
char str[10100];
char pre[10100];
char post[10100];
char _table[10][10];
int first_i;
int first_k;

#define I 2
#define J 3
#define K 4
#define table(a, b) (_table[(a)+4][(b)+4])

inline char map(int a, int b) 
{
    if (a < 0) {
        return -map(-a, b);
    }
    
    if (b < 0) {
        return -map(a, -b);
    }
    
    if (a == 1) {
        return b;
    }

    if (b == 1) {
        return a;
    }
    
    if (a == b) {
        return -1;
    }

    if (a == I && b ==J) {
        return K;
    }

    if (a == J && b ==K) {
        return I;
    }

    if (a == K && b ==I) {
        return J;
    }

    if (a == J && b ==I) {
        return -K;
    }

    if (a == K && b ==J) {
        return -I;
    }

    if (a == I && b ==K) {
        return -J;
    }

    return 0;
}

int check_total()
{
    int total = 1;
    int times = X%4 + 4;
    for (int i = 0; i < times; i++) {
        total = map(total, L[1]);
    }

    return total == -1;
}

int ans_1()
{
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            int flag = -1;
            for (int i = 0; i <= l; i++) {
                if (map(L[x], pre[i]) == I) {
                    flag = i;
                    break;
                }
            }
            if (flag == -1) {
                continue;
            }

            for (int i = 0; i <= l-flag; i++) {
                if (map(post[i], L[y]) == K) {
                    int less = X - x - y - 1;
                    if (less < 0) {
                        break;
                    }
                    if (less%4 == 0) {
                        return 1;
                    }
                    break;
                }
            }
        }
    }

    return 0;
}

int ans_2()
{
    if (X == 1) {
        return 0;
    }

    for (int a = -4; a <= 4 ; a++) {
        if (!a) {
            continue;
        }
        for (int b = -4; b <= 4 ; b++) {
            if (!b) {
                continue;
            }
            if (table(a, b)) {
                for (int c = -4; c <= 4 ; c++) {
                    if (!c) {
                        continue;
                    }
                    for (int d = -4; d <= 4 ; d++) {
                        if (!d) {
                            continue;
                        }
                        if (table(c, d)) {
                            for (int x = 0; x < 4; x++) {
                                for (int y = 0; y < 4; y++) {
                                    for (int z = 0; z < 4; z++) {
                                        if (map(L[x], a) != I) {
                                            continue;
                                        }
                                        if (map(b, map(L[y], c)) != J) {
                                            continue;
                                        }
                                        if (map(d, L[z]) != K) {
                                            continue;
                                        }
                                        int less = X - x - y - z - 2;
                                        if (less < 0) {
                                            continue;
                                        }
                                        if (less % 4) {
                                            continue;
                                        }
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}

int ans()
{
    if (!check_total()) {
        return 0;
    }

    if (ans_1()) {
        return 1;
    }

    if (ans_2()) {
        return 1;
    }

    return 0;
}

int main()
{
    scanf("%d", &T);
    for (int z = 1; z <= T; z++) {
        scanf("%d%lld%s", &l, &X, str);
        
        pre[0] = 1;
        post[0] = 1;
        first_i = -1;
        first_k = -1;
        for (int i = 0; i < l; i++) {
            pre[i+1] = map(pre[i], str[i]-'i'+2);
            post[i+1] = map(str[l-i-1]-'i'+2, post[i]);

            if (pre[i+1] == I && first_i == -1) {
                first_i = i+1;
            }
            if (post[i+1] == K && first_k == -1) {
                first_k = l - i - 1;
            }
        }

        memset(_table, 0, sizeof(_table));
        for (int i = 0; i <= l; i++) {
            table(pre[i], post[l-i]) = 1;
        }

        L[0] = 1;
        L[1] = post[l];
        L[2] = map(L[1], L[1]);
        L[3] = map(L[1], L[2]);

        printf ("Case #%d: %s\n", z, ans() ? "YES" : "NO");
    }
	return 0;
}

