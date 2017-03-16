#!/usr/bin/python
import json, sys

T = int(sys.stdin.readline())
for t in xrange(T):
  uncover = []

  K, C, S = map(int, sys.stdin.readline().split())
  
  all = range(K)
  targets = []
  while factors:
    curr = all[:C]
    factors = all[C:]
    # pad if there's nothing left
    if len(curr) < C:
      curr += [0] * (C - len(curr))
    target = 0
    for i, factor in enumerate(curr):
      target += factor * (K ** i)
    # print target
    targets.append(target)
  
  print 'Case #%d: %s' % (t + 1, \
      ' '.join(map(lambda x: str(x + 1), targets)) if len(targets) <= S \
      else 'IMPOSSIBLE')
