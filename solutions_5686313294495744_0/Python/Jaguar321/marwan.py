def readInt(): return int(raw_input())
def readList(): return map(int, raw_input().split(' '))

t = readInt()

for l in xrange(t):

    n = readInt()
    g = []
    a = []
    b = []
    for i in xrange(n):
        x, y = raw_input().split(' ')
        a.append(x)
        b.append(y)
        g.append([x, y])
    fakes = 0
    gg = g[:]
    aa = a[:]
    bb = b[:]
    for r in xrange(n):
        for rr in xrange(r+1, n):
            tt = g.pop(r)
            p1 = a.pop(r)
            q1 = b.pop(r)
            ttt = g.pop(rr-1)
            p2 = a.pop(rr-1)
            q2 = b.pop(rr-1)
            g.insert(0, tt)
            g.insert(0, ttt)
            a.insert(0, p1)
            a.insert(0, p2)
            b.insert(0, q1)
            b.insert(0, q2)
            f = 0
            for i in xrange(2, n):
                t = a.pop(i)
                if g[i][0] in a:
                    t2 = b.pop(i)
                    if g[i][1] in b:
                        f += 1
                    b.insert(i, t2)
                a.insert(i, t)
            if f > fakes:
                fakes = f
        g = gg[:]
        a = aa[:]
        b = bb[:]

    print "Case #%d:" % (l+1),
    print min(fakes, n-2)
