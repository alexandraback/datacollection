import sys
sys.setrecursionlimit(10000) 

read_ints = lambda: map(int, raw_input().split())
read_int  = input



for no_t in xrange(1, read_int() + 1):
    e, r, n = read_ints()
    dp = [[0] * (e+1) for _ in xrange(n + 1)]
    v = [0] + read_ints()

    for i in xrange(n):
        for j in xrange(e + 1):
            for x in xrange(j + 1):
                k = min(e, j-x+r)
                dp[i+1][k] = max(dp[i+1][k], dp[i][j] + v[i+1]*x)

    ans = max([x for a in dp for x in a])
    print 'Case #%d: %s' % (no_t, ans)
