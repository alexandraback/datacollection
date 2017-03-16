
from collections import Counter

def findRoute(fromNode, edges):
    if len(fromNode[0]) == fromNode[1]:
        return []
    for e in xrange(len(edges)):
        if e not in fromNode[0] and edges[e][0] in fromNode[2]:
            newNode = fromNode
            newNode[0].add(e)
            newNode[2][edges[e][0]] -= 1
            deltaCounter = Counter(edges[e][1:])
            newNode[2] += deltaCounter
            rest = findRoute(newNode, edges)
            newNode[2][edges[e][0]] += 1
            newNode[2] -= deltaCounter
            newNode[0].remove(e)
            if rest != None:
                return [e+1] + rest
    return None

def solve(filename):
    f = open(filename)
    out = open(filename+'.out.txt','w')
    T = int(f.readline())
    for t in xrange(T):
        K,N = map(int,f.readline().split())
        StartNode = [set(),N,Counter(map(int,f.readline().split()))]
        edges = []
        for n in xrange(N):
            edges.append(map(int,f.readline().split()))
        edges.sort(key = len, reverse = True)
        route = findRoute(StartNode, edges)
        if route == None:
            out.write("Case #"+str(t+1)+": IMPOSSIBLE\n")
        else:
            out.write("Case #"+str(t+1)+": " + " ".join(map(str,route))+'\n')
solve('D:\D-small-attempt1.in')
