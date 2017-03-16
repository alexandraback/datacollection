"""Usage:
    X.py < X.in > X.out
"""

def setup(infile):
    #C = {}
    return locals()

def reader(testcase, infile, **ignore):
    #N = int(infile.next())
    P = map(int, infile.next().split())
    I = map(int, infile.next().split())
    #T = infile.next().split()
    #S = [map(int, infile.next().split()) for i in range(1)]
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
    
    A, N = P
    I.sort()

    for i in I[:]:
        if i < A:
            A += i
            I.pop(0)
        else:
            break

    if A == 1:
        return 'Case #%s: %s\n' % (testcase, len(I))

    res = [len(I)]
    while len(I):
        A = 2 * A - 1
        for i in I[:]:
            if i < A:
                A += i
                I.pop(0)
            else:
                break
        res.append(len(I))
    
    resr = len(res) - 1
    for i, r in enumerate(res):
        if r < len(res)-1-i:
            resr = i+r
            break

    return 'Case #%s: %s\n' % (testcase, resr)

if __name__ == '__main__':
    import sys
    T = int(sys.stdin.next())
    common = setup(sys.stdin)
    for t in xrange(1, T+1):
        sys.stdout.write(solver(**reader(t, **common)))
