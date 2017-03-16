for T in xrange(input()):
    data = raw_input().strip().split(" ")
    N = int(data[0])
    shy = map(int, list(data[1]))
    cum = list(shy)
    for i in xrange(1, N+1):
        cum[i] = cum[i-1] + shy[i]
    add = 0
    for i in xrange(N):
        cum[i] += add
        if cum[i] < (i+1):
            diff = (i+1 - cum[i])
            add += diff
    print "Case #%d: %d" % (T+1, add)
