#!/usr/bin/python

from sys import stdin as I
import math

def solve(n):
  K, C, S = map(int, I.readline().split())
  
  if S * C < K:
    print("Case #%i: IMPOSSIBLE" % (n+1))
    return

  check = []
  t = range(K)
  while len(t) > 0:
    st = t[:C]
    t = t[C:]
    c = 0
    for x in zip(st, range(C)):
      c += x[0]*K**x[1]
    check.append(c + 1)

  print("Case #%i: %s" % (n+1, ' '.join(map(str, check))))

T = int(I.readline())
for i in range(T):
    solve(i)
