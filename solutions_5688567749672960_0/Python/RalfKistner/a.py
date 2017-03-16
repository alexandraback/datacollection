#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Uses https://github.com/rkistner/contest-algorithms

import sys

from fractions import gcd

def debug(*args):
    print(*args, file=sys.stderr)

def reverse(nr):
    return int(str(nr)[::-1])

fin = sys.stdin
T = int(fin.readline())
for case in range(1, T + 1):
    n = int(fin.readline())
    least = {1: 1}
    for i in range(2, n+1):
        if i in least:
            least[i] = min(least[i-1]+1, least[i])
        else:
            least[i] = least[i-1]+1

        rev = reverse(i)
        if rev > i:
            least[rev] = least[i] + 1

    result = least[n]
    # debug(least)

    print("Case #%d: %s" % (case, result))