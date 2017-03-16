#!/usr/bin/env python

def ri():
  x=''
  while not x:
    x = raw_input().strip()
  return x

T=int(ri())
for t in xrange(1,T+1):
  A,N = map(int,ri().split())
  x = map(int,ri().split())
  x.sort()
  out = len(x)
  adds = 0
  while x and adds<out:
    x0 = x.pop(0)
    if A<2 and A<=x0:
      break
    while A <= x0:
      adds += 1
      A += A-1
    A += x0
    out = min(out,adds+len(x))
  print 'Case #%d: %d' % (t,out)
