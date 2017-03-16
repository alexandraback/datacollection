#!/usr/bin/python

import sys;
import os.path; 

def readi():
    return int(sys.stdin.readline().strip());

def readia():
    return [int(x) for x in sys.stdin.readline().strip().split()];

def readfa():
    return [float(x) for x in sys.stdin.readline().strip().split()];

RICHARD = False;
GABRIEL = True;

#bestMinSide = [0, 1, 1, 2, 2];

def mysqrt(n):
    for i in range(n+1):
        if i*i >= n:
            return i;
    return 0;

def solve(X, R, C):
    if R > C:
        tmp = R;
        R = C;
        C = tmp;

    if R*C % X != 0:
        return RICHARD; # cant't put whole number

    if X > C:
        return RICHARD; # 1*X
    
    bestMinSide = (X + 1) // 2; # min side of a corner of X cells
    if bestMinSide > R:
        return RICHARD;

    #if X == 4 and R == 2 and C == 4:
    #    return RICHARD;

    if bestMinSide >= 2 and bestMinSide == R and X >= 4:
        return RICHARD;

    return GABRIEL;

def main():
    nt = readi();
    for t in range(1, nt+1):
        (X, R, C) = readia();

        res = solve(X, R, C)
        print "Case #%d: %s" % (t, "GABRIEL" if res else "RICHARD");
    

main();
