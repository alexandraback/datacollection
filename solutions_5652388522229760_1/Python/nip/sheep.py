#! /usr/bin/env python

from sys import stdin
import sys

ntest = input()

for test in xrange(ntest):
    N = input()
    if (N):
        seen = set()
        cur = 0
        while len(seen) < 10:
            cur += N
            seen.update(str(cur))
        print "Case #{}: {}".format(test + 1, cur)
    else:
        print "Case #{}: INSOMNIA".format(test + 1)
