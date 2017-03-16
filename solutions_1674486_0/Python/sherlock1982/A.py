import sys

inp  = sys.stdin
# inp  = open("A.test", "r")
outp = sys.stdout

T = int( inp.readline() )

def find_all_paths(graph, start, end, path=[]):
        path = path + [start]
        if start == end:
            return [path]
        if not graph.has_key(start):
            return []
        paths = []
        for node in graph[start]:
            if node not in path:
                newpaths = find_all_paths(graph, node, end, path)
                for newpath in newpaths:
                    paths.append(newpath)
        return paths

for i in range(T):
    classes = int( inp.readline() )
    diagram = [ [] ] * classes
    
    graph   = {} 
    
    # read graph
    for j in range(classes):
        raw = map(int, inp.readline().split(" "))
        
        if raw[0] > 0:
            graph[ j + 1 ] = raw[1:]
        else:
            graph[ j + 1 ] = []
    # process graph
    diamond = False
    for a in range(classes):
        for b in range(classes):
            paths = find_all_paths( graph, a + 1, b + 1 )
            if len(paths) >= 2:
                diamond = True
                break
    if diamond:
        outp.write("Case #" + str(i+1) + ": Yes\n")
    else:
        outp.write("Case #" + str(i+1) + ": No\n")
