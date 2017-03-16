#!/usr/bin/python

import math

def quad(a, b, c):
    x1 = (-b + math.sqrt(b**2 - 4*a*c))/2*a
    x2 = (-b - math.sqrt(b**2 - 4*a*c))/2*a
    return x1, x2

def f(n, r):
    return 2*n*n + (2*r -1)*n
    
def draw_ring_fast(r, t, left, right):
    m = (left + right) / 2
    
    t1 = f(m, r)
    t2 = f(m+1, r)
    
    if t1 <= t <= t2:
        return m
    elif t1 < t:
        return draw_ring_fast(r, t, m + 1, right)
    else:
        return draw_ring_fast(r, t, left, m - 1)
    
def draw_ring(r, t):
    xt = 2*r + 1
    if xt > t:
        return 0
    return 1 + draw_ring(r+2, t - xt)

cases = int(raw_input())
for i in range(cases):
    s = raw_input().split()
    r, t = int(s[0]), int(s[1])
    rings = draw_ring_fast(r, t, 0, t)
    print "Case #%d: %d" % (i+1, rings)