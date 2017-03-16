for t in range(0, input()):
    v = []

    groups = input()
    for i in range(0, groups):
        d, n, h = map(int, raw_input().split())

        for j in range(0, n):
            v.append((d, h+j))

    if len(v) < 2:
        print "Case #%i: 0" % t+1
        continue

    #v = sorted(v)
    if v[0][1] > v[1][1]: v = v[::-1]
    #print v

    aPortion = ((360.0 - v[0][0]) / 360) * v[0][1]
    aLap = v[0][1]

    bPortion = ((360.0 - v[1][0]) / 360) * v[1][1]
    bLap = v[1][1]

    sol = 0
    if v[0][0] != 0:
        if aPortion + aLap <= bPortion:
            sol = 1
            #print
            #print "primu isi face portiunea in %.2f" % aPortion
            #print "al doilea isi face portiunea in %.2f si turul in %.2f" % (bPortion, bLap)
        #if bPortion > aPortion + aLap: sol = 1

        #if aPortion == bPortion + bLap: sol = 2
        #if bPortion == aPortion + aLap: sol = 2

    sol = max(sol, len([x for x in v if x[0] == 0]))
    print "Case #%i: %i" % (t+1, sol)
