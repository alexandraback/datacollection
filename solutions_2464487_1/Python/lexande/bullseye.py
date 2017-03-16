#!/usr/bin/env python
import math
import sys

def paintneeded(r, rings):
    return 2*rings*rings + (2*r - 1)*rings
  

def paintable(r, q):
    return int(((1 - 2*r) + math.sqrt((2*r - 1)*(2*r - 1) + 8*q))/4)

cases = int(sys.stdin.readline())
for i in range(0,cases):
    (r, t) = sys.stdin.readline().split(" ")
    r = int(r)
    t = int(t)
    p = paintable(r, t)
    while (paintneeded(r, p) > t):
        p = p - 1
    print "Case #%i: %i" % (i+1, p)
