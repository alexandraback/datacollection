#!/usr/bin/env python2
# coding: utf-8

from itertools import islice
import sys

def addcost(a, b):
    if a < 2:
        return None

    cost = 0
    while a <= b:
        cost += 1
        a += a - 1

    return (a, cost)

T = int(sys.stdin.readline())

for case in range(1,T+1):
    A, N = map(int, sys.stdin.readline().split())
    sizes = sorted(map(int, sys.stdin.readline().split()))
    dp = [[] for i in range(N+1)]
    dp[0].append((A, 0))
    for i in range(N):
        for pos in dp[i]:
            if pos[0] > sizes[i]:
                dp[i+1].append((pos[0] + sizes[i], pos[1]))
            else:
                dp[i+1].append((pos[0], pos[1]+1)) # remove
                ac = addcost(pos[0], sizes[i])
                if ac is not None:
                    dp[i+1].append((ac[0] + sizes[i], pos[1] + ac[1]))

    ans = None
    for pos in dp[N]:
        if ans is None or ans > pos[1]:
            ans = pos[1]

    print 'Case #%d: %s' % (case, ans)
