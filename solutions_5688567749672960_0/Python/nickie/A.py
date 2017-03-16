#!/usr/bin/env python3

def solve(N):
    dp = [0] + [None]*N
    for i in range(1, N+1):
        if dp[i] == None:
            dp[i] = 1+dp[i-1]
        else:
            dp[i] = min(dp[i], 1+dp[i-1])
        r = int(str(i)[::-1])
        if r <= N:
            if dp[r] == None:
                dp[r] = 1+dp[i]
            else:
                assert(dp[r] <= 1+dp[i])
    return dp

tests = int(input())
dp = solve(1000000)
for test in range(tests):
    N = int(input())
    result = dp[N]
    print("Case #{}: {}".format(1+test, result))
