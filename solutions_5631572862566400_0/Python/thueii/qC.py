import sys
import networkx

l = sys.stdin.readline()
m = int(l.strip())

for i in range(0, m):
    l = sys.stdin.readline().strip()
    n = int(l)
    G = networkx.Graph()
    for j in range(1, n + 1):
        G.add_node(j)
    l = sys.stdin.readline().strip()
    tokens = l.split(" ")
    for z in range(0, n):
        x = z + 1
        y = int(tokens[z])
        G.add_edge(x, y)
    max_n = 0
    Cs = list(networkx.connected_component_subgraphs(G))
    for C in Cs:
        cycles = networkx.cycle_basis(C)
        if len(cycles) == 0:
            max_n = max(max_n, networkx.diameter(C) + 1)
        else:
            cycle = cycles[0]
            cycle_edges = []
            for (n1, n2) in zip(cycle[:-1], cycle[1:]):
                cycle_edges.append((n1, n2))
            cycle_edges.append((cycle[-1], cycle[0]))
            for edge in cycle_edges:
                H = C.copy()
                H.remove_edge(edge[0], edge[1])
                max_n = max(max_n, networkx.diameter(H) + 1)
    print("Case #%d: %s" % (i + 1, max_n))

