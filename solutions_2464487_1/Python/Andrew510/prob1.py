#!/usr/bin/python

import math
import sys

infile = sys.stdin

T = int(infile.readline())
for n in range(T):
    r, t = map(int, infile.readline().split())
    
    b = 2*r - 1
    xx = int(math.sqrt(b*b + 8*t))
    
    sol = (-b + xx) / 4
    
    #XXX
    need = 2*sol*sol + sol*b
    #print need, t
    while need > t:
        sol -= 1
        need = 2*sol*sol + sol*b

    if sol < 0:
        sol = 0
    
    print 'Case #%d: %d' % (n+1, sol)

    
