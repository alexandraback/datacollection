for t in xrange(input()):
    sm = mx = 0
    for s,d in enumerate(raw_input().split()[1]):
        mx = max(mx,s-sm)
        sm+= int(d)
    print "Case #%d: %d"%(t+1,mx)
