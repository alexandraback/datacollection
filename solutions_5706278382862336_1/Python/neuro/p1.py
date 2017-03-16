#!/usr/bin/env python
# -*- coding: utf-8 -*-

from fractions import Fraction
from math import log
T = int(raw_input())

def isp2(n):
    return n!=0 and ((n&(n-1)) == 0)

def maxp2lesseq(n):
    if n == 1:
        return 0
    else:
        return 1+maxp2lesseq(n/2)

for case in xrange(1,T+1):

    p,q = map(int,raw_input().split('/'))
    res = 0

    print "Case #%d:" % case,

    f = Fraction(p,q)
    p,q = f.numerator, f.denominator

    if not isp2(q):
        print "impossible"
        continue

    m = maxp2lesseq(p)

    res = int(log(q/2**m,2))
    print res


