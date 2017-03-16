#!/usr/bin/python

import sys
from math import *
from collections import *


def line():
    return sys.stdin.readline()

def solve(ns):
    s = float(sum(ns))
    eq = 1.0/float(len(ns))

    avg = s*eq
    
    #fs = [(avg - float(n))/s + eq for n in ns]
    fs = [round((2*eq - float(n)/s)*100,7) for n in ns]

    neg = 0.0
    negc = 0
    for i in range(len(fs)):
        if fs[i] < 0:
            neg += fs[i]
            negc += 1

    for i in range(len(fs)):
        if fs[i] < 0:
            fs[i] = 0
        else:
            fs[i] += neg / (len(ns) - negc)

    ss = [str(f) for f in fs]
    return ' '.join(ss)


tc = int(line())
for i in range(1, tc+1):
    
    # read params
    nns = [int(t) for t in line().split()]

    print "Case #%s: %s" % (i, solve(nns[1:]))
