#!/usr/bin/env python

import sys

yes = "YES"
no = "NO"

def solve(heights):
    N = len(heights)
    M = len(heights[0])
    for y in xrange(N):
        for x in xrange(M):
            possible = True
            for y1 in xrange(N):
                if heights[y1][x] > heights[y][x]:
                    possible = False
            if possible:
                continue
            possible = True
            for x1 in xrange(M):
                if heights[y][x1] > heights[y][x]:
                    possible = False
            if possible:
                continue
            return no
    return yes

def readInts():
    return [ int(s) for s in sys.stdin.readline().split() ]

T = int(sys.stdin.readline())
for t in xrange(T):
    inputs = readInts()
    N = inputs[0]
    heights = []
    for i in xrange(N):
        heights.append(readInts())
    res = solve(heights)
    print "Case #%d: %s" % (t + 1, res)
