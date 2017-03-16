#!/usr/bin/python

import sys
import re
import math
import string
import scipy.stats

f = open(sys.argv[1],'r')
num = int(f.readline())

def layer(N):
    if N == 0:
        return (0,0)
    if N == 1:
        return (1,0)
    lmx = N
    lmn = 0
    while lmn+1 < lmx:
        l = (lmn+lmx)/2
        if 2*l*l + 3*l + 1 <= N:
            lmn = l
        else:
            lmx = l
    return (lmn+1, N - (2*lmn*lmn + 3*lmn + 1))

def dist(l, y):
    ns = l[0] * 2
    nfix = max(0, l[1]-ns)
    #print y, nfix
    if y < nfix:
        return 1.0
    #print y, l[1]
    return 1-scipy.stats.binom.cdf(y,l[1],0.5)


for i in xrange(num):
    l = f.readline()
    N, x, y = [int(z) for z in l.split()]
    #print N, x, y
    l = layer(N)
    lxy = (abs(x) + abs(y))/2+1
    #print l, lxy
    if lxy <= l[0]:
        print 'Case #{}:'.format(i+1), 1.0
    elif lxy > l[0]+1 or x == 0:
        print 'Case #{}:'.format(i+1), 0.0
    else:
        print 'Case #{}:'.format(i+1), dist(l, y)
