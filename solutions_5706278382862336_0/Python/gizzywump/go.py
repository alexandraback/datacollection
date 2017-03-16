#!/usr/bin/env python

import collections

import math
import re
import sys

INPUT = "tiny"
INPUT = "A-small-attempt0.in"
#INPUT = "A-large.in"

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


def gcf(a, b):
    while 1:
        if a > b:
            a, b = b, a
        if a in (0, b):
            return b
        b %= a


def do_trial(P, Q):
    g = gcf(P, Q)
    P /= g
    Q /= g
    if (1 << (Q.bit_length()-1)) != Q:
        return "impossible"
    gen = 0
    while 1:
        if P >= Q:
            return gen
        gen += 1
        P += P

f = file(INPUT)
T = int(f.readline()[:-1])
for i in range(T):
    P, Q = (int(x) for x in f.readline().split("/"))
    v = do_trial(P, Q)
    print "Case #%d: %s" % (i+1, v)
