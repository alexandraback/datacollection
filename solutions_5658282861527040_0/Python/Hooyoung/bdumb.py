#!/usr/bin/env python

T = int(raw_input())
for t in xrange(T):
  A,B,K = map(int,raw_input().split())
  c = 0
  for a in xrange(A):
    for b in xrange(B):
      if (a&b)<K:
        c += 1
  print 'Case #%d: %d' % (t+1,c)

