def find_all_paths(graph, start, end, path=[]):
    path = path + [start]
    if start == end:
        return [path]
    if not start in graph.keys():
        return []
    paths = []
    for node in graph[start]:
        if node not in path:
            newpaths = find_all_paths(graph, node, end, path)
            for newpath in newpaths:
                paths.append(newpath)
    return paths

inFile = open("B-small-attempt3.in")
outFile = open("2.out", "w")

from itertools import product

inFile.readline()
cnt = 1

for line in inFile:
    [B, M] = [int(val) for val in line.rstrip().split()]
    
##    graph = {0: [i for i in range(1,B)]}

    options = [[] for i in range(B)]
    for i in range(B):
        for j in range(B):
            options[i].append([val for val in range(j, B)])
        options[i].append([])

    prod = list(product(*options))

    for val in prod:
        graph = {i:[] for i in range(B)}
        for i in range(B):
            graph[i] = val[i]
##        for i in range(B):
##            if i not in val:
##                graph[i] = []
    
##    for i in range(B):
##        graph[i] = []
##
##    depth = 0
##
##    while(depth < B):
##        depth += 1
##        currNode = B-depth
##        for i in range(B-1, currNode, -1):
##            graph[currNode].append(i)

        paths = find_all_paths(graph, 0, B-1)
##            print(paths)

##        print(graph)
        if(len(paths) == M):
            print("Case #" + str(cnt) + ": POSSIBLE", file=outFile)
            for i in range(B):
                print("".join(str(int(j in graph[i])) for j in range(B)), file=outFile)
            break

    if(len(paths) != M):
        print("Case #" + str(cnt) + ": IMPOSSIBLE", file=outFile)

    cnt += 1

outFile.close()
