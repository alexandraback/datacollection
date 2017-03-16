__author__ = 'David'

import sys

T = int(sys.stdin.readline())

for N in xrange(T):
    stack = sys.stdin.readline().strip()

    last = '+'
    flips = 0
    for p in reversed(stack):
        if p != last:
            flips += 1
        last = p

    print "Case #%d: %d" % (N + 1, flips)
