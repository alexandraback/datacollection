# -*- coding: utf-8 -*-

import sys

N = int(sys.stdin.readline())

for n in range(1, N+1):
    E, R, N = map(int, sys.stdin.readline().split())
    activities = map(int, sys.stdin.readline().split())

    dp = []
    for i in range(N):
        dp.append([0] * (E + 1))
        
    for e in range(E, -1, -1):
        dp[0][e] = activities[0] * (E - e)

    for a in range(1, len(activities)):
        for e in range(E, -1, -1):
            left_idx = e - R
            if left_idx < 0:
                left_idx = 0
            left = dp[a - 1][left_idx]
            top = dp[a][e + 1] if e < E else 0
            dp[a][e] = max(left, top + activities[a])

    ans = dp[N - 1][0]
    print 'Case #%(n)s: %(ans)s' % locals()
