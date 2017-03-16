#!/usr/bin/python
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

def solve(N):
    if N==0: return "INSOMNIA"
    digits = set()
    c=0
    while len(digits)<10:
        c+=1
        number=N*c
        digits |= set("%s" % number)
        #~ print(N,digit
    return "%s" % number

for case in range(0, T):
    N = int(sys.stdin.readline().strip())
    solution = solve(N)
    print "Case #%i: %s" % (case + 1, solution)

