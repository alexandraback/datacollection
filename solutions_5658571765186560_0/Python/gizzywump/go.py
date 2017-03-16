#!/usr/bin/env python

import collections

import math
import re
import sys

#sys.setrecursionlimit(50)

INPUT = "tiny"
INPUT = "D-small-attempt1.in"

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

RICH = "RICHARD"
GABE = "GABRIEL"

def do_trial(X, R, C):
    # WLOG, let R <= C
    debug("X = %d, R, C = %d, %d" % (X, R, C))
    R, C = min(R, C), max(R, C)
    if R * C % X != 0:
        debug("size %d x %d is not a multiple of %d" % (R, C, X))
        return RICH
    if X >= 7:
        # for 7-ominos or higher, Richard always wins by creating a hole
        # .xx
        # x.x
        # xxx
        debug("X > 7")
        return RICH
    if X in (1, 2):
        # X = 1: easy
        # X = 2: you can always tile a chessboard
        debug("X in (1, 2)")
        return GABE
    if X == 3:
        if R <= 1:
            # choose .x
            #        xx  which is too wide
            return RICH
        return GABE
    if X == 4:
        if R <= 1:
            # rows is 1, R wins as we can pick the T piece
            return RICH
        if R == 2:
            # choose xx.
            #        .xx
            # and then there are an odd number to the right of wherever it's placed
            return RICH
        if R >= 4:
            return GABE
        # so R == 3
        # this means C >= 3
        # C = 3 means % 4 != 0 so this is handled
        # C = 4
        # 4 x 4 is always solvable
        return GABE

    # X = 5
    if X == 5:
        if R <= 2:
            # choose x..
            #        xx.
            #        .xx
            return RICH
        if R >= 5:
            return GABE
        # cases:
        # R = 3 or 4
        if R == 3:
            if C == 5:
                # choose
                #    x..
                #    xx.
                #    .xx
                return RICH
            # for C == 10, 15 or 20, GABE wins
            return GABE
        # R = 4
        if R == 4:
            return GABE
    # X = 6
    if X == 6:
        pass



f = file(INPUT)
T = int(f.readline()[:-1])
for i in range(T):
    X, R, C= [int(x) for x in f.readline().split()]
    v = do_trial(X, R, C)
    print "Case #%d: %s" % (i+1, v)
