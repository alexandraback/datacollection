#!/usr/bin/env python

import sys, math, decimal
decimal.getcontext().prec = 1000

f = open(sys.argv[1],'r')
T = int(f.readline())
for c in range(1,T+1):
    l = map(int,f.readline().split())
    r = l[0]
    t = l[1]
    D = (2*r-1)*(2*r-1)+8*t
    n = max(0,int((decimal.Decimal(-2*r+1)+decimal.Decimal(D).sqrt())/decimal.Decimal(4)))
    print 'Case #%d: %d' % (c,n)
