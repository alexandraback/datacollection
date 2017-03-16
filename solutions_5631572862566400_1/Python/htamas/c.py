#!/usr/bin/env python3

T = int(input())
for case in range(1, T+1):
  N = int(input())
  F = [int(i)-1 for i in input().split()]

  visited = set()
  cycle = {}
  for i in range(N):
    t = i
    current = set()
    while t not in visited and t not in current:
      current.add(t)
      t = F[t]
    visited.update(current)
    if t in current:
      curcycle = set()
      while t not in curcycle:
        curcycle.add(t)
        t = F[t]
      l = len(curcycle)
      for u in curcycle:
        cycle[u] = l

  dist = {i: (0, i) for i in cycle}
  for i in range(N):
    t = i
    d = 0
    while t not in dist:
      t = F[t]
      d += 1
    d += dist[t][0]
    u = dist[t][1]
    t = i
    while t not in dist:
      dist[t] = (d, u)
      d -= 1

  res = max(max(cycle.values()), sum(1+max(k for k, l in dist.values() if l==i) for i, j in cycle.items() if j==2))
  print("Case #{}: {}".format(case, res))

