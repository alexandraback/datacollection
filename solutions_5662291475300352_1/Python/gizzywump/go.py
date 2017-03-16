#!/usr/bin/env python

import collections
import fractions

import math
import re
import sys

#sys.setrecursionlimit(50)

INPUT = "tiny"
#INPUT = "C-large.in"
INPUT = "C-small-2-attempt0.in"

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

def do_trial(groups):
    trips = []
    for (D, H, M) in groups:
        for _ in range(H):
            trips.append((D, M+_))
    if len(trips) == 1:
        return 0
    times = []
    for pos, minutes in trips:
        time_once = fractions.Fraction(360 - pos, 360) * minutes
        time_twice = time_once + minutes
        times.append((time_once, time_twice))
    debug(times)
    best_time_twice = min(t[-1] for t in times)
    # deer time = best_time_twice
    count = 0
    for t in times:
        if t[0] >= best_time_twice:
            count += 1
    return count
    worst_time_once = max(t[0] for t in times)
    debug(worst_time_once, best_time_twice)
    if worst_time_once >= best_time_twice:
        return 1
    return 0
    # let's get the fast hiker to catch up with the slow
    

f = file(INPUT)
T = int(f.readline()[:-1])
for i in range(T):
    N, = [int(x) for x in f.readline().split()]
    groups = []
    for _ in range(N):
        D, H, M = [int(x) for x in f.readline().split()]
        groups.append((D, H, M))
    v = do_trial(groups)
    print "Case #%d: %s" % (i+1, v)
