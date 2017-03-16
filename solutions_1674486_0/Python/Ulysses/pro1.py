
def sear(r, node, graph):
    global visited
    for g in graph:
        if g[0] == node:
            visited.append((r, g[1]))
            search(r, g[1], graph)
        else:
            continue
        
    
with file('A-small-attempt0.in') as f:
    out = file('proA.out','w')
    T = int(f.readline().strip())
    for t in xrange(1, T+1):
        N = int(f.readline().strip())
        graph = []
        for n in xrange(1,N+1):
            nums = map(int, f.readline().split())
            nums.pop(0)
            for x in nums:
                graph.append([x,n])
        
        visited = []
        for x in xrange(1, N+1):
            sear(x, x, graph)
        s=''
        if len(visited) != len(set(visited)):
            s = 'Yes'
        else:
            s = 'No'
        out.write('Case #%i: %s\n'%(t, s))
    out.close()


