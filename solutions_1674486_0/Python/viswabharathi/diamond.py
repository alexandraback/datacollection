

t = int(raw_input())

for i in xrange(t):
    n = int(raw_input())
    c = []
    m = []
    for j in xrange(n):
        tmp = map(int, raw_input().split())
        m.append(tmp[0])
        c.append(tmp[1:])

    is_possible = False
    for j in xrange(n):
        if m[j] < 2:
            continue
        visited = {}
        def travel(trav):
            possible = False
            for node in trav:
                if node in visited or possible == True:
                    return True
                visited[node] = None
                #print node
                possible = travel(c[node-1])
            return possible
                
        is_possible = travel(c[j])
        if is_possible:
            break
    print "Case #%s: %s" % (i+1, "Yes" if is_possible else "No")
    
