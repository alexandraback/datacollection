for c in xrange(input()):
    D, Q = input(), map(int, raw_input().split())
    minmaxcake = []
    G = [i for i in xrange(D)]
    getGs = {i:[i] for i in xrange(D)}
    for i in xrange(1001):
        maxindex = Q.index(max(Q))
        minmaxcake.append(Q[maxindex])
        if Q[maxindex] < 4: break
        Q.append(0)
        G.append(G[maxindex])
        getGs[maxindex].append(D + i)
        Gs = getGs[maxindex]
        total = sum([Q[g] for g in Gs])
        gg = len(Gs)
        for g in Gs:
            Q[g] = total/gg
        rem = total % gg
        for g in Gs:
            if not rem: break
            Q[g] += 1
            rem -= 1
    print "Case #" + str(c + 1) + ": " + str(min([i + x for i, x in enumerate(minmaxcake)]))
