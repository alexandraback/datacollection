#!/usr/bin/python2 -u
# -*- coding: utf-8 -*-
#
import sys, math, re
from fractions import Fraction

### ----- Variables
LINES = []

### ----- Functions
def pop_line():
    global LINES
    if len(LINES) == 0:
        return None
    line = LINES[0]
    LINES = LINES[1:]
    return line

def check_if_power2(n):
    while n > 1:
        if n % 2 != 0:
            return False
        n = n / 2
    return True

### ----- Program Main
LINES = [line.rstrip() for line in sys.stdin]

T = int(pop_line())
for t in range(T):

    (P,Q) = map(int, pop_line().split('/'))
    pq = Fraction(P, Q)

    if not check_if_power2(pq.denominator):
        print 'Case #%d: %s' % (t+1, 'impossible')
        continue

    p = pq.numerator
    q = pq.denominator

    count = 0
    while p < q:
        p *= 2
        count += 1

    #print count

    #exit()
    print 'Case #%d: %d' % (t+1, count)
