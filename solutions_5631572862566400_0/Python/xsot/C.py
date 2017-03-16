for t in range(1, int(raw_input())+1):
    n = int(raw_input())
    a = [int(i)-1 for i in raw_input().split()]
    
    
    longest = 0
    i = 0
    visited = [0] * n
    pairs = []
    while i < n:
        while i < n and visited[i]:
            i += 1
        if i >= n:
            break
        j = i
        depth = 0
        path = [i]
        while not visited[j]:
        # while j not in path:
            depth += 1
            visited[j] = depth
            path += [j]
            j = a[j]
        if j in path:
            cycle_len = depth-visited[j]+1
            # print depth, visited[j], cycle_len, visited
            if cycle_len == 2:
                pairs += [path[-cycle_len:]]
            if longest < cycle_len:
                longest = cycle_len

    
    b = []
    for i in range(n):
        b += [[]]
    for i, v in enumerate(a):
        b[v] += [i]
    # print b
    
    bfsmax = 0
    for p in pairs:
        x = 0
        visited = [0] * n
        q = [(p[0], 0)]
        while q:
            top, depth = q.pop(0)
            visited[top] = 1
            x = max(x, depth)
            for el in b[top]:
                if not visited[el]:
                    q += [(el, depth+1)]
        y = 0
        visited = [0] * n
        q = [(p[1], 0)]
        while q:
            top, depth = q.pop(0)
            visited[top] = 1
            y = max(y, depth)
            for el in b[top]:
                if not visited[el]:
                    q += [(el, depth+1)]      
        bfsmax = max(bfsmax, x+y)

        
        
    print "Case #%d: %d" % (t,  max(longest, bfsmax))