for t in xrange(input()):
    C,D,V = map(int,raw_input().split())
    d = map(int,raw_input().split())
    v = [0]*(V+1)
    v[0] = 1
    for x in d:
        v2 = v[:]
        for i in xrange(V+1-x):
            if v[i]: v2[i+x] = 1
        v = v2
    j = 0
    while v.count(0):
        j+=1
        x = v.index(0)
        v2 = v[:]
        for i in xrange(V+1-x):
            if v[i]: v2[i+x] = 1
        v = v2
    print "Case #%d: %d"%(t+1,j)
