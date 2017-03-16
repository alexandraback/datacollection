for case in xrange(input()):
    k,c,s = map(int, raw_input().split())
    print "Case #%d: %s" % (case + 1, ' '.join(str(1+i) for i in xrange(k)))
