from collections import defaultdict
from itertools import combinations
from heapq import heappush, heappop
t = int(raw_input())
for kei in xrange(t):
    n, m = [int(x) for x in raw_input().split()]
    labels = []
    ml = 0
    for i in xrange(n):
        labels.append(raw_input())
        if labels[ml] > labels[i]:
            ml = i
    edges = []
    for i in xrange(m):
        u, v = [int(x)-1 for x in raw_input().split()]
        edges.append((u,v))
    mintot = '9'*1000
    for comb in combinations(edges, m):
        comb = list(comb)
        el = defaultdict(list)
        for u, v in comb:
            el[u].append(v)
            el[v].append(u)
        visited = [False] * n
        # visited[ml] = True
        heap = [(labels[ml], ml)]
        tot = ''
        while len(heap):
            # print(heap)
            val, u = heappop(heap)
            if visited[u]:
                continue
            visited[u] = True
            tot += val
            # print val
            for v in el[u]:
                if not visited[v]:
                    heappush(heap, (labels[v], v))
        mintot = min(mintot, tot)
    print 'Case #%d: %s' % (kei+1, mintot)
    # print '*'*100




        