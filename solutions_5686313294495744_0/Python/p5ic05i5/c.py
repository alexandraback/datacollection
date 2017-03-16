
T = int(raw_input())
for x in xrange(1, T+1):
    N = int(raw_input())
    P = [raw_input().split() for _ in xrange(N)]

    r = 0
    for k in xrange(len(P)):
        p = P[k]

        f = False
        for i in xrange(len(P)):
            if i != k and P[i][0] == p[0]:
                f = True
                break

        s = False
        for i in xrange(len(P)):
            if i != k and P[i][1] == p[1]:
                s = True
                break

        if f and s:
            r += 1

    print 'Case #{}: {}'.format(x, r)
