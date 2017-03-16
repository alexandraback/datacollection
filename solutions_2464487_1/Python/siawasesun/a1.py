#!/usr/bin/env python

import sys
import math

def can_draw(R, T, n):
    r = (2 * R + 1) + 2 * R * n + 2 * n * n + 3 * n
    return r <= T

def solve(R, T):
    l = 0
    r = T

    while l + 1 < r:
        m = (l + r) / 2

        if can_draw(R, T, m - 1):
            l = m
        else:
            r = m

    return l

test_cases = int(sys.stdin.readline())
for t in range(test_cases):
    R, T = [int(c) for c in sys.stdin.readline().split(" ")]
    print "Case #%d: %d" % (t + 1, solve(R, T))
