#!/usr/bin/python

from itertools import *
from collections import *
from math import *

def memo(f):
    tab = {}
    def g(arg):
        if arg not in tab:
            tab[arg] = f(arg)
        #print arg, "=>", tab[arg]
        return tab[arg]
    return g

@memo
def special(po):
    p = list(po)
    x = p.pop()
    v = []
    for s1 in range(1, x // 2 + 1):
        p2 = p + [s1, x - s1]
        p2.sort()
        v.append(p2)
    return v

def solve(P):
    P.sort()
    work = defaultdict(int)
    for p in P:
        for w in range(1, p):
            splits = int(ceil(float(p) / w))
            work[w] += splits - 1
        work[p] += 0
    #print P, work
    return min(a + b for (a, b) in work.items())

T = int(raw_input())
for i in range(T):
    raw_input()
    P = map(int, raw_input().split())
    print "Case #%i: %s" % (i+1, solve(P))
