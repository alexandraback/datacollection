for t in xrange(input()):
    D = input()
    P = map(int,raw_input().split())
    print "Case #%d: %d"%(t+1,min(n+sum((p-1)/n for p in P) for n in xrange(1,1001)))
