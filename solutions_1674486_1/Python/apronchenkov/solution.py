import sys

def Test(graph, u):
    used = set([u])
    stack = [u]
    while stack:
        i = stack.pop()
        for j in graph[i]:
            if j in used:
                return True
            used.add(j)
            stack.append(j)
    return False
        

def Solve(graph):
    leafs = set(graph.keys())
    for e in graph.values():
        map(leafs.discard, e)
    for u in leafs:
        if Test(graph, u):
            return "Yes"
    return "No"

numberOfCases = int(sys.stdin.readline())
for case in xrange(numberOfCases):
    graph = dict()
    N = int(sys.stdin.readline())
    for u in xrange(1, N + 1):
        token = map(int, sys.stdin.readline().split())
        graph[u] = token[1:1+ token[0]]
    print "Case #%d: %s" % (case + 1, Solve(graph))
