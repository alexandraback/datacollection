# -*- coding: utf-8 -*-

import sys
import math

def ratio(m):
    pass

def solve(p):
    p.sort(reverse=True)
    m = p[0]
    if m<=3:
        return m
    q = list(p)
    p[0]=m/2
    p=p+[m-m/2]
    q[0]=m/3
    q=q+[m-m/3]
    return min(m,1+solve(p),1+solve(q))

filename = sys.argv[1]
with open(filename) as f:
    n_cases = int(f.readline())
    for i in xrange(n_cases):
        d = int(f.readline())
        p = map(int,f.readline().split())
        res = solve(p)
        print 'Case #%d: %d' % (i+1,res)
        
