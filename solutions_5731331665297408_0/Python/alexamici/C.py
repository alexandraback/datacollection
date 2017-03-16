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
    S = [next(infile).strip() for T in range(P[0])]
    I = [map(int, next(infile).split()) for T in range(P[1])]
    #T = next(infile).split()
    return locals()


def setupper(cases):
    #C = {}
    return locals()


def solver(tc, infile=None, N=None, P=None, I=None, T=None, S=None, C={}):
    import collections as co
    #import functools32 as ft
    #import itertools as it
    #import math as ma
    #import networkx as nx
    #import numpy as np
    #import operator as op
    #import random as rn
    #import re
    #import scipy as sp
    import heapq as hq

    N, M = P

    G = co.defaultdict(list)
    for u, v in I:
        G[u - 1].append(v - 1)
        G[v - 1].append(u - 1)

    next = min((s, i) for i, s in enumerate(S))[1]
    Q = [(S[next], [next], frozenset([next]))]
    while len(Q):
        res, way, seen = hq.heappop(Q)
        if len(seen) == len(G):
            break
        if len(way) == 0:
            continue
        cur = way[-1]
        for v in G[cur]:
            if v not in seen:
                hq.heappush(Q, (res + S[v], way + [v], seen | frozenset([v])))
        hq.heappush(Q, (res, way[:-1], seen))

    return 'Case #%s: %s' % (tc, res)


if __name__ == '__main__':
    T = int(next(sys.stdin))
    cases = [reader(tc, sys.stdin) for tc in range(1, T + 1)]
    caches = setupper(cases)
    for case in cases:
        print solver(C=caches, **case)
