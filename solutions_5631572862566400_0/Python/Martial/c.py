import sys

def f(n, a):
    for i in range(n):
        a[i] -= 1
    res = 0
    isOnCycle = [-1] * n
    cycles = []
    n_cycles = 0
    l = [0] * n
    for i in range(n):
        u = [-1] * n
        c = 0
        j = i
        p = -1
        while u[j] == -1:
            u[j] = c
            c += 1
            p = j
            j = t[j]
        k = j
        if isOnCycle[k] > -1:
            continue
        cycle = []
        lc = u[p] - u[j] + 1
        for _ in range(lc):
            cycle.append(k)
            isOnCycle[k] = n_cycles
            l[k] = lc
            k = t[k]
        cycles.append(cycle)
        n_cycles += 1
    
    ti = [[] for i in range(n)]
    for i in range(n):
        if isOnCycle[i] == -1:
            ti[t[i]].append(i)

    distToCycle = [-1] * n
    leadToCycle = [-1] * n
    q = []
    for i in range(n_cycles):
        for j in cycles[i]:
            leadToCycle[j] = j
            q.append(j)
    dist = 0
    while len(q) > 0:
        qq = []
        for i in q:
            distToCycle[i] = dist
            for j in ti[i]:
                leadToCycle[j] = leadToCycle[i]
                qq.append(j)
        q = qq[:]
        dist += 1
    
    strings = [[0] * len(cycles[k]) for k in range(n_cycles)]
    for i in range(n):
        if isOnCycle[i] == -1:
            j = leadToCycle[i]
            k = isOnCycle[j]
            if len(cycles[k])==2:

                for q in [0,1]:
                    if cycles[k][q] == j:
                        strings[k][q] = max (strings[k][q], distToCycle[i])
    for k in range(len(cycles)):
        r = len(cycles[k])
        if len(cycles[k]) == 2:
            r += strings[k][0] + strings[k][1]
        if r > res:
            res = r
            
    return res

n_cases = int(input())
for test_case in range(1, n_cases + 1):
    N = int(input())
    t = list(map(int, input().split()))
    print(test_case, file=sys.stderr, end=' ')
    res = f(N, t)
    print('Case #' + str(test_case) + ':', res)

print(file=sys.stderr)
    
