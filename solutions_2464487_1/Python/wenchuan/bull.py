#!/usr/bin/python

import sys, os
import math

fin = sys.stdin

T = int(fin.readline())

def solve(r,t):
    dd = (2 * r - 1) * (2 * r - 1) + 8 * t
    cmd = 'echo "sqrt(%d)" | bc' % dd
    d = long(os.popen(cmd).read())
    return (d - 2 * r + 1) / 4

for i in xrange(T):
    r,t = map(int, fin.readline().split())
    x = solve(r,t)
    print 'Case #%d: %d' % (i+1, x)
