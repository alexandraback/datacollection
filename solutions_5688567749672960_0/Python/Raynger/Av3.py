def rev(N):
    J = int(str(N)[::-1])
    return J

N = 10 ** 6
dp = [None] * (N + 1)
dp[0] = 0
for i in range(1, N+1):
    ri = rev(i)    
    if dp[i] == None:
        dp[i] = dp[i-1] + 1
        if ri <= N and ri > i:
            dp[ri] = dp[i] + 1
    else:
        dp[i] = min(dp[i], dp[i-1] + 1)
        
print('done')


for c in range(int(input())):
    n = int(input())
    print("Case #{}: {}".format(c+1, dp[n]))
    