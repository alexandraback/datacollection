import sys
from itertools import combinations

basename = "C-small-attempt1"

input_filename = basename + ".in"
output_filename = basename + ".out"

input_file = open(input_filename, 'r')
output_file = open(output_filename, 'w')

test_cases = int(input_file.readline().rstrip())

def bfs(edges, N, zips):
    graph = {i:[] for i in range(N)}
    for u,v in edges:
        graph[u].append(v)
        graph[v].append(u)
    path = []
    q = [0]
    while q:
        v = q.pop(0)
        if v not in path:
            path = path + [v]
            q = q + graph[v]
    return path 

def is_tree(edges, N):
    return len(bfs(edges, N, zips)) == N

def bestzip(edges, N, zips, root):
    graph = {i:[] for i in range(N)}
    for u,v in edges:
        graph[u].append(v)
        graph[v].append(u)
    result = str(zips[root])
    
    children = graph[root]
    children.sort(key= lambda x: zips[x])
    subedges = [e for e in edges if root not in e]
    for child in children:
        result += str(bestzip(subedges, N, zips, child))
    return result
    


for case in range(1, test_cases+1):
    N, M = [int(i) for i in input_file.readline().rstrip().split()]
    zips = []
    for i in range(N):
        zips.append(int(input_file.readline().rstrip()))
    flights = []
    for j in range(M):
        u,v = [int(i)-1 for i in input_file.readline().rstrip().split()]
        u,v = sorted([u,v])
        flights.append([u,v])
    found = []
    root = min((val, idx) for (idx, val) in enumerate(zips))[1]
    for tree in combinations(flights, N-1):
        if is_tree(tree, N):
            found.append(int(bestzip(tree, N, zips, root)))
    solution = str(min(found)) 

    # Output all goes below here. Make sure to define var 'solution' 
    output_file.write("Case #" + str(case) + ": " + str(solution))
    if case < test_cases:
        output_file.write('\n')

