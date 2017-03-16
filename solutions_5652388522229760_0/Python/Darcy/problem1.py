for tc in range(input()):
    N = input()
    n = int(N)
    
    s = set()
    t = -1
    for i in range(1,1000):
        x = str(i*n)
        for d in x:
            s.add(d)
        #print i, s
        if len(s) == 10:
            t = i*n
            break
        # print i, len(s)
    if t<0:
        print "Case #%d: INSOMNIA" % (tc + 1,)
    else: 
        print "Case #%d: %s" % (tc + 1, t)
