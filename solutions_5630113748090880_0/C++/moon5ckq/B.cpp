/*
 * B.cpp
 * Copyright (C) 2016 mlckq <moon5ckq@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <cstdio>
#include <cstring>
#define HH 2505 

int c[HH];

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        printf("Case #%d:", i);
        memset(c, 0, sizeof(c));
        int N;
        scanf("%d", &N);
        for (int j = 0; j < N * (2 * N - 1); ++j) {
            int x;
            scanf("%d", &x);
            c[x] ^= 1;
        }
        for (int j = 0; j < HH; ++j)
            if (c[j]) printf(" %d", j);
        printf("\n");

    }
    return 0;
}

