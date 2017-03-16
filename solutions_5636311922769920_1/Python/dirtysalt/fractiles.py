#!/usr/bin/env python
# coding:utf-8
# Copyright (C) dirlt

import sys
fh = sys.stdin
case_num = int(fh.readline())
def f(K, C, S):
    group = (K - C + 1)
    if S < group:
        return 'IMPOSSIBLE'
    res = []
    x = 0
    for i in range(1, min(C, K)):
        x = x * K + i
    res.append(x + 1)
    for i in range(C, K):
        res.append(i + 1)
    return ' '.join(map(lambda x: str(x), res))

for c in range(case_num):
    (K, C, S) = map(lambda x: int(x), fh.readline().split())
    res = f(K, C, S)
    print('Case #%d: %s' % (c + 1, res))
