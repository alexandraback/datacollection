def rev(n):
    return int(str(n)[::-1])

def solve(dp):
    for n in xrange(2, 1000005):
        dp[n] = dp[n - 1] + 1
        tmp = rev(n)
        if rev(tmp) == n and tmp < n:
            dp[n] = min(dp[n], dp[tmp] + 1)


T = int(raw_input())
dp = [None] * 1000005
dp[0], dp[1] = 0, 1
ans = solve(dp)
for cs in  xrange(1, T + 1):
    n = int(raw_input())
    ans = dp[n]
    print 'Case #{}: {}'.format(cs, ans)
