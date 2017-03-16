import itertools
z = int(raw_input())
INF = '::::::::'
for casei in xrange(1, z+1):
    n, m = map(int, raw_input().split())
    labels = [ raw_input() for i in xrange(n) ]
    a_edges = [ map(int, raw_input().split()) for i in xrange(m) ]
    edges = [ [] for i in xrange(n) ]
    for a, b in a_edges:
        edges[a-1].append(b-1)
        edges[b-1].append(a-1)

    def find(pos, openc, returnf, cnodes):
        if not openc:
            return labels[pos]
        for node in sorted(cnodes, key=lambda k: labels[k]):
            if node not in openc: continue
            #print 'goto', node, openc, returnf
            _returnf = list(returnf)
            npos = pos
            while node not in edges[npos]:
                npos = _returnf.pop()
            new_cnodes = set()
            new_returnf = _returnf + [npos]
            for i in new_returnf + [node]:
                new_cnodes |= set(edges[i])
            new_openc = openc - set([node])
            ret = find(node, new_openc, new_returnf, new_cnodes)
            if ret is not None:
                return labels[pos] + ret

    best = INF
    for i in xrange(n):
        p = find(i, set(range(n)) - set([i]), [], set(edges[i]))
        if p is not None:
            best = min(best, p)
    assert len(best) / 5 == n
    print 'Case #%s: %s' % (casei, best)
