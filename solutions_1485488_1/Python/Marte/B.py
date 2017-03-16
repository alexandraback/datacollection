import sys
import string
from heapq import *
inp = sys.stdin
T = int(inp.readline())

for cas in xrange(1, T + 1):
  print "Case #%d:" % cas,
  H, N, M = [int(x) for x in inp.readline().split(' ')]
  def gen(n, m):
    if n - 1 >= 0:
      yield n-1, m
    if n + 1 < N:
      yield n+1, m
    if m - 1 >= 0:
      yield n, m-1
    if m + 1 < M:
      yield n, m+1
  ceils = []
  for i in xrange(N):
    ceils.append([int(x) for x in inp.readline().split(' ')])
  floors = []
  for i in xrange(N):
    floors.append([int(x) for x in inp.readline().split(' ')])
  vis = set()
  q = [(0, (0, 0, H, 1))]
  while 1:
    d, node = heappop(q)
    n, m, h, st = node
    if n == N-1 and m == M-1:
      break
    if node in vis:
      continue
    vis.add(node)
    for xn, xm in gen(n, m):
      if ceils[xn][xm] - floors[xn][xm] < 50:
        continue
      if ceils[xn][xm] - floors[n][m] < 50:
        continue
      if ceils[n][m] - floors[xn][xm] < 50:
        continue
      if ceils[xn][xm] - h < 50:
        continue
      if st:
        xd = 0
        xnode = xn, xm, h, 1
      elif h - floors[n][m] < 20:
        xd = d + 100
        xnode = xn, xm, max(0, h-100), 0
      else:
        xd = d + 10
        xnode = xn, xm, max(0, h-10), 0
      heappush(q, (xd, xnode))
    if h > floors[n][m]:
      heappush(q, (d+1, (n, m, h-1, 0)))
  print "%0.1f" % (d/10.0)

