#!/usr/bin/env python
# coding:utf-8
# Copyright (C) dirlt

import sys
fh = sys.stdin
case_n = int(fh.readline())

def f(s):
    cache = [None] * len(s)
    def rec(s, n):
        if n == 0:
            return s[0]
        if cache[n]:
            return cache[n]
        x = rec(s, n-1)
        c = s[n]
        res = max(c + x, x + c)
        cache[n] = res
        return res
    return rec(s, len(s) - 1)

for c in range(case_n):
    s = fh.readline().strip()
    res = f(s)
    print('Case #%d: %s' % (c + 1, res))
