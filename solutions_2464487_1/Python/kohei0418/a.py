#!/usr/bin/env python

import sys

n = int(sys.stdin.readline())

for casenum in range(n):
    r, t = map(int, sys.stdin.readline().split())

    lb, ub = (0, t)
    a1 = 2 * r + 1
    d = 4
    while ub - lb > 1:
        mid = (lb + ub) / 2
        cost = mid * ((2 * a1 + (mid - 1) * d) / 2)
        if cost <= t:
            lb = mid
        else:
            ub = mid

    print "Case #%d: %d" % (casenum + 1, lb)
