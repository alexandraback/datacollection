from collections import defaultdict, deque

T = int(raw_input())

for t in xrange(1, T+1):
    N = int(raw_input())
    children = defaultdict(list)
    #parents = defaultdict(list)
    roots = set(xrange(1, N+1))
    for n in xrange(1, N+1):
        line = map(int, raw_input().split())
        assert len(line) == line[0] + 1
        for m in line[1:]:
            children[n].append(m)
            #parents[m].append(n)
            roots.discard(m)
    diamond = False
    for root in roots:
        queue = deque([root])
        visited = set()
        while queue:
            node = queue.popleft()
            if node in visited:
                diamond = True
                break
            visited.add(node)
            queue.extend(children[node])
        if diamond:
            break
    print "Case #%i: %s" % (t, "Yes" if diamond else "No")
