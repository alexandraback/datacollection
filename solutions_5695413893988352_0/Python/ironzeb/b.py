#!/usr/bin/env python
# -*- Encoding: utf-8 -*-

from __future__ import print_function, unicode_literals

import sys
from collections import defaultdict


def matches(ref, num2):
    for i, c in enumerate(ref):
        if c != "?" and c != num2[i]:
            return False
    return True


def solve(C, J):
    best = None
    bestVal = (0, 0)
    L = len(J)
    for Cnum in range(0, 10**L):
        for Jnum in range(0, 10**L):
            c = str(Cnum).zfill(L)
            j = str(Jnum).zfill(L)
            if matches(C, c) and matches(J, j):
                if best is None or abs(Cnum - Jnum) < abs(best[0] - best[1]):
                    best = (Cnum, Jnum)
                    bestVal = (c, j)
    return " ".join(bestVal)

if __name__ == '__main__':
    f = sys.stdin
    T = int(f.readline())

    for t in range(T):
        C, J = map(str, f.readline().strip().split(" "))
        ans = solve(C, J)
        print("Case #{}: {}".format(t + 1, ans))
