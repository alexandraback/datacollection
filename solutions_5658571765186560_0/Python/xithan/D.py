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
    if R < X and C < X:
      return 'RICHARD'
    if R >= X and C >= X:
      return 'GABRIEL'
    if X >= 7:
      return 'RICHARD'
    if min(R,C)*2+1 <= X: # there is a piece that always overlaps
      return 'RICHARD'
    if min(R,C)*2-1 > X: # it's not possible to isolate an area
      return 'GABRIEL'

    if X <= 3:
      return 'GABRIEL'
    if min(R,C)*2==max(R,C):
      return 'RICHARD'
    return 'GABRIEL'


GCJ('D', solve, parse, None).run()

