#!/usr/local/Cellar/python/2.7.9/Frameworks/Python.framework/Versions/2.7/bin/python2.7

import sys
from decimal import *
import itertools as it
from math import sqrt
from math import floor
from math import ceil
from math import log
from math import log10
import time
import random

def solve(N,D,H,M):
    #print N,D,H,M
    intercepts = []
    slopes = []
    for n in range(N):
        for h in range(H[n]):
            intercepts.append(1.*D[n]/360)
            slopes.append(1./(M[n]+h))
    encounters = 0
    #print zip(slopes,intercepts)
##    for m,b in zip(slopes,intercepts):
##        if deer_slope == m: continue
##        # find number of intersections between
##        # y == dx and y == slope*x + intercept (mod 1)
##        encounters += int(floor(1.*(deer_slope-m)/b))
    m1,b1 = slopes[0],intercepts[0]
    m2,b2 = slopes[1],intercepts[1]
    if slopes[1] > slopes[0]: m1,b1,m2,b2 = m2,b2,m1,b1
    if m1 == m2: return 0
    n = int(1.*floor(m1-m2)/m2)
    k = 0
    intersections = []
    while True:
        t = 1.*(b2-b1)/(m1-m2) + 1.*k/(m1-m2)
        if t <= (1.-b2)/m2:
            intersections.append(t)
            k += 1
        else:
            break
    #print len(intersections)
    if len(intersections) > 1:
        return 1
    else: return 0
        
##    return '{}'.format(encounters)

infile = sys.argv[1]
f = open(infile,'r')
T = int(f.readline().strip())
for t in range(T):
    N = int(f.readline().strip())
    D = []
    H = []
    M = []
    for n in range(N):
        d, h, m = map(int,f.readline().strip().split())
        D.append(d)
        H.append(h)
        M.append(m)
    print 'Case #{}: {}'.format(t+1,solve(N,D,H,M))
f.close()
