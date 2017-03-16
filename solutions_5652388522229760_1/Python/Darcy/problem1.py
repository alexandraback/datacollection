for tc in range(input()):
    N = input()
    n = int(N)
    
    s = set()
    t = 10
    if n == 0:
        print "Case #%d: INSOMNIA" % (tc + 1,)
    else:
        i = 1
        while True:
            x = str(i*n)
            for d in x:
                s.add(d)
            #print i, s
            if len(s) == 10:
                t = i*n
                break
            i += 1
            # print i, len(s) 
        print "Case #%d: %s" % (tc + 1, t)
