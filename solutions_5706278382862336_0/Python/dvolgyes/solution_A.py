#!/usr/bin/python2.7

#
# Google Code Jam 2014: Round 1C, Problem A
#

import numpy as np
import sys, time, os, math, random, scipy, sympy
import fractions
#from fractions import Fraction

def solve(P,Q):
    G=fractions.gcd(P,Q)
    P=P/G
    Q=Q/G
    generation = int(math.log(Q, 2))
    if Q!= 2**generation or generation>40: return "impossible"
    if P>=Q/2: return 1
    return solve(P,Q/2)+1

CASES=int(sys.stdin.readline())
for CASE in range(1,CASES+1):
    solution = None
    P,Q=map(int,sys.stdin.readline().strip().split("/"))
    solution = solve(P,Q)
    print "Case #%i: %s" % (CASE,solution)
