#!/usr/bin/env python

import fileinput, collections, sys, operator, itertools

def autodict():
    return collections.defaultdict(autodict)

def input():
    it = iter(itertools.imap(str.rstrip, fileinput.input()))
    it.next()
    while True:
        yield map(int, it.next().rstrip().split())

def main():
    for casenum, ints in enumerate(input()):
        (n, numSurprising, p) = ints[:3]
        totals = ints[3:]

        us = s = 0
        for total in totals:
            if (total+2)/3 >= p:
                us += 1
            elif 2 <= total <= 28 and (total+4)/3 >= p:
                s += 1
        res = us + min(s, numSurprising)

        print "Case #%d: %d" % (casenum+1, res)

main()
