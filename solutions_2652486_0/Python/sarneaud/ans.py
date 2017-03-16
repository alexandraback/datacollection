#!/usr/bin/env python
from sys import stdin, stdout
from itertools import *
from functools import reduce
from operator import mul
from collections import defaultdict

def answer(data):
    candidates = reduce(merge, [pre_tbl[v] for v in data])
    ans = select(candidates)
    return ''.join(map(str, ans))

def cases(s):
    while 1:
        v = map(int, next(s).rstrip().split())
        yield v

def mkdi():
    return defaultdict(int)

pre_tbl = defaultdict(mkdi)
nrange = range(2,5+1)
pops = product(nrange, nrange, nrange)
for p in pops:
    k = tuple(sorted(p))
    for msk in xrange(8):
        i = 0
        sample = []
        while msk:
            if msk & 1:
                sample.append(p[i])
            msk >>= 1
            i += 1
        v = reduce(mul, sample, 1)

        pre_tbl[v][k] += 1

def select(cand):
    ret = (2,2,2)
    best = 0

    for k,v in cand.items():
        if v >= best:
            ret = k

    return ret

def merge(d1, d2):
    ret = {}

    for k,v in d1.items():
        if k in d2:
            ret[k] = min(v, d2[k])

    return ret

stdin.next()
stdin.next()

print "Case #1:"
for n,c in enumerate(cases(stdin)):
    print answer(c)
