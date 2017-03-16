#!/usr/bin/env python2
# -*- coding: utf-8 -*-

import networkx as nx

def case(t):
    B = nx.Graph()
    na, nb = [], []
    es = [raw_input().split() for _ in xrange(int(raw_input()))]
    res = []
    for a, b in es:
        a = 'a' + a
        b = 'b' + b
        res.append((a, b))
        na.append(a)
        nb.append(b)
    B.add_nodes_from(na, bipartite=0)
    B.add_nodes_from(nb, bipartite=1)
    B.add_edges_from(res)
    m = nx.algorithms.bipartite.matching.hopcroft_karp_matching(B)
    # print 'matching:', len(m) >> 1
    # print 'a:', len(set(na))
    # print 'b:', len(set(nb))
    # print 'edges:', len(res)
    tot = len(res) - len(set(na)) - len(set(nb)) + (len(m) >> 1)
    print('Case #{}: {}'.format(t, tot))

if __name__ == "__main__":
    map(case, xrange(1, int(raw_input())+1))
