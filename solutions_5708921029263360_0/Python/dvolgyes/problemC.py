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

def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)

def powerset(iterable):
    s = list(iterable)
    return itertools.chain.from_iterable(itertools.combinations(s, r) for r in range(len(s)+1))

def solve(J,P,S,K):
    jp = dict()
    ps = dict()
    js = dict()
    results = "\n"
    cnt = 0
    for i,j,k in itertools.product( range(1,J+1), range(1,P+1), range(1,S+1) ):
        a= jp.get( (i,j), 0)
        b= ps.get( (j,k), 0)
        c= js.get( (i,k), 0)
        if max(a,b,c) >= K:
            continue
        jp[ (i,j) ] = a+1
        ps[ (j,k) ] = b+1
        js[ (i,k) ] = c+1

        results += "%i %i %i\n" % (i,j,k)
        cnt+=1
    return str(cnt) + results[:-1]



T = int(sys.stdin.readline())
for t in range(1,T+1):
    J,P,S,K = list(map(int,sys.stdin.readline().strip().split()))
    print("Case #%i: %s" % (t,solve(J,P,S,K)))
