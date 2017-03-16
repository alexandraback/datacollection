import sys

sys.setrecursionlimit(100000)

def dfs(node):
    if visited[node]:
        return True
    visited[node] = True
    return any(map(dfs, graph[node]))

f = open('A-large.in')
testcases = int(f.readline())
for testcase in range(1, testcases + 1):
    n = int(f.readline())
    graph = []
    in_edge = [0, ] * n
    for i in range(0, n):
        line = f.readline()
        edges = map(lambda x: x-1, map(int, line.split()[1:]))
        graph.append(edges)
        for e in edges:
            in_edge[e] = 1
    result = 'No'
    for i in range(0, n):
        if not in_edge[i]:
            visited = [0, ] * n
            if dfs(i):
                result = 'Yes'
                break
    print 'Case #%d: %s' % (testcase, result)

