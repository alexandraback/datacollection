for tc in xrange(input()):
    K, C, S = map(int, raw_input().split())
    req = max(K-C+1,1)
    if S < req:
    	print "Case #%d: IMPOSSIBLE" % (tc + 1)
    	continue
    pos = []
    C2 = min(C,K)
    blk = max(C2-2,0)
    for i in xrange(req):
    	pos.append(str(blk*K+C2+i))
    print "Case #%d: %s" % (tc + 1, ' '.join(pos))
