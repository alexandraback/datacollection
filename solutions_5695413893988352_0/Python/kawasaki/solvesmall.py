T = int(raw_input())
for tc in xrange(1, T + 1):
    C, J = raw_input().split()
    assert 1 <= len(C) == len(J) <= 3
    n = len(C)

    minvalue = None
    for c in xrange(10 ** n):
        sc = '{:0{}d}'.format(c, n)
        if not all(C[i] in ('?', sc[i]) for i in xrange(n)):
            continue
        for j in xrange(10 ** n):
            sj = '{:0{}d}'.format(j, n)
            if not all(J[i] in ('?', sj[i]) for i in xrange(n)):
                continue
            if minvalue is None or abs(c - j) < minvalue[0]:
                minvalue = (abs(c - j), sc, sj)

    print 'Case #{}: {} {}'.format(tc, minvalue[1], minvalue[2])
