for _t in xrange(int(raw_input())):
    C, F, X = map(float, raw_input().split())

    best = X/2.0
    ant = C/2.0
    n=1
    while True:
        this = ant + X/(2+n*F)
        #print "->", this
        if this>best: break
        best = this
        ant += C/(2+n*F)
        n+= 1

    print "Case #%s: %s"%(_t+1,best)