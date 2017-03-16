from collections import defaultdict 
from networkx.algorithms.bipartite.matching import hopcroft_karp_matching
from networkx.algorithms.bipartite import sets
import networkx as nx

def main():
    T = int(raw_input())
    for i in xrange(T):
        # print '=== case', i
        N = int(raw_input())
        l = []

        left_nodes = set()
        right_nodes = set()
        edges = []
        for n in xrange(N):
            topic = raw_input().split()
            topic[0] += '_left'
            topic[1] += '_right'
            left_nodes.add(topic[0])
            right_nodes.add(topic[1])
            edges.append(tuple(topic))

        # print left_nodes, right_nodes, edges
        edges = set(edges)

        G = nx.Graph()
        G.add_nodes_from(left_nodes, bipartite=0)
        G.add_nodes_from(right_nodes, bipartite=1)
        G.add_edges_from(edges)

        matching = hopcroft_karp_matching(G)
        min_cover = set(matching.items())
        uncovered_nodes = set(G) - {v for u, v in min_cover}
        for v in uncovered_nodes:
            u = next(iter(G[v]))
            min_cover.add((u, v))
            min_cover.add((v, u))

        min_cover = [(u, v) for u, v in min_cover if (u, v) in edges]
        # print min_cover
        output(i, N - len(min_cover))
     
        

def output(casenum, n):
    print 'Case #%d: %s' % (casenum + 1, n)


main()
