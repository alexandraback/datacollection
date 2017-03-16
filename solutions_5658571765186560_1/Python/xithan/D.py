#!/usr/local/bin/python3
# Codejam ID 6224486
# Run with parameter
# -s for small input
# -l for large input

from GCJ import GCJ


def parse(infile):
    X, R, C = GCJ.readints(infile)
    return X, R, C

def solve(data):
    X,R,C = data

    if (R*C)%X != 0:
      return 'RICHARD'
    if max(R,C) < X:
      return 'RICHARD'
    if min(R,C) >= X:
      return 'GABRIEL'
    if X >= 7:
      return 'RICHARD'
    # one side is at least X long
    if min(R,C)*2+1 <= X: # there is a piece that always overlaps
      return 'RICHARD'
    if min(R,C)*2-1 > X: # it's not possible to isolate an area
      return 'GABRIEL'

    if X <= 3:
      return 'GABRIEL'
    if min(R,C)*2==X:
      return 'RICHARD'
    return 'GABRIEL'


GCJ('D', solve, parse, None).run()

