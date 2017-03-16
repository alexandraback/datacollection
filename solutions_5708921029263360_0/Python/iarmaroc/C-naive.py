
def solve_fast(t, J, P, S, K):
    conf = []
    for j in xrange(1, J+1):
        for p in xrange(1, P+1):
            for s in xrange(1, S+1):
                conf.append((j, p , s))

    maxsol = []
    maxcount = 0
    for start in xrange(len(conf)):
        jp = [[0 for _ in xrange(P+1)] for _ in xrange(J+1)]
        ps = [[0 for _ in xrange(S+1)] for _ in xrange(P+1)]
        js = [[0 for _ in xrange(S+1)] for _ in xrange(J+1)]

        sol = []
        count = 0

        for i in xrange(start, len(conf)):
            j, p, s = conf[i]
            if jp[j][p] < K and ps[p][s] < K and js[j][s] < K:
                count += 1
                sol.append(' '.join([str(j), str(p), str(s)]))
                jp[j][p] += 1
                ps[p][s] += 1
                js[j][s] += 1

        if count > maxcount:
            maxcount = count
            maxsol = sol

    print "Case #{}: {}".format(t, maxcount)
    for s in maxsol:
        print s


def solve_naive(t, J, P, S, K):
    conf = []
    for j in xrange(1, J+1):
        for p in xrange(1, P+1):
            for s in xrange(1, S+1):
                conf.append((j, p, s))

    maxcount = 0
    maxsol = []
    L = len(conf)
    for x in xrange(1 << L):
        jp = [[0 for _ in xrange(P+1)] for _ in xrange(J+1)]
        ps = [[0 for _ in xrange(S+1)] for _ in xrange(P+1)]
        js = [[0 for _ in xrange(S+1)] for _ in xrange(J+1)]

        count = 0
        sol = []
        bad_config = False
        for i in xrange(L):
            if (1 << i) & x:
                j, p, s = conf[i]
                if jp[j][p] == K or ps[p][s] == K or js[j][s] == K:
                    bad_config = True
                    break
                count += 1
                sol.append(' '.join([str(j), str(p), str(s)]))
                jp[j][p] += 1
                ps[p][s] += 1
                js[j][s] += 1

        if not bad_config and count > maxcount:
            maxcount = count
            maxsol = sol

    print "Case #{}: {}".format(t, maxcount)
    for s in maxsol:
        print s


T = int(raw_input())
for t in xrange(1, T + 1):
    J, P, S, K = [int(x) for x in raw_input().split(' ')]

    if J == P == S:
        solve_fast(t, J, P, S, K)
    else:
        solve_naive(t, J, P, S, K)

