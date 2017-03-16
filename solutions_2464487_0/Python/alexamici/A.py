"""Usage:
    X.py < X.in > X.out
"""

def setup(infile):
    #C = {}
    return locals()

def reader(testcase, infile, **ignore):
    #N = int(infile.next())
    P = map(int, infile.next().split())
    #I = map(int, infile.next().split())
    #T = infile.next().split()
    #S = [infile.next().strip() for i in range(N)]
    return locals()

def solver(testcase, N=None, P=None, I=None, T=None, S=None, C=None, **ignore):
    #import collections as co
    #import functools as ft
    #import itertools as it
    #import operator as op
    #import math as ma
    #import re
    #import numpy as np
    #import scipy as sp
    #import networkx as nx
    
    r, t = P


    res = 0
    while t>=2*r+1:
        res += 1
        t -= 2*r +1
        r += 2
    return 'Case #%s: %s\n' % (testcase, res)

if __name__ == '__main__':
    import sys
    T = int(sys.stdin.next())
    common = setup(sys.stdin)
    for t in xrange(1, T+1):
        sys.stdout.write(solver(**reader(t, **common)))
