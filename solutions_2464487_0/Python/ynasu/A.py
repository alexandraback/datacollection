#!/usr/bin/env python

import sys

def is_drawable(r, t, n):
    return n * ((2 * r + 1) + (2 * (r + 2 * (n - 1)) + 1)) / 2 <= t

def solve(r, t):
    d = 1
    while d < t:
        d <<= 1
    res = 0
    while d > 0:
        if is_drawable(r, t, res | d):
            res |= d
        d >>= 1
    return res

def read_ints():
    return [ int(s) for s in sys.stdin.readline().split() ]

T = int(sys.stdin.readline())
for i in xrange(T):
    inputs = read_ints()
    r = inputs[0]
    t = inputs[1]
    res = solve(r, t)
    print "Case #%d: %s" % (i + 1, res)
