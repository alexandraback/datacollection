#!/usr/bin/python

from __future__ import print_function
import math

def solveQuadratic(r, t):
    delta = r**2 - r + 0.25 + 2*t
    zero = (0.5 - r + math.sqrt(delta)) / 2
    return zero

def inkUsage(r, n):
    return 2 * n**2 + (2*r - 1) * n

def findMax(r, t, a, b):
    if a == b:
        return a
    midPoint = (a + b + 1) / 2
    if inkUsage(r, midPoint) > t:
        return findMax(r, t, a, midPoint - 1)
    else:
        return findMax(r, t, midPoint, b)

def main():
    T = int(raw_input())
    for caseNum in xrange(1, T+1):
        r, t = map(int, raw_input().split())
        startPoint = int(solveQuadratic(r, t))
        n = findMax(r, t, max(1, startPoint - 100000), startPoint + 100000)
        print("Case #", caseNum, ": ", n, sep='')

if __name__ == '__main__':
    main()
