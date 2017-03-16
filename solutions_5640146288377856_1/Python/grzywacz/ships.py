#!/usr/bin/env python

import sys

def solve(r, c, w):
    if c == w:
        return w + (r - 1)
    else:
        hits_per_row = c / w
        prior_row_hits = (r - 1) * hits_per_row
        if hits_per_row * w < c:
            last_row_hits = hits_per_row - 1 + (w + 1)
        else:
            last_row_hits = hits_per_row - 1 + w

        return prior_row_hits + last_row_hits

infile = open(sys.argv[1])
t = infile.readline()

for x, line in enumerate(infile):
    r, c, w = [int(i) for i in line.strip().split()]
    solution = solve(r, c, w)
    print "Case #{case}: {solution}".format(
        case=x + 1,
        solution=solution
    )
