#!/usr/bin/env python

import sys

COUNTEREXAMPLE_FOUND = "RICHARD"
FILL = "GABRIEL"

# Assuming for now 1 <= X, R, C <= 4
# R >= C
def solve(X, R, C):
    if X == 1: return FILL # no hope here
    if X > R: return COUNTEREXAMPLE_FOUND # a (1,X) tile

    if (R * C) % X != 0: return COUNTEREXAMPLE_FOUND # size mismatch, just impossible to fill the board 

    if C == 1:
        if X == 2: return FILL
        if X >= 3: return COUNTEREXAMPLE_FOUND # any 2-D tile is not possible to be played
    if C == 2:
        if X == 2: return FILL
        if X == 3: return FILL
        if X == 4: return COUNTEREXAMPLE_FOUND if R == 4 else "UNKNOWN" # T-shape works as a counterexample for 4x2, need to figure out what happens for R > 4

    # now only computing specific sizes
    if C == 3:
        if R == 3:
            if X == 3: return FILL # both 3-ominos don't make counterexamples
        if R == 4:
            if X == 2: return FILL
            if X == 3: return FILL # both 3-ominos don't make counterexamples
            if X == 4: return FILL # don't know of a counterexample
    if C == 4:
        if R == 4:
            if X == 2: return FILL
            if X == 4: return FILL # don't know of a counterexample
    return "UNKNOWN" # should not be here

case = 0
for ln in open(sys.argv[1], 'r'):
    ln = map(int, ln.strip().split())
    if len(ln) != 3: continue
    case += 1
    X, R, C = ln
    print "Case #%d: %s" % (case, solve(X, max(R, C), min(R, C)))
