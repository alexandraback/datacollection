#!/usr/bin/env python

import collections

import math
import re
import sys

INPUT = "tiny"
if 1:
    INPUT = "B-small-attempt2.in"

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

def prod(l):
    return l[0] * l[1]

def do_trial(E, R, v_list):
    N = len(v_list)
    min_after = [0] * N
    max_before = [E] * N
    spend = [None] * N
    the_order = sorted(range(N), key=lambda i: -v_list[i])
    debug("v_list", v_list)
    debug("ORDER", the_order)
    for idx in the_order:
        #import pdb; pdb.set_trace()
        spend[idx] = max_before[idx] - min_after[idx]
        idx2 = idx
        mb = min_after[idx]
        while idx2 < N-1:
            idx2 += 1
            mb += R
            if mb > E: break
            max_before[idx2] = min(mb, max_before[idx2])
        ma = spend[idx] + min_after[idx]
        idx2 = idx
        while idx2 > 0:
            idx2 -= 1
            ma -= R
            if ma <= 0: break
            min_after[idx2] = max(ma, min_after[idx2])
        debug("==>", v_list, spend, max_before, min_after)
    debug(spend, v_list)
    return sum(prod(t) for t in zip(spend, v_list))

f = file(INPUT)
T = int(f.readline()[:-1])
for i in range(T):
    E, R, N = [int(x) for x in f.readline().split()]
    v_list = [int(x) for x in f.readline().split()]
    v = do_trial(E, R, v_list)
    print "Case #%d: %s" % (i+1, v)
