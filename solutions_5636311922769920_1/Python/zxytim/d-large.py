#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# $File: d-large.py
# $Date: Sun Apr 10 00:20:07 2016 +0800
# $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>

import math

def solve():
    K, C, S = map(int, input().strip().split())
#     K, C, S = 100, 2, 100
    n = K**C
    m = math.ceil(K / C)
    if S < m:
        return 'IMPOSSIBLE'

    ans = []
    num = 0
    for i in range(m):
        cur = 0
        for j in range(C):
            assert num < K, (num, i, m, j, C)
            cur += num * K**max(0, j - 1)
            num += 1
            if num == K:
                break
        ans.append(cur + 1)
    return ' '.join(map(str, ans))

# print(solve())
nr_case = int(input().strip())

for caseid in range(1, nr_case + 1):
    print('Case #{}: {}'.format(caseid, solve()))


# vim: foldmethod=marker

