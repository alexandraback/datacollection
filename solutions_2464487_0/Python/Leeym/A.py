#!/usr/local/bin/python
# Yen-Ming Lee <leeym@leeym.com>
# http://code.google.com/codejam/contest/dashboard?c=2418487#s=p0

import getopt
import math
import os
import re
import string
import sys

opt, arg = getopt.getopt(sys.argv[1:], 'vd')
verbose = False
debug = False
for k, v in opt:
    if k == '-v':
        verbose = True
    if k == '-d':
        debug = True

def paint(x, r):
    return 2 * x * x - x + 2 * x * r

C = int(sys.stdin.readline().rstrip())
for c in range(1, C+1):
    print >> sys.stderr, "Case #%d/%d" % (c, C)
    (R, T) = [int(i) for i in sys.stdin.readline().rstrip().split()]
    if verbose:
        print >> sys.stderr, "\tR:%d T:%d" % (R, T)
    l = 1
    r = T
    m = 1
    while True:
        m = int((l + r) / 2)
        p = paint(m, R)
        q = paint(m + 1, R)
        if verbose:
            print >> sys.stderr, "\tl:%d m:%d r:%d p:%d q:%d t:%d" % (l, m, r, p, q, T)
        if p <= T and q > T:
            break
        if p < T and r < 100:
            l += 1
        elif q >= T:
            r = m - 1
        elif p <= T:
            l = m + 1
    print "Case #%d: %s" % (c, m)
