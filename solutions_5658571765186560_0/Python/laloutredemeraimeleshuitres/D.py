import bisect

def solve_case(X, R, C):
    if ((R*C) % X) != 0:
        return 'RICHARD'
    if X <= 2:
        return 'GABRIEL'
    if X == (R*C):
        return 'RICHARD'
    if X == 3:
        return 'GABRIEL'
    if (X,R,C) == (4,2,4):
        return 'RICHARD'
    return 'GABRIEL'
    

def parse(f):
    ncase = int(f.readline())
    for i in range(ncase):
        print "Case #%d:"%(i+1),
        X, R, C = map(int, f.readline().split())
        print solve_case(X, min(R, C), max(R, C))

import sys
parse(sys.stdin)

