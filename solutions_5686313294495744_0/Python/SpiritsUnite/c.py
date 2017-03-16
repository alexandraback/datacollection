T = int(raw_input())
for C in xrange(1, T+1):
    n = int(raw_input())
    topics = []
    ts = set()
    for i in xrange(n):
        topics += [raw_input().split()]
        ts.add(tuple(topics[i]))
    assert(len(topics) == len(ts))
    ans = 0
    #print ts
    for i in xrange(1<<n):
        s = set()
        t = set()
        for j in xrange(n):
            if not (i & (1<<j)):
                s.add(topics[j][0])
                t.add(topics[j][1])
        good = True
        for j in xrange(n):
            if i & (1<<j) and (topics[j][0] not in s or topics[j][1] not in t):
                good = False
                break
        if good:
            #print bin(i)
            ans = max(ans, bin(i).count('1'))
    print "Case #%d: %d" % (C, ans)
