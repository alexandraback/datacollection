import sys

getline = lambda: sys.stdin.readline().replace("\n", "")
getlist = lambda: getline().split(" ")
getint = lambda: int(getline())
getints = lambda: map(int, getlist())


for t in xrange(1, 1+int(getline())):
    E, R, N = getints()
    vs = getints()

    Enow = E
    ma = max(vs)
    d = {}
    for havenow in range(0, E+1):
        d[N-1, havenow] = vs[-1] * havenow
    for i in xrange(N-2,-1,-1):
        v = vs[i]
        for havenow in range(0, E+1):
            best = 0
            for usenow in range(0, havenow+1):
                havenext = havenow - usenow + R
                if havenext > E:
                    havenext = E
                if v*usenow + d[i+1, havenext] > best:
                    d[i,havenow] = v * usenow + d[i+1, havenext]
                    best = d[i, havenow]

    print "Case #%d: %d" % (t, d[0,E])


