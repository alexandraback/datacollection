r = open('4.in')
T = int(r.readline().rstrip())

for t in range(1, T+1):
    D = int(r.readline().rstrip())
    P = map(int, r.readline().rstrip().split())

    pmax = max(P)
    min_time = pmax
    min_kmax = 0
    min_rounds = 0
    for kmax in range(1, pmax):
        rounds = 0
        for p in P:
            if p > kmax:
                rounds += (p-kmax-1)//kmax + 1

        if rounds + kmax  < min_time:
            min_time = rounds + kmax
            min_kmax = kmax
            min_rounds = rounds

    print 'Case #%d: %d' % (t, min_time)
