#!/usr/bin/env python
# -*- coding: utf-8 -*-

T = int(input())
f = lambda x:int(''.join(reversed(str(x))))
for case in range(T):
    N = int(input())
    dp = [10**9 for i in range(10**6+2)]
    dp[1] = 1
    for i in range(1,N+1):
        dp[i + 1] = min(dp[i + 1],dp[i] + 1)
        dp[f(i)] = min(dp[f(i)],dp[i]+1)
    print("Case #{0}: {1}".format(case+1,dp[N]))



