import sys
sys.stdin = open('sbin.in')
sys.stdout = open('test.out', 'w')
T = input()


def checkmax(dp, k, v):
    if k not in dp or v>dp[k]:
        dp[k] = v
    return dp

def sol():
    e, r, n = map(long, raw_input().split())
    v = map(long, raw_input().split())
    dp = {e: 0}
    now = 0
    for vi in v:
        dp1 = {}
        for (k, v) in dp.items():
            for i in range(k+1):
                dp1 = checkmax(dp1, min(k-i+r, e), v+i*vi)
        dp = dp1
    return max([v for (k, v) in dp.items()])
                

for ca in range(1, T+1):
    res = sol()
    print 'Case #'+str(ca)+':', res
