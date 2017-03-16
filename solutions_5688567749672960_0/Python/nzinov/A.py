inf = 1000000000
dp = [inf for i in range(1000001)]
dp[1] = 1
for i in range(2, 1000001):
    op = int(str(i)[::-1])
    dp[i] = dp[i-1] + 1
    if op < i and int(str(op)[::-1]) == i:
        dp[i] = min(dp[i], dp[op] + 1)
t = int(input())
for case in range(t):
    b = int(input())
    print("Case #{}: {}".format(case + 1, dp[b]))
