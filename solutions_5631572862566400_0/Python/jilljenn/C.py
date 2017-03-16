T = int(input())
for t in range(T):
    N = int(input())
    bff = list(map(int, input().split()))
    for i in range(N):
        bff[i] -= 1
    graph = [[] for _ in range(N)]
    for i in range(N):
        if bff[bff[i]] != i:
            graph[bff[i]].append(i)
    record = 0
    meta = []
    for i in range(N):
        cycle = 0
        j = i
        mark1 = [False] * N
        while not mark1[j]:
            mark1[j] = True
            j = bff[j]
            cycle += 1
        if i != j:
            continue
        if i == j and cycle >= 3:
            # print('new record cycle', cycle)
            record = max(record, cycle)
    for i in range(N):
        if i < bff[i] and bff[bff[i]] == i:
            j = i
            # print(i, 'interr, lancer recherche depuis', j)
            mark2 = [0] * N
            todo = [(j, 0)]
            l2 = 0
            while todo:
                u, d = todo.pop()
                l2 = max(l2, d)
                if not mark2[u]:
                    mark2[u] = True
                    mark1[u] = True
                    for v in graph[u]:
                        todo.append((v, d + 1))
            l3 = 0
            # print('rallonge', l2, 'depuis', j)
            todo = [(bff[j], 0)]
            while todo:
                u, d = todo.pop()
                l3 = max(l3, d)
                if not mark2[u]:
                    mark2[u] = True
                    mark1[u] = True
                    for v in graph[u]:
                        todo.append((v, d + 1))
            # print('rallonge', l3, 'depuis', bff[j])
            meta.append(l2 + l3 + 2)
    # print(record, meta)
    print('Case #%d:' % (t + 1), max(record, sum(meta)))
