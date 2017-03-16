for t in xrange(input()):
    X,R,C = map(int,raw_input().split())
    R,C = sorted((R,C))
    print "Case #%d: %s"%(t+1,["GABRIEL","RICHARD"][
           X>=7
        or R*C%X!=0
        or (R==1 and X>2)
        or (R==2 and X>3)
        or (R==3 and X>5)
        or (R==3 and C==5 and X==5)
        ])
