for case in range(input()):
    print "Case #"+str(case+1)+":",
    N,M=map(int,raw_input().split())
    a = []
    for i in xrange(N):
        a.append(map(int,raw_input().split()))
    heights = [[] for i in xrange(101)]
    for i in xrange(N):
        for j in xrange(M):
            heights[a[i][j]].append((i,j))
    rows = set(range(N))
    cols = set(range(M))
    possible = True
    #print heights
    for h in xrange(100,-1,-1):
        if not heights[h]:
            continue
        for i,j in heights[h]:
            if i not in rows and j not in cols:
                possible = False
                break
        if not possible: break
        frow,fcol = map(set,zip(*heights[h]))
        rows -= frow
        cols -= fcol
    if possible:
        print "YES"
    else:
        print "NO"
