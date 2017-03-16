T = int(raw_input())

for qq in xrange(1,T+1):
    e,r,n = map(int,raw_input().split(" "))
    v = map(int, raw_input().split(" "))
    dp = [[0]*10 for x in xrange(30)]
    # dp[time][energy] = score
    for time in xrange(n):
        for energy in xrange(e+1):
            for spent in xrange(energy+1):
                new_score = dp[time][energy] + spent * v[time]
                new_energy = min(e, energy - spent + r)
                dp[time+1][new_energy] = max(dp[time+1][new_energy], new_score)
    print "Case #%d: %s"%(qq,max(dp[n]))
