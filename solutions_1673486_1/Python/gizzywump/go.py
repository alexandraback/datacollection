#!/usr/bin/env python

import re
import sys

INPUT = "tiny"
if 1:
    INPUT = "A-large.in"

def log(*args):
    pass

def zlog(*args):
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

def exp_return(A, B, probs):
    e = 1 + B + 1
    log("exp_return", e)
    return e

def exp_typing(backspace_count, A, B, probs):
    chars_left_pretyped = A - backspace_count
    prob_all_correct = reduce(lambda x,y: x*y, probs[:chars_left_pretyped], 1.0)
    log("backspace_count", backspace_count, "chars_left_pretyped", chars_left_pretyped, "prob_all_correct", prob_all_correct)
    # probability the backspacing fixed everything is prob_all_correct
    typed = (1 + backspace_count + backspace_count + B - A)
    exp1 = prob_all_correct * typed
    log(typed, "typed", prob_all_correct, exp1)
    # backspacing did NOT fix everything
    typed = (1 + backspace_count + backspace_count + B - A + B + 1)
    exp2 = (1.0-prob_all_correct) * typed
    log(typed, "typed", (1.0-prob_all_correct), exp2)
    e = exp1 + exp2
    log("exp_typing", backspace_count, e)
    return e

def do_trial(A, B, probs):
    e = min(exp_return(A, B, probs), *[exp_typing(x, A, B, probs) for x in range(A+1)])
    return e

f = file(INPUT)
T = int(f.readline()[:-1])
for i in range(T):
    A, B = (int(x) for x in f.readline()[:-1].split())
    probs = [float(x) for x in f.readline()[:-1].split()]
    v = do_trial(A, B, probs)
    sys.stderr.write("%d\n" % i)
    print "Case #%d: %s" % (i+1, v)
