import networkx as nx
G=nx.DiGraph()
for n in range(2,1000001):
    N=str(n)
    G.add_edge(str(n-1),N)
    if N[-1]!='0':
        G.add_edge(N[::-1],N)
for tc in range(input()):
    N=raw_input()
    print'Case #{}: {}'.format(tc+1,nx.shortest_path_length(G,'1',N)+1)