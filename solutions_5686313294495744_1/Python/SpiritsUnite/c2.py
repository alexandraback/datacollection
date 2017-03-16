#from collections import deque
T = int(raw_input())
for C in xrange(1, T+1):
    n = int(raw_input())
    topics = []
    for i in xrange(n):
        topics += [raw_input().split()]
    degree = [[0, 0] for i in xrange(n)]
    edges = [[] for i in xrange(n)]
    ans = 0
    for i in xrange(n):
        for j in xrange(i):
            if topics[i][0] == topics[j][0]:
                degree[i][0] += 1
                degree[j][0] += 1
                edges[j] += [i]
                edges[i] += [j]
            elif topics[i][1] == topics[j][1]:
                degree[i][1] += 1
                degree[j][1] += 1
                edges[j] += [i]
                edges[i] += [j]

    #print edges
    s = []
    for i in xrange(n):
        if degree[i][0] == 0 or degree[i][1] == 0:
            s += [i]

    seen = set()
    found = True
    while found:
        while len(s):
            node = s.pop()
            seen.add(node)
            for i in edges[node]:
                if i in seen: continue
                if degree[i][0] > 0 and degree[i][1] > 0:
                    ans += 1
                    for j in xrange(n):
                        if i == j: continue
                        if topics[i][0] == topics[j][0]:
                            degree[i][0] -= 1
                            degree[j][0] -= 1
                        elif topics[i][1] == topics[j][1]:
                            degree[i][1] -= 1
                            degree[j][1] -= 1
                    for j in edges[i]:
                        if j in seen: continue
                        if degree[j][0] == 0 or degree[j][0] == 0:
                            s += [j]
                            seen.add(j)
        found = False
        for i in xrange(n):
            if i in seen: continue
            if degree[i][0] > 0 and degree[i][1] > 0:
                found = True
                ans += 1
                for j in xrange(n):
                    if i == j: continue
                    if topics[i][0] == topics[j][0]:
                        degree[i][0] -= 1
                        degree[j][0] -= 1
                    elif topics[i][1] == topics[j][1]:
                        degree[i][1] -= 1
                        degree[j][1] -= 1
                for j in edges[i]:
                    if j in seen: continue
                    if degree[j][0] == 0 or degree[j][0] == 0:
                        s += [j]
                        seen.add(j)
                break



    print "Case #%d: %d" % (C, ans)
