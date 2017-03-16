#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Uses https://github.com/rkistner/contest-algorithms

import sys


def debug(*args):
    print(*args, file=sys.stderr)

fin = sys.stdin
T = int(fin.readline())
for case in range(1, T + 1):
    B, N = map(int, fin.readline().split())

    result = []
    for i in range(B-1):
        row = '0' * (B-i) + '1' * i
        result.append(row)

    # 0: 1
    # 1: 1
    # 2: 2
    # 3: 4
    # 2 ** (i-1)
    remaining = N
    lastrow = '0'
    for i in range(1, B):
        val = 1
        if (B-i-1) > 1:
            val = 2 ** (B-i-2)
        debug(i, val)
        if remaining >= val:
            remaining -= val
            lastrow += '1'
        else:
            lastrow += '0'
    result.append(lastrow)
    result.reverse()

    if remaining == 0:
        print("Case #%d: %s" % (case, "POSSIBLE"))
        for row in result:
            print(row)
    else:
        print("Case #%d: %s" % (case, "IMPOSSIBLE"))

