#!/usr/bin/env python
# coding:utf-8
# Copyright (C) dirlt

import sys
fh = sys.stdin
case_n = int(fh.readline())

import itertools

def f2(arr, fwd):
    n = len(arr)
    for i in range(1, n):
        x = arr[i-1]
        y = arr[i]
        if not (fwd[x] == y or fwd[y] == x):
            return i
    x = arr[0]
    y = arr[n-1]
    if fwd[x] == y or fwd[y] == x:
        return n
    return n - 1

def f(fwd):
    res = 0
    n = len(fwd)
    for arr in itertools.permutations(range(0, n)):
        # print arr
        x = f2(arr, fwd)
        res = max(res, x)
        if res == n:
            break
    return res

for c in range(case_n):
    n = int(fh.readline())
    fwd = [0] * n
    vs = map(lambda x: int(x), fh.readline().split())
    for (idx, v) in enumerate(vs):
        fwd[idx] = (v-1)
    res = f(fwd)
    print('Case #%d: %d' % (c + 1, res))
