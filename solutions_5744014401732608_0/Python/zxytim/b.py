#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# $File: b.py
# $Date: Sun May 08 17:50:13 2016 +0800
# $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>

import math
import numpy as np
import collections


def dp_check(g):
    n = len(g)
    degin = [0] * n
    for i in range(n):
        for j in range(n):
            degin[j] += g[i][j]

    f = [0] * n
    queue = collections.deque()
    for i in range(n):
        if degin[i] == 0:
            queue.append(i)
            f[i] = 1

    while len(queue) > 0:
        cur = queue.popleft()
        for j in range(n):
            if g[cur][j]:
                f[j] += f[cur]
            degin[j] -= 1
            if degin[j] == 0:
                queue.append(j)

    return f[n-1]


def solve():
    B, M = list(map(int, input().strip().split()))
    f = [0] * B
    f[0] = 1
    for i in range(1, B):
        for j in range(0, i):
            f[i] += f[j]

    if M > f[B - 1]:
        print('IMPOSSIBLE')
        return
    print('POSSIBLE')

    selected = []
    cur = M
    for i in range(B - 2, -1, -1):
        if cur >= f[i]:
            cur -= f[i]
            selected.append(i)

    g = [[0] * B for _ in range(B)]
    for i in range(B - 1):
        for j in range(0, i):
            g[j][i] = 1

    for i in selected:
        g[i][B-1] = 1

    for i in range(B):
        print(''.join(map(str, g[i])))
    t = dp_check(g)
    assert t == M, (t, M)



# print(solve())
nr_case = int(input().strip())

for case_id in range(1, nr_case + 1):
    print('Case #{}: '.format(case_id), end='')
    solve()


# vim: foldmethod=marker

