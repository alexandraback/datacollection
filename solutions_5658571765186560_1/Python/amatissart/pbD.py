# -*- coding: utf-8 -*-

import sys
import math

def solve(x,r,c):
    if x >= 7 :
        return 'RICHARD'
    elif (r*c) % x != 0:
        return 'RICHARD'
    elif max(r,c) < x:
        return 'RICHARD'
    elif min(r,c) < int(math.ceil(x/2)):
        return 'RICHARD'
    elif min(r,c) == 2 and x>=4:
        return 'RICHARD'
    else:
        return 'GABRIEL'


filename = sys.argv[1]
with open(filename) as f:
    n_cases = int(f.readline())
    for i in xrange(n_cases):
        x,r,c = tuple(map(int,f.readline().split()))
        res = solve(x,r,c)
        print 'Case #%d: %s' % (i+1,res)
        
