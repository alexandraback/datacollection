#!/usr/bin/env python

import sys
from collections import defaultdict
from fractions import Fraction
from math import log, floor

def Solve(P, Q):
    deg = log(Q, 2)
    if 2**int(deg) != Q or deg > 40: return "impossible"
    else: 
        p = floor(log(P, 2))
        return str(int(deg-p))
        

inp = open(sys.argv[1], 'r').readlines()
T = int(inp[0].strip())
for t in range(T):
    P, Q = map(int, inp[t+1].strip().split('/'))
    F = Fraction(P, Q)
    P, Q = F.numerator, F.denominator
    print "Case #"+str(t+1)+": "+Solve(P, Q)

    
