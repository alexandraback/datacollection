#!/usr/bin/env python

import numpy as np

def adjlist_find_paths(a, n, m, path=[]):
  "Find paths from node index n to m using adjacency list a."
  path = path + [n]
  if n == m:
    return 1
  paths = 0
  for i, c in enumerate(a[n]):
    if c == 1 and i not in path:
      paths += adjlist_find_paths(a, i, m, path)
  return paths

for i in xrange(int(raw_input())):
    B, P = [int(k) for k in raw_input().split()]
    found = False
    for b in xrange(2**(B*(B-1)/2)):
        graph = np.zeros(B*B, dtype=int).reshape(B,B)
        for k in range(B-1):
            for l in range(k+1,B):
                graph[k, l] = b % 2
                b = b >> 1
        if adjlist_find_paths(graph, 0, B-1) == P:
            sol = [''.join(map(str, x)) for x in graph]
            print "Case #{}: POSSIBLE".format(i+1)
            for s in sol:
                print s
            found = True
            break
    if not found:
        print "Case #{}: IMPOSSIBLE".format(i+1)


