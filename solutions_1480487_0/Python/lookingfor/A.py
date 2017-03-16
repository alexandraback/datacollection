T = int(raw_input())
for z in xrange(1, T+1):
    spl = raw_input().split()
    N = int(spl[0])
    a = map(float, spl[1:])
    a.append(10000)
    b = zip(a, xrange(N+1))
    b.sort()
    res = [0]*N
    S, d = sum(a)-10000, 0

    i = 0
    while True:
        e = d + (i+1)*(b[i+1][0] - b[i][0])
        if e >= S:
            L = b[i][0] + 1.0*(S - d)/(i+1)
            break
        else:
            d = e
        i += 1
    for i in xrange(N):
        if a[i] < L:
            res[i] = (L - a[i])/S*100

    resstr = str(res).strip('[]').replace(',', '')

    print "Case #%d: " % z, resstr