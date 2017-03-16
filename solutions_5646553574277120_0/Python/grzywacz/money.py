#!/usr/bin/env python

import sys
import itertools


def solve(c, d, v, denominations):
    if c > 1:
        return None

    added = 0

    needed_numbers = set(range(1, v + 1))

    while needed_numbers:
        for d in denominations:
            needed_numbers.discard(d)
            if not needed_numbers:
                return added
        for x in xrange(1, len(denominations) + 1):
            for p in itertools.permutations(denominations, x):
                needed_numbers.discard(sum(p))
            if not needed_numbers:
                return added
        added += 1
        denominations.append(min(needed_numbers))
        denominations.sort() 

infile = open(sys.argv[1])
t = int(infile.readline())

for x in xrange(t):
    c, d, v = [int(i) for i in infile.readline().strip().split()]
    denominations = [int(i) for i in infile.readline().strip().split()]
    solution = solve(c, d, v, denominations)
    print "Case #{case}: {solution}".format(
        case=x + 1,
        solution=solution
    )
