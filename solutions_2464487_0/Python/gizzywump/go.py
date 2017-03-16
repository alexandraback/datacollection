#!/usr/bin/env python

import collections

import math
import re
import sys

INPUT = "tiny"
if 1:
    INPUT = "A-small-attempt0.in"

def debug(*args):
    pass #print str(args)

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

def f_x(R, r, t):
    return 2*R*R + (2*r-1) * R - t

def do_trial(r, t):
    guess = int((1-2*r+math.sqrt(4*r*r-4*r+1+8*t))/4.0 + 2)
    while 1:
        if f_x(guess, r, t) <= 0:
            return guess
        guess -= 1

f = file(INPUT)
T = int(f.readline()[:-1])
for i in range(T):
    r, t = [int(x) for x in f.readline().split()]
    v = do_trial(r, t)
    print "Case #%d: %s" % (i+1, v)
