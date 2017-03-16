#!/usr/bin/python

import sys
from math import *
from collections import *


def line():
    return sys.stdin.readline()


def solve(ns):
    sums = [0 for i in range(1<<20)]
    for i in range(1<<20):
        for c in range(20):
            if i & (1 << c):
                sums[i] += ns[c]

    ss = list(enumerate(sums))
    ss.sort(key=lambda (x,y): y)

    left, right = [], []
    for i in range((1 << 20) - 1):
        if ss[i][1] == ss[i+1][1]:
            for c in range(20):
                if ss[i][0] & (1 << c):
                    left.append(ns[c])
            for c in range(20):
                if ss[i+1][0] & (1 << c):
                    right.append(ns[c])

            
            print ' '.join([str(i) for i in left])
            print ' '.join([str(i) for i in right])
            return

    print "Impossible"



tc = int(line())
for i in range(1, tc+1):
    
    # read params

    ns = [int(t) for t in line().split()][1:]
    print "Case #%s:" % i
    solve(ns)
