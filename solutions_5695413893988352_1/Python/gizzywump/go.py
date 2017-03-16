#!/usr/bin/env python

import collections

import math
import re
import sys

#sys.setrecursionlimit(50)

INPUT = "tiny"
INPUT = "B-large.in"
#INPUT = "B-small-attempt7.in"

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

def does_match(n, s):
    if len(n) != len(s):
        return False
    for a, b in zip(n, s):
        if a != b and b != '?':
            return False
    return True


def do_trial(s1, s2):
    L = len(s1)
    r1 = []
    r2 = []
    r1p = []
    r2p = []
    state = "min_both"
    switch_idx = None
    for idx, (c1, c2) in enumerate(zip(s1, s2)):
        if c1 == c2 and c2 == '?':
            if state == "min_both":
                r1.append("0")
                r2.append("0")
                r1p.append("0")
                r2p.append("0")
                continue
            elif state == 'min_1':
                r1.append("0")
                r2.append("9")
                r1p.append("9")
                r2p.append("0")
                continue
            else:
                r1.append("9")
                r2.append("0")
                r1p.append("0")
                r2p.append("9")
                continue
        if c1 == '?':
            r2.append(c2)
            r2p.append(c2)
            if state == "min_both":
                r1.append(c2)
                r1p.append(c2)
                continue
            elif state == 'min_1':
                r1.append("0")
                r1p.append("9")
                continue
            else:
                r1.append("9")
                r1p.append("0")
                continue
        if c2 == '?':
            r1.append(c1)
            r1p.append(c1)
            if state == "min_both":
                r2.append(c1)
                r2p.append(c1)
                continue
            elif state == 'min_2':
                r2.append("0")
                r2p.append("9")
                continue
            else:
                r2.append("9")
                r2p.append("0")
                continue
        # neither is wild
        r1.append(c1)
        r1p.append(c1)
        r2.append(c2)
        r2p.append(c2)
        # change state
        if c1 == c2 or state != "min_both":
            continue
        #import pdb; pdb.set_trace()
        if idx > 0:
            switch_idx = idx - 1
        if c1 > c2:
            state = "min_1"
            continue
        state = "min_2"
    t1 = int(''.join(r1))
    t2 = int(''.join(r2))
    t1p = int(''.join(r1p))
    t2p = int(''.join(r2p))
    fs = "%%0%dd" % L
    #import pdb; pdb.set_trace()
    min_diff = 1e80
    add_factor = 0
    if switch_idx is not None:
        ll = ['0'] * L
        ll[switch_idx] = '1'
        add_factor = int(''.join(ll))

    for v1 in sorted([t1-add_factor, t1, t1+add_factor, t1p-add_factor, t1p, t1p+add_factor]):
        if v1 < 0:
            continue
        if not does_match(fs % v1, s1):
            continue
        for v2 in sorted([t2-add_factor, t2, t2+add_factor, t2p-add_factor, t2p, t2p+add_factor]):
            if v2 < 0:
                continue
            if not does_match(fs % v2, s2):
                continue
            if abs(v1-v2) < min_diff:
                bv1, bv2 = v1, v2
                min_diff = abs(v1-v2)
    return ("%s %s" % (fs, fs)) % (bv1, bv2)

f = file(INPUT)
T = int(f.readline()[:-1])
for i in range(T):
    s1, s2 = f.readline().split()
    v = do_trial(s1, s2)
    v1 = do_trial(s2, s1)
    if ' '.join(reversed(v1.split())) != v:
        print s1, s2, v, v1
        import pdb; pdb.set_trace()
        print "OOPS"
    print "Case #%d: %s" % (i+1, v)
