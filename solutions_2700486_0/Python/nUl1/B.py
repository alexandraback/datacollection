#!/usr/bin/env python2
# coding: utf-8

from scipy.special import binom
import sys

def level(N):
    size = 1
    outer = 1
    res = 0
    while size < N:
        outer += 4
        size += outer
        res += 1
    return (res, size, outer)

T = int(sys.stdin.readline())

for case in range(1,T+1):
    N, X, Y = map(int, sys.stdin.readline().split())

    lvl, size, outer = level(N)

    ans = 0.0
    if abs((X + Y) / 2) < lvl:
        ans = 1.0 # inside
    elif abs((X + Y) / 2) == lvl:
        if Y == lvl * 2:
            ans = (N == size and 1.0 or 0.0)
        else:
            for i in range(Y + 1, N - (size - outer) + 1):
                ans += (0.5 ** (N - (size - outer))) * binom(N - (size - outer), i)
            for i in range(0, min(N - (size - outer) - (outer + 1) / 2, Y + 1)):
                ans += (0.5 ** (N - (size - outer))) * binom(N - (size - outer), i)

    print 'Case #%d: %s' % (case, ans)
