#!/usr/bin/env python

import collections

import math
import re
import sys

INPUT = "tiny"
if 1:
    INPUT = "C-small-1-attempt1.in"

def debug(*args):
    #print str(args)
    pass

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

def gcf(a, b):
    while 1:
        a, b = min(a,b), max(a,b)
        if a == 0:
            return b
        b %= a

def lcm(a, b):
    return a * b / gcf(a,b)

def lcm_m(args):
    return reduce(lcm, args, 1)

def trial(N, M, K, the_set):
    #import pdb; pdb.set_trace()
    factors = []
    lcm_v = lcm_m(the_set)
    while lcm_v % 5 == 0:
        factors.append(5)
        lcm_v /= 5
    while lcm_v % 3 == 0:
        factors.append(3)
        lcm_v /= 3
    if lcm_v == 16:
        factors.append(4)
        factors.append(4)
    elif lcm_v == 8:
        return "\n222"
    elif lcm_v == 4:
        factors.append(4)
    elif lcm_v == 2:
        factors.append(2)
    while len(factors) < 3:
        factors.append(2)
    return "\n" + ''.join(str(f) for f in factors[:3])

def do_trial(N, M, K, sets):
    v = [trial(N, M, K, s) for s in sets]
    return ''.join(v)

f = file(INPUT)
T = int(f.readline()[:-1])
for i in range(T):
    R, N, M, K = [int(x) for x in f.readline().split()]
    sets = []
    for j in range(R):
        sets.append([int(x) for x in f.readline().split()])
    v = do_trial(N, M, K, sets)
    print "Case #%d: %s" % (i+1, v)
