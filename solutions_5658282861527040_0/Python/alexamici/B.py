"""Usage:
    pypy -u X.py < X-test.in > X-test.out
or sometimes
    python -u X.py < X-test.in > X-test.out
"""

import os
import sys
#sys.setrecursionlimit(20000)


def reader(tc, infile):
    #N = int(next(infile))
    P = map(int, next(infile).split())
    #I = [map(int, next(infile).split()) for i in range(N)]
    #T = next(infile).split()
    #S = [next(infile).strip() for i in range(N)]
    return locals()


def setupper(cases):
    #C = {}
    return locals()


def solver(tc, infile=None, N=None, P=None, I=None, T=None, S=None, C={}):
    #import collections as co
    #import functools32 as ft
    #import itertools as it
    #import math as ma
    #import networkx as nx
    #import numpy as np
    #import operator as op
    #import random as rn
    #import re
    #import scipy as sp

    A, B, K = P

    res = 0
    for i in range(A):
        res += sum(i & j < K for j in range(B))
    return 'Case #%s: %s' % (tc, res)


if __name__ == '__main__':
    T = int(next(sys.stdin))
    cases = [reader(tc, sys.stdin) for tc in range(1, T + 1)]
    caches = setupper(cases)
    for case in cases:
        print solver(C=caches, **case)
