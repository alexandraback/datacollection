def dfs(G,start):
    visited = set()
    #visited.add(start)
    queue = [start]
    while queue:
        v = queue.pop()
        if v not in visited:
            visited.add(v)
            queue.extend(G[v])
    return visited

for case in range(input()):
    print "Case #"+str(case+1)+":",
    K,N = map(int,raw_input().split())
    startkeys = map(int,raw_input().split())
    chests = []
    needkey = []
    knum = 0
    contents = []
    for i in xrange(N):
        contents.append([])
        chests.append(map(int,raw_input().split()))
        chests[-1].pop(1)
        needkey.append(chests[-1].pop(0))
        #needkey.append(chests[-1][0])
        for t in chests[-1]:
            contents[-1].append((knum,t))
            knum += 1
    #print startkeys,needkey,chests,contents
    #G = dict((k,[]) for k in needkey)
    G = {}
    for i,k in enumerate(needkey):
        G[("L",i)] = [("R",knum) for knum,t in contents[i]]
    #G = dict((("L",i),contents[i]) for i,k in enumerate(needkey))
    for content in contents:
        for knum,t in content:
            G[("R",knum)] = [("L",i) for i,k in enumerate(needkey) if t==k]
    for j,t in enumerate(startkeys):
        G[("RS",j)] = [("L",i) for i,k in enumerate(needkey) if t==k]
    G[("L","start")] = [("RS",i) for i,t in enumerate(startkeys)]

    #Check trivial key count condition
    #Find best path
    start = ("L","start")
    solution = []
    rverts = set()
    minlvert = start
    visited = set()
    #visited.add(start)
    """
    visited = [start]
    for v in visited:
        if v[0]=="L":
            visited.update(G[v])
        else:
            rverts.append(v)
    """
    #For each R vertex, try every assignment and then pick the lexicographically lowest.
    while 1:
        visited.add(minlvert)
        rverts.update(G[minlvert])
        lverts = {}
        for rv in rverts-visited:
            oldnh = G[rv]
            for u in oldnh:
                if u not in visited and u not in lverts:
                    G[rv] = [u]
                    if len(dfs(G,start)) == len(G):
                        lverts[u] = rv
            G[rv] = oldnh
        #print "lverts found",lverts
        if not lverts:
            #Was impossible from the start by theorem.
            solution = None#"IMPOSSIBLE"
            break
        minlvert = min(lverts, key=lambda x:x[1])
        solution.append(minlvert)
        if len(solution) == len(needkey):
            break
        rvert = lverts[minlvert]
        G[rvert] = [minlvert]
        visited.add(rvert)
        #print "Added",minlvert,rvert
    if solution:
        print " ".join(map(str,[s[1]+1 for s in solution]))
    else:
        print "IMPOSSIBLE"

