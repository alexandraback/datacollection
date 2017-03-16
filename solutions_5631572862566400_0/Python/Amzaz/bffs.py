
import sys
f = sys.stdin
T = int(f.readline())
for case in xrange(1, T+1):
    N = int(f.readline())
    F = map(lambda x: int(x) - 1, f.readline().split())
    bffs = [[] for _ in xrange(N)]
    for i in xrange(N):
        bffs[F[i]].append(i)
    closed = {}
    full_group = {}
    for i in xrange(N):
        d = set()
        j = i
        count = 0
        while j not in d:
            d.add(j)
            j = F[j]
        if j == i:
            full_group[i] = len(d)
        if F[F[j]] == j:
            if frozenset([j, F[j]]) not in closed:
                closed[frozenset([j, F[j]])] = []
            closed[frozenset([j, F[j]])].append((j, frozenset(d)))
    best_blok = 0
    for k, vs in closed.iteritems():
        local_best = 0
        for i in xrange(len(vs)):
            for j in xrange(i, len(vs)):
                assert len(vs[i][1] & vs[j][1]) >= 2
                if len(vs[i][1] & vs[j][1]) == 2 and vs[i][0] != vs[j][0]:
                    local_best = max(local_best, len(vs[i][1] | vs[j][1]))
        best_blok += local_best
        
    best_circ = max(full_group.values()) if len(full_group) != 0 else 0
    print "Case #%d: %s" % (case, max(best_circ, best_blok))
        