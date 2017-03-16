for t in xrange(input()):
    R,C,W = map(int,raw_input().split())
    print "Case #%d: %d"%(t+1,R*(C/W) + W - (C%W==0))
