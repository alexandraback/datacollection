#!/usr/bin/python
import math
import string
import sys

def fn(n, r, t):
    return 2 * n * r - 3 * n + 2 * n * (n+1) - t

def findNum(r, t):
    lo = 1
    hi = 1
    while fn(hi, r, t) <= 0:
        hi *= 2
    while (hi - lo > 8):
        n = (lo + hi)/2
        if fn(n, r, t) > 0:
            hi = n
        elif fn(n, r, t) < 0:
            lo = n
        else:  # It is zero, so we have exact
            return n
    candidates = range(lo, hi + 1)
    return max([ x for x in candidates if fn(x, r, t) <= 0])
        

def solve(line):
    r, t = [int(x) for x in line.split() ]
    return findNum(r, t)

f = open(sys.argv[1])
NUM_CASES = int(f.readline())  # number of lines
for qq in range(NUM_CASES):
    line = f.readline().strip()
    print "Case #%d: %s" % (qq+1, solve(line))
