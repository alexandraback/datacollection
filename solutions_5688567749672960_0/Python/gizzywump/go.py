#!/usr/bin/env python

import collections

import math
import re
import sys

#sys.setrecursionlimit(50)

INPUT = "tiny"
INPUT = "A-small-attempt0.in"

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

def calc_distance():
    MAX = int(1e6) + 2
    m = [MAX] * int(MAX)
    m[0] = 0
    for idx, v in enumerate(m[:-1]):
        m[idx+1] = min(m[idx+1], m[idx] + 1)
        # reverse it
        rm = int(''.join(reversed(str(idx))))
        m[rm] = min(m[rm], m[idx] + 1)
    return m

CD = calc_distance()

def do_trial(N):
    return CD[N]

f = file(INPUT)
T = int(f.readline()[:-1])
for i in range(T):
    N = int(f.readline()[:-1])
    v = do_trial(N)
    print "Case #%d: %s" % (i+1, v)
