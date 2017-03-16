cases = int(raw_input())
for c in xrange(cases):
    J,P,S,K = map(int, raw_input().split())
    res = []
    # avail_PS = []
    # for p in xrange(P):
    #     for s in xrange(S):
    #         avail_PS.append([p,s,K])
    for j in xrange(J):
        for p in xrange(P):
            for s in xrange(min(S,K)):
                res.append((j+1,p+1,(j+s+p)%S+1))

    print "Case #%d: %d" % (c+1,len(res))
    for i in res:
        print "%d %d %d" % (i[0],i[1],i[2])
