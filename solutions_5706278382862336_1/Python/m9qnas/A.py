#!/usr/bin/env python
import sys

range = xrange
_g = (i for line in sys.stdin for i in line.split())
n = lambda t=int: t(next(_g))

from fractions import Fraction as F

def result():
    f = F(*map(int,n(str).split('/')))
    if f == 1:
        return 1
    g = 41
    for i in range(1,41):
        f *= 2
        if f.numerator >= f.denominator and i < g:
            g = i
    if f.denominator != 1:
        return 'impossible'
    else:
        return g

T = n()
for t in range(1,T+1):
    print "Case #%d:" % t, result()
