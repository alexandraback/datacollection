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

def solve(s):
    t = s+"+"
    i=0
    cnt = 0
    while i<len(s):
        cnt += 1 if (t[i]!=t[i+1]) else 0
        i+=1
    return cnt

T = int(sys.stdin.readline())
for t in range(1,T+1):
    s = sys.stdin.readline().strip()
    print("Case #%i: %s" % (t,solve(s)))
