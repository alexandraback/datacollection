#!/usr/bin/python

import math

def quad(a, b, c):
    x1 = (-b + math.sqrt(b**2 - 4*a*c))/2*a
    x2 = (-b - math.sqrt(b**2 - 4*a*c))/2*a
    return x1, x2
    
def draw_ring_fast(r, t):
    b = 3 + 2*r
    a = 2
    c = 1 + 2*r - t
    
    x1, x2 = quad(a,b,c)
    print x1,x2
    return 0
    
def draw_ring(r, t):
    xt = 2*r + 1
    if xt > t:
        return 0
    return 1 + draw_ring(r+2, t - xt)

cases = int(raw_input())
for i in range(cases):
    s = raw_input().split()
    r, t = int(s[0]), int(s[1])
    rings = draw_ring(r, t)
    print "Case #%d: %d" % (i+1, rings)