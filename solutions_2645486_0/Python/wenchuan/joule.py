#!/usr/bin/python

import sys, os

fin = sys.stdin

T = int(fin.readline())

def solve():
    E, R, N = map(int, fin.readline().split())
    v = map(int, fin.readline().split())
    m = max(v)
    s = sum(v)
    return R * s + (E - R) * m

for i in xrange(T):
    x = solve()
    print 'Case #%d: %d' % (i+1, x)
