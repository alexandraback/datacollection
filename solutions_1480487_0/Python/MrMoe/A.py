


T = int(raw_input())

for t in range(T):
    inp = map(int, raw_input().split())
    N = inp[0]
    J = inp[1:]
    if (len(J) != N):
        raise Exception("wrong")
    
    X = sum(J)
    avg = float(X)/N
    
    print "Case #%i:" % (t+1),
    for n in J:
        musthave = 1.0/X*(avg+(avg-n))
        score = n + X*musthave

        nJ = J[:]
        m = max(nJ)
        while score < m:
            nJ.remove(m)
            while m in nJ:
                nJ.remove(m)
            m = max(nJ)
            
            nX = sum(nJ)
            nN = len(nJ)
            navg = float(nX)/nN
            try:
                musthave = 1.0/X*(navg+(navg-n))
            except:
                musthave = 0.0
            score = n + X*musthave

        print "%0.6f" % max(0.0, (musthave*100)),

            
    print




