#!/usr/bin/python
import sys
import numpy as np     # http://www.numpy.org/
import scipy           # http://scipy.org/
import networkx as nx  # https://networkx.github.io/
import sympy           # http://www.sympy.org
import itertools
import operator
import string

T = int(sys.stdin.readline())

def reverse(x):
    return int(str(x)[::-1])

def generate(N):
    solutions = dict()
    steps = 0
    solutions[1] = 1
    for i in xrange(1,N+1):
        n = i+1
        if n in solutions:
            d = min(solutions[n],solutions[i]+1)
        else:
            d = solutions[i]+1
        solutions[n] = d
        
        r = reverse(i)
        if r>i:
            if r in solutions:
                d = min(solutions[r],solutions[i]+1)
            else:
                d = solutions[i]+1
            solutions[r] = d
    return solutions

g = generate(1000000)
for case in range(0, T):
    N = int(sys.stdin.readline().strip())
#    x = map(int,map(string.strip,sys.stdin.readline().strip()))
    s=g[N]
    print "Case #%i: %s" % (case + 1, s)
    
