#!/usr/bin/env python

import fileinput, collections, sys, operator, itertools

def autodict():
    return collections.defaultdict(autodict)

def input():
    it = iter(itertools.imap(str.rstrip, fileinput.input()))
    it.next()
    while True:
        line = it.next().rstrip()
        yield map(int, line.split()[1:])

def possible(fracs, level):
    total = 0
    for frac in fracs:
        if level > frac:
            total += level - frac
    return total <= 1

def binsearch(fracs):
    min = 0.; max=2.
    while max - min > 1e-8:
        mid = (max+min)/2.
        if possible(fracs,mid):
            min=mid
        else:
            max=mid
    return min

def main():
    for casenum, nums in enumerate(input()):
        total = 0.+sum(nums)
        fracs = [num / total for num in nums]
        #print fracs
        level = binsearch(fracs)
        #print level

        res = [100 * max(0, level - frac) for frac in fracs]
        res = ["%0.6f" % x for x in res]
        print "Case #%d: %s" % (casenum+1, ' '.join(res))

main()
