import sys

f = open(sys.argv[1])
T = int(f.readline())
for X in range(1, T+1):
    N = int(f.readline())
    adj = [[] for i in range(N)]
    for U in range(N):
        vals = [int(x) for x in f.readline().split()]
        M = vals[0]
        neigh = [v-1 for v in vals[1:]]
        adj[U].extend(neigh)

    #print adj
    cycle = False
    # try each class as starting point and seek a cycle
    for S in range(N):
        if cycle:
            break
        # all start unseen
        seen = [False] * N
        Q = [S]
        while Q and not cycle:
            V = Q.pop()
            for U in adj[V]:
                if not seen[U]:
                    seen[U] = True
                    Q.insert(0, U)
                else:
                    # encounter same class twice
                    cycle = True
                    break
    result = 'Yes' if cycle else 'No'
    print 'Case #{}: {}'.format(X, result)
