for cas in xrange(1,1+input()):
    s = raw_input() + '+'
    print "Case #%s: %s" % (cas, sum(c != d for c, d in zip(s, s[1:])))
