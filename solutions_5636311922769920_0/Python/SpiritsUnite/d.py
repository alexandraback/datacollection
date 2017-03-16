T = int(raw_input())
for C in xrange(1, T+1):
    k, c, s = map(int, raw_input().strip().split())
    print "Case #%d: %s" % (C, ' '.join(map(str, xrange(1, s+1))))
