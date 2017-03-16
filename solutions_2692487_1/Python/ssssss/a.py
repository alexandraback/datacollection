#!/usr/bin/python3

import math
import sys

def steps(a, b):
    return r

def case():
    A, N = [int(x) for x in sys.stdin.readline().split()]
    M = [int(x) for x in sys.stdin.readline().split()]
    M = sorted(M)
    cost = 0
    mincost = N
    left = N
    if A == 1: return mincost
    for i in M:
        while A <= i:
            A += A -1
            cost += 1
        A += i
        left -= 1
        if mincost > cost + left:
            mincost = cost + left
    return mincost


T = int(sys.stdin.readline())
for i in range(1,T+1):
    print("Case #%s: %s" % (i, case()))
    

