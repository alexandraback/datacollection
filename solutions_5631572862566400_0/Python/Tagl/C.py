def dfs(G,C,v,c):
    if C[v] == 0:
        C[v] = c
        for u in G[v]:
            dfs(G,C,u,c)

def cycle(G,V,P,v):
    if not V[v]:
        V[v] = True
        P.append(v)
        return cycle(G,V,P,G[v])
    else:
        return v

def longest(G,v,d):
    #print(v,d)
    if len(G[v]) == 0:
        return d
    else:
        mx = d
        for u in G[v]:
            mx = max(mx, longest(G,u,d+1))
        return mx

t = int(input())
for i in range(t):
    n = int(input())
    V = [False]*n
    C = [0]*n
    G = [[] for x in range(n)]
    GG = [[] for x in range(n)]
    A = [x-1 for x in map(int,input().split())]
    for j in range(n):
        G[A[j]].append(j)
        GG[j].append(A[j])
    cycles = []
    for j in range(n):
        path = []
        if not V[j]:
            end = cycle(A,V,path,j)
            try:
                start = path.index(end)
                cycles.append(path[start:])
            except:
                pass

    single = 0
    many = 0
    for cyc in cycles:
        if len(cyc) > 2:
            single = max(single, len(cyc))
        else:
            v1 = cyc[0]
            v2 = cyc[1]
            #print(cyc)
            l1,l2 = 1,1
            #print(G[v1])
            for u in G[v1]:
                if u != v2:
                    l1 = max(l1,longest(G,u,2))
            for u in G[v2]:
                if u != v1:
                    l2 = max(l2,longest(G,u,2))
            many += l1+l2
    print('Case #%d: %d' %(i+1,max(many,single)))
    
    
    
