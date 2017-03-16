for tc in xrange(input()):
    K, C, S = map(int, raw_input().split())
    pos = []
    for i in xrange(S):
    	pos.append(str(i+1))
    print "Case #%d: %s" % (tc + 1, ' '.join(pos))
