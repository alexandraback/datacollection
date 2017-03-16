import sys
sys.setrecursionlimit(100000)
def parse(f):
    lines = f.xreadlines()
    next(lines)
    while True:
        try:
            n = int(next(lines)) # number of classes
            graph = dict()
            for i in xrange(n):
                line = map(int, next(lines).split())
                cls, inherits = i+1, line[1:]
                graph[cls] = inherits
            yield graph
        except StopIteration:
            break

def reachable(graph, node, memoized):
    if not node in memoized:
        immediate = set(graph[node])
        memoized[node] = reduce(lambda x,y: x|y, 
                (reachable(graph, x, memoized) for x in immediate), set([node]) | immediate)
    return memoized[node]
def has_diamond_node(graph, node, no_diamond, reachability):
    if node in no_diamond: return False

    for i, o in enumerate(graph[node]):
        for w in graph[node][1+i:]:
            r1 = reachable(graph, o, reachability) 
            r2 = reachable(graph, w, reachability)
            if  r1 & r2:
                return True
    no_diamond.append(node)
    return False

def has_diamond(graph):
    no_diamond = []
    reachability = dict()
    for node in graph.keys():
        if has_diamond_node(graph, node, no_diamond, reachability):
            return True
    return False
import sys
with open(sys.argv[1]) as f:
    i = 1
    for graph in parse(f):
        if has_diamond(graph):
            print "Case #{}: Yes".format(i)
        else:
            print "Case #{}: No".format(i)
        i+=1
