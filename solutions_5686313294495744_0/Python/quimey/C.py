from itertools import combinations

T = input()
for t in range(T):
    N = input()
    a = set()
    for n in range(N):
        u = tuple(raw_input().split())
        a.add(u)
    listo = False
    for n in range(N + 1):
        for lreals in combinations(a, n):
            reals = set(lreals)
            fakes = set([x for x in a if x not in reals])
            firsts = set([r[0] for r in reals])
            seconds = set([r[1] for r in reals])
            sirve = True
            for f in fakes:
                if f[0] not in firsts or f[1] not in seconds:
                    sirve = False
                    break
            if sirve:
                print "Case #%d: %d" % (t + 1, len(fakes))
                listo = True
                break
        if listo: break
