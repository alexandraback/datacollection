for t in xrange(input()):
    k, c, s = map(int, raw_input().split())
    assert k == s
    print "Case #%d: %s" %(t + 1, ' '.join(map(str, [i + 1 for i in xrange(s)])))
