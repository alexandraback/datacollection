#!/usr/bin/env python

import sys

def draw(r):
    return pow(r + 1, 2) - pow(r, 2)

def solve(R, T):
    res = 0
    rest = T
    r = R

    while True:
        use = draw(r)
        if rest >= use:
            rest -= use
            res += 1
            r += 2
        else:
            break

    return res

test_cases = int(sys.stdin.readline())
for t in range(test_cases):
    R, T = [int(c) for c in sys.stdin.readline().split(" ")]
    print "Case #%d: %d" % (t + 1, solve(R, T))
