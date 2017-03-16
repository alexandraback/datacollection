#!/usr/bin/env python
# -*- coding: utf-8 -*-

import collections

import math
import re
import sys

#sys.setrecursionlimit(50)

INPUT = "tiny"
INPUT = "C-small-attempt0.in"
INPUT = "C-large.in"

def debug(*args):
    #return
    sys.stderr.write(str(args) + "\n")

class Memoize:
    def __init__(self,function):
        self._cache = {}
        self._callable = function
            
    def __call__(self, *args, **kwds):
        cache = self._cache
        key = self._getKey(*args,**kwds)
        try: return cache[key]
        except KeyError:
            cachedValue = cache[key] = self._callable(*args,**kwds)
            return cachedValue
    
    def _getKey(self,*args,**kwds):
        return kwds and (args, ImmutableDict(kwds)) or args    

#            0     1    2     3    4     5    6     7
Q_LOOKUP = ["1", "-1", "i", "-i", "j", "-j", "k", "-k"]
Q_LOOKUP_REV = dict((q, idx) for idx, q in enumerate(Q_LOOKUP))


def m(a, b):
    M_LOOKUP = [
            [0, 1, 2, 3, 4, 5, 6, 7], # 1
            [1, 0, 3, 2, 5, 4, 7, 6], # -1
            [2, 3, 1, 0, 6, 7, 5, 4], # i
            [3, 2, 0, 1, 7, 6, 4, 5], # -i
            [4, 5, 7, 6, 1, 0, 2, 3], # j
            [5, 4, 6, 7, 0, 1, 3, 2], # -j
            [6, 7, 4, 5, 3, 2, 1, 0], # k
            [7, 6, 5, 4, 2, 3, 0, 1], # -k
    ]
    return M_LOOKUP[a][b]


def dump():
    for a in range(8):
        for b in range(8):
            debug("%s x %s = %s" % (Q_LOOKUP[a], Q_LOOKUP[b], Q_LOOKUP[m(a, b)]))

dump()

def check_associtivity():
    for a in range(8):
        for b in range(8):
            for c in range(8):
                debug(" ".join(Q_LOOKUP[x] for x in (a, b, c)))
                assert m(a, m(b, c)) == m(m(a, b), c)
    debug("all checked")

check_associtivity()


def do_trial(X, line):
    # check that the total product is -1
    if X > 12:
        X %= 12
        X += 12
    debug(X, line)
    vals = [Q_LOOKUP_REV[x] for x in line]
    prod = 0
    for v in vals:
        prod = m(prod, v)
    t = 0
    for idx in range(X):
        t = m(t, prod)
    debug("%s ^ %d = %s" % (line, X, Q_LOOKUP[t]))
    if t != 1:
        debug("can't make ijk as final product is not -1")
        return "NO"

    all_vals = vals * X
    p = 0
    # look for i
    for i_idx, v in enumerate(all_vals):
        p = m(p, v)
        if p == 2:
            break
    else:
        debug("can't make i")
        return "NO"

    i_idx += 1

    p = 0
    for k_idx, v in enumerate(reversed(all_vals)):
        p = m(v, p)
        if p == 6:
            break
    else:
        debug("can't make k")
        return "NO"
    k_idx += 1
    k_idx = len(all_vals) - k_idx
    if i_idx >= k_idx:
        return "NO"
    debug("i = %s" % " . ".join(Q_LOOKUP[v] for v in all_vals[:i_idx]))
    debug("j = %s" % " . ".join(Q_LOOKUP[v] for v in all_vals[i_idx:k_idx]))
    debug("k = %s" % " . ".join(Q_LOOKUP[v] for v in all_vals[k_idx:]))
    p = 0
    for v in all_vals[i_idx:k_idx]:
        p = m(p, v)
    assert p == 4
    return "YES"

f = file(INPUT)
T = int(f.readline()[:-1])
for i in range(T):
    L, X = [int(x) for x in f.readline().split()]
    line = f.readline()[:-1]
    v = do_trial(X, line)
    print "Case #%d: %s" % (i+1, v)
