if __name__ == "__main__":
    casenum = input()
    for caseidx in xrange(1, casenum + 1):
        input()
        d = map(int, raw_input().split())
        maxans = max(d)
        dp = [[0], None]
        f = 0
        t = 1
        for di in d:
            dp[t] = []
            for use in xrange(0, di):
                for used in xrange(0, len(dp[f])):
                    if use + used > maxans:
                        break
                    if use + used >= len(dp[t]):
                        dp[t].append(max(dp[f][used], (di - 1) / (use + 1) + 1))
                    else:
                        dp[t][use + used] = min(dp[t][use + used], max(dp[f][used], (di - 1) / (use + 1) + 1))
            f, t = t, f
        ans = dp[f][0]
        for i in xrange(1, len(dp[f])):
            ans = min(ans, i + dp[f][i])
        print "Case #%d: %d" % (caseidx, ans)
