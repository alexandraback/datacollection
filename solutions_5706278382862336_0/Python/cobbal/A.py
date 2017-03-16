#!/usr/bin/python

from fractions import Fraction
import math

def isPowerOfTwo(n):
    b = 1
    while b <= n:
        if b == n:
            return True
        b *= 2
    return False

def solve(f):
    x = 2 ** 40 * f
    if f < 0 or f > 1 or not x == int(x):
        return 'impossible'
    x = int(x)
    for g in range(40, 0, -1):
        if x == 0:
            return 'impossible'
        if x == 1:
            return g
        x //= 2
    return 0

T = int(raw_input())
for i in range(T):
    print "Case #%i: %s" % (i+1, solve(Fraction(raw_input())))
