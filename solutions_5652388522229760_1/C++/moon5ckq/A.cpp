/*
 * A.cpp
 * Copyright (C) 2016 mlckq <moon5ckq@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <cstdio>

int main() {
    int T;
    scanf("%d\n", &T);
    for (int i = 1; i <= T; ++i) {
        printf("Case #%d: ", i);
        int n;
        scanf("%d", &n);

        if (n == 0) printf("INSOMNIA\n");
        else {
            char text[20];
            bool mark[10] = {};
            int cnt = 0;

            for (int j = n; ; j += n) {
                sprintf(text, "%d", j);
                for (char *ch = text; *ch; ch ++)
                    if (!mark[*ch - '0']) {
                        mark[*ch - '0'] = true;
                        cnt ++;
                    }
                if (cnt == 10) {
                    printf("%d\n", j);
                    break;
                }
            }
        }
    }
}

