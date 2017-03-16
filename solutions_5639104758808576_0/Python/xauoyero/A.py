#!/usr/bin/env python
# 2.x

# O(T*(sMax + 1)) ~ O(100*6) or O(100*1000)

#[1, 100]
T = int(raw_input())
for t in xrange(1, T + 1):
    #small [0, 6] large [0, 1000]
    data = raw_input().split()
    sMax = int(data[0])
    #number of audience members with si in [0, i - 1]
    #prev[0] = 0 always since si >= 0, and stand up and clap immediately
    #prev[1] = prev[0] + cnt[0] = cnt[0] is safe
    prev = [0 for x in xrange(sMax + 1 + 1)]
    #ans in [0, sMax]
    ans = 0
    #do not check data[1][sMax], count the members with si < sMax
    for si in xrange(sMax):
        #count s = si
        prev[si + 1] = int(data[1][si])
        #count s < si
        prev[si + 1] += prev[si]
        #at least si + 1
        need = si + 1 - prev[si + 1]
        if need > 0:
            ans = max(ans, need)
    print("Case #%s: %s"%(t, ans))
