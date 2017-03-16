#!/usr/bin/python

import sys
import functools
import operator
import bisect

def solve(armin, mots):
    while (mots and armin > mots[0]):
        armin += mots.pop(0)

    if not mots:
        return 0

    minmot = mots[0]
    k = 1
    newarmin = armin + armin - 1
    while (newarmin <= minmot):
        k += 1
        newarmin += newarmin - 1
    
    remaining = len(mots)
    blow = solve(newarmin, mots)

    return min(k + blow, remaining)
    
    

def main():
    N = int(sys.stdin.readline()) # number of testcases
    for i in range(N):
        [armin, nummots] = [int(x) for x in sys.stdin.readline().rstrip().split()]
        mots = [int(x) for x in sys.stdin.readline().rstrip().split()]
        if armin == 1:
            result = len(mots)
        else:
            mots.sort()
            result = solve(armin, mots)
        print ("Case #%s: %s" % (i+1, result))


if __name__ == '__main__':
    main()
