def symgraph(graph):
    out = dict()
    for i in range(len(graph)):
        out[i] = []
    for i in range(len(graph)):
        out[i].append(graph[i])
        out[graph[i]].append(i)
    return out

def components(graph):
    colors = [ None for x in range(len(graph)) ]

    def dfs(pt,col):
        if colors[pt] != None:
            return
        colors[pt] = col
        
        for ch in graph[pt]:
            dfs(ch,col)

    col = -1
    for pt in range(len(graph)):
        if(colors[pt] == None):
            col += 1
        dfs(pt,col)
    
    out = [ [] for x in range(col+1) ]
    for pt in range(len(graph)):
        out[colors[pt]].append(pt)
    return out

def cycle(graph, component):
    seen = [ False for x in graph ]
    def dfs(pos,parent):
        if(seen[pos]):
            return (1, [pos],False)
        seen[pos] = True

        onceParent = True
        for ch in graph[pos]:
            if(ch == parent and onceParent):
                onceParent = False
                continue
            out=dfs(ch,pos)
            if(out != None):
                if(pos == out[1][0]) or (out[2]):
                    return out[0],out[1],True
                return (out[0]+1, out[1]+[pos],False)
        return None
    return dfs(component[0],None)[:-1]

def chainLen(graph, couple):
    assert(len(couple) == 2)
    invGraph = [ [] for x in graph ]
    for i in range(len(graph)):
        invGraph[graph[i]].append(i)

    seen = [False]*len(graph)
    def findChain2(pos):
        if len(invGraph[pos]) == 0:
            return 1
        return max([findChain2(x) for x in invGraph[pos] ])+1
    def findChain(pos,noway):
        maxDepth = 0
        for ch in invGraph[pos]:
            if(ch == noway):
                continue
            maxDepth = max(maxDepth, findChain2(ch))
        return maxDepth+1
    
    return findChain(couple[0],couple[1]) + findChain(couple[1],couple[0])

def solve():
    input()
    descr = input().strip().split(' ')
    graph = [ int(x)-1 for x in descr ]
    sym = symgraph(graph)
    comps = components(sym)
    compCycles = []
    
    for comp in comps:
        compCycles.append(cycle(sym,comp))

    sumOf2chains = 0
    for (cLen,couple) in compCycles:
        if(cLen == 2):
            sumOf2chains += chainLen(graph,couple)
    
    longestCycle = max( [ x[0] for x in compCycles ] )

    return max(sumOf2chains, longestCycle)

T = int(input())
for c in range(T):
    print("Case #{}: {}".format(c+1,solve()))
