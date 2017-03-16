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

range = xrange

sys.setrecursionlimit(5000)

def solve(C,J):
    CJ=C+J
    N=(C+J).count("?")
    CJ=CJ.replace('?',"%c")
    solution = (99999999999999999999999999,99999999999999999999999999999)
    for s in itertools.product('0123456789', repeat=N):
        x = (CJ % tuple(s)).replace(" ","")
        x1,x2 = x[0:len(C)],x[len(C):]
        n1,n2 = int(x1),int(x2)
        diff = abs(n1-n2)
        if diff<=solution[0]:
            if diff<solution[0]:
                solution=(diff,n1,n2,x1,x2)
            if diff==solution[0] and n2<solution[2]:
                solution=(diff,n1,n2,x1,x2)
    return "%s %s" % (solution[3],solution[4])

T = int(sys.stdin.readline())
for t in range(1,T+1):
    C,J = sys.stdin.readline().strip().split()
    print("Case #%i: %s" % (t,solve(C,J)))
