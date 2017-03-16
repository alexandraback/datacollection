#!/usr/bin/python
import json, sys

T = int(sys.stdin.readline())
for t in xrange(T):
  uncover = []

  K, C, S = map(int, sys.stdin.readline().split())
  
  # makes it easier to calculate, lol
  all = range(K)
  targets = []
  while all:
    # take the complexity factors
    curr = all[:C]
    all = all[C:]
    
    # calculate a target for each C elements
    target = 0
    for i, factor in enumerate(curr):
      target += factor * (K ** i)
    
    # print target
    targets.append(target)
  
  print 'Case #%d: %s' % (t + 1, \
      ' '.join(map(lambda x: str(x + 1), targets)) if len(targets) <= S \
      else 'IMPOSSIBLE')
