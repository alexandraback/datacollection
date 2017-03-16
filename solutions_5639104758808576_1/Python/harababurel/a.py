for t in range(0, input()):
    n, v = raw_input().split()
    n = int(n)
    v = [int(x) for x in v]

    currentlyStanding, needed = 0, 0
    for shyness, x in enumerate(v):
        if shyness > currentlyStanding and x > 0:
            needed += shyness - currentlyStanding
            currentlyStanding = shyness
        currentlyStanding += x

    print "Case #%i: %i" % (t+1, needed)

