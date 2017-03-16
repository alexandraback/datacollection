T = int(raw_input())
for case in xrange(1, T + 1):
    C, D, V = map(int, raw_input().split())
    coin = map(int, raw_input().split())
    dp = [0] * (V + 1)
    for i in xrange(C):
        for c in coin:
            for j in xrange(V - c, -1, -1):
                if dp[j]: dp[j + c] = 1
            dp[c] = 1

    ans = 0
    for i in xrange(1,V + 1):
        if dp[i] == 0:
            for j in xrange(V - i, -1, -1):
                if dp[j]: dp[j + i] = 1
            dp[i] = 1
            ans += 1

    print "Case #%d: %d" % (case, ans)
