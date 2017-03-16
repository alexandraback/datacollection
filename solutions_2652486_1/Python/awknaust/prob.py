#!/usr/bin/python

import math, random
from operator import mul
from itertools import combinations_with_replacement
import itertools
import operator

def randselect(l):
    l2 = []
    for x in l:
        if random.uniform(0.0, 1.0) > 0.5:
            l2.append(x)
    return l2


def simulate(N, M, K, simulations):
    combos = list(combinations_with_replacement(range(2, M+1), N))
    table = {}
    for i in range(len(combos)):
        for j in range(simulations):
            p = reduce(mul, randselect(combos[i]), 1)
            if p not in table:
                table[p] = {}
            if i not in table[p]:
                table[p][i] = 1
            else:
                table[p][i] += 1
    return combos, table

def getmaxdict(d):
    mk = -1
    for k, v in d.iteritems():
        if mk == -1:
            mk = k
        if v > d[mk]:
            mk = k
    return mk
    
def guess(combos, table, nums):
    l = []
    for num in nums:
        try:
            l.append(getmaxdict(table[num]))
        except KeyError:
            pass
    try:
        pd = {}
        for c in l:
            pd[c] = 1
            for n in nums:
                if c in table[n]:
                    pd[c] *= table[n][c]
                else:
                    pd[c] = 0
    except:
        pass
                
    return combos[getmaxdict(pd)]
    
cases = int(raw_input())
for i in range(cases):
    s = raw_input().split()
    R, N, M, K = int(s[0]), int(s[1]), int(s[2]), int(s[3])
    combos, table = simulate(N, M, K, 100)
    print "Case #1:"
    for i in range(R):
        nums = [int(x) for x in raw_input().split()]
        g = guess(combos, table, nums)
        print ''.join(str(z) for z in g)