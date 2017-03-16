#!/usr/bin/env python

from collections import defaultdict
from itertools import product

TEST="""5
7 6 6
BANANAS
MONKEY
2 3 4
AA
AAA
2 1 2
AB
B
6 2 2
GOOGLE
GO
26 11 100
ABCDEFGHIJKLMNOPQRSTUVWXYZ
ROSENCRANTZ"""
#raw_input = iter(TEST.splitlines()).next


def solve(keys, K, S, target, L):
    if not set(target).issubset( set(keys) ):
        # Impossible target
        return 0.0
    kc = defaultdict(float)
    for k in keys:
        kc[k] += 1.0
 
    tp = 1.0
    for l in target:
        tp *= kc[l] / K
    if tp == 1.0:
        # No variance.
        return 0.0
        
    # brute the small?
    all_words = [''.join(i) for i in product(keys, repeat=S)]
    mtc = 0
    EXP = 0.0
    for word in all_words:
        tc = 0
        for ix in range(0, S-L+1):
            if word[ix:ix+L] == target:
                tc += 1
        EXP += float(tc) / (K**S)
        mtc = max(tc, mtc)

    WORST = mtc
    return WORST-EXP


T = int(raw_input())
for case in range(1,T+1):
    K, L, S = map(int, raw_input().strip().split())
    keys = raw_input().strip()
    target = raw_input().strip()
    assert(len(keys) == K)
    assert(len(target) == L)
    print("Case #%s: %s" % (case, solve(keys, K, S, target, L)))
