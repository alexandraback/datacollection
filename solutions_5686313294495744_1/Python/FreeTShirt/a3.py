import networkx as nx
from networkx.algorithms import bipartite


fp = open("a3s.txt")
fw = open("a3a.txt", 'w')
t = int(fp.readline().strip())
for case in range(t):
    n = int(fp.readline().strip())
    
    s1c = set()
    s2c = set()
    edge = []
    for _ in range(n):
        s1, s2 = fp.readline().strip().split()
        s1 = s1 + 'a'
        s2 = s2 + 'b'
        s1c.add(s1)
        s2c.add(s2)
        edge.append((s1,s2))
    b = nx.Graph()
    b.add_nodes_from(list(s1c), bipartite=0)
    b.add_nodes_from(list(s2c), bipartite=1)
    b.add_edges_from(edge)
    d = bipartite.hopcroft_karp_matching(b)
    print(len(edge))
    print(len(s1c))
    print(len(s2c))
    print(d)
    p = len(edge) - len(s1c) - len(s2c) + len(d)/2
    fw.write(('Case #{0}: {1}\n'.format(case+1, int(p))))
