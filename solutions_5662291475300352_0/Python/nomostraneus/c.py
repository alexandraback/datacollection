#!/usr/bin/env python
# -*- coding: utf-8 -*-
import math
import numpy as np
import sys
import copy
import itertools as it
import re
import collections

def rint():
    return map(int, raw_input().split())

def rstr():
    return raw_input().split()

def rlist(*lfn):
    return  [f(a) for (f, a) in zip(lfn, raw_input().split())]

if __name__ == "__main__":
    testcases = input()
     
    for caseNr in xrange(testcases):
        [N] = rint()
        L = []
        R = []
        for n in xrange(N):
            U = rint()
            L += [U]
            for h in xrange(U[1]):
                R += [(U[0], U[2] + h)]

        T = 0
#        print R
        if len(R) == 1:
            T = 0
        if len(R) == 2:
            t0 = (1 - R[0][0]/360.0) * float(R[0][1])
            t1 = (1 - R[1][0]/360.0) * float(R[1][1])
#            print t0, t1
            T = (0 if max(t0, t1) < min(t0 + R[0][1], t1 + R[1][1]) else 1)

        print("Case #%i: %i" % (caseNr + 1, T))
#        print("Case #%i:" % (caseNr + 1))
