# -*- coding: utf-8 -*-

t = int(raw_input())

for i in xrange(1, t+1):
  print 'Case #%d:' % i,
  a, n = map(int, raw_input().split())
  ms = map(int, raw_input().split())
  ms.sort()
  best = len(ms)
  i = 0
  added = 0
  while i < n:
    if a > ms[i]:
      a += ms[i]
      i += 1
    else:
      a += a-1
      added += 1
      if a == 1:
	i += 1
    best = min(best, added + n-i)
  print best
