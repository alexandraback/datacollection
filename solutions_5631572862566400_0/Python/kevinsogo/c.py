for cas in xrange(1,1+input()):
    n = input()
    f = map(int, raw_input().strip().split())
    f = [x-1 for x in f]

    ansbig = 0
    anssmall = 0

    parent = [-1]*n
    dist = [-1]*n
    cyclen = [-1]*n
    maxdist = [0]*n

    for i in xrange(n):
        j = i
        vis = {}
        time = 0
        while j not in vis:
            vis[j] = time
            time += 1
            j = f[j]
        cyclen[i] = time - vis[j]
        parent[i] = j
        dist[i] = vis[j]
        assert cyclen[i] > 1
        if cyclen[i] > 2:
            ansbig = max(ansbig, cyclen[i])
        else:
            maxdist[j] = max(maxdist[j], dist[i])

    for i in xrange(n):
        if i < f[i] and f[f[i]] == i:
            anssmall += maxdist[i] + maxdist[f[i]] + 2

    ans = max(ansbig, anssmall)
    print "Case #%s: %s" % (cas, ans)
