"""Usage:
    pypy X.py < X-size.in > X-size.out
or sometimes
    python X.py < X-size.in > X-size.out
"""

def setup(infile):
    #C = {}
    return locals()

def reader(testcase, infile, C=None, **ignore):
    #N = int(infile.next())
    #P = map(int, infile.next().split())
    #I = map(int, infile.next().split())
    T = infile.next().split()
    #S = [infile.next().strip() for i in range(N)]
    return locals()

def solver(testcase, N=None, P=None, I=None, T=None, S=None, C=None, **ignore):
    #import collections as co
    #import functools32 as ft
    #import itertools as it
    #import operator as op
    #import math as ma
    #import re
    #import numpypy as np
    #import scipy as sp
    #import networkx as nx

    name, n = T[0], int(T[1])

    N = []
    c = 0
    for i, l in enumerate(name):
        if l not in 'aeiou':
            c += 1
            if c >= n:
                N.append(i)
        else:
            c = 0
    res = 0
    for i in range(len(name)):
        for j in range(i+n-1, len(name)):
            for k in range(i+n-1,j+1):
                if k in N:
                    res += 1
                    break
    return 'Case #%s: %s\n' % (testcase, res)

if __name__ == '__main__':
    import sys
    T = int(sys.stdin.next())
    common = setup(sys.stdin)
    for t in xrange(1, T+1):
        sys.stdout.write(solver(**reader(t, **common)))
