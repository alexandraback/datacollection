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
    
def most_common(L):
    SL = sorted((x, i) for i, x in enumerate(L))
    groups = itertools.groupby(SL, key=operator.itemgetter(0))
    def _auxfun(g):
        item, iterable = g
        count = 0
        min_index = len(L)
        for _, where in iterable:
            count += 1
            min_index = min(min_index, where)
        return count, -min_index
    return max(groups, key=_auxfun)[0]

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
        l.append(getmaxdict(table[num]))
    
    pd = {}
    for c in l:
        pd[c] = 1
        for n in nums:
            if c in table[n]:
                pd[c] *= table[n][c]
            else:
                pd[c] = 0
                
    return combos[getmaxdict(pd)]
    
cases = int(raw_input())
for i in range(cases):
    s = raw_input().split()
    R, N, M, K = int(s[0]), int(s[1]), int(s[2]), int(s[3])
    combos, table = simulate(N, M, K, 1000000)
    print "Case #1:"
    for i in range(R):
        nums = [int(x) for x in raw_input().split()]
        g = guess(combos, table, nums)
        print ''.join(str(z) for z in g)