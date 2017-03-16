#!/usr/bin/env python
# encoding: utf-8

from collections import defaultdict
from itertools import chain, combinations

def powerset_generator(group):
    for subset in chain.from_iterable(combinations(group, r) for r in range(len(group)+1)):
        yield set(subset)

T = int(raw_input())
for i in xrange(1, T+1):
    C, D, V = map(int, raw_input().split())
    denoms = map(int, raw_input().split())
    desirable_denoms = set(denoms)
    min_denom = 0
    all_possible = set()
    for comb in powerset_generator(denoms):
        if len(comb) == 0:
            continue
        sumup = sum(comb)
        if sumup <= V:
            all_possible.add(sumup)
    desirable = set(range(1, V+1))
    # print desirable
    # print all_possible
    diff = desirable  - all_possible
    # print diff
    while len(diff) != 0:
        new_denom = min(diff)
        new_all_possible = set()
        for pos in all_possible:
            sumup = pos + new_denom
            if sumup <= V:
                new_all_possible.add(sumup)
        # print "for new denom: "+str(new_denom)
        new_all_possible.add(new_denom)
        # print new_all_possible
        all_possible = all_possible.union(new_all_possible)
        # print all_possible
        min_denom += 1
        diff = desirable - all_possible
        # print diff
    # print
    print "Case #" + str(i) + ": " + str(min_denom)
