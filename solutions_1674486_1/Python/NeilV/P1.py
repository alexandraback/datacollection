def f(n): return int(n)-1

def bfs(root,n):
    visited = [False]*n
    queue = [root]
    
    while len(queue) > 0:
        top = queue.pop(0)
        if visited[top]: return True
        visited[top] = True
        for j in adj[top]:
            queue.append(j)
    return False
        

data = open("P1.txt")
out = open("P1.out","w")
cases = int(data.readline())

for case in range(cases):
    out.write("Case #%i: " %(case+1))
    n = int(data.readline())
    adj = [[] for z in range(n)]
    indegree = [0]*n
    
    for i in range(n):
        adj[i] = map(f,data.readline().split())[1:]
        for j in adj[i]:
            indegree[j] += 1
    #print indegree

    for i in range(n):
        if indegree[i] == 0:
            if bfs(i,n):
                out.write("Yes\n")
                break
    else:
        out.write("No\n")