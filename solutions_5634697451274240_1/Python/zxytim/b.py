#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# $File: b.py
# $Date: Sat Apr 09 22:11:17 2016 +0800
# $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>


import numpy as np


def solve():
    s = input().strip()
    sym2int = {'+': 1, '-': 0}
    s = [sym2int[i] for i in s]
    n = len(s)

    f = np.ones((n + 1, 2), dtype=int) * n * 2
    f[0] = 0

    for i in range(1, n + 1):
        c = s[i-1]
        f[i,c] = min(f[i-1,c], f[i-1,1-c] + 1)
        f[i,1-c] = min(f[i-1,c] + 1, f[i,c] + 1)
        f[i,c] = min(f[i,c], f[i,1-c] + 1)
        f[i,1-c] = min(f[i,1-c], f[i,c] + 1)
    return f[n,1]


nr_case = int(input().strip())

for caseid in range(1, nr_case + 1):
    print('Case #{}: {}'.format(caseid, solve()))

# vim: foldmethod=marker

