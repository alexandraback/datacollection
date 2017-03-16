for t in xrange(input()):
    print "Case #%d:"%(t+1),
    c, j = raw_input().split()
    mi = 10**9
    nowA = [0]*len(c)
    nowB = [0]*len(j)
    aA = aB = None
    ansA = ansB = None

    def fA(d, now):
        if d == len(c):
            fB(0, nowB)
            return
        if c[d] == "?":
            for i in xrange(10):
                now[d] = i
                fA(d+1, now)
        else:
            now[d] = int(c[d])
            fA(d+1, now)

    def fB(d, now):
        if d == len(j):
            check()
            return
        if j[d] == "?":
            for i in xrange(10):
                now[d] = i
                fB(d+1, now)
        else:
            now[d] = int(j[d])
            fB(d+1, now)
    def check():
        global mi, ansA, ansB, aA, aB
        #print nowA, nowB
        numA = int("".join(map(str, nowA)))
        numB = int("".join(map(str, nowB)))
        dif = abs(numA - numB)
        #print dif
        if dif < mi:
            mi = dif
            ansA = numA
            aA = nowA[:]
            ansB = numB
            aB = nowB[:]
        elif dif == mi:
            if numA < ansA:
                ansA = numA
                aA = nowA[:]
                ansB = numB
                aB = nowB[:]
            elif numA == ansA and numB < ansB:
                ansB = numB
                aB = nowB[:]
    fA(0, nowA)

    print "".join(map(str, aA)), "".join(map(str, aB))
