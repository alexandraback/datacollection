T = int(raw_input())

for z in xrange(1,T+1):
    C, F, X = map(float, raw_input().split())

    k = 0
    best = X/2.0

    uptoCost = 0.0

    while True:
        # add time to buy next farm
        uptoCost += C/(2.0 + k*F)
        k += 1

        newSpeed = 2.0 + k*F
        timeHere = (X / newSpeed) + uptoCost

        if timeHere < best:
            best = timeHere
        else:
            break

    print "Case #%d: %.7lf" % (z,best)
