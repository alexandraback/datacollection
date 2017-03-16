from random import randint

dp = [1005000 for i in range(10 ** 6 + 123)]

def solve(cnt=False, nn=1):
    if cnt:

        n = nn
        dp[1] = 1
        for i in range(1, n):
            ri = int(str(i)[::-1])
            if i < ri <= n:
                dp[ri] = min(dp[ri], dp[i] + 1)
            dp[i + 1] = min(dp[i + 1], dp[i] + 1)
    else:
        n = int(input())



    return dp[n]

solve(True, 10**6 + 1)
for t in range(1, int(input()) + 1):
    print('Case #%d: %d' % (t, solve()))
