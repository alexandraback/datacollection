import networkx as nx

def main_code(x):
    N = int(input())
    gg = nx.MultiGraph()
    for _ in range(N):
        a, b = input().split()
        gg.add_edge('<' + a, '>' + b)
    
    g = nx.Graph(gg)
    t = nx.bipartite.maximum_matching(g)
    result = gg.size() - ((len(t)//2) + sum(1 for v in g.nodes() if v not in t))
    print("Case #" + str(x + 1) + ":", result)

T = int(input())
for x in range(T):
    main_code(x)
