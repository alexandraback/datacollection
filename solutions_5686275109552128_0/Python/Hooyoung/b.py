#!/usr/bin/env python

T = int(raw_input())
for t in xrange(T):
  raw_input()
  P = map(int,raw_input().split())
  best = max(P)+1
  for i in xrange(1,best):
    v = i
    for p in P:
      v += (p-1)//i
    if v < best:
      best = v
  print "Case #%d: %d" % (t+1,best)
    
  
