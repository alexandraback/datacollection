#!/usr/bin/python

from itertools import *

def powerset(iterable):
    "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))

def findSubsetEq(stuff):
    sets = powerset(stuff)
    sums = {}
    for set_ in sets:
        s = sum(set_)
        if s in sums:
            return sums[s], set_
        sums[s] = set_
    return None

import sys
N = int(sys.stdin.readline())
for test_case, test_case_str in enumerate(sys.stdin.readlines(), 1):
    input_ = map(int, test_case_str.strip().split())[1:]

    stuff = findSubsetEq(input_)

    print "Case #%d:" % test_case
    if stuff is None:
        print "Impossible"
    else:
        s1,s2 = stuff
        print ' '.join(map(str, s1))
        print ' '.join(map(str, s2))
