#!/usr/bin/env python

import sys
from heapq import heapify, heappop, heappush

def solve(H):
    heapify(H)
    curBest = -H[0]
    curDelay = 0
    while True:
        #print "curBest:", curBest, "curDelay:", curDelay, "sum: ", -sum(H), map(lambda x: -x, sorted(H))
        m = -heappop(H)
        curBest = min(curBest, m + curDelay)
        if m <= 3: return curBest
        curDelay += 1
        hm = m / 2
        if m % 2 == 0:
            heappush(H, -hm)
            heappush(H, -hm)
        else:
            heappush(H, -hm)
            heappush(H, -(hm+1))

case = 1
inp = open(sys.argv[1], 'r').readlines()
T = int(inp[0])
while case <= T:
    D = map(lambda x: -int(x), inp[case * 2].strip().split())
    print "Case #%d: %d" % (case, solve(D))
    case += 1
