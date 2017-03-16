def dfs(begining, graph, visted):
    visted.append(begining)
    if begining in graph:
        for end in graph[begining]:
            dfs(end, graph, visted)
    return visted

def isDiamond(graph):
    for begining in graph:
        visted = dfs(begining, graph, [])
        print visted
        if len(visted) > len(set(visted)):
            return True
    return False
    
    

fin = open('A-small-attempt0.in', 'r')
s = fin.read()
fin.close()
lines = s.split('\n')

fout = open('output', 'w')
T = int(lines.pop(0))

for i in range(T):
    graph = {}
    N = int(lines.pop(0))
    for classNum in range(1, N+1):
        inheritsFrom = [int(x) for x in lines.pop(0).split(' ')[1:]]
        graph[classNum] = inheritsFrom
    result = isDiamond(graph)

    fout.write('Case #%d: ' % (i+1))
    if result:
        fout.write('Yes')
    else:
        fout.write('No')
    fout.write('\n')


fout.close()
