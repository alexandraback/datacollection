#!/usr/bin/env python3

T = int(input())

for t in range(1, T+1):
    N, M = [int(x) for x in input().split()]

    ZIP_D = {}
    ZIP_A = []
    sZIP = {}
    for i in range(1, N+1):
        x = int(input())
        ZIP_D[x] = i
        sZIP[i] = x
        ZIP_A.append(x)

    ZIP_A.sort()
    sCity = []
    for z in ZIP_A:
        sCity.append(ZIP_D[z])
    
    conn = {}
    for i in range(M):
        a, b = [int(x) for x in input().split()]
        if a in conn:
            conn[a].append(b)
        else:
            conn[a] = [b]
        
        if b in conn:
            conn[b].append(a)
        else:
            conn[b] = [a]

    for k in conn:
        conn[k] = sorted(conn[k], key = lambda x: sCity.index(x))

    print("Case #{}: ".format(t), end='')
    vis = {}
    
    dostepne = [sCity[0]]

    while(len(dostepne) > 0):
        v = dostepne[0]
        vis[v] = True
        print(sZIP[v], end='')
        if v in conn:
            for u in conn[v]:
                dostepne.append(u)
        ndst = [x for x in dostepne if x not in vis]
        dostepne = sorted(ndst, key = lambda x: sCity.index(x))
    
    print()
