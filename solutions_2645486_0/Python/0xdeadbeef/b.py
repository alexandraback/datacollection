#!/usr/bin/env python
from math import sqrt
from math import floor

def solve(E, R, N, v):
  d = [[0 for x in xrange(E + 1)] for x in xrange(N + 1)]
  for i in range(1, N + 1):
    for e in range(0, E + 1):
      maxval = 0
      for k in range(0, e + 1):
        val = d[i-1][min(e-k+R, E)] + k * v[i-1]
        if val > maxval:
          maxval = val
      d[i][e] = max(d[i-1][e],maxval)
  return d[N][E]
  
def main():
  cases = int(raw_input())
  for case in range(cases):
    case = case + 1
    tups = raw_input().split()
    E = int(tups[0])
    R = int(tups[1])
    N = int(tups[2])
    tups = raw_input().split()
    v = [int(x) for x in tups]
    print "Case #%d: %d" % (case, solve(E, R, N, v))

main()
