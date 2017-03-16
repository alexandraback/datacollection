#!/usr/bin/python
from __future__ import division,print_function
import sys
import numpy as np     # http://www.numpy.org/
import scipy           # http://scipy.org/
import networkx as nx  # https://networkx.github.io/
import sympy           # http://www.sympy.org
import itertools
import operator
import string

sys.setrecursionlimit(5000)

T = int(sys.stdin.readline())

def solve(K,C):
    solution = ""
    #length = K**C
    #step = length / K
    step  = K**(C-1)
    for s in range(0,K):
        solution += "%s " % (1+step*s)
    return solution.strip()
for t in range(1,T+1):
    K,C,S = map(int,sys.stdin.readline().strip().split())
    print("Case #%i: %s" % (t,solve(K,C)))

