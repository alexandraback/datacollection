#!/usr/bin/python
# -*- coding: utf-8 -*-
from hopcroftkarp import HopcroftKarp

T = int(raw_input().strip())

for t in xrange(0, T):
    N = int(raw_input().strip())
    fst = {}
    sec = {}
    words = []
    count1 = {}
    count2 = {}
    G = {}
    for _ in xrange(N):
        u, v = tuple(raw_input().strip().split())
        u = '1'+u
        v = '2'+v
        if u not in count1:
            count1[u] = 1

        if v not in count2:
            count2[v] = 1

        if u in G:
            G[u].add(v)
        else:
            G[u] = {v}

    H = HopcroftKarp(G).maximum_matching()
    answer = N - (len(count1) + len(count2) - len(H)/2)

    print "Case #%d: %s" % (t+1, answer)

