#!/usr/bin/env python

import re
import sys

INPUT = "tiny"
if 1:
    INPUT = "B-small-attempt2.in"

def log(*args):
    sys.stderr.write(str(args) + "\n")

def zlog(*args):
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

def do_trial(levels, pairs):
    pairs.sort(key=lambda x:-x[1])
    log('-'*80)
    for p in pairs:
        log(p)
    level_state = [0] * levels
    stars = 0
    rounds = 0
    while 1:
        stars = sum(level_state)
        log(stars, "stars")
        if stars >= 2 * levels: break
        for i,p in enumerate(pairs):
            if level_state[i] == 2: continue
            if p[1] <= stars:
                log("getting 2 stars in round", i)
                rounds += 1
                level_state[i] = 2
                break
        else:
            for i,p in enumerate(pairs):
                if level_state[i] >= 1: continue
                if p[0] <= stars:
                    log("getting 1 star in round", i)
                    rounds +=1
                    level_state[i] = 1
                    break
            else:
                return "Too Bad"
    return rounds

f = file(INPUT)
T = int(f.readline()[:-1])
for i in range(T):
    levels = int(f.readline()[:-1])
    pairs = []
    for j in range(levels):
        pairs.append([int(x) for x in f.readline()[:-1].split()])
    v = do_trial(levels, pairs)
    print "Case #%d: %s" % (i+1, v)
