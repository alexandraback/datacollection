#!/usr/bin/env python

from fractions import Fraction

def solve(P, Q):
    if 2**40 % Q != 0:
        return 'impossible'
    cnt = 0
    while (P < Q):
        cnt += 1
        P *= 2
    return cnt


T = int(raw_input().strip())
for t in range(T):
    ratio = Fraction(raw_input().strip())
    P, Q = ratio.numerator, ratio.denominator
    print 'Case #%d: %s' % (t+1, solve(P, Q))
