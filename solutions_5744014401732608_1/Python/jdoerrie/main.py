#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys
import numpy as np

YES = "POSSIBLE"
NO = "IMPOSSIBLE"


def check_mat(mat, B, M):
    counts = np.zeros(B + 1, int)
    counts[B] = 1
    for i in range(B - 1, 0, -1):
        for j in range(i, B + 1):
            if mat[i, j] == 1:
                counts[i] += counts[j]

    if counts[1] != M:
        print(B, M)
        print(counts)
    assert counts[1] == M


def solve():
    B, M = map(int, input().split())
    if 2 ** (B - 2) < M:
        print(NO)
        return

    print(YES)
    mat = np.zeros([B + 1, B + 1], int)

    if 2 ** (B - 2) == M:
        for i in range(1, B):
            for j in range(i, B):
                mat[i, j + 1] = 1
    else:
        pow2 = 1
        u = B - 1
        while pow2 <= M:
            for v in range(u, B):
                mat[u, v + 1] = 1
            pow2 *= 2
            u -= 1

        # connecting u to all following nodes would result in pow2 paths
        for i in range(50):
            if (M & (2 ** i)) != 0:
                mat[1, B - 1 - i] = 1

    for i in range(1, B + 1):
        assert mat[i, i] == 0
        assert mat[B, i] == 0

    check_mat(mat, B, M)
    for i in range(B):
        print(''.join(list(map(str, mat[i + 1, 1:]))))


def main():
    T = int(input())
    for t in range(T):
        print("Case #{0}: ".format(t + 1), end='')
        solve()


if __name__ == "__main__":
    main()
