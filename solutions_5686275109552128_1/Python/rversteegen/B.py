#!/usr/bin/python

import sys
import math
import numpy as np
import time

def readline():
    return sys.stdin.readline().strip().split()

def readints():
    return [int(x) for x in readline()]


tstart = time.clock()

T, = readints()
for testcase in range(T):
    D, = readints()
    P = readints()
    P_max = max(P)

    P = np.array(P)
    best = P_max

    for maxstack in range(1, P_max + 1):
        maxstack = float(maxstack)
        # print "MAX", maxstack
        cost = maxstack
        # for Pi in P:
        #     # splits needed
        #     splits = math.ceil(Pi / maxstack) - 1
        #     cost += splits
        #     #int(math.ceil(float(Pi)/(splits+1)))
        #     # print Pi, splits, int(math.ceil(float(Pi)/(splits+1)))

        cost += (np.ceil(P / maxstack) - 1).sum()

        best = min(cost, best)
        # print "cost", cost

    print "Case #%d: %d" % (testcase + 1, best)
    

#print "done in ",  time.clock() - tstart
