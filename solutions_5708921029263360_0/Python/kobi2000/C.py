import os
import sys
import StringIO
import itertools
from collections import defaultdict

inputs="""\
4
1 1 1 10
1 2 3 2
1 1 3 2
1 2 3 1
"""

inf = StringIO.StringIO(inputs) if sys.stdin.isatty() else sys.stdin
#sys.setrecursionlimit(10000)

def solve(J, P, S, K):
  mapa = {}
  mapjp = {}
  mapps = {}
  mapjs = {}

  res = []
  while True:
    bFound = False
    for j in range(J):
      for p in range(P):
        for s in range(S):
          if mapa.setdefault((j,p,s),0) < 1\
              and mapjp.setdefault((j,p),0) + mapps.setdefault((p,s),0) + mapjs.setdefault((j,s),0) < K:
              mapa[(j,p,s)] = mapa.setdefault((j,p,s),0) + 1
              mapjp[(j,p)] = mapjp.setdefault((j,p),0) + 1
              mapps[(p,s)] = mapps.setdefault((p,s),0) + 1
              mapjs[(j,s)] = mapjs.setdefault((j,s),0) + 1
              res.append([j+1, p+1, s+1])
              bFound = True
              break
        if bFound: break
      if bFound: break

    if not bFound:
      return res

def nextVal():
  return inf.readline().rstrip('\n')

T = int(nextVal())
for t in range(1,T+1):
  J, P, S, K = map(int, nextVal().split())
  res = solve(J, P, S, K)
  print "Case #%d: %d"%(t, len(res),)
  for r in res:
    print ' '.join(map(str, r))
