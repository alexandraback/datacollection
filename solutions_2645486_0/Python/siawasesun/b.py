#!/usr/bin/env python

import sys
import math

def solve(E, R, N, V):
    dp = []
    for i in range(100):
        tmp = []
        for i in range(100):
            tmp.append(0)
        dp.append(tmp)

    for i in range(N):
        for rest in range(E + 1):
            for use in range(rest + 1):
                nextE = min(E, rest - use + R)
                dp[i + 1][nextE] = max(dp[i + 1][nextE], dp[i][rest] + V[i] * use)

    res = 0
    for i in range(E+1):
        res = max(res, dp[N][i])
    return res

test_cases = int(sys.stdin.readline())
for t in range(test_cases):
    E, R, N = [int(c) for c in sys.stdin.readline().split(" ")]
    V = [int(c) for c in sys.stdin.readline().split(" ")]
    assert(N == len(V))
    print "Case #%d: %d" % (t + 1, solve(E, R, N, V))
