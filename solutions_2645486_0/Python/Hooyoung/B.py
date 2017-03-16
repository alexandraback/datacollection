#!/usr/bin/env python
import math

def ri():
  x=''
  while not x:
    x=raw_input().strip()
  return x

T = int(ri())
for t in xrange(T):
  E,R,N = map(int,ri().split())
  if R>E: R = E
  v = map(int,ri().split())
  n = [0]*len(v)
  i = 0
  out = 0
  cur = E
  while i < N:
    k = i
    j=i+1
    while j < N and cur+(j-i)*R <= E:
      if v[j]>v[k]:
        k = j
      j += 1
    if k == i:
      spend = cur
    else:
      spend = min(max(0,cur+(k-i)*R-E),cur)
    out += v[i]*spend
    cur = cur-spend
    i = i+1
  print 'Case #%d: %d'%(t+1,out)
