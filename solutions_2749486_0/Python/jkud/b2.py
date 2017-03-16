#!/usr/bin/env python

import sys

def solve(tx, ty):
    x = 0
    y = 0
    m = ''
    while tx != x:
        if tx > x:
            m += 'WE'
            x += 1
        else:
            m += 'EW'
            x -= 1
    while ty != y:
        if ty > y:
            m += 'SN'
            y += 1
        else:
            m += 'NS'
            y -= 1
    assert len(m) <= 500
    return m

T = int(raw_input())
for t in range(T):
    print >> sys.stderr, t
    x, y = [int(i) for i in raw_input().split()]
    print "Case #%d: %s" % (t+1, solve(x, y))
