#!/usr/bin/python
import math

testcases = int(raw_input())

def isqrt(x):
    if x < 0:
        raise ValueError('square root not defined for negative numbers')
    n = int(x)
    if n == 0:
        return 0
    a, b = divmod(n.bit_length(), 2)
    x = 2**(a+b)
    while True:
        y = (x + n//x)//2
        if y >= x:
            return x
        x = y

for case in xrange(1,testcases+1):
    r,t = raw_input().split()
    r = int(r)
    t = int(t)
    sol = (isqrt((2*r-1)*(2*r-1)+8*t) - (2*r-1)) / 4
    print "Case #%d: %d" % (case,sol)
