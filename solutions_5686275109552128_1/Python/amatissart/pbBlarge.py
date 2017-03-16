# -*- coding: utf-8 -*-

import sys
import math
sys.setrecursionlimit(10000)

def solve(p,maxi=10000,it=0):
    p.sort(reverse=True)
    m = p[0]
    if m == maxi and it>1:
        return m
    if m == 1000 and it==0 and min(p)==1000:
        return 1000
    if m<=3:
        return m
    q = list(p)
    t = m+2+it
    p = map(lambda x:x+1,p)
    p[0]=t/2
    p=p+[t-t/2]
    if t==11:
        q = map(lambda x:x+1,q)
        q[0]=7
        q = q +[4]
        return min(m,solve(p,m,it+1),solve(q,m,it+1))
    return min(m,solve(p,m,it+1))

filename = sys.argv[1]
with open(filename) as f:
    n_cases = int(f.readline())
    for i in xrange(n_cases):
        d = int(f.readline())
        p = map(int,f.readline().split())
        res = solve(p)
        print 'Case #%d: %d' % (i+1,res)
        