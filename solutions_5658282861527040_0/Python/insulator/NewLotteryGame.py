#!/usr/bin/env python
import sys

def solve(a, b, k):
    #a, b = min(a, b), max(a, b)
    #if a <= k:
        #return (a - 1) * (b - 1)
    s = 0
    for i in xrange(a):
        for j in xrange(b):
            if i & j < k:
                s += 1
    return s

if __name__ == "__main__":
    input = open(sys.argv[1])
    T = int(input.readline())
    for ncase in xrange(1, T + 1):
        a, b, k = map(int, input.readline().split())
        print "Case #%d: %d" % (ncase, solve(a, b, k))

