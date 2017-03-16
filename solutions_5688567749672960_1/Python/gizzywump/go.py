#!/usr/bin/env python

import collections

import math
import re
import sys

#sys.setrecursionlimit(50)

INPUT = "tiny"
#INPUT = "A-small-attempt0.in"
INPUT = "A-large.in"


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

def calc_distance():
    MAX = int(1e4) + 2
    m = [MAX] * int(MAX)
    m[0] = 0
    for idx, v in enumerate(m[:-1]):
        m[idx+1] = min(m[idx+1], m[idx] + 1)
        # reverse it
        rm = int(''.join(reversed(str(idx))))
        m[rm] = min(m[rm], m[idx] + 1)
    return m

CD = calc_distance()

def count_down(N, so_far=0):
    if N == 10:
        import pdb; pdb.set_trace()
    while 1:
        s = str(N)
        if len(s) == 1:
            return so_far + N
        rN = int(''.join(reversed(s)))
        ur = 0
        half_s = len(s) // 2
        lh = s[-half_s:]
        s1 = '0' * (half_s-1) + '1'
        if lh == s1 and N != rN:
            ur = 1
        if ur:
            N = int(''.join(reversed(s)))
            so_far += 1
        else:
            diff = int(s[-half_s:]) - int(s1)
            if diff <= 0:
                diff = 1
            N -= diff
            so_far += diff

def check():
    for i in range(int(1e6)):
        if i == 11111:
            import pdb; pdb.set_trace()
        debug(i, count_down(i), CD[i])
        assert count_down(i) == CD[i]

#check()

def do_trial(N):
    return count_down(N)

f = file(INPUT)
T = int(f.readline()[:-1])
for i in range(T):
    N = int(f.readline()[:-1])
    v = do_trial(N)
    print "Case #%d: %s" % (i+1, v)
