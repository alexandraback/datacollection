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
    #S = [infile.next().strip() for i in range(N)]
    return locals()

def solver(testcase, N=None, P=None, I=None, T=None, S=None, C=None, **ignore):
    #import collections as co
    #import functools as ft
    #import itertools as it
    #import operator as op
    #import math as ma
    #import re
    import numpypy as np
    #import scipy as sp
    #import networkx as nx
    

    e, R, N = P
    I = np.array(I)
    E = np.array([0]*len(I))
    E[0] = e

    nexts = reversed(I.argsort())
    res = 0
    for current in nexts:
        e_next = R
        for nex in xrange(current+1, len(E)):
            ediff = R*(nex-current-1)
            if ediff>=e:
                break
            if E[nex] > 0:
                e_next = max(R, E[nex] - ediff)
                break

        if current+1 < len(E) and E[current+1] == 0:
            E[current+1] = e_next

        if E[current] == 0:
            for prev in xrange(current-1, -1, -1):
                ediff = R*(current-prev)
                if E[prev] > 0 or ediff >= e:
                    E[current] = min(e, E[prev] + ediff)
                    break

        res += (E[current]+R-e_next) * I[current]

    return 'Case #%s: %s\n' % (testcase, res)

if __name__ == '__main__':
    import sys
    T = int(sys.stdin.next())
    common = setup(sys.stdin)
    for t in xrange(1, T+1):
        sys.stdout.write(solver(**reader(t, **common)))
