#!/usr/bin/env python

import collections

import math
import re
import sys

#sys.setrecursionlimit(50)

INPUT = "tiny"
INPUT = "A-large.in"
#INPUT = "A-small-attempt0.in"

def debug(*args):
    return
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

def do_trial(S):
    c = collections.Counter(S)
    r = [0] * 10
    r[0] = c["Z"]
    r[1] = c["O"] - c["Z"] - c["W"] - c["U"]
    r[2] = c["W"]
    r[3] = c["H"] - c["G"]
    r[4] = c["U"]
    r[5] = c["F"] - c["U"]
    r[6] = c["X"]
    r[7] = c["S"] - c["X"]
    r[8] = c["G"]
    r[9] = c["I"] - r[5] - r[6] - r[8]
    l = []
    for i in range(10):
        l.append(("%d" % i) * r[i])
    return ''.join(l)

f = file(INPUT)
T = int(f.readline()[:-1])
for i in range(T):
    S = f.readline()[:-1]
    v = do_trial(S)
    print "Case #%d: %s" % (i+1, v)
