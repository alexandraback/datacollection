#!/usr/bin/python

import sys
import re
import math
import string
import gmpy

f = open(sys.argv[1],'r')
num = int(f.readline())

def layer(N):
    if N == 0:
        return (0,0)
    if N >= 1+5+9:
        return (3,N-15)
    if N >= 1+5:
        return (2,N-6)
    return (1,N-1)

def dist(l, y):
    ns = l[0] * 2
    nfix = max(0, l[1]-ns)
    #print y, nfix
    if y < nfix:
        return 1.0
    s = 0
    for i in xrange(y+1):
        s += gmpy.comb(l[1], i)
    #print y, s
    return 1-float(s)/2**l[1]


for i in xrange(num):
    l = f.readline()
    N, x, y = [int(z) for z in l.split()]
    l = layer(N)
    lxy = (abs(x) + abs(y))/2+1
    #print N, x, y
    #print l, lxy
    if lxy <= l[0]:
        print 'Case #{}:'.format(i+1), 1.0
    elif lxy > l[0]+1 or x == 0:
        print 'Case #{}:'.format(i+1), 0.0
    else:
        print 'Case #{}:'.format(i+1), dist(l, y)
