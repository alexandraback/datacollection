#!/usr/bin/env python

import decimal

def calc(r, t):
    a = 2
    b = 2 * r - 1
    c = -t
    x = (-b + (b * b - 4 * a * c).sqrt()) / (2 * a)
    return int(x)

T = input()
for i in xrange(T):
    r, t = [decimal.Decimal(s) for s in raw_input().split()]
    print 'Case #%d: %s' % (i + 1, calc(r, t))
