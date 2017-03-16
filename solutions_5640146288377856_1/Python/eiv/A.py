#!/usr/bin/env python

import sys

def solve(R, C, W):
    score = R*(C / W) + W - 1 + (1 if C % W != 0 else 0)
    return score

case = 0
for ln in open(sys.argv[1], 'r'):
    ln = ln.strip().split()
    if len(ln) != 3: continue
    case += 1
    R, C, W = map(int, ln)
    print "Case #%d: %d" % (case, solve(R, C, W))
