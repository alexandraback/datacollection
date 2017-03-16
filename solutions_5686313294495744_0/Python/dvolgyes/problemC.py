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

from itertools import chain, combinations

def powerset(iterable):
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))

sys.setrecursionlimit(5000)

def check(uniques,full):
    d1,d2 = set(),set()
    d = set(uniques)
    for u in uniques:
        d1.add(u[0])
        d2.add(u[1])

    for s in full:
        if s in d: continue
        if (s[0] in d1) and (s[1] in d2): continue
        return 0
    return len(full)-len(uniques)

def solve(strings):
    n = 0
    for uniques in powerset(strings):
        n = max(n,check(uniques,strings))
    return n

T = int(sys.stdin.readline())
for t in range(1,T+1):
    N = int(sys.stdin.readline())
    strings=list()
    for i in range(N):
        S1,S2 = sys.stdin.readline().strip().split()
        strings.append( (S1,S2) )
    print("Case #%i: %s" % (t,solve(strings)))
