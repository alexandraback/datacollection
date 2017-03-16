#!/usr/bin/env python

import itertools

d = {}

def calc(e, ee, r, n, i, v):
    dd = d.get((ee, i))
    if dd is not None:
        return dd
    if i == n:
        return 0
    return max([
        x * v[i] + calc(e, min(e, ee - x + r), r, n, i + 1, v)
        for x in xrange(ee + 1)
    ])

T = input()
for i in xrange(T):
    e, r, n = [int(s) for s in raw_input().split()]
    v = [int(s) for s in raw_input().split()]
    d.clear()
    print 'Case #%d: %s' % (i + 1, calc(e, e, r, n, 0, v))
