
for t in range(int(raw_input())):
    H,N,M = map(int, raw_input().split(' '))
    maps = {}
    # Worst time is getting the kayak on the back, on
    # each tile and waiting for the tide to completely
    # vanish
    worst = float(H)/10 + N*M*10

    for i in range(N):
        for j, ceil in enumerate(map(int, raw_input().split(' '))):
            maps[(i,j)] = [ceil]
    for i in range(N):
        for j, floor in enumerate(map(int, raw_input().split(' '))):
            maps[(i,j)].append(floor)

    position = (0,0)

    # Utility functions
    def neighbours(p):
        if p[0] > 0:
            yield (p[0]-1, p[1])
        if p[0] < N-1:
            yield (p[0]+1, p[1])
        if p[1] > 0:
            yield (p[0], p[1]-1)
        if p[1] < M-1:
            yield (p[0], p[1]+1)

    def reachable(u, v, t=0.0):
        limit = maps[v][0] - 50
        h = H - t * 10.0
        if h <= limit and maps[u][1] <= limit and maps[v][1] <= limit and maps[v][1] <= (maps[u][0] - 50):
            return ((h - maps[u][1]) >= 20) and 1.0 or 10.0
        else:
            return 0.0

    def wait_for(u, v, t=0.0):
        limit = maps[v][0] - 50
        h = H - t * 10.0
        if h > limit and maps[u][1] <= limit and maps[v][1] <= limit and maps[v][1] <= (maps[u][0] - 50):
            return (h - limit) / 10.0 + ((limit - maps[u][1] >= 20) and 1.0 or 10.0)
        else:
            return 0.0


    # First pass, establish the list of end points we can reach
    # and the list of starting position with initial timing
    cost = { k: worst for k in maps.keys() }
    cost[position] = 0.0
    Q = maps.keys()
    while Q:
        # Find next node to visit
        best = worst
        u = None
        for q in Q:
            if q in cost and cost[q] < best:
                best = cost[q]
                u = q

        if u:
            Q.remove(u)
            for v in neighbours(u):
                #print "from %s to %s" % (u, v)
                reach = reachable(u, v, cost[u])
                if reach:
                    if cost[u]:
                        dist = cost[u] + reach
                        if dist < cost[v]:
                            #print "goind for %.2f" % dist
                            cost[v] = dist
                    else:
                        cost[v] = 0
                else:
                    #print "%s to %s not reachable at %.2f" % (u,v,cost[u])
                    wait = wait_for(u, v, cost[u])
                    dist = wait + cost[u]
                    if wait and dist < cost[v]:
                        #print "wait for %.2f" % dist
                        cost[v] = dist
        else:
            # WHY U NO...
            break

    print "Case #%d: %f" % (t+1, cost[(N-1, M-1)])



