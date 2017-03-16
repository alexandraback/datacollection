#!/usr/bin/env python3

import numpy as np

T = int(input())

for t in range(1, T+1):
    N = int(input())

    A = np.zeros((2 * N - 1, N), dtype=int)
    for i in range(2 * N - 1):
        A[i, :] = list(map(int, str.split(input())))

    A = np.sort(A, 0)
    U = np.unique(A)

    l = []
    for u in U:
        if np.sum(A == u) % 2 == 1:
            l.append(u)

    print('Case #' + str(t) + ': ' + ' '.join(map(str, l)))
