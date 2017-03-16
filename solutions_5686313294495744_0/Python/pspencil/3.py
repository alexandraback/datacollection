def bfs(s,t,adj):
    pred = [-1 for i in range(len(adj))]
    q = [s]
    while q != []:
        c = q.pop(0)
        if c == t:
            break
        for i in adj[c]:
            if pred[i] == -1:
                pred[i] = c
                q.append(i)
    if pred[t] != -1:
        cur = t
        while cur != s:
            nex = pred[cur]
            adj[nex].remove(cur)
            adj[cur].append(nex)
            cur = nex
        return True
    else:
        return False
T = int(raw_input())
for i in range(T):
    print "Case #"+str(i+1)+":",
    n = int(raw_input())
    l = []
    for j in range(n):
        a,b = raw_input().split(' ')
        l.append((a,b,j))
    adj = [[] for i in range(3*n)]
    A = dict()
    B = dict()
    for a,b,j in l:
        if a in A:
            for s in A[a]:
                adj[s].append(j+n)
                adj[j].append(s+n)
            A[a].append(j)
        else:
            A[a] = [j]
        if b in B:
            for s in B[b]:
                adj[s+n].append(j+n*2)
                adj[j+n].append(s+n*2)
            B[b].append(j)
        else:
            B[b] = [j]
    s = 3*n
    t = 3*n+1
    adj.append([k for k in range(n)])
    adj.append([])
    for k in range(n):
        adj[2*n+k].append(t)
    count = 0
    while bfs(s,t,adj):
        count+=1
    print count
    
        

    
