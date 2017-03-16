#!/usr/bin/env python

import sys, math

f = open(sys.argv[1],'r')
T = int(f.readline())
for c in range(1,T+1):
    l = map(int,f.readline().split())
    r = l[0]
    t = l[1]
    D = (2*r-1)*(2*r-1)+8*t
    #print math.sqrt(D)
    n = max(0,int(math.floor((-2*r+1+math.sqrt(D))/4.0)))
    print 'Case #%d: %d' % (c,n)
