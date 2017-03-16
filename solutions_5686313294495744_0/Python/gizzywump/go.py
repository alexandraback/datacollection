#!/usr/bin/env python

import collections

import math
import re
import sys

#sys.setrecursionlimit(50)

INPUT = "tiny"
#INPUT = "C-large.in"
INPUT = "C-small-attempt2.in"

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

def do_trial(pairs):
    remaining = set(pairs)
    fakes = set()
    reals = set()
    #import pdb; pdb.set_trace()
    while len(remaining) > 0:
        count = [collections.Counter(p[i] for p in remaining) for i in range(2)]
        debug("count", count)
        uniques = set([p for p in remaining if count[0][p[0]] == 1 or count[1][p[1]] == 1])
        debug("U ", uniques)
        if len(uniques) == 0:
            ll = [(s, (count[0][s[0]], count[1][s[1]])) for s in remaining]
            #import pdb; pdb.set_trace()
            u1 = min(remaining, key=lambda s: (count[0][s[0]], count[1][s[1]]))
            debug(u1)
            uniques.add(u1)
        s_u = [set(p[i] for p in reals.union(uniques)) for i in range(2)]
        for p in remaining:
            if p in uniques:
                continue
            if p[0] in s_u[0] and p[1] in s_u[1]:
                fakes.add(p)
                continue
        reals.update(uniques)
        remaining.difference_update(uniques)
        remaining.difference_update(fakes)
        debug("R ", remaining)
    return len(fakes)

f = file(INPUT)
T = int(f.readline()[:-1])
for i in range(T):
    N = int(f.readline()[:-1])
    pairs = []
    for _ in range(N):
        pairs.append(tuple(f.readline()[:-1].split()))
    v = do_trial(pairs)
    print "Case #%d: %s" % (i+1, v)
