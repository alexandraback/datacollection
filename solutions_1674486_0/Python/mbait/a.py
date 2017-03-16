#!/usr/bin/env python

import sys

def visit(g, u, v):
    v[u] = True

    for adj in g[u][1:]:
        if v[adj - 1] or visit(g, adj - 1, v):
            return True

    return False

def dfs(g):
    v = [False for i in range(len(g))]

    for adj in g:
        for u in adj[1:]:
            v[u - 1] = True

    for i in range(len(g)):
        if not v[i] and visit(g, i, [False for i in range(len(g))]):
            return 'Yes'

    return 'No'

t = int(sys.stdin.readline())

for t in range(1, t + 1):
    g = [[int(x) for x in sys.stdin.readline().strip().split()] for i in range(int(sys.stdin.readline()))]
    print 'Case #{0}: {1}'.format(t, dfs(g))
