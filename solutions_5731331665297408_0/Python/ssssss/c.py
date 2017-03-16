#!/usr/bin/python3

import sys
import heapq
#int(sys.stdin.readline())
#[int(x) for x in sys.stdin.readline().split()]

def case1():
    N,M=[int(x) for x in sys.stdin.readline().split()]
    ZIP = []
    for i in range(N): ZIP.append((int(sys.stdin.readline()),i))
    edges = []
    for i in range(M):
        a,b = [int(x) for x in sys.stdin.readline().split()]
        a -= 1
        b -= 1
        edges.append((a,b))
        edges.append((b,a))
    edges = sorted(edges)
    first = [0]
    v = 0
    for i in range(len(edges)):
        while edges[i][0] != v:
            first.append(i)
            v += 1
    while v != N:
        first.append(len(edges))
        v += 1
    assert len(first) == N+1
    SZIP = sorted(ZIP)
    #print(SZIP)

    dfsstack = []
    start = -1
    for i in range(N):
        s = SZIP[i][1]
        visited = [False]*N
        dfsstack.append(s)
        visited[s] = True
        while len(dfsstack) > 0:
            v = dfsstack.pop()
            for j in range(first[v], first[v+1]):
                u = edges[j][1]
                if not visited[u]:
                    visited[u] = True
                    dfsstack.append(u)
        if all(visited):
            start = s
            break
    assert start != -1
    
    #r = "%s" % ZOP[start][0]
    r = ""
    h = []
    heapq.heappush(h, ZIP[start])
    state = [0]*N
    state[start] = 1
    while len(h) > 0:
        entry = heapq.heappop(h)
        v = entry[1]
        r += "%s" % entry[0]
        if state[v] < 2:
            for j in range(first[v], first[v+1]):
                u = edges[j][1]
                if state[u] == 0:
                    heapq.heappush(h, ZIP[u])
                    state[u] = 1
        state[v] = 2
    return r 

def P(N):
    perm = [i for i in range(N)]
    j = N-1
    yield perm
    while j > 0:
        if perm[j] < perm[j-1]: j -= 1
        else:
            for k in range(j, N):
                for l in range(j, N-1):
                    if perm[l] > perm[l+1]:
                        perm[l], perm[l+1] = perm[l+1], perm[l]
            k = j
            while perm[k] < perm[j-1]: k +=1
            perm[k], perm[j-1] = perm[j-1], perm[k]
            j = N-1
            yield perm
def case():
    N,M=[int(x) for x in sys.stdin.readline().split()]
    ZIP = []
    for i in range(N): ZIP.append((int(sys.stdin.readline()),i))
    edges = []
    for i in range(M):
        a,b = [int(x) for x in sys.stdin.readline().split()]
        a -= 1
        b -= 1
        edges.append((a,b))
        edges.append((b,a))
    edges = sorted(edges)
    first = [0]
    v = 0
    for i in range(len(edges)):
        while edges[i][0] != v:
            first.append(i)
            v += 1
    while v != N:
        first.append(len(edges))
        v += 1
    assert len(first) == N+1
    SZIP = sorted(ZIP)
    #print(SZIP)

    def adjacent(u,v):
        for j in range(first[u],first[u+1]):
            if edges[j][1] == v: return True
        return False
    
    for p in P(N):
        #print(p)
        start = SZIP[p[0]][1]
        nxt = 1
        dfsstack = []
        dfsstack.append(start)
        #visited = [False]*N
        #visited[start] = True
        while len(dfsstack) > 0 and nxt < N:
            v = dfsstack[-1]
            #print(v, SZIP[p[nxt]][1], adjacent(v, SZIP[p[nxt]][1]))
            if adjacent(v, SZIP[p[nxt]][1]):
                dfsstack.append(SZIP[p[nxt]][1])
                nxt +=1
            else:
                dfsstack.pop()
        if nxt == N:
            #print(p)
            r = ""
            for i in range(N):
                r += "%s" % SZIP[p[i]][0]
            return r



T = int(sys.stdin.readline())
for i in range(1,T+1):
    print("Case #%s: %s" % (i, case()))
    

