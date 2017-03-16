import sys
import numpy
import networkx

def full(B):
    if B <= 1:
        G = networkx.DiGraph()
        G.add_node(1)
        return G
    else:
        G = full(B - 1)
        for i in range(1, B):
            G.add_edge(i, B)
        return G

def solve(B, M):
    if M > 2 ** (B - 2):
        return None
    tokens = bin(M-1)[2:]
    G = full(len(tokens) + 1)
    for i in range(0, len(tokens)):
        if tokens[i] == '1':
            G.add_edge(len(tokens) - i + 1, B)
        G.add_edge(1, B)
    return G

def adj(B, G):
    a = numpy.zeros((B, B), dtype=int)
    for e in G.edges():
        a[e[0]-1, e[1]-1] = 1
    return a

l = sys.stdin.readline()
m = int(l.strip())

for i in range(0, m):
    l = sys.stdin.readline().strip()
    tokens = l.split(" ")
    B = int(tokens[0])
    M = int(tokens[1])
    G = solve(B, M)
    if G is None:
        print("Case #%d: IMPOSSIBLE" % (i + 1))
    else:
        print("Case #%d: POSSIBLE" % (i + 1))
        a = adj(B, G)
        for j in range(0, a.shape[0]):
            print("".join([str(x) for x in a[j]]))

